#pragma once
#include <GL/glut.h>
#include <string>
#include <vector>
#include "../core/Particle.h"



class Renderer {
    private:
      int windowWidth;
      int windowHeight;
      std::string windowTitle;

      float cameraRotX, cameraRotY;

      float cameraDist;
      int lastMouseX, lastMouseY;
      bool mousePressed;

      std::vector<Particle> particles;
      float boxSize;

      int frameCount;
      float fps;
      double lastTime;


    public:


        Renderer();
        ~Renderer();

        bool initialize(int width, int height, std::string title);

        void render();
        void update();

        void mouseButton(int button, int state, int x, int y);
        void mouseMove(int x, int y);
        void keyboard(unsigned char key, int x, int y);
        void reshape(int width, int height);

        void drawBox();
        void drawParticles();
        void drawInfo();

        inline void setParticles(const std::vector<Particle>& newParticles) { particles = newParticles;}
        inline void setBoxSize(float size) { boxSize = size; }

    
        
        static void displayCallback();
        static void keyboardCallback(unsigned char key, int x, int y);
        static void mouseCallback(int button, int state, int x, int y);
        static void motionCallback(int x, int y);
        static void reshapeCallback(int width, int height);
        static void idleCallback();
};