#include "mb_10_19.h"

//--------------------------------------------------------------
void mb_10_19::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(30);
    cam.disableMouseInput();
    cam.setDistance(150);

    
    // Gradient
    gradient.addColor(ofColor(199, 76, 37));            // C74C25
    gradient.addColor(ofColor(232, 191, 65));           // E8BF41
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
     
    int radius = 25;
    for (float deg = 0; deg < 360; deg += 3) {
        auto location = glm::vec2(radius * sin(deg * DEG_TO_RAD), radius * cos(deg * DEG_TO_RAD));
        auto location2 = glm::vec2(radius * tan(deg * DEG_TO_RAD), -radius * tan(deg * DEG_TO_RAD));
        locations.push_back(location);
        locations.push_back(location2);
    }
}

//--------------------------------------------------------------
void mb_10_19::update(){
    list.clear();
     
    int limit = 100;
    for (int i = 0; i < this->locations.size(); i++) {
        vector<glm::vec2> log;
        log.push_back(glm::vec2(locations[i]));
        list.push_back(log);
    }
 
    int step = 1;
    for (int i = 0; i < this->list.size(); i++) {
        int k = 0;
        while (true) {
            auto deg = ofMap(ofNoise(glm::vec3(list[i].back() * 0.005, ofGetFrameNum() * 0.0006 + k * 0.0005)), 0, 1, -360, 360);
            auto next = list[i].back() + glm::vec2(step * sin(deg * DEG_TO_RAD), step * cos(deg * DEG_TO_RAD));
 
            if (next.x < -limit || next.x > limit || next.y < -limit || next.y > limit) { break; }
            else { list[i].push_back(next); }
 
            k++;
        }
    }
}

//--------------------------------------------------------------
void mb_10_19::draw(){
    cam.begin();
    
    ofSetLineWidth(1);
    for (int i = 0; i < list.size(); i++) {
        if (list[i].size() > 1) {
            for (int k = 0; k < this->list[i].size(); k++) {
                float pct = ofMap(k, 0, this->list[i].size(), 0, 255);
                ofNoFill();
                ofSetColor(gradient.getColorAtPercent(pct));
                ofDrawCircle(this->list[i][k], 1);
            }
        }
    }

    cam.end();
}

//--------------------------------------------------------------
void mb_10_19::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_10_19::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_10_19::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_10_19::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_19::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_19::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_19::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_10_19::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_10_19::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_10_19::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_10_19::dragEvent(ofDragInfo dragInfo){

}
