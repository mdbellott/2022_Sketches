#include "mb_02_20.h"

//--------------------------------------------------------------
void mb_02_20::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    ofSetFrameRate(60);
    
    for (int i=0; i<5; i++) {
        dts.push_back(400 - i*100);
        incs.push_back(true);
    }
    
    ofColor colorOne(75, 192, 176); // 4bc0b0
    ofColor colorTwo(199, 198, 204); // c7c6cc
    ofColor colorThree(138, 82, 22); // 8a5216
    
    gradient1.addColor(colorOne);
    gradient1.addColor(colorTwo);
    gradient1.addColor(colorThree);
    
    gradient2.addColor(colorThree);
    gradient2.addColor(colorTwo);
    gradient2.addColor(colorOne);
    
    gradient3.addColor(colorOne);
    gradient3.addColor(colorTwo);
    gradient3.addColor(colorThree);
    
    gradient4.addColor(colorThree);
    gradient4.addColor(colorTwo);
    gradient4.addColor(colorOne);
    
    gradient5.addColor(colorOne);
    gradient5.addColor(colorTwo);
    gradient5.addColor(colorThree);
}

//--------------------------------------------------------------
void mb_02_20::update(){
    for (int i=0; i<5; i++) {
        if (incs[i]) { dts[i] += 2.5; }
        else { dts[i] -= 2.5; }

        if (dts[i] > 1000) { incs[i] = false; }
        else if (dts[i] < 0) { incs[i] = true; }
    }
}

//--------------------------------------------------------------
void mb_02_20::draw(){
    gradient1.drawDebug(0, 0, ofGetWidth()/5, ofGetHeight() + dts[0], 100, false, true);
    
    gradient2.drawDebug(ofGetWidth()/5, 0 - dts[1], 2*ofGetWidth()/5, ofGetHeight() + dts[1], 100, false, true);
    
    gradient3.drawDebug(2*ofGetWidth()/5, 0, 3*ofGetWidth()/5, ofGetHeight() + dts[2], 100, false, true);
    
    gradient4.drawDebug(3*ofGetWidth()/5, 0 - dts[3], 4*ofGetWidth()/5, ofGetHeight() + dts[3], 100, false, true);
    
    gradient5.drawDebug(4*ofGetWidth()/5, 0, ofGetWidth(), ofGetHeight() + dts[4], 100, false, true);
}

//--------------------------------------------------------------
void mb_02_20::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_20::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_20::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_20::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_20::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_20::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_20::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_20::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_20::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_20::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_20::dragEvent(ofDragInfo dragInfo){

}
