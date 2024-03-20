#include "mb_07_07.h"

//--------------------------------------------------------------
void mb_07_07::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    cam.disableMouseInput();
    cam.setDistance(200);
    
    gradient.addColor(ofColor(230, 54, 132));       // E63684
    gradient.addColor(ofColor(110, 235, 250));      // 6EEBFA
    
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
}

//--------------------------------------------------------------
void mb_07_07::update(){
    ofSeedRandom(27);
}

//--------------------------------------------------------------
void mb_07_07::draw(){
    
    cam.begin();
     
    for (int i = 0; i < 20; i++) {
        auto rotation = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
        for (float z = 0; z < 100; z += 1) {
            ofPushMatrix();
            ofTranslate(0, 0);
            
            int size = 20;
            int mapMin = -500;
            int mapMax = 500;
            float zVal = (z + ofGetFrameNum()) * 0.0005;
            
            ofRotateXDeg(ofMap(ofNoise(rotation.x, zVal), 0, 1, mapMin, mapMax));
            ofRotateYDeg(ofMap(ofNoise(rotation.y, zVal), 0, 1, mapMin, mapMax));
            ofRotateZDeg(ofMap(ofNoise(rotation.z, zVal), 0, 1, mapMin, mapMax));
            
            float prct = (i % 2 == 1) ? (z/100) : ((100-z)/100);
            ofSetColor(gradient.getColorAtPercent(prct));
            ofDrawSphere(0, 0, z, size);
            ofPopMatrix();
        }
    }
 
    cam.end();
}

//--------------------------------------------------------------
void mb_07_07::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_07_07::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_07_07::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_07_07::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_07::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_07::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_07::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_07_07::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_07_07::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_07_07::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_07_07::dragEvent(ofDragInfo dragInfo){

}
