#include "mb_01_30.h"

//--------------------------------------------------------------
void mb_01_30::setup(){
    ofBackground(0);
    ofSetWindowShape(1000, 1000);
}

//--------------------------------------------------------------
void mb_01_30::update(){
    dt += 0.025;
}

//--------------------------------------------------------------
void mb_01_30::draw(){
    ofNoFill();
    ofEnableSmoothing();
    
    int count = 7;
    int size = ofGetWidth()/count;
    int buf = 0;

    for (int i = 1; i < count; i++) {
        for(int j = 1; j <count; j++) {
            float xPos = ofMap(sin(dt + i), -1, 1, -20, 20);
            float yPos = ofMap(cos(dt + j), -1, 1, -20, 20);
            float w = ofMap(sin(dt - i - j), -1, 1, 100, 150);
            float h = ofMap(cos(dt - i - j), -1, 1, 100, 150);
            ofDrawPlane((i*size) + (i*buf) + xPos, (j*size) + (j*buf) + yPos, w, h);
        }
    }
}

//--------------------------------------------------------------
void mb_01_30::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_01_30::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_01_30::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_01_30::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_30::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_30::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_01_30::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_01_30::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_01_30::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_01_30::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_01_30::dragEvent(ofDragInfo dragInfo){

}
