#include "mb_07_13.h"

//--------------------------------------------------------------
void mb_07_13::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(500);
    
    // Gradient
    gradient.addColor(ofColor(147, 248, 221));                      // 93F8DD
    gradient.addColor(ofColor(235, 170, 207));                      // EBAACF
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofNoFill();
    ofSetLineWidth(10);
    
    // Mesh
    mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_07_13::update(){
    ofSeedRandom(27);
}

//--------------------------------------------------------------
void mb_07_13::draw(){
    cam.begin();
    mesh.clear();
    
    auto noise = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
    
    float colors = 100.0;
    float damp = 0.005;
    int angle = 50;
    int min = -100;
    int max = 500;
    
    
    for (int i = 0; i < 10; i++) {
        for (float j = 0; j<=colors; j++) {
            
            auto noiseX = ofNoise(noise.x, ofGetFrameNum() * damp);
            auto noiseY = ofNoise(noise.y, ofGetFrameNum() * damp);
            auto noiseZ = ofNoise(noise.z, ofGetFrameNum() * damp);
            
            auto angleX = ofMap(noiseX, 0, 1, -angle, angle);
            auto angleY = ofMap(noiseY, 0, 1, -angle, angle);
            auto angleZ = ofMap(noiseZ, 0, 1, -angle, angle);
            
            ofSetColor(gradient.getColorAtPercent(j/colors));
            
            ofPushMatrix();
            
            ofRotateXDeg(angleX);
            ofRotateYDeg(angleY*2);
            ofRotateZDeg(angleZ*0.5);

            if (i%2 == 0) {
                auto size = ofMap(ofNoise(i + j + ofGetFrameNum() * damp), 0, 1, min, max);
                ofDrawBox(size);
            } else {
                auto size = ofMap(ofNoise(i + j + (ofGetFrameNum() + 30) * damp), 0, 1, max, min);
                ofDrawBox(size);
            }

            ofPopMatrix();
        }
    }
    
    mesh.drawWireframe();
    cam.end();
}

//--------------------------------------------------------------
void mb_07_13::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_07_13::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_07_13::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_07_13::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_13::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_13::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_13::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_07_13::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_07_13::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_07_13::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_07_13::dragEvent(ofDragInfo dragInfo){

}
