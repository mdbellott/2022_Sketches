#pragma once

#include "ofMain.h"
#include "ScratchShape.h"

class Scratch : public ofBaseApp{

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
    
    void setupVideo();
    ofVideoPlayer wavesMovie;
    ofPixels videoInverted;
    ofTexture videoTexture;
    ofTexture videoTexture1;
    ofTexture videoTexture2;
    ofTexture videoTexture3;
    float dt;
    
    void setupShapes();
    int n;
    vector<ScratchShape> shapes;
};
