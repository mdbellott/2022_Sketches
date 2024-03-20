#include "mb_04_01.h"

//--------------------------------------------------------------
void mb_04_01::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    gradient.addColor(ofColor(104, 197, 207));          // 68C5CF
    gradient.addColor(ofColor(225, 129, 111));          // E1816F
    gradient.drawDebug(0,
                       0,
                       ofGetWidth(),
                       ofGetHeight(),
                       100,
                       false,
                       true);

    dt = 0.0;
    inc = 0.1;
    
    m = 7;
    n = 50;
    
    up = true;
}

//--------------------------------------------------------------
void mb_04_01::update(){
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
void mb_04_01::draw(){
    gradient.drawDebug(0,
                       0,
                       ofGetWidth(),
                       ofGetHeight(),
                       100,
                       false,
                       true);

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
            float w = (ofGetWidth()/n) - 14;
            float h = (ofGetWidth()/m);
            ofDrawPlane(x, y, w, h);
        }
    }
}

//--------------------------------------------------------------
void mb_04_01::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_04_01::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_04_01::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_04_01::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_01::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_01::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_01::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_04_01::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_04_01::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_04_01::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_04_01::dragEvent(ofDragInfo dragInfo){

}
