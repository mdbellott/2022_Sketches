#pragma once

#include "ofMain.h"
#include "ofxColorGradient.h"

class mb_09_29 : public ofBaseApp{

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
    
    void drawFBO();
    
    ofxColorGradient<ofColor> gradient;
    
    ofFbo fbo;
    
    float n;
    float m;
    vector<vector<glm::vec2>> pos;
    vector<vector<glm::vec2>> vel;
    vector<vector<bool>> xUp;
    
    float rad;
    float dt;
    float inc;
    float fade;
};
