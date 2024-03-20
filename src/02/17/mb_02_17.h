#pragma once

#include "ofMain.h"

class mb_02_17 : public ofBaseApp{

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

    void drawFbo();
    
    int fadeAmnt;
    int n;
    float size;
    
    int speed;
    int x;
    int y;
    
    vector<ofFbo> shapes;
};
