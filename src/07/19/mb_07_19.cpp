#include "mb_07_19.h"

//--------------------------------------------------------------
void mb_07_19::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(500);
    
    // Gradient
    gradient.addColor(ofColor(216, 49, 72));            // D83148
    gradient.addColor(ofColor(170, 222, 235));          // AADEEB
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
//    ofNoFill();
    ofEnableSmoothing();
    ofSetLineWidth(10);
    
    // Mesh
    mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_07_19::update(){
    ofSeedRandom(27);
}

//--------------------------------------------------------------
void mb_07_19::draw(){
    cam.begin();
    mesh.clear();
    
    auto noise = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
    
    float colors = 10.0;
    float damp = 0.005;
    int angle = 50;
    int min = -200;
    int max = 700;
    
    
    for (int i = 0; i < 5; i++) {
        for (float j = 0; j<=colors; j++) {
            
            auto noiseX = ofNoise(noise.x, ofGetFrameNum() * damp);
            auto noiseY = ofNoise(noise.y, ofGetFrameNum() * damp);
            auto noiseZ = ofNoise(noise.z, ofGetFrameNum() * damp);
            
            auto angleX = ofMap(noiseX, 0, 1, -angle, angle);
            auto angleY = ofMap(noiseY, 0, 1, -angle, angle);
            auto angleZ = ofMap(noiseZ, 0, 1, -angle, angle);
            
            ofSetColor(gradient.getColorAtPercent(j/(colors-1)));
            
            ofPushMatrix();
            
            ofRotateXDeg(angleX);

            if (i%2 == 0) {
                auto size = ofMap(ofNoise(i + j + ofGetFrameNum() * damp), 0, 1, min, max);
                ofDrawPlane(size, size);
            } else {
                auto size = ofMap(ofNoise(i + j + (ofGetFrameNum() + 30) * damp), 0, 1, max, min);
                ofDrawPlane(size, size);
            }

            ofPopMatrix();
        }
    }
    
    mesh.drawWireframe();
    cam.end();
}

//--------------------------------------------------------------
void mb_07_19::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_07_19::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_07_19::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_07_19::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_19::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_19::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_19::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_07_19::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_07_19::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_07_19::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_07_19::dragEvent(ofDragInfo dragInfo){

}
