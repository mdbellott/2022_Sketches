#include "mb_03_03.h"

//--------------------------------------------------------------
void mb_03_03::setup(){
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
            rad.push_back(100 - (i*mult) - (j*mult));
            if (i%2 == 0) { up.push_back(true); }
            else { up.push_back(false); }
        }
        rads.push_back(rad);
        ups.push_back(up);
    }
    n -= 1;

    setupGradient();
}

//--------------------------------------------------------------
void mb_03_03::setupGradient(){
    gradient.addColor(ofColor(221, 208, 190));      // DDD0BE
    gradient.addColor(ofColor(124, 103, 80));      // 7C6750
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(113, 112, 76)); // 71704C
}

//--------------------------------------------------------------
void mb_03_03::update(){
    float dr = 0.75;
    float min = -100;
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
void mb_03_03::draw(){
    
    for (int i=0; i<n; i++) {
        float x = xs[i];
        for (int j=0; j<n; j++) {
            float y = ys[j];
            float rad = rads[i][j];
            float pct = rad/100;
            if (pct >= 1.0) { pct = 0.99; }
            if (pct <= -1.0) { pct = -0.99; }
//            ofNoFill();
            ofEnableSmoothing();
            ofSetColor(gradient.getColorAtPercent(pct));
//            ofDrawBox(x, y + rad, 0, rad, rad, rad);
//            ofDrawCone(x, y + rad, 0, rad/2, rad);
//            ofDrawTriangle(x, y-rad, x+rad/2, y-(rad*2), x-rad/2, y-(rad*2));
//            ofDrawPlane(x-rad, y, rad/2, rad/2);
            ofDrawCylinder(x, y, 0, rad/2, rad);
            
            
        }
    }
    ofRotateDeg(rads[0][0], 1.0, 1.0, 1.0);
}

//--------------------------------------------------------------
void mb_03_03::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_03_03::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_03_03::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_03_03::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_03::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_03::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_03::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_03_03::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_03_03::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_03_03::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_03_03::dragEvent(ofDragInfo dragInfo){

}
