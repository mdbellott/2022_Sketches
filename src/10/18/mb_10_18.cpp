#include "mb_10_18.h"

//--------------------------------------------------------------
void mb_10_18::setup(){
    // Window
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    
    // Cam
    ofSetFrameRate(60);
    cam.disableMouseInput();
    cam.setDistance(375);

    
    // Gradient
    gradient.addColor(ofColor(183, 41, 96));            // B72960
    gradient.addColor(ofColor(73, 151, 204));           // 4997CC
    gradient.drawDebug(0, 0, -ofGetWidth(), -ofGetHeight(), 100, false, true);
    
    // Draw
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetLineWidth(0);
    
    // Mesh
    auto shape = ofBoxPrimitive(100, 100, 100);
    meshBase = shape.getMesh();
    meshDraw.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_10_18::update(){

    meshDraw.clear();
    
    for (auto vert : meshBase.getVertices()) {
        
        auto length = ofMap(atan(ofGetFrameNum()*0.005), 0, 1, 0.1, 0.5);
        
        auto normVert = glm::normalize(vert) * 200;
        normVert = glm::vec4(normVert, 0) * length;
         
        meshDraw.addVertex(vert);
        meshDraw.addVertex(normVert);
 
        meshDraw.addIndex(meshDraw.getNumVertices() - 1);
        meshDraw.addIndex(meshDraw.getNumVertices() - 2);
        meshDraw.addIndex(meshDraw.getNumVertices() - 3);
        meshDraw.addIndex(meshDraw.getNumVertices() - 4);
        
        meshDraw.addColor(gradient.getColorAtPercent(1.0));
        meshDraw.addColor(gradient.getColorAtPercent(99.0));
    }
}

//--------------------------------------------------------------
void mb_10_18::draw(){
    cam.begin();
    
    float speed = 0.25;
    float min = 5;
    float max = 20;
    
    ofRotateXDeg(ofGetFrameNum() * 2 * speed);
    ofRotateYDeg(ofGetFrameNum() * 2 * speed);
//    ofRotateZDeg(ofGetFrameNum() * 2 * speed);
    
    int index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(meshDraw.getColor(index++));
        auto size = ofMap(atan(ofGetFrameNum()*0.0025), 0, 1, min, max);
        ofDrawCone(vert.x-20, vert.y-20, vert.z-20, size/2, size);
    }
 
    
    ofRotateXDeg(ofGetFrameNum() * 2 * -speed);
    ofRotateYDeg(ofGetFrameNum() * 2 * -speed);
//    ofRotateZDeg(ofGetFrameNum() * 2 * -speed);
    
    index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(meshDraw.getColor(index++));
        auto size = ofMap(atan(ofGetFrameNum()*0.0025), 0, 1, min, max);
        ofDrawCone(vert.x-20, vert.y-20, vert.z-20, size/2, size);
    }
    
    cam.end();
}

//--------------------------------------------------------------
void mb_10_18::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_10_18::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_10_18::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_10_18::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_18::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_18::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_18::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_10_18::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_10_18::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_10_18::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_10_18::dragEvent(ofDragInfo dragInfo){

}
