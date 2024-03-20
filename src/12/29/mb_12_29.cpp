#include "mb_12_29.h"

//--------------------------------------------------------------
void mb_12_29::setup(){
    // Window
    ofSetWindowShape(900, 900);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(700);

    // Gradient
    
    gradient.addColor(ofColor(51, 115, 186));    // 3373BA
    gradient.addColor(ofColor(51, 245, 186));    // 33F5BA
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);

    ofBackground(0);
    ofEnableDepthTest();
 
    frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_12_29::update(){
    
}

//--------------------------------------------------------------
void mb_12_29::draw(){
    face.clear();
    frame.clear();
    
    cam.begin();
     
    auto radius = 200;
     
    ofSetColor(gradient.getColorAtPercent(0.5));
    ofNoFill();
    ofSetLineWidth(5);
    ofRotateDeg((ofGetFrameNum()*1), 1.0, 1.0, 1.0);
    ofDrawBox(radius, radius, radius);
 
    for (radius = radius + 50; radius < 300; radius += 5) {
        setRingToMesh(face, frame, glm::vec3(), radius, radius * 0.1,
                      gradient.getColorAtPercent(float(float(-radius)/300.0)),
                      gradient.getColorAtPercent(float(float(radius)/300.0)));
    }
 
    face.draw();
    frame.drawWireframe();
    
    cam.end();
}

//--------------------------------------------------------------
void mb_12_29::setRingToMesh(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float radius, float height, ofColor face_color, ofColor frame_color) {
 
    int index = face_target.getNumVertices();
 
    for (int deg = 0; deg < 360; deg += 5) {
        vector<glm::vec3> vertices;
        vertices.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), height * -0.5));
        vertices.push_back(glm::vec3(radius * cos((deg + 1) * DEG_TO_RAD), radius * sin((deg + 1) * DEG_TO_RAD), height * -1));
        vertices.push_back(glm::vec3(radius * cos((deg + 1) * DEG_TO_RAD), radius * sin((deg + 1) * DEG_TO_RAD), height * 1));
        vertices.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), height * 0.5));
 
        for (auto& vertex : vertices) {
            auto noise_value_x = ofNoise(
                location.x, radius * 0.001 + ofGetFrameNum() * 0.003);
            auto noise_value_y = ofNoise(
                location.y, radius * 0.001 + ofGetFrameNum() * 0.003);
            auto noise_value_z = ofNoise(
                location.z, radius * 0.001 + ofGetFrameNum() * 0.003);
 
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
void mb_12_29::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_12_29::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_12_29::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_12_29::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_29::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_29::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_12_29::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_12_29::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_12_29::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_12_29::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_12_29::dragEvent(ofDragInfo dragInfo){

}
