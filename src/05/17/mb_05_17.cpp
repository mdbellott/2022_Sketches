#include "mb_05_17.h"

//--------------------------------------------------------------
void mb_05_17::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    gradient.addColor(ofColor(81, 144, 198));       // 5190C6
    gradient.addColor(ofColor(74, 127, 73));        // 4A7F49
    gradient.addColor(ofColor(252, 240, 95));       // FCF05F
    
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
    n = 20;
    
    up = true;
}

//--------------------------------------------------------------
void mb_05_17::update(){
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
void mb_05_17::draw(){
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
            ofDrawCircle(y, x, w);
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
            ofDrawCircle(y, x, w);
        }
    }
}

//--------------------------------------------------------------
void mb_05_17::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_05_17::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_05_17::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_05_17::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_17::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_17::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_17::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_05_17::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_05_17::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_05_17::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_05_17::dragEvent(ofDragInfo dragInfo){

}
