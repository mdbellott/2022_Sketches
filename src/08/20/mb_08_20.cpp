#include "mb_08_20.h"

//--------------------------------------------------------------
void mb_08_20::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(375);

    
    // Gradient
    gradient.addColor(ofColor(237, 111, 101));          // ED6F65
    gradient.addColor(ofColor(50, 116, 75));            // 32744B
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(10);
    
    // Mesh
    auto shape = ofConePrimitive(50, 50, 100, 5);
    meshBase = shape.getMesh();
    meshDraw.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_08_20::update(){

    meshDraw.clear();
    
    for (auto vert : meshBase.getVertices()) {
        
        auto length = ofMap(sin(ofGetFrameNum()*0.005), 0, 1, 0.1, 1);
        
        auto normVert = glm::normalize(vert) * 200;
        normVert = glm::vec4(normVert, 0) * length;
         
        meshDraw.addVertex(vert);
        meshDraw.addVertex(normVert);
 
        meshDraw.addIndex(meshDraw.getNumVertices() - 1);
        meshDraw.addIndex(meshDraw.getNumVertices() - 2);
    }
}

//--------------------------------------------------------------
void mb_08_20::draw(){
    cam.begin();
    
    float speed = 0.25;
    ofRotateXDeg(ofGetFrameNum() * 2 * speed);
    ofRotateYDeg(ofGetFrameNum() * 2 * speed);
    ofRotateZDeg(ofGetFrameNum() * 2 * speed);
    
    int index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(ofColor(237, 111, 101));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 1, 0, 5, 15);
        ofDrawCone(vert.x-20, vert.y-20, vert.z, size/2, size);
    }
    meshDraw.drawWireframe();
 
    
    ofRotateXDeg(ofGetFrameNum() * 2 * -speed);
    ofRotateYDeg(ofGetFrameNum() * 2 * -speed);
    ofRotateZDeg(ofGetFrameNum() * 2 * -speed);
    
    index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(ofColor(50, 116, 75));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 0, 1, 5, 15);
        ofDrawCone(vert.x+20, vert.y+20, vert.z, size/2, size);
    }
    meshDraw.drawWireframe();
    
    cam.end();
}

//--------------------------------------------------------------
void mb_08_20::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_08_20::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_08_20::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_08_20::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_20::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_20::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_20::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_08_20::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_08_20::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_08_20::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_08_20::dragEvent(ofDragInfo dragInfo){

}
