#include "mb_02_09.h"

//--------------------------------------------------------------
void mb_02_09::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
}

//--------------------------------------------------------------
void mb_02_09::update(){
    float inc = 0.2;
    if (up) { offset += inc; }
    else { offset -= inc; }
}

//--------------------------------------------------------------
void mb_02_09::draw(){
    float w = ofGetWidth()/n;
    float h = (ofGetHeight()/n)/2;
    
    float pad = 5;
    if (offset >= h*2 + pad) {
        up = false;
    } else if (offset <= 0 - pad) {
        up = true;
    }
    
    for (int i=0-n; i<n*4; i++) {
        for (int j=0-n; j<n*4; j++) {
            float x = (i * w) + w/2;
            float y = (j * h) + h/2;
            
            if (i%2 == 0) {
                ofDrawTriangle(x, y + offset, x + (w/2) + 1, y + h, x - (w/2) - 1, y + h);
            } else {
                ofDrawTriangle(x, y - offset, x + (w/2) + 1, y - h, x - (w/2) - 1, y - h);
            }
        }
    }
}

//--------------------------------------------------------------
void mb_02_09::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_09::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_09::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_09::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_09::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_09::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_09::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_09::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_09::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_09::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_09::dragEvent(ofDragInfo dragInfo){ 

}
