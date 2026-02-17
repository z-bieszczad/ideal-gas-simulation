#pragma once
#include <GL/glut.h>
#include <string>
#include <vector>
#include "../world/World.h"
#include "../core/Particle.h"



class Renderer {
    private:
      int _windowWidth;
      int _windowHeight;
      std::string _windowTitle;

      float _cameraRotX, _cameraRotY;

      float _cameraDist;
      int _lastMouseX, _lastMouseY;
      bool _mousePressed;

      World* _worldPtr;

      int _frameCount;
      float _fps;
      double _lastTime;



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

        inline void setWorld(World* world) { _worldPtr = world; }    
        
        static void displayCallback();
        static void keyboardCallback(unsigned char key, int x, int y);
        static void mouseCallback(int button, int state, int x, int y);
        static void motionCallback(int x, int y);
        static void reshapeCallback(int width, int height);
        static void idleCallback();
};