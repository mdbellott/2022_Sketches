#include "mb_07_11.h"

//--------------------------------------------------------------
void mb_07_11::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    cam.disableMouseInput();
    cam.setDistance(200);
    
    gradient.addColor(ofColor(132, 201, 149));      // 84C995
    gradient.addColor(ofColor(239, 159, 57));      // EF9F39
    
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
}

//--------------------------------------------------------------
void mb_07_11::update(){
    ofSeedRandom(27);
}

//--------------------------------------------------------------
void mb_07_11::draw(){
    cam.begin();
     
    for (int i = 0; i < 10; i++) {
        auto rotation = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
        for (float z = 0; z < 100; z += 1) {
            ofPushMatrix();
            ofTranslate(0, 0);
            
            int size = 50;
            int mapMin = -500;
            int mapMax = 500;
            float zVal = (z + ofGetFrameNum()) * 0.0001;
            
            ofRotateXDeg(ofMap(ofNoise(rotation.x, zVal), 0, 1, mapMin, mapMax));
            ofRotateYDeg(ofMap(ofNoise(rotation.y, zVal), 0, 1, mapMin, mapMax));
            ofRotateZDeg(ofMap(ofNoise(rotation.z, zVal), 0, 1, mapMin, mapMax));
            
            float prct = (i % 2 == 1) ? (z/100) : ((100-z)/100);
            ofSetColor(gradient.getColorAtPercent(prct));
            ofDrawBox(0, 0, z, size, size, size);
            ofPopMatrix();
        }
    }
 
    cam.end();
}

//--------------------------------------------------------------
void mb_07_11::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_07_11::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_07_11::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_07_11::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_11::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_11::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_11::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_07_11::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_07_11::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_07_11::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_07_11::dragEvent(ofDragInfo dragInfo){

}
