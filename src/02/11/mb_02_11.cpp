#include "mb_02_11.h"

//--------------------------------------------------------------
void mb_02_11::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    ofEnableSmoothing();
    
    setupShapes();
}

void mb_02_11::setupShapes() {
    n = 10;
    
    float w = ofGetWidth()/n;
    float h = (ofGetHeight()/n)/2;
    
    for (int i=0-n; i<n*4; i++) {
        for (int j=0-n; j<n*4; j++) {
            
            float x = (i * w) + w/2;
            float y = (j * h) + h/2;
        
            float inc = 0.2;

            shapes.push_back(Shape_02_11(glm::vec2(x, y),
                                   w,
                                   inc + (i*0.001) + (j*0.005),
                                   0,
                                   h,
                                   i%2 == 0));
        }
    }
}

//--------------------------------------------------------------
void mb_02_11::update(){
    for(unsigned int i = 0; i < shapes.size(); i++){
        shapes[i].update();
    }
}

//--------------------------------------------------------------
void mb_02_11::draw(){
    for(unsigned int i = 0; i < shapes.size(); i++){
        shapes[i].draw();
    }
}

//--------------------------------------------------------------
void mb_02_11::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_11::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_11::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_11::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_11::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_11::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_11::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_11::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_11::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_11::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_11::dragEvent(ofDragInfo dragInfo){

}
