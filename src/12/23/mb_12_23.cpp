#include "mb_12_23.h"

//--------------------------------------------------------------
void mb_12_23::setup(){
    // Window
    ofSetWindowShape(900, 900);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(1700);

    // Gradient
    
    gradient.addColor(ofColor(223, 48, 36));    // DF3024
    gradient.addColor(ofColor(117, 250, 101));   // 75FA51
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
 
    // Seed
    ofSetFrameRate(30);
    ofSetWindowTitle("openframeworks");
     
    ofBackground(0);
     
    ofEnableDepthTest();
    ofSetLineWidth(3);
}

//--------------------------------------------------------------
void mb_12_23::update(){
    
}

//--------------------------------------------------------------
void mb_12_23::draw(){
    cam.begin();
    
    int width = 450;
    int height = 450;
    int len = 15;
    for (int z = 0; z <= 1000; z += 10) {
 
        ofPushMatrix();
        ofTranslate(0, 0, z);
        ofRotate(ofMap(cos(z + ofGetFrameNum() * 0.001), 0, 1, -180, 180));
 
        ofFill();
        if (z%3 == 0) { ofSetColor(ofColor(223, 58, 36)); }
        else { ofSetColor(ofColor(117, 210, 81)); }

        ofBeginShape();
        
        float mult = (0.5 * ofMap(sin(z + ofGetFrameNum() * 0.001), 0, 1, 0, 1));
        
        ofVertex(glm::vec2(width * mult, height * mult));
        ofVertex(glm::vec2(width/2 * mult, height*2.5 * mult));
        ofVertex(glm::vec2((3 * width / 2) * -mult, height*2.5 * mult));
        ofVertex(glm::vec2(width * mult, height * mult));
 
//        ofNextContour(true);
//
//        ofVertex(glm::vec2(width * mult, height * mult));
//        ofVertex(glm::vec2(width/2 * mult, height*3 * mult));
//        ofVertex(glm::vec2((3 * width / 2) * mult, height*3 * mult));
//        ofVertex(glm::vec2(width * mult, height * mult));

        ofEndShape(true);
 
        ofNoFill();
        ofSetColor(255);
 
        ofBeginShape();
 
        ofVertex(glm::vec2(width * mult, height * mult));
        ofVertex(glm::vec2(width/2 * mult, height*2.5 * mult));
        ofVertex(glm::vec2((3 * width / 2) * -mult, height*2.5 * mult));
        ofVertex(glm::vec2(width * mult, height * mult));

//        ofNextContour(true);
//
//        ofVertex(glm::vec2(width * mult, height * mult));
//        ofVertex(glm::vec2(width/2 * mult, height*3 * mult));
//        ofVertex(glm::vec2((3 * width / 2) * mult, height*3 * mult));
//        ofVertex(glm::vec2(width * mult, height * mult));
 
        ofEndShape(true);
 
        ofPopMatrix();
    }
 
    cam.end();
    
}

//--------------------------------------------------------------
void mb_12_23::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_12_23::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_12_23::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_12_23::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_23::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_23::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_23::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_12_23::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_12_23::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_12_23::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_12_23::dragEvent(ofDragInfo dragInfo){

}
