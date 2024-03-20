#pragma once

#include "ofMain.h"
#include "ofxColorGradient.h"

class mb_03_07 : public ofBaseApp{

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
    
    void setupGradient();
    
    int n;
    int offset;

    
    vector<float> xs;
    vector<float> ys;
    vector<vector<float>> rads;
    vector<vector<bool>> ups;
    
    ofxColorGradient<ofColor> gradient;
};
