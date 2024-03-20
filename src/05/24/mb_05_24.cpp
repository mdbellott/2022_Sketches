#include "mb_05_24.h"

//--------------------------------------------------------------
void mb_05_24::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

    shader.load("shaders/GL2/shader");

    img.allocate(100, 100, OF_IMAGE_COLOR);

    plane.set(3000, 3000, 100, 100);
    plane.mapTexCoordsFromTexture(img.getTexture());
    
    xVal = 700;
    yVal = 100;
}

//--------------------------------------------------------------
void mb_05_24::update(){
    float noiseScale = ofMap(xVal, 0, ofGetWidth(), 0, 0.25);
    float noiseVel = ofGetElapsedTimef();

    ofPixels & pixels = img.getPixels();
    int w = img.getWidth();
    int h = img.getHeight();
    for(int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {
            int i = y * w + x;
            float noiseVelue = ofNoise(x * noiseScale, y * noiseScale, noiseVel);
            pixels[i] = 255 * noiseVelue;
        }
    }
    img.update();
}

//--------------------------------------------------------------
void mb_05_24::draw(){
    float percentX = xVal / (float)ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);
    
    ofColor colorLeft = ofColor::cyan;
    ofColor colorRight = ofColor::orchid;
    ofColor colorMix = colorLeft.getLerped(colorRight, percentX);
    ofSetColor(colorLeft);

    img.getTexture().bind();

    shader.begin();

    ofPushMatrix();

    float tx = ofGetWidth() / 2;
    float ty = ofGetHeight() / 2;
    ofTranslate(-tx, -ty);

    float percentY = yVal / (float)ofGetHeight();
    float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
    ofRotateDeg(rotation, 1, 0, 0);

    ofNoFill();
    plane.drawWireframe();
//    plane.drawFaces();
    plane.drawNormals(100);

    ofPopMatrix();

    shader.end();
}

//--------------------------------------------------------------
void mb_05_24::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_05_24::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_05_24::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_05_24::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_24::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_24::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_05_24::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_05_24::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_05_24::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_05_24::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_05_24::dragEvent(ofDragInfo dragInfo){

}
