#include "mb_02_27.h"

//--------------------------------------------------------------
void mb_02_27::setup(){
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
void mb_02_27::setupGradient(){
    gradient.addColor(ofColor(252, 206, 165));      // FCCEA5
    gradient.addColor(ofColor(228, 179, 196));      // E4B3C4
    gradient.addColor(ofColor(148, 169, 190));      // 94A9BE
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(185, 205, 218));           // B9CDDA
}

//--------------------------------------------------------------
void mb_02_27::update(){
    float dr = 0.75;
    float min = 50;
    float max = 100;
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
void mb_02_27::draw(){
    
    for (int i=0; i<n; i++) {
        float x = xs[i];
        for (int j=0; j<n; j++) {
            float y = ys[j];
            float rad = rads[i][j];
            ofSetColor(gradient.getColorAtPercent(y/ofGetHeight()*2));
            ofDrawSphere(x, y, rad/2);
        }
    }
}

//--------------------------------------------------------------
void mb_02_27::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_27::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_27::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_27::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_27::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_27::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_27::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_27::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_27::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_27::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_27::dragEvent(ofDragInfo dragInfo){

}
