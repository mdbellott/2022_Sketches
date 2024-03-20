// Inspiration: "Division Circle" by jyoshi
// https://github.com/junkiyoshi/Insta20220608

#include "mb_08_08.h"

//--------------------------------------------------------------
void mb_08_08::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(200);

    
    // Gradient
    gradient.addColor(ofColor(81, 162, 241));          // 51A2F1
    gradient.addColor(ofColor(228, 129, 110));          // E4816E
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(2);
}

//--------------------------------------------------------------
void mb_08_08::update(){
}

//--------------------------------------------------------------
void mb_08_08::draw(){
    float x = ofGetWidth()/2;
    float y = ofGetHeight()/2;
    
    
    
    float z = -1000;
    ofSetColor(gradient.getColorAtPercent(0.5));
    ofDrawLine(x, -ofGetHeight(), z, x, ofGetHeight()*2, z);
    
    cam.begin();
    
    ofPushMatrix();
    
    ofRotateZDeg(90);

    auto radius = 99;
    auto start = 0;
    auto end = start + 180;
    auto span = 22;
    
    for (int deg = start; deg < end; deg += span) {

        auto center = glm::vec2(radius * cos((deg + span / 2) * DEG_TO_RAD), 0);
        auto noise = ofNoise((center.x), y, ofGetFrameNum()* 0.005) * 0.2;
        auto rotate = ofMap(noise, 0, 1, -360, 360);

        ofPushMatrix();
        ofTranslate(center);
        ofRotateXDeg(rotate);

        vector<glm::vec2> v1, v2;
        for (int tmp = deg + 1; tmp < deg + span; tmp++) {
            auto point = glm::vec2(radius * cos(tmp * DEG_TO_RAD), radius * sin(tmp * DEG_TO_RAD));
            v1.push_back(point - center);
            v1.push_back(glm::vec2(point.x, -point.y) - center);
        }

        reverse(v2.begin(), v2.end());

        ofFill();
        ofSetColor(gradient.getColorAtPercent(0.75));
        ofBeginShape();
        ofVertices(v1);
        ofVertices(v2);
        ofEndShape(true);

        ofNoFill();
        ofSetColor(gradient.getColorAtPercent(0.25));
        ofBeginShape();
        ofVertices(v1);
        ofVertices(v2);
        ofEndShape(true);

        ofPopMatrix();
    }

    ofPopMatrix();
    
    cam.end();
}

//--------------------------------------------------------------
void mb_08_08::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_08_08::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_08_08::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_08_08::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_08::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_08::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_08::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_08_08::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_08_08::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_08_08::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_08_08::dragEvent(ofDragInfo dragInfo){

}
