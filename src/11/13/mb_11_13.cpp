#include "mb_11_13.h"

//--------------------------------------------------------------
void mb_11_13::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(700);

    // Gradient
    gradient.addColor(ofColor(253, 221, 118));            // FDDD76
    gradient.addColor(ofColor(238, 135, 92));             // EE875C
    gradient.addColor(ofColor(108, 123, 126));            // 6D7B7E
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
 
    // Seed
    ofSetColor(225);
    frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
    bands = 1;
    for (int i = 0; i < bands; i++) {
        seeds.push_back(ofRandom(10));
    }
}

//--------------------------------------------------------------
void mb_11_13::update(){
    ofSeedRandom(5);
     
    face.clear();
    frame.clear();
 
    for (int i = 0; i < bands; i++) {
        float kMax = 100.0;
        auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
        for(int k = 0; k < kMax; k++){
 
            int deg = ofRandom(360);
 
            auto angle_x = ofMap(ofNoise(noise_seed.x, tan(deg * DEG_TO_RAD), seeds[i]), 0, 1, -PI, PI);
            auto angle_y = ofMap(ofNoise(noise_seed.y, tan(deg * DEG_TO_RAD), seeds[i]), 0, 1, -PI, PI);
            auto angle_z = ofMap(ofNoise(noise_seed.z, seeds[i]), 0, 1, -PI, PI);
 
            auto rotation_x = glm::rotate(glm::mat4(), angle_x, glm::vec3(1, 0, 0));
            auto rotation_y = glm::rotate(glm::mat4(), angle_y, glm::vec3(0, 1, 0));
            auto rotation_z = glm::rotate(glm::mat4(), angle_z, glm::vec3(0, 0, 1));
 
            auto location = glm::vec3(300 * cos(deg * DEG_TO_RAD), 300 * sin(deg * DEG_TO_RAD), ofRandom(-100, 100));
            location = glm::vec4(location, 0) * rotation_z * rotation_y * rotation_x;
 
            face.addVertex(location);
            frame.addVertex(location);
 
            face.addColor(gradient.getColorAtPercent(float(k)/kMax));
        }
    }
 
    for (int i = 0; i < face.getNumVertices(); i++) {
 
        vector<int> near_index_list;
        auto location = face.getVertex(i);
        for (int k = 0; k < face.getNumVertices(); k++) {
 
            auto other = face.getVertex(k);
            auto distance = glm::distance(location, other);
 
            if (distance < 150) {
                near_index_list.push_back(k);
            }
        }
 
        if (near_index_list.size() > 3) {
 
            for (int k = 0; k < near_index_list.size() - 2; k++) {
 
                face.addIndex(i);
                face.addIndex(near_index_list[k]);
                face.addIndex(near_index_list[k + 1]);
 
                frame.addIndex(i); frame.addIndex(near_index_list[k]);
                frame.addIndex(i); frame.addIndex(near_index_list[k + 1]);
            }
        }
    }
 
    auto frame = 60;
    auto param = ofGetFrameNum() % (frame * bands);
    auto index = param / frame;
    
    float mult = 100;
 
    for (int i = 0; i < bands; i++) {
        if (i == index) {
            auto f = ofGetFrameNum() % frame;
            if (f > frame * mult) {
                seeds[index] += ofMap(f, frame * mult, frame, 0.05, 0.0005);
            } else {
                seeds[index] += ofMap(f, 0, frame * mult, 0.0005, 0.05);
            }
        } else {
            seeds[i] += 0.0005;
        }
    }
}

//--------------------------------------------------------------
void mb_11_13::draw(){
    cam.begin();
    
    ofRotateYDeg(ofGetFrameNum() * 0.5);
    ofRotateXDeg(ofGetFrameNum() * 0.75);
 
    face.draw();
    frame.drawWireframe();
 
    for (auto& vertex : face.getVertices()) {
        ofDrawSphere(vertex, 3);
    }

    cam.end();
}

//--------------------------------------------------------------
void mb_11_13::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_11_13::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_11_13::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_11_13::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_11_13::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_11_13::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_11_13::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_11_13::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_11_13::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_11_13::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_11_13::dragEvent(ofDragInfo dragInfo){

}
