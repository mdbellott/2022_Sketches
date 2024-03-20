#pragma once

#include "ofMain.h"
#include "ofxColorGradient.h"

class mb_09_07 : public ofBaseApp{

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
    
    ofxColorGradient<ofColor> gradient;
    
    float inc;
    
    float n;
    float m;
    float size;
    
    vector<vector<glm::vec2>> sqr1;
    vector<vector<glm::vec2>> sqr2;
    vector<vector<float>> vsqr2;
    vector<vector<glm::vec2>> sqr3;
    vector<vector<float>> vsqr3;
};
