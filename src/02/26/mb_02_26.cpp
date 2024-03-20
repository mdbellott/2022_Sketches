#include "mb_02_26.h"

//--------------------------------------------------------------
void mb_02_26::setup(){
    ofSetWindowShape(1000, 1000);
    ofSetFrameRate(60);
    
    n = 20;
    offset = 10;
    
    for (int i=0; i<n; i++) {
        xs.push_back((ofGetWidth()*1.5/n) * (i + 1));
        ys.push_back((ofGetHeight()*1.5/n) * (i + 1));
        

        vector<float> rad;
        vector<bool> up;
        for (int j=0; j<n; j++) {
            int mult = 4;
            rad.push_back(100 - (i*mult) - (j*mult));
            up.push_back(true);
        }
        rads.push_back(rad);
        ups.push_back(up);
    }
    n -= 1;

    setupGradient();
}

//--------------------------------------------------------------
void mb_02_26::setupGradient(){
    gradient.addColor(ofColor(23, 184, 149));   // 17B895
    gradient.addColor(ofColor(232, 71, 106));   // E8476A
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(gradient.getColorAtPercent(0.7));
}

//--------------------------------------------------------------
void mb_02_26::update(){
    float dr = 0.75;
    float min = 30;
    float max = 120;
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
void mb_02_26::draw(){
    
    for (int i=0; i<n; i++) {
        float x = xs[i];
        for (int j=0; j<n; j++) {
            float y = ys[j];
            float rad = rads[i][j];
            ofSetColor(gradient.getColorAtPercent(y/ofGetHeight()*2));
            ofDrawBox(x, y, 0, rad, rad, rad);
        }
    }
}

//--------------------------------------------------------------
void mb_02_26::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_26::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_26::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_26::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_26::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_26::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_26::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_26::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_26::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_26::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_26::dragEvent(ofDragInfo dragInfo){

}
