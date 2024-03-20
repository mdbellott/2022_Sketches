#include "mb_03_05.h"

//--------------------------------------------------------------
void mb_03_05::setup(){
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
                    rad.push_back(100 + (i*mult));
                    up.push_back(true);
                }
                else {
                    rad.push_back(100 - (i*mult));
                    up.push_back(false);
                }
            } else {
                if(j%2 == 0) {
                    rad.push_back(100 + (j*mult));
                    up.push_back(false);
                }
                else {
                    rad.push_back(100 - (j*mult));
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
void mb_03_05::setupGradient(){
    gradient.addColor(ofColor(255, 255, 167));      // FFFFA7
    gradient.addColor(ofColor(228, 134, 127));      // E4867F
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(220, 157, 93)); // DC9D5D
}

//--------------------------------------------------------------
void mb_03_05::update(){
    float dr = 0.5;
    float min = -120;
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
void mb_03_05::draw(){
    
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
            ofDrawBox(x, y, 0, rad, rad, rad);
//            ofDrawCone(x, y + rad, 0, rad/2, rad);
//            ofDrawTriangle(x, y-rad, x+rad/2, y-(rad*2), x-rad/2, y-(rad*2));
//            ofDrawPlane(x-rad, y, rad/2, rad/2);
//            ofDrawCylinder(x, y, 0, rad/2, rad);
            
            
        }
    }
    ofRotateDeg(rads[0][0], 1.0, 1.0, 1.0);
}

//--------------------------------------------------------------
void mb_03_05::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_03_05::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_03_05::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_03_05::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_05::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_05::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_05::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_03_05::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_03_05::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_03_05::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_03_05::dragEvent(ofDragInfo dragInfo){

}
