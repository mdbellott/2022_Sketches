#include "mb_09_07.h"

//--------------------------------------------------------------
void mb_09_07::setup(){
    gradient.addColor(ofColor(104, 225, 96));          // 68E160
    gradient.addColor(ofColor(82, 57, 220));           // 5239DC
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(8, 45, 72));                   // 082D48
    
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

    inc = 0.1;
    
    n = 15;
    m = 15;
    size = 40;
    
    for(float i=0; i<n; i+=1.0) {
        vector<glm::vec2> pos;
        vector<float> p2Inc;
        vector<float> p3Inc;
        
        for(float j=0; j<m; j+=1.0) {
            pos.push_back(glm::vec2(((i/n) * (ofGetWidth())), (j/m) * ofGetHeight()));
            float vel = ofMap(ofRandom(1.0), 0.0, 1.0, -1.0, 1.0);
            p2Inc.push_back(vel > 0 ? -inc : inc);
            p3Inc.push_back(vel < 0 ? -inc : inc);
        }
        sqr1.push_back(pos);
        sqr2.push_back(pos);
        sqr3.push_back(pos);
        vsqr2.push_back(p2Inc);
        vsqr3.push_back(p3Inc);
    }
}

//--------------------------------------------------------------
void mb_09_07::update(){
}

//--------------------------------------------------------------
void mb_09_07::draw(){
    ofFill();
    ofSetColor(0, 0, 0);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for (float i=0; i<n; i+=1.0) {
        for (float j=0; j<m; j+=1.0) {
            
            // SQR2
            if(sqr2[i][j].x > (sqr1[i][j].x + size) || sqr2[i][j].x < (sqr1[i][j].x - size)) {
                vsqr2[i][j] = -vsqr2[i][j];
            }
            sqr2[i][j].x = sqr2[i][j].x + vsqr2[i][j];
            sqr2[i][j].y = sqr2[i][j].y + vsqr2[i][j];
            ofSetColor(gradient.getColorAtPercent(0.05));
            ofDrawPlane(sqr2[i][j].x, sqr2[i][j].y, size, size);

            // SQR3
            if(sqr3[i][j].x > (sqr1[i][j].x + size) || sqr3[i][j].x < (sqr1[i][j].x - size)) {
                vsqr3[i][j] = -vsqr3[i][j];
            }
            sqr3[i][j].x = sqr3[i][j].x + vsqr3[i][j];
            sqr3[i][j].y = sqr3[i][j].y + vsqr3[i][j];
            ofSetColor(gradient.getColorAtPercent(0.95));
            ofDrawPlane(sqr3[i][j].x, sqr3[i][j].y, size, size);

            // SQR1
            ofSetColor(255);
            ofDrawPlane(sqr1[i][j].x, sqr1[i][j].y, size, size);
        }
    }
}

//--------------------------------------------------------------
void mb_09_07::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_09_07::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_09_07::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_09_07::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_07::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_07::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_07::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_09_07::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_09_07::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_09_07::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_09_07::dragEvent(ofDragInfo dragInfo){

}
