#include "mb_08_01.h"

//--------------------------------------------------------------
void mb_08_01::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(375);

    
    // Gradient
    gradient.addColor(ofColor(81, 162, 241));          // 51A2F1
    gradient.addColor(ofColor(228, 129, 110));          // E4816E
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(2);
    
    // Mesh
    auto shape = ofSpherePrimitive(100, 5);
    meshBase = shape.getMesh();
    meshDraw.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_08_01::update(){

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
void mb_08_01::draw(){
    cam.begin();
    
    float speed = 0.25;
    ofRotateXDeg(ofGetFrameNum() * speed);
    ofRotateYDeg(ofGetFrameNum() * 0.5 * speed);
    ofRotateZDeg(ofGetFrameNum() * 2 * speed);
    
    int index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(meshDraw.getColor(index++));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 0, 1, 2, 7);
        ofDrawCone(vert.x, vert.y, vert.z, size/2, size);
    }
    meshDraw.drawWireframe();
 
    
    ofRotateXDeg(ofGetFrameNum() * 2 * -speed);
    ofRotateYDeg(ofGetFrameNum() * 1 * -speed);
    ofRotateZDeg(ofGetFrameNum() * 4 * -speed);
    
    index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(meshDraw.getColor(index++));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 0, 1, 2, 7);
//        ofDrawSphere(vert, size);
        ofDrawCone(vert.x, vert.y, vert.z, size/2, size);
    }
    meshDraw.drawWireframe();
    
    cam.end();
}

//--------------------------------------------------------------
void mb_08_01::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_08_01::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_08_01::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_08_01::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_01::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_01::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_01::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_08_01::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_08_01::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_08_01::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_08_01::dragEvent(ofDragInfo dragInfo){

}
