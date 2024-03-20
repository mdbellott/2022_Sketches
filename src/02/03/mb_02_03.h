#pragma once

#include "ofMain.h"
#include "Particle_02_03.h"

class mb_02_03 : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void resetParticles();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        vector <Particle_02_03> p;
        vector <glm::vec3> points;
        vector <glm::vec3> pointsWithMovement;
		
};
