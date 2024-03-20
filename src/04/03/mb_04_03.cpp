#include "mb_04_03.h"

//--------------------------------------------------------------
void mb_04_03::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    gradient.addColor(ofColor(228, 179, 196));      // E4B3C4
    gradient.addColor(ofColor(148, 169, 190));      // 94A9BE
    
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
void mb_04_03::update(){
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
void mb_04_03::draw(){
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
            float w = (ofGetWidth()/n) - 16;
            float h = (ofGetWidth()/m);
            ofDrawPlane(y, x, h, w);
        }
    }
    ofRotateDeg(-45, 0.0, 0.0, 1.0);
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
            float w = (ofGetWidth()/n) - 16;
            float h = (ofGetWidth()/m);
            ofDrawPlane(y, x, h, w);
        }
    }
}

//--------------------------------------------------------------
void mb_04_03::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_04_03::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_04_03::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_04_03::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_03::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_03::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_04_03::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_04_03::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_04_03::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_04_03::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_04_03::dragEvent(ofDragInfo dragInfo){

}
