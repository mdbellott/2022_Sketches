#include "mb_04_02.h"

//--------------------------------------------------------------
void mb_04_02::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    gradient.addColor(ofColor(116, 179, 184));          // 74B3B8
    gradient.addColor(ofColor(172, 222, 232));          // ACDEE8
    gradient.addColor(ofColor(35, 37, 34));             // 232522
    
    gradient.drawDebug(0,
                       0,
                       ofGetWidth(),
                       ofGetHeight(),
                       100,
                       false,
                       true);

    dt = 0.0;
    inc = 0.2;
    
    m = 5;
    n = 50;
    
    up = true;
}

//--------------------------------------------------------------
void mb_04_02::update(){
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
void mb_04_02::draw(){
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
            ofDrawPlane(y, x, h, w);
        }
    }
}

//--------------------------------------------------------------
void mb_04_02::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_04_02::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_04_02::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_04_02::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_02::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_02::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_02::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_04_02::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_04_02::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_04_02::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_04_02::dragEvent(ofDragInfo dragInfo){

}
