#include "mb_12_15.h"

//--------------------------------------------------------------
void mb_12_15::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(1500);

    // Gradient
    gradient.addColor(ofColor(185, 128, 193));            // B980C1
    gradient.addColor(ofColor(93, 203, 175));            // 5DCBAF
    gradient.addColor(ofColor(70, 127, 181));             // 467FB5
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
 
    // Seed
    ofSetFrameRate(30);
    ofSetWindowTitle("openframeworks");
     
    ofBackground(0);
     
    ofEnableDepthTest();
    ofSetLineWidth(3);
}

//--------------------------------------------------------------
void mb_12_15::update(){
    
}

//--------------------------------------------------------------
void mb_12_15::draw(){
    cam.begin();
    
    int width = 500;
    int height = 500;
    int len = 15;
    for (int z = 0; z <= 1000; z += 10) {
 
        ofPushMatrix();
        ofTranslate(0, 0, z);
        ofRotate(ofMap(sin(z + ofGetFrameNum() * 0.001), 0, 1, -180, 180));
 
        ofFill();
        ofSetColor(gradient.getColorAtPercent(abs(float(z) / 500)));
 
        ofBeginShape();
        
        ofVertex(glm::vec2(width * -0.5, height * -0.5));
        ofVertex(glm::vec2(width * 0.5, height * -0.5));
        ofVertex(glm::vec2(width * 0.5, height * 0.5));
        ofVertex(glm::vec2(width * -0.5, height * 0.5));
 
        ofNextContour(true);
 
        ofVertex(glm::vec2(width * -0.5 + len, height * -0.5 + len));
        ofVertex(glm::vec2(width * 0.5 - len, height * -0.5 + len));
        ofVertex(glm::vec2(width * 0.5 - len, height * 0.5 - len));
        ofVertex(glm::vec2(width * -0.5 + len, height * 0.5 - len));
 
        ofEndShape(true);
 
        ofNoFill();
        ofSetColor(255);
 
        ofBeginShape();
 
        ofVertex(glm::vec2(width * -0.5, height * -0.5));
        ofVertex(glm::vec2(width * 0.5, height * -0.5));
        ofVertex(glm::vec2(width * 0.5, height * 0.5));
        ofVertex(glm::vec2(width * -0.5, height * 0.5));
 
        ofNextContour(true);
 
        ofVertex(glm::vec2(width * -0.5 + len, height * -0.5 + len));
        ofVertex(glm::vec2(width * 0.5 - len, height * -0.5 + len));
        ofVertex(glm::vec2(width * 0.5 - len, height * 0.5 - len));
        ofVertex(glm::vec2(width * -0.5 + len, height * 0.5 - len));
 
        ofEndShape(true);
 
        ofPopMatrix();
    }
 
    cam.end();
    
}

//--------------------------------------------------------------
void mb_12_15::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_12_15::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_12_15::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_12_15::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_15::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_15::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_15::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_12_15::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_12_15::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_12_15::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_12_15::dragEvent(ofDragInfo dragInfo){

}
