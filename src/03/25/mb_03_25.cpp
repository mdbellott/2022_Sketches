#include "mb_03_25.h"

//--------------------------------------------------------------
void mb_03_25::setup(){
    gradient.addColor(ofColor(142, 46, 224  ));          // 8E2EE0
//    gradient.addColor(ofColor(247, 205, 130));          // EBCEF2
    gradient.addColor(ofColor(99, 112, 185));           // 6370B9
    
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(187, 92, 113));                // BB5C71
    
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

    dt = 0.0;
    inc = 0.00025;
    
    rad = 10.0;
    fade = 5;
    
    m = 4;
    n = 100;
    
    float x = 2;
    float dx = 1;
    float y = 1000;
    float dy = 100;
    
    for(float j = 0; j<m; j+=1.0) {
        vector<bool> up;
        vector<glm::vec2> p;
        vector<glm::vec2> v;
        for(float i = 0; i<n; i+=1.0) {
            up.push_back(true);
            p.push_back(glm::vec2((0 - (j/m) * (ofGetWidth()*2)) + 0, (i/n) * ofGetHeight()));
            v.push_back(glm::vec2(x + ofRandom(-dx, dx), y + 9));
        }
        xUp.push_back(up);
        pos.push_back(p);
        vel.push_back(v);
    }
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    fbo.begin();
        ofClear(141, 73, 61, 0);
    fbo.end();
}

//--------------------------------------------------------------
void mb_03_25::update(){
    dt += inc;
    
    ofEnableAlphaBlending();
    
    fbo.begin();
        drawFBO();
    fbo.end();
}

//--------------------------------------------------------------
void mb_03_25::drawFBO(){
    ofFill();
    ofSetColor(141, 73, 61, fade);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    for (float j=0; j<m; j+=1.0) {
        for (float i=0; i<n; i+=1.0) {
            float ds = ofMap(sin(dt*TWO_PI), -1, 1, -vel[j][i].y, vel[j][i].y);
            //1
            float y = pos[j][i].y + ds;
            if (xUp[j][i]) { pos[j][i].x += vel[j][i].x; }
            else { pos[j][i].x -= vel[j][i].x; }
            
            float pct;
            if (int(j)%2 == 0 ) { pct = pos[j][i].y/ofGetHeight();}
            else { pct = 1.0 - pos[j][i].y/ofGetHeight();}
            if (pct >= 1.0) { pct = 0.99; }
            if (pct <= -1.0) { pct = -0.99; }
            ofSetColor(gradient.getColorAtPercent(pct));
//            ofDrawCircle(y, pos[j][i].x, rad/2);
//            ofDrawCone(pos[j][i].y, pos[j][i].x, 10, 20);
//            ofNoFill();
            ofDrawBox(pos[j][i].x, pos[j][i].y, 0, 10, 10, 10);
//            ofDrawIcoSphere(pos[j][i].x, pos[j][i].y, 50);
//            ofDrawCone(pos[j][i].x, pos[j][i].y, 10, 20);
//            ofDrawCylinder(pos[j][i].x, pos[j][i].y, 50, 100);
            
            if (pos[j][i].x >= ofGetWidth() * 1.05) { xUp[j][i] = false; }
            else if (pos[j][i].x <= -0.05 * ofGetWidth()) { xUp[j][i] = true; }
        }
    }
}

//--------------------------------------------------------------
void mb_03_25::draw(){
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void mb_03_25::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_03_25::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_03_25::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_03_25::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_25::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_25::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_25::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_03_25::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_03_25::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_03_25::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_03_25::dragEvent(ofDragInfo dragInfo){

}
