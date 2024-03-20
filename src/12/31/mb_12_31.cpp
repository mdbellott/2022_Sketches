#include "mb_12_31.h"

//--------------------------------------------------------------
void mb_12_31::setup(){
    // Window
    ofSetWindowShape(900, 900);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(700);

    // Gradient
    
    gradient.addColor(ofColor(238, 228, 76));      // EEE44C
    gradient.addColor(ofColor(8, 22, 35));         // 081623
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);

    ofBackground(0);
    ofEnableDepthTest();
 
    frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_12_31::update(){
    
}

//--------------------------------------------------------------
void mb_12_31::draw(){
    face.clear();
    frame.clear();
    
    cam.begin();
     
    auto radius = 200;
     
    ofSetColor(gradient.getColorAtPercent(0.0));
    ofNoFill();
    ofSetLineWidth(3);
    ofRotateDeg((ofGetFrameNum()), 1.0, 1.0, 1.0);
    ofDrawIcoSphere(radius/1.5);
 
    for (radius = radius + 50; radius < 300; radius += 5) {
        setRingToMesh(face, frame, glm::vec3(), radius, radius * 0.1,
                      gradient.getColorAtPercent(float(float(300.0-radius)/300.0)),
                      gradient.getColorAtPercent(float(float(radius)/300.0)));
    }
 
    face.draw();
    frame.drawWireframe();
    
    cam.end();
}

//--------------------------------------------------------------
void mb_12_31::setRingToMesh(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float radius, float height, ofColor face_color, ofColor frame_color) {
 
    int index = face_target.getNumVertices();
 
    for (int deg = 0; deg < 360; deg += 5) {
        vector<glm::vec3> vertices;
        float mult = 0.5;
        vertices.push_back(glm::vec3(radius * sin(deg * DEG_TO_RAD), radius * cos(deg * DEG_TO_RAD), height * -mult));
        vertices.push_back(glm::vec3(radius * sin((deg + 2) * DEG_TO_RAD), radius * cos((deg ) * DEG_TO_RAD), height * -mult));
        vertices.push_back(glm::vec3(radius * sin((deg + 2) * DEG_TO_RAD), radius * cos((deg ) * DEG_TO_RAD), height * mult));
        vertices.push_back(glm::vec3(radius * sin(deg * DEG_TO_RAD), radius * cos(deg * DEG_TO_RAD), height * mult));
 
        for (auto& vertex : vertices) {
            auto noise_value_x = ofNoise(
                location.x, radius * 0.001 + ofGetFrameNum() * 0.001);
            auto noise_value_y = ofNoise(
                location.y, radius * 0.001 + ofGetFrameNum() * 0.001);
            auto noise_value_z = ofNoise(
                location.z, radius * 0.001 + ofGetFrameNum() * 0.001);
 
            auto rotation_x = glm::rotate(glm::mat4(), ofMap(noise_value_x, 0, 1, -PI, PI), glm::vec3(1, 0, 0));
            auto rotation_y = glm::rotate(glm::mat4(), ofMap(noise_value_y, 0, 1, -PI, PI ), glm::vec3(0, 1, 0));
            auto rotation_z = glm::rotate(glm::mat4(), ofMap(noise_value_z, 0, 1, -PI, PI), glm::vec3(0, 0, 1));
 
            vertex = glm::vec4(vertex, 0) * rotation_y * rotation_x + glm::vec4(location, 0);
        }
 
        auto face_index = face_target.getNumVertices();
        face_target.addVertices(vertices);
 
        face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 1); face_target.addIndex(face_index + 2);
        face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 2); face_target.addIndex(face_index + 3);
 
        auto frame_index = frame_target.getNumVertices();
        frame_target.addVertices(vertices);
 
        frame_target.addIndex(frame_index + 0); frame_target.addIndex(frame_index + 1);
        frame_target.addIndex(frame_index + 2); frame_target.addIndex(frame_index + 3);
 
        for (int i = 0; i < vertices.size(); i++) {
            face_target.addColor(face_color);
            frame_target.addColor(frame_color);
        }
    }
}

//--------------------------------------------------------------
void mb_12_31::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_12_31::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_12_31::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_12_31::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_31::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_31::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_31::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_12_31::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_12_31::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_12_31::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_12_31::dragEvent(ofDragInfo dragInfo){

}
