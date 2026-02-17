#pragma once
#include <GL/glut.h>
#include <string>
#include <vector>



/**
 * @class Renderer
 * @brief Handles 3D rendering, camera movement and user interaction.
 * Initializes window and OpenGL.
 * Handles camera rotation and zoom.
 * Draws box and scene objects.
 * Calculates FPS.
 */
class Renderer {
    private:
      /// Current window width in pixels
      int windowWidth;
      /// Current window height in pixels
      int windowHeight;
      std::string windowTitle;

      float cameraRotX, cameraRotY;

      /// Distance of camera from scene center
      float cameraDist;
      int lastMouseX, lastMouseY;
      bool mousePressed;

      // std::vector<Particle> particles;
      float boxSize;

      int frameCount;
      float fps;
      double lastTime;


    public:

        /**
         * @brief Creates renderer with default parameters.
         * 
         * Initializes camera position, window size,
         * rendering settings and FPS counter.
         */
        Renderer();
        ~Renderer();

        bool initialize(int width, int height, std::string title);
        /**
         * @brief Renders entire scene.
         * 
         * Clears buffers, applies camera transformations,
         * draws scene objects and swaps buffers.
         */
        void render();
        void update();

        void mouseButton(int button, int state, int x, int y);
        void mouseMove(int x, int y);
        void keyboard(unsigned char key, int x, int y);
        void reshape(int width, int height);

        void drawBox();
        // void drawParticles();
        void drawInfo();
        void drawGrid();

        // inline void setParticles(const std::vector<Particle>& newParticles) { particles = newParticles;}
        inline void setBoxSize(float size) { boxSize = size; }

    
        
        static void displayCallback();
        static void keyboardCallback(unsigned char key, int x, int y);
        static void mouseCallback(int button, int state, int x, int y);
        static void motionCallback(int x, int y);
        static void reshapeCallback(int width, int height);
        static void idleCallback();
};