#include "mb_02_21.h"

//--------------------------------------------------------------
void mb_02_21::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    ofSetFrameRate(60);
    
    n = 50;
    
    for (int i=0; i<n; i++) {
        dts.push_back(i*5);
        incs.push_back(true);
    }
    
    setupGradients();
}

//--------------------------------------------------------------
void mb_02_21::setupGradients(){
    
    ofColor colorOne(254, 244, 181); // FEF4B5
    ofColor colorTwo(178, 201, 135); // B2C987
    ofColor colorThree(76, 95, 62); // 4C5F3E
    
    for (int i=0; i<n; i++) {
        ofxColorGradient<ofColor> gradient;
        
        if (i%2 == 0) {
            gradient.addColor(colorOne);
            gradient.addColor(colorTwo);
            gradient.addColor(colorThree);
        } else {
            gradient.addColor(colorThree);
            gradient.addColor(colorTwo);
            gradient.addColor(colorOne);
        }
        
        gradients.push_back(gradient);
    }
}

//--------------------------------------------------------------
void mb_02_21::update(){
    for (int i=0; i<n; i++) {
        if (incs[i]) { dts[i] += 10; }
        else { dts[i] -= 10; }

        if (dts[i] > 2500) { incs[i] = false; }
        else if (dts[i] < 10) { incs[i] = true; }
    }
}

//--------------------------------------------------------------
void mb_02_21::draw(){
    for (int i=0; i<gradients.size(); i++) {
        if (i%2 == 0) {
            gradients[i].drawDebug(0 - dts[i],
                                   (i * ofGetHeight() / n),
                                   ofGetWidth() + dts[i],
                                   ((i + 1) * ofGetHeight() / n));
        } else {
            gradients[i].drawDebug(0,
                                   (i * ofGetHeight() / n),
                                   ofGetWidth() + dts[i],
                                   ((i + 1) * ofGetHeight() / n));
        }
    }
}

//--------------------------------------------------------------
void mb_02_21::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_21::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_21::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_21::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_21::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_21::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_21::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_21::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_21::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_21::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_21::dragEvent(ofDragInfo dragInfo){

}
