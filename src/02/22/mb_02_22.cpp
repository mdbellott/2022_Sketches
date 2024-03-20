#include "mb_02_22.h"

//--------------------------------------------------------------
void mb_02_22::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    ofSetFrameRate(60);
    
    n = 4;
    
    for (int i=0; i<n; i++) {
        dts.push_back(i*100);
        incs.push_back(true);
    }
    
    setupGradients();
}

//--------------------------------------------------------------
void mb_02_22::setupGradients(){
    ofColor colorTwo(116, 179, 184); // 74B3B8
    ofColor colorOne(172, 222, 232); // ACDEE8
    ofColor colorThree(35, 37, 34); // 232522
    
    for (int i=0; i<n; i++) {
        ofxColorGradient<ofColor> gradient;
        
        if (i == 0 || i == 3) {
            gradient.addColor(colorThree);
            gradient.addColor(colorTwo);
            gradient.addColor(colorOne);
        } else {
            gradient.addColor(colorOne);
            gradient.addColor(colorTwo);
            gradient.addColor(colorThree);
        }
        
        gradients.push_back(gradient);
    }
}

//--------------------------------------------------------------
void mb_02_22::update(){
    for (int i=0; i<n; i++) {
        if (incs[i]) { dts[i] += 5; }
        else { dts[i] -= 5; }

        if (dts[i] > 1000) { incs[i] = false; }
        else if (dts[i] < 10) { incs[i] = true; }
    }
}

//--------------------------------------------------------------
void mb_02_22::draw(){
    for (int i=0; i<gradients.size(); i++) {
        if (i%4 == 0) {
            gradients[i].drawDebug(0,
                                   0,
                                   ofGetWidth()/2,
                                   ofGetHeight()/2 + dts[i],
                                   100,
                                   false,
                                   true);
        } else if (i%4 == 1) {
            gradients[i].drawDebug(0 - dts[i],
                                   ofGetHeight()/2,
                                   ofGetWidth()/2 + dts[i],
                                   ofGetHeight(),
                                   100,
                                   false,
                                   false);
        } else if (i%4 == 2) {
            gradients[i].drawDebug(ofGetWidth()/2,
                                   ofGetHeight()/2 - dts[i],
                                   ofGetWidth()/2,
                                   ofGetHeight()/2 + dts[i] + 5,
                                   100,
                                   false,
                                   true);
        } else {
            gradients[i].drawDebug(ofGetWidth()/2,
                                   0,
                                   ofGetWidth()/2 + dts[i],
                                   ofGetHeight()/2,
                                   100,
                                   false,
                                   false);
        }
    }
}

//--------------------------------------------------------------
void mb_02_22::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_22::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_22::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_22::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_22::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_22::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_22::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_22::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_22::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_22::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_22::dragEvent(ofDragInfo dragInfo){

}
