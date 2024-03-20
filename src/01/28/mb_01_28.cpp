#include "mb_01_28.h"

//--------------------------------------------------------------
void mb_01_28::setup(){
    ofBackground(0);
    ofSetWindowShape(1000, 1000);
}

//--------------------------------------------------------------
void mb_01_28::update(){
    dt += 0.025;
}
//--------------------------------------------------------------
void mb_01_28::draw(){
    ofNoFill();
    ofEnableSmoothing();
    
    int count = 7;
    int size = ofGetWidth()/count;
    int buf = 0;

    for (int i = 1; i < count; i++) {
        for(int j = 1; j <count; j++) {
            float xPos = ofMap(sin(dt + i), -1, 1, -20, 20);
            float yPos = ofMap(sin(dt + j), -1, 1, -20, 20);
            float rad = ofMap(sin(dt - i - j), -1, 1, 10, 50);
            ofDrawIcoSphere((i*size) + (i*buf) + xPos, (j*size) + (j*buf) + yPos, rad);
        }
    }
}

//--------------------------------------------------------------
void mb_01_28::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_01_28::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_01_28::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_01_28::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_28::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_28::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_28::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_01_28::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_01_28::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_01_28::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_01_28::dragEvent(ofDragInfo dragInfo){

}
