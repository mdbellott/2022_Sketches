#include "mb_02_16.h"

//--------------------------------------------------------------
void mb_02_16::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    ofSetFrameRate(60);
    
    speed = 20;
    fadeAmnt = 15;
    n = 5;
    size = ofGetWidth() / n;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ofFbo texture;
            texture.allocate(400, 400, GL_RGBA);

            texture.begin();
            ofClear(255,255,255, 0);
            texture.end();
            
            shapes.push_back(texture);
        }
    }
}

//--------------------------------------------------------------
void mb_02_16::update(){
    ofEnableAlphaBlending();
    x = 0;
    for (int i=0; i<shapes.size(); i++) {
        x++;
        shapes[i].begin();
            drawFbo();
        shapes[i].end();
    }
}

//--------------------------------------------------------------
void mb_02_16::drawFbo(){
    ofFill();
    ofSetColor(255,255,255, fadeAmnt);
    ofDrawRectangle(0,0,size,size);

    ofNoFill();
    ofSetColor(255,255,255);

    float xR = 0.0;
    float yR = 0.0;
    float zR = 0.0;
    
    if (x % 3 == 0) {
        xR = 1;
        yR = 0.75;
        zR = 0.25;
    } else if (x % 3 == 1) {
        xR = 1.5;
        yR = 1.25;
        zR = 0.75;
    } else {
        xR = 0.5;
        yR = 1.75;
        zR = 1;
    }
    
    int rand = ofRandom(0, 10);
    if (rand % 2 == 0) { xR *= -1; }

    if (x + rand % 2 == 0) { xR *= -1; }
    if (x + rand % 2 == 0) { yR *= -1; }
    if (x + rand % 2 == 0 && x + rand % 2 == 0) { zR *= -1; }
    
    ofPushMatrix();
        ofTranslate(size/2,size/2,0);
        ofRotateDeg(ofGetElapsedTimef()*speed, xR, yR, zR);
        ofDrawPlane(0, 0, size/2, size/2);
    ofPopMatrix();
}

//--------------------------------------------------------------
void mb_02_16::draw(){
    ofSetColor(255, 255, 255);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            x = i;
            y = j;
            shapes[i*j].draw(i * size, j * size);
        }
    }
}

//--------------------------------------------------------------
void mb_02_16::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_16::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_16::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_16::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_16::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_16::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_16::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_16::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_16::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_16::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_16::dragEvent(ofDragInfo dragInfo){

}
