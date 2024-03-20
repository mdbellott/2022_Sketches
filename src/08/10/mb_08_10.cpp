// Inspiration: "Division Circle" by jyoshi
// https://github.com/junkiyoshi/Insta20220608

#include "mb_08_10.h"

//--------------------------------------------------------------
void mb_08_10::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(200);

    
    // Gradient
    gradient.addColor(ofColor(220, 133, 103));                      // DC8567
    gradient.addColor(ofColor(104, 198, 208));                      // 68C6D0
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(2);
}

//--------------------------------------------------------------
void mb_08_10::update(){
}

//--------------------------------------------------------------
void mb_08_10::draw(){
    float x = ofGetWidth()/2;
    float y = ofGetHeight()/2;
    
    cam.begin();
    
    ofPushMatrix();
    
    auto radius = 150;
    auto start = 0;
    auto end = start + 180;
    auto span = 20;

    auto damp = 0.005;
    
    for (int deg = start; deg < end; deg += span) {

        auto center = glm::vec2(radius * sin((deg + span) * DEG_TO_RAD), 0);
        auto noise = ofNoise((center.x), y, ofGetFrameNum() * damp);

        ofPushMatrix();
        ofTranslate(center);

        vector<glm::vec2> v1, v2;
        for (int tmp = deg + 1; tmp < deg + span; tmp++) {
            auto point = glm::vec2(radius * cos(tmp * DEG_TO_RAD), radius * cos(tmp * DEG_TO_RAD)) * (noise);
            v1.push_back(point - center);
            v1.push_back(glm::vec2(point.x, -point.y) - center);
        }

        reverse(v2.begin(), v2.end());

        ofFill();
        ofSetColor(gradient.getColorAtPercent(0.25));
        ofBeginShape();
        ofVertices(v1);
        ofVertices(v2);
        ofEndShape(true);

        ofNoFill();
        ofSetColor(gradient.getColorAtPercent(0.75));
        ofBeginShape();
        ofVertices(v1);
        ofVertices(v2);
        ofEndShape(true);

        ofPopMatrix();
    }
    
    ofRotateZDeg(90);
    
    for (int deg = start; deg < end; deg += span) {

        auto center = glm::vec2(radius * sin((deg + span) * DEG_TO_RAD), 0);
        auto noise = ofNoise((center.x), y, ofGetFrameNum() * damp);

        ofPushMatrix();
        ofTranslate(center);

        vector<glm::vec2> v1, v2;
        for (int tmp = deg + 1; tmp < deg + span; tmp++) {
            auto point = glm::vec2(radius * cos(tmp * DEG_TO_RAD), radius * cos(tmp * DEG_TO_RAD)) * (noise);
            v1.push_back(point - center);
            v1.push_back(glm::vec2(point.x, -point.y) - center);
        }

        reverse(v2.begin(), v2.end());

        ofFill();
        ofSetColor(gradient.getColorAtPercent(0.25));
        ofBeginShape();
        ofVertices(v1);
        ofVertices(v2);
        ofEndShape(true);

        ofNoFill();
        ofSetColor(gradient.getColorAtPercent(0.75));
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
void mb_08_10::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_08_10::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_08_10::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_08_10::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_10::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_10::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_10::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_08_10::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_08_10::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_08_10::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_08_10::dragEvent(ofDragInfo dragInfo){

}
