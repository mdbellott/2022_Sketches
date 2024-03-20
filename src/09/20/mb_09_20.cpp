#include "mb_09_20.h"

//--------------------------------------------------------------
void mb_09_20::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(400);

    
    // Gradient
    gradient.addColor(ofColor(212, 46, 34));          // D42E22
    gradient.addColor(ofColor(116, 249, 138));        // 74F98A
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(100);
    
    // Mesh
    auto shape = ofConePrimitive(100, 100, 100, 20);
    
    meshBase1 = shape.getMesh();
    meshDraw1.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
    meshBase2 = shape.getMesh();
    meshDraw2.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_09_20::update(){

    meshDraw1.clear();
    
    for (auto vert : meshBase1.getVertices()) {
        
        auto length = ofMap(tan(ofGetFrameNum()*0.0005), 0, 1, 0.1, 5);
        
        auto normVert = glm::normalize(vert) * 200;
        normVert = glm::vec4(normVert, 0) * length;
         
        meshDraw1.addVertex(vert);
        meshDraw1.addVertex(normVert);
 
        meshDraw1.addIndex(meshDraw1.getNumVertices() - 1);
        meshDraw1.addIndex(meshDraw1.getNumVertices() - 2);
 
        meshDraw1.addColor(gradient.getColorAtPercent(1.0));
        meshDraw1.addColor(gradient.getColorAtPercent(99.0));
    }
    
    meshDraw2.clear();
    
    for (auto vert : meshBase2.getVertices()) {
        
        auto length = ofMap(atan(ofGetFrameNum()*0.0005), 0, 1, 0.1, 5);
        
        auto normVert = glm::normalize(vert) * 200;
        normVert = glm::vec4(normVert, 0) * length;
         
        meshDraw2.addVertex(vert);
        meshDraw2.addVertex(normVert);
 
        meshDraw2.addIndex(meshDraw2.getNumVertices() - 1);
        meshDraw2.addIndex(meshDraw2.getNumVertices() - 2);
 
        meshDraw2.addColor(gradient.getColorAtPercent(1.0));
        meshDraw2.addColor(gradient.getColorAtPercent(99.0));
    }
}

//--------------------------------------------------------------
void mb_09_20::draw(){
    cam.begin();
    
    float speed = 0.05;
    ofRotateYDeg(ofGetFrameNum() * 0.5 * speed);
    
    int index = 0;
    for (auto& vert : meshDraw1.getVertices()) {
        ofSetColor(meshDraw1.getColor(index++));
        auto size = ofMap(cos(ofGetFrameNum()*0.0005), 0, 1, 10, 20);
        ofDrawBox(vert, size);
    }
    meshDraw1.drawWireframe();
    
    ofRotateYDeg(ofGetFrameNum() * -1.5 * speed);
    
    index = 0;
    for (auto& vert : meshDraw2.getVertices()) {
        ofSetColor(meshDraw2.getColor(index++));
        auto size = ofMap(cos(ofGetFrameNum()*0.0005), 0, 1, 10, 20);
        ofDrawBox(vert, size);
    }
    meshDraw2.drawWireframe();
 
    cam.end();
}

//--------------------------------------------------------------
void mb_09_20::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_09_20::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_09_20::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_09_20::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_20::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_20::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_20::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_09_20::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_09_20::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_09_20::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_09_20::dragEvent(ofDragInfo dragInfo){

}
