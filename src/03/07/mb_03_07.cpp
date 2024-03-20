#include "mb_03_07.h"

//--------------------------------------------------------------
void mb_03_07::setup(){
    ofSetWindowShape(1000, 1000);
    ofSetFrameRate(60);
    
    n = 35;
    offset = 10;
    
    for (int i=0; i<n; i++) {
        xs.push_back((ofGetWidth()*1.5/n) * (i + 1));
        ys.push_back((ofGetHeight()*1.5/n) * (i + 1));
        

        vector<float> rad;
        vector<bool> up;
        for (int j=0; j<n; j++) {
            int mult = 4;
            if (i%2 == 0) {
                if(j%2 == 0) {
                    rad.push_back(50 + (i*mult));
                    up.push_back(true);
                }
                else {
                    rad.push_back(50 - (j*mult));
                    up.push_back(false);
                }
            } else {
                if(j%2 == 0) {
                    rad.push_back(50 + (i*mult));
                    up.push_back(false);
                }
                else {
                    rad.push_back(50 - (j*mult));
                    up.push_back(true);
                }
            }
        }
        rads.push_back(rad);
        ups.push_back(up);
    }
    n -= 1;

    setupGradient();
}

//--------------------------------------------------------------
void mb_03_07::setupGradient(){
    gradient.addColor(ofColor(100, 102, 56));       // 646638
    gradient.addColor(ofColor(109, 114, 60));       // 6D723C
    gradient.addColor(ofColor(245, 224, 163));      // F5E0A3
    gradient.addColor(ofColor(73, 105, 109));       // 4A696D
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(88, 119, 119));           // 587777
}

//--------------------------------------------------------------
void mb_03_07::update(){
    float dr = 0.5;
    float min = -50;
    float max = 50;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (rads[i][j] > max) {
                ups[i][j] = false;
            } else if (rads[i][j] < min) {
                ups[i][j] = true;
            }
            int div = 10;
            if (ups[i][j]) { rads[i][j] += dr; }
            else { rads[i][j] -= dr; }
        }
    }
}

//--------------------------------------------------------------
void mb_03_07::draw(){
    
    for (int i=0; i<n; i++) {
        float x = xs[i];
        for (int j=0; j<n; j++) {
            float y = ys[j];
            float rad = rads[i][j];
            float pct = rad/100;
            if (pct >= 1.0) { pct = 0.99; }
            if (pct <= -1.0) { pct = -0.99; }
            ofEnableSmoothing();
            ofSetColor(gradient.getColorAtPercent(pct));
            ofDrawCylinder(x, y, 0, rad/2, rad);
            
            
        }
    }
    ofRotateDeg(rads[0][0], 1.0, 1.0, 1.0);
}

//--------------------------------------------------------------
void mb_03_07::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_03_07::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_03_07::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_03_07::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_07::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_07::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_07::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_03_07::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_03_07::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_03_07::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_03_07::dragEvent(ofDragInfo dragInfo){

}
