#include "mb_12_21.h"

//--------------------------------------------------------------
void mb_12_21::setup(){
    // Window
    ofSetWindowShape(900, 900);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(1500);

    // Gradient
    
    gradient.addColor(ofColor(246, 229, 132));
    gradient.addColor(ofColor(245, 245, 245));
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
 
    // Seed
    ofSetFrameRate(30);
    ofSetWindowTitle("openframeworks");
     
    ofBackground(0);
     
    ofEnableDepthTest();
    ofSetLineWidth(3);
}

//--------------------------------------------------------------
void mb_12_21::update(){
    
}

//--------------------------------------------------------------
void mb_12_21::draw(){
    cam.begin();
    
    int width = 500;
    int height = 500;
    int len = 15;
    for (int z = 0; z <= 1000; z += 10) {
 
        ofPushMatrix();
        ofTranslate(0, 0, z);
        ofRotate(ofMap(sin(z + ofGetFrameNum() * 0.001), 0, 1, -180, 180));
 
        ofFill();
        if (z%2 == 0) { ofSetColor(gradient.getColorAtPercent(abs(float(z) / -500))); }
        else { ofSetColor(gradient.getColorAtPercent(abs(float(z) / 500))); }

        ofBeginShape();
        
        float mult = (0.5 * ofMap(sin(z + ofGetFrameNum() * 0.001), 0, 1, 0, 1));
        
        ofVertex(glm::vec2(width * -mult, height * -mult));
        ofVertex(glm::vec2(width/2 * mult, height * -mult));
        ofVertex(glm::vec2(width * mult, height * mult));
        ofVertex(glm::vec2(width * -mult, height * mult));
 
        ofNextContour(true);
 
        ofVertex(glm::vec2(width * -mult + len, height * -mult + len));
        ofVertex(glm::vec2(width * mult - len, height * -mult + len));
        ofVertex(glm::vec2(width * mult - len, height * mult - len));
        ofVertex(glm::vec2(width * -mult + len, height * mult - len));
 
        ofEndShape(true);
 
        ofNoFill();
        ofSetColor(150);
 
        ofBeginShape();
 
        ofVertex(glm::vec2(width * -mult, height * -mult));
        ofVertex(glm::vec2(width * mult, height * -mult));
        ofVertex(glm::vec2(width * mult, height * mult));
        ofVertex(glm::vec2(width * -mult, height * mult));
 
        ofNextContour(true);
 
        ofVertex(glm::vec2(width * -mult + len, height * -mult + len));
        ofVertex(glm::vec2(width * mult - len, height * -mult + len));
        ofVertex(glm::vec2(width * mult - len, height * mult - len));
        ofVertex(glm::vec2(width * -mult + len, height * mult - len));
 
        ofEndShape(true);
 
        ofPopMatrix();
    }
 
    cam.end();
    
}

//--------------------------------------------------------------
void mb_12_21::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_12_21::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_12_21::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_12_21::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_21::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_21::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_21::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_12_21::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_12_21::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_12_21::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_12_21::dragEvent(ofDragInfo dragInfo){

}
