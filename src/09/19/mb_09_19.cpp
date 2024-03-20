#include "mb_09_19.h"

//--------------------------------------------------------------
void mb_09_19::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(400);

    
    // Gradient
    gradient.addColor(ofColor(7, 21, 34));          // 071522
    gradient.addColor(ofColor(240, 231, 77));           // F0E74D
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(10);
    
    // Mesh
    auto shape = ofSpherePrimitive(200, 10);
    meshBase1 = shape.getMesh();
    meshDraw1.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
    meshBase2 = shape.getMesh();
    meshDraw2.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_09_19::update(){

    meshDraw1.clear();
    
    for (auto vert : meshBase1.getVertices()) {
        
        auto length = ofMap(sin(ofGetFrameNum()*0.005), 0, 1, 0.1, 1);
        
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
        
        auto length = ofMap(tan(ofGetFrameNum()*0.005), 0, 1, 0.1, 1);
        
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
void mb_09_19::draw(){
    cam.begin();
    
    float speed = 0.25;
    ofRotateXDeg(ofGetFrameNum() * speed);
    ofRotateYDeg(ofGetFrameNum() * 0.5 * speed);
    
    int index = 0;
    for (auto& vert : meshDraw1.getVertices()) {
        ofSetColor(meshDraw1.getColor(index++));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 0, 1, 1, 2);
        ofDrawSphere(vert, size);
        ofDrawBox(vert, size);
    }
    meshDraw1.drawWireframe();
    
    ofRotateYDeg(ofGetFrameNum() * -1.5 * speed);
    
    index = 0;
    for (auto& vert : meshDraw2.getVertices()) {
        ofSetColor(meshDraw2.getColor(index++));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 0, 1, 1, 2);
        ofDrawSphere(vert, size);
        ofDrawBox(vert, size);
    }
    meshDraw2.drawWireframe();
 
    cam.end();
}

//--------------------------------------------------------------
void mb_09_19::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_09_19::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_09_19::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_09_19::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_19::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_19::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_19::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_09_19::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_09_19::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_09_19::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_09_19::dragEvent(ofDragInfo dragInfo){

}
