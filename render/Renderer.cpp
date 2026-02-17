#include <iostream>
#include "Renderer.h"

Renderer* instance = nullptr;


Renderer::Renderer() :
    windowWidth(1024), windowHeight(768), windowTitle("Ideal Gas Simulation 3D"),
    cameraRotX(30.0), cameraRotY(-30.0), cameraDist(20.0), lastMouseX(0), lastMouseY(0),
    mousePressed(false), boxSize(10.0), frameCount(0), fps(0.0), lastTime(0.0) {
    
    instance = this;

    std::cout << "[RENDERER] Creating renderer \n";
}

void Renderer::drawParticles() {
    if (particles.empty()) return;

    for (const auto& p : particles) {
        glPushMatrix();

        Vector3d pos = p.getPosition();
        glTranslatef(pos.getX(), pos.getY(), pos.getZ());

        Vector3d vel = p.getVelocity();
        double speed = vel.magnitude();

        float speedFactor = std::min(1.0, speed / 5.0f);
        glColor3f(speedFactor, 0.2f, 1.0f - speedFactor);

        GLUquadric* quad = gluNewQuadric();
        gluSphere(quad, 0.2, 16, 16);
        gluDeleteQuadric(quad);

        glPopMatrix();
    }
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, -cameraDist);
    glRotatef(cameraRotX, 1, 0, 0);
    glRotatef(cameraRotY, 0, 1, 0);

    drawBox();
    drawParticles();
    drawInfo();

    glutSwapBuffers();

    frameCount++;
    double currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0; 
    if (currentTime - lastTime > 1.0) {
        fps = frameCount / (currentTime - lastTime);
        frameCount = 0;
        lastTime = currentTime;
    }
}

void Renderer::drawBox() {
    glDisable(GL_LIGHTING);
    
    glColor4f(0.3f, 0.5f, 1.0f, 0.1f);

    float s = boxSize/2;

    glColor3f(0.5f, 0.7f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);

    for (int i = -1; i <= 1; i+=2) {
        for (int j = -1; j <=1; j+=2) {
            glVertex3f(i*s, j*s, -s);
            glVertex3f(i*s, j*s, s);

            glVertex3f(i*s, s, j*s);
            glVertex3f(i*s, -s, j*s);

            glVertex3f(-s, i*s, j*s);
            glVertex3f(s, i*s, j*s);
        }
    }

    glEnd();

    glEnable(GL_LIGHTING);
}


void Renderer::drawInfo() {

}

void Renderer::update() {
    glutPostRedisplay();
}

void Renderer::reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width/height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void Renderer::keyboard(unsigned char key, int x, int y){

}



void Renderer::mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        mousePressed = (state == GLUT_DOWN);
        lastMouseX = x;
        lastMouseY = y;
    }
}

void Renderer::mouseMove(int x, int y) {
    if (mousePressed) {
        cameraRotY += (x - lastMouseX) * 0.3f;
        cameraRotX += (y - lastMouseY) * 0.3f;

        if (cameraRotX > 80) cameraRotX = 80;
        if (cameraRotY< -80) cameraRotY = -80;

        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();
    }
}

void Renderer::displayCallback() {
    if (instance) instance->render();
}

void Renderer::keyboardCallback(unsigned char key, int x, int y) {
    if (instance) instance->keyboard(key, x, y);
}

void Renderer::mouseCallback(int button, int state, int x, int y) {
    if (instance) instance->mouseButton(button, state, x, y);
}

void Renderer::motionCallback(int x, int y) {
    if (instance) instance->mouseMove(x, y);
}

void Renderer::reshapeCallback(int width, int height) {
    if (instance) instance->reshape(width, height);
}

void Renderer::idleCallback() {
    if (instance) instance->update();
}

bool Renderer::initialize(int width, int height, std::string title) {
    windowHeight = height;
    windowTitle = title;
    windowWidth = width;

    int argc = 1;
    char* argv[1] = {(char*)"simulation"};
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(windowTitle.c_str());

    glutDisplayFunc(displayCallback);
    glutKeyboardFunc(keyboardCallback);
    glutMouseFunc(mouseCallback);
    glutMotionFunc(motionCallback);
    glutReshapeFunc(reshapeCallback);
    glutIdleFunc(idleCallback);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glClearColor(0.05f, 0.05f, 0.01f, 1.0f); //kolory tla

    GLfloat lightPos[] = {10.0f, 10.0f, 10.0f, 1.0f};
    GLfloat lightAmb[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat lightDiff[] = {0.8f, 0.8f, 0.8f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);

    return true;
}

Renderer::~Renderer() {
    instance = nullptr;
}

