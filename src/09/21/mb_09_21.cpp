#include "mb_09_21.h"

//--------------------------------------------------------------
void mb_09_21::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(400);

    
    // Gradient
    gradient.addColor(ofColor(170, 37, 214));           // AA25D6
    gradient.addColor(ofColor(113, 241, 240));          // 71F1F0
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(10);
    
    // Mesh
    auto shape = ofPlanePrimitive(100, 100, 10, 10);
    
    meshBase1 = shape.getMesh();
    meshDraw1.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
    meshBase2 = shape.getMesh();
    meshDraw2.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_09_21::update(){

    meshDraw1.clear();
    
    auto length = ofMap(tan(ofGetFrameNum()*0.0005), 0, 1, 1, 10);
    
    for (auto vert : meshBase1.getVertices()) {
        
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
void mb_09_21::draw(){
    cam.begin();
    
    float speed = 0.5;
    float vSpeed = 0.05;
    ofRotateYDeg(ofGetFrameNum() * 0.5 * speed);
    
    int index = 0;
    float min = 1;
    float max = 5;
    for (auto& vert : meshDraw1.getVertices()) {
        ofSetColor(meshDraw1.getColor(index++));
        auto size = ofMap(cos(ofGetFrameNum()*vSpeed), 0, 1, min, max);
        ofDrawBox(vert, size);
    }
    meshDraw1.drawWireframe();
    
    ofRotateYDeg(ofGetFrameNum() * -1.5 * speed);
    
    index = 0;
    for (auto& vert : meshDraw2.getVertices()) {
        ofSetColor(meshDraw2.getColor(index++));
        auto size = ofMap(cos(ofGetFrameNum()*vSpeed), 0, 1, min, max);
        ofDrawBox(vert, size);
    }
    meshDraw2.drawWireframe();
 
    cam.end();
}

//--------------------------------------------------------------
void mb_09_21::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_09_21::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_09_21::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_09_21::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_21::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_21::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_21::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_09_21::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_09_21::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_09_21::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_09_21::dragEvent(ofDragInfo dragInfo){

}
