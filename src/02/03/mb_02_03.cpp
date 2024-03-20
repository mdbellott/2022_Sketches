#include "mb_02_03.h"

//--------------------------------------------------------------
void mb_02_03::setup(){
    ofSetWindowShape(1000, 1000);
    ofBackground(0);
    ofSetVerticalSync(true);
    
    int num = 5000;
    p.assign(num, Particle_02_03());

    resetParticles();
}

//--------------------------------------------------------------
void mb_02_03::resetParticles(){

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
void mb_02_03::update(){
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].update();
    }
    
    for(unsigned int i = 0; i < pointsWithMovement.size(); i++){
        pointsWithMovement[i].x = points[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef());
        pointsWithMovement[i].y = points[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef());
    }
}

//--------------------------------------------------------------
void mb_02_03::draw(){
    for(unsigned int i = 0; i < p.size(); i++){ p[i].draw(); }
}

//--------------------------------------------------------------
void mb_02_03::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_02_03::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_02_03::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_02_03::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_03::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_03::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_02_03::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_02_03::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_02_03::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_02_03::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_02_03::dragEvent(ofDragInfo dragInfo){ 

}
