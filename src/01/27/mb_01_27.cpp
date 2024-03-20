#include "mb_01_27.h"

//--------------------------------------------------------------
void mb_01_27::setup(){
    ofBackground(0);
    ofSetWindowShape(1000, 1000);
}

//--------------------------------------------------------------
void mb_01_27::update(){
    dt += 0.025;
}

//--------------------------------------------------------------
void mb_01_27::draw(){
    ofNoFill();
    
    int count = 7;
    int size = ofGetWidth()/count;
    int buf = 0;

    for (int i = 1; i < count; i++) {
        for(int j = 1; j <count; j++) {
            float xPos = ofMap(sin(dt + i), -1, 1, -20, 20);
            float yPos = ofMap(sin(dt + j), -1, 1, -20, 20);
            ofDrawBox((i*size) + (i*buf) + xPos, (j*size) + (j*buf) + yPos, 0, size);
        }
    }
}

//--------------------------------------------------------------
void mb_01_27::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_01_27::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_01_27::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_01_27::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_27::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_27::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_27::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_01_27::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_01_27::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_01_27::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_01_27::dragEvent(ofDragInfo dragInfo){

}
