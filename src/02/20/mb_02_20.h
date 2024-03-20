#pragma once

#include "ofMain.h"
#include "ofxColorGradient.h"

class mb_02_20 : public ofBaseApp{

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

    vector<float> dts;
    vector<bool> incs;
    
    ofxColorGradient<ofColor> gradient1;
    ofxColorGradient<ofColor> gradient2;
    ofxColorGradient<ofColor> gradient3;
    ofxColorGradient<ofColor> gradient4;
    ofxColorGradient<ofColor> gradient5;
};
