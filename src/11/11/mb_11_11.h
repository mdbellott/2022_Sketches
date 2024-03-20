// Base code by: https://junkiyoshi.com/openframeworks20200525/

#pragma once

#include "ofMain.h"
#include "ofxColorGradient.h"


class mb_11_11 : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

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
     
        ofEasyCam cam;
        ofxColorGradient<ofColor> gradient;
    
        ofMesh face, frame;
        int bands;
        vector<float> seeds;
    
};
