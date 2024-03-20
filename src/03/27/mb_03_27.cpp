#include "mb_03_27.h"

//--------------------------------------------------------------
void mb_03_27::setup(){
    gradient.addColor(ofColor(212, 206, 157));          // D4CE9D
    gradient.addColor(ofColor(114, 208, 231));          // 8DD0E7
    gradient.addColor(ofColor(176, 117, 199));           // B075C7
    
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(187, 92, 113));                // BB5C71
    
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    ofSetVerticalSync(true);
    
    int num = 10000;
    p.assign(num, Particle_03_27());

    resetParticles();
}

//--------------------------------------------------------------
void mb_03_27::resetParticles(){

    points.clear();
    for(int i = 0; i < 4; i++){
        points.push_back(glm::vec3( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) , 0) );
    }
    
    pointsWithMovement = points;
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setPoints(&pointsWithMovement);
        p[i].reset();
    }
}

//--------------------------------------------------------------
void mb_03_27::update(){
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].update();
    }
    
    for(unsigned int i = 0; i < pointsWithMovement.size(); i++){
        pointsWithMovement[i].x = points[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef());
        pointsWithMovement[i].y = points[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef());
    }
}

//--------------------------------------------------------------
void mb_03_27::draw(){
    for(unsigned int i = 0; i < p.size(); i++){
        float pct = float(i)/float(p.size());
        p[i].draw(gradient.getColorAtPercent(pct));
    }
}

//--------------------------------------------------------------
void mb_03_27::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_03_27::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_03_27::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_03_27::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_27::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_27::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_27::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_03_27::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_03_27::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_03_27::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_03_27::dragEvent(ofDragInfo dragInfo){ 

}
