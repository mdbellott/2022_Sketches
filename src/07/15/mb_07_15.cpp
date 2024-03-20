#include "mb_07_15.h"

//--------------------------------------------------------------
void mb_07_15::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(500);
    
    // Gradient
    gradient.addColor(ofColor(220, 133, 103));                      // DC8567
    gradient.addColor(ofColor(104, 198, 208));                      // 68C6D0
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableSmoothing();
    ofSetLineWidth(10);
    
    // Mesh
    mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_07_15::update(){
    ofSeedRandom(27);
}

//--------------------------------------------------------------
void mb_07_15::draw(){
    cam.begin();
    mesh.clear();
    
    auto noise = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
    
    float colors = 10.0;
    float damp = 0.005;
    int angle = 50;
    int min = -400;
    int max = 450;
    
    
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
            ofRotateYDeg(angleY*2);
            ofRotateZDeg(angleZ*0.5);

            if (i%2 == 0) {
                auto size = ofMap(ofNoise(i + j + ofGetFrameNum() * damp), 0, 1, min, max);
                ofDrawSphere(size);
            } else {
                auto size = ofMap(ofNoise(i + j + (ofGetFrameNum() + 30) * damp), 0, 1, max, min);
                ofDrawSphere(size);
            }

            ofPopMatrix();
        }
    }
    
    mesh.drawWireframe();
    cam.end();
}

//--------------------------------------------------------------
void mb_07_15::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_07_15::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_07_15::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_07_15::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_15::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_15::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_15::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_07_15::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_07_15::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_07_15::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_07_15::dragEvent(ofDragInfo dragInfo){

}
