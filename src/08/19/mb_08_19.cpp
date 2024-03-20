#include "mb_08_19.h"

//--------------------------------------------------------------
void mb_08_19::setup(){
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
    ofSetLineWidth(10);
    
    // Mesh
    auto shape = ofSpherePrimitive(100, 5);
    meshBase = shape.getMesh();
    meshDraw.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void mb_08_19::update(){

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
void mb_08_19::draw(){
    cam.begin();
    
    float speed = 0.25;
    ofRotateXDeg(ofGetFrameNum() * 2 * speed);
    ofRotateYDeg(ofGetFrameNum() * 1 * speed);
    ofRotateZDeg(ofGetFrameNum() * 4 * speed);
    
    int index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(meshDraw.getColor(index++));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 1, 0, 5, 20);
        ofDrawSphere(vert, size);
    }
    meshDraw.drawWireframe();
 
    
    ofRotateXDeg(ofGetFrameNum() * 2 * -speed);
    ofRotateYDeg(ofGetFrameNum() * 1 * -speed);
    ofRotateZDeg(ofGetFrameNum() * 4 * -speed);
    
    index = 0;
    for (auto& vert : meshDraw.getVertices()) {
        ofSetColor(meshDraw.getColor(index++));
        auto size = ofMap(sin(ofGetFrameNum()*0.025), 0, 1, 5, 20);
        ofDrawSphere(vert, size);
    }
    meshDraw.drawWireframe();
    
    cam.end();
}

//--------------------------------------------------------------
void mb_08_19::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_08_19::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_08_19::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_08_19::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_19::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_19::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_08_19::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_08_19::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_08_19::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_08_19::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_08_19::dragEvent(ofDragInfo dragInfo){

}
