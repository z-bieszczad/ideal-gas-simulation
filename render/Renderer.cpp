#include <iostream>
#include "Renderer.h"

Renderer* instance = nullptr;


Renderer::Renderer() :
    _windowWidth(1024), _windowHeight(768), _windowTitle("Ideal Gas Simulation 3D"),
    _cameraRotX(30.0), _cameraRotY(-30.0), _cameraDist(20.0), _lastMouseX(0), _lastMouseY(0),
    _mousePressed(false), _frameCount(0), _fps(0.0), _lastTime(0.0), _worldPtr(nullptr) {
    
    instance = this;

    std::cout << "[RENDERER] Creating renderer \n";
}

void Renderer::drawParticles() {
    if (!_worldPtr) return;

    const auto& particles = _worldPtr->getParticles();
    if (particles.empty()) return;

    for (const auto& p : particles) {
        glPushMatrix();

        Vector3d pos = p.getPosition();
        glTranslatef(pos.getX(), pos.getY(), pos.getZ());
// 
        Vector3d vel = p.getVelocity();
        double speed = vel.magnitude();

        float speedFactor = std::min(1.0, speed / 5.0f);
        glColor3f(speedFactor, 0.2f, 1.0f - speedFactor);

//  do  zmiany na color liczony z physics system tam gdzie wszystkie wartosci czastki
        // Vector3d color = p.getColor();
        // glColor3f(color.getX(), color.getY(), color.getZ())

        GLUquadric* quad = gluNewQuadric();
        gluSphere(quad, 0.2, 16, 16);
        gluDeleteQuadric(quad);

        glPopMatrix();
    }
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, -_cameraDist);
    glRotatef(_cameraRotX, 1, 0, 0);
    glRotatef(_cameraRotY, 0, 1, 0);

    drawBox();
    drawParticles();
    drawInfo();

    glutSwapBuffers();

    _frameCount++;
    double currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0; 
    if (currentTime - _lastTime > 1.0) {
        _fps = _frameCount / (currentTime - _lastTime);
        _frameCount = 0;
        _lastTime = currentTime;
    }
}

void Renderer::drawBox() {
    glDisable(GL_LIGHTING);
    
    glColor4f(0.3f, 0.5f, 1.0f, 0.1f);

    float s = _worldPtr->getBoxSize() / 2;

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
    _windowWidth = width;
    _windowHeight = height;

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
        _mousePressed = (state == GLUT_DOWN);
        _lastMouseX = x;
        _lastMouseY = y;
    }
}

void Renderer::mouseMove(int x, int y) {
    if (_mousePressed) {
        _cameraRotY += (x - _lastMouseX) * 0.3f;
        _cameraRotX += (y - _lastMouseY) * 0.3f;

        if (_cameraRotX > 80) _cameraRotX = 80;
        if (_cameraRotY< -80) _cameraRotY = -80;

        _lastMouseX = x;
        _lastMouseY = y;
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
    _windowHeight = height;
    _windowTitle = title;
    _windowWidth = width;

    int argc = 1;
    char* argv[1] = {(char*)"simulation"};
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(_windowWidth, _windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(_windowTitle.c_str());

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

