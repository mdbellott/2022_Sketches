#include "mb_05_18.h"

//--------------------------------------------------------------
void mb_05_18::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    gradient.addColor(ofColor(193, 209, 153));      // C1D199
    gradient.addColor(ofColor(222, 66, 21));        // DE4215
    gradient.addColor(ofColor(206, 226, 140));      // CEE28C
    
    gradient.drawDebug(0,
                       0,
                       ofGetWidth(),
                       ofGetHeight(),
                       100,
                       false,
                       true);

    dt = 0.0;
    inc = 0.2;
    
    m = 10;
    n = 20;
    
    up = true;
}

//--------------------------------------------------------------
void mb_05_18::update(){
    int mult = 1000;
    if (up) {
        dt += inc;
        if (dt > inc*mult) {
            up = false;
        }
    } else {
        dt -= inc;
        if (dt < 0 - inc*mult) {
            up = true;
        }
    }
}

//--------------------------------------------------------------
void mb_05_18::draw(){
    ofNoFill();
    ofSetLineWidth(2);
    ofEnableSmoothing();
    
    float mult = 2;
    
    gradient.drawDebug(0,
                       0,
                       ofGetWidth(),
                       ofGetHeight(),
                       100,
                       false,
                       true);

    ofRotateDeg(45, 0.0, 0.0, 1.0);
    for (float j=-m; j<=m*2; j+=1.0) {
        for (float i=-n; i<=n*2; i+=1.0) {
            ofSetColor(255);
            float x = (ofGetWidth()/n) * i;
            float y = (ofGetWidth()/m) * j;
            if (int(j)%2 == 0) {
                x -= dt;
            } else {
                x += dt;
            }
            float w = (ofGetWidth()/n)*mult;
            ofDrawLine(y, x, y+w, x-w);
        }
    }
    ofRotateDeg(-90, 0.0, 0.0, 1.0);
    for (float j=-m; j<=m*2; j+=1.0) {
        for (float i=-n; i<=n*2; i+=1.0) {
            ofSetColor(255);
            float x = (ofGetWidth()/n) * i;
            float y = (ofGetWidth()/m) * j;
            if (int(j)%2 == 0) {
                x -= dt;
            } else {
                x += dt;
            }
            float w = (ofGetWidth()/n)*mult;
            ofDrawLine(y, x, y-w, x+w);
        }
    }
}

//--------------------------------------------------------------
void mb_05_18::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_05_18::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_05_18::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_05_18::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_18::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_18::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_18::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_05_18::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_05_18::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_05_18::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_05_18::dragEvent(ofDragInfo dragInfo){

}
