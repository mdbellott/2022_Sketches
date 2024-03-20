#include "mb_05_19.h"

//--------------------------------------------------------------
void mb_05_19::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    gradient.addColor(ofColor(234, 238, 245));      // EAEEF5
    gradient.addColor(ofColor(231, 227, 119));      // E7E377
    gradient.addColor(ofColor(226, 93, 142));       // E25D8E
    
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
void mb_05_19::update(){
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
void mb_05_19::draw(){
    ofNoFill();
    ofSetLineWidth(3);
    ofEnableSmoothing();
    
    float mult = 1;
    
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
//            ofDrawLine(y, x, y+w, x-w);
            ofDrawBox(y, x, w, w, w, w);
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
//            ofDrawLine(y, x, y-w, x+w);
            ofDrawBox(y, x, w, w, w, w);
        }
    }
}

//--------------------------------------------------------------
void mb_05_19::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_05_19::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_05_19::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_05_19::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_19::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_19::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_19::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_05_19::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_05_19::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_05_19::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_05_19::dragEvent(ofDragInfo dragInfo){

}
