#include "mb_07_28.h"

//--------------------------------------------------------------
void mb_07_28::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(375);

    
    // Gradient
    gradient.addColor(ofColor(101, 203, 211));          // 65CBD3
    gradient.addColor(ofColor(148, 149, 234));          // 9495EA
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(2);
    
    // Mesh
//    auto shape = ofBoxPrimitive(200, 200, 200);
    auto shape = ofPlanePrimitive(200, 200, 7, 7);
    meshBase = shape.getMesh();
    meshDraw.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_07_28::update(){

    meshDraw.clear();
    
    for (auto vert : meshBase.getVertices()) {
        
        auto length = ofMap(sin(ofGetFrameNum()*0.005), 0, 1, 0.1, 1);
        
        auto normVert = glm::normalize(vert) * 200;
        normVert = glm::vec4(normVert, 0) * length;
         
        meshDraw.addVertex(vert);
        meshDraw.addVertex(normVert);
 
        meshDraw.addIndex(meshDraw.getNumVertices() - 1);
        meshDraw.addIndex(meshDraw.getNumVertices() - 2);
 
        meshDraw.addColor(gradient.getColorAtPercent(1.0));
        meshDraw.addColor(gradient.getColorAtPercent(99.0));
    }
}

//--------------------------------------------------------------
void mb_07_28::draw(){
    cam.begin();
    
    float speed = 0.25;
//    ofRotateXDeg(ofGetFrameNum() * speed);
//    ofRotateYDeg(ofGetFrameNum() * 0.5 * speed);
    ofRotateZDeg(ofGetFrameNum() * 2 * speed);
    
    int index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(meshDraw.getColor(index++));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 0, 1, 2, 7);
//        ofDrawSphere(vert, size);
        ofDrawBox(vert, size);
    }
    meshDraw.drawWireframe();
 
    
//    ofRotateXDeg(ofGetFrameNum() * 2 * -speed);
//    ofRotateYDeg(ofGetFrameNum() * 1 * -speed);
    ofRotateZDeg(ofGetFrameNum() * 4 * -speed);
    
    index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(meshDraw.getColor(index++));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 0, 1, 1, 5);
//        ofDrawSphere(vert, size);
        ofDrawBox(vert, size);
    }
    meshDraw.drawWireframe();
    
    cam.end();
}

//--------------------------------------------------------------
void mb_07_28::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_07_28::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_07_28::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_07_28::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_28::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_28::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_07_28::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_07_28::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_07_28::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_07_28::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_07_28::dragEvent(ofDragInfo dragInfo){

}
