#include "mb_10_02.h"

//--------------------------------------------------------------
void mb_10_02::setup(){
    gradient.addColor(ofColor(223, 59, 100));       // DF3B64
    gradient.addColor(ofColor(94, 148, 246));       // 5E94F6
    gradient.addColor(ofColor(73, 109, 50));        // 496D32
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(6, 3, 20));             // 060314
    
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

    dt = 0.0;
    inc = 0.0075;
    
    rad = 100.0;
    fade = 5;
    
    m = 4;
    n = 250;
    
    float x = 2.0;
    float dx = 0.5;
    float y = 50;
    float dy = 25;
    
    for(float j = 0; j<m; j+=1.0) {
        vector<bool> up;
        vector<glm::vec2> p;
        vector<glm::vec2> v;
        for(float i = 0; i<n; i+=1.0) {
            up.push_back(true);
            p.push_back(glm::vec2((i/n) * ofGetHeight(), (0 - (j/m) * (ofGetWidth()*2)) + ofRandom(-100, 100)));
            v.push_back(glm::vec2(x + ofRandom(-dx, dx), y + ofRandom(-dy, dy)));
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
void mb_10_02::update(){
    dt += inc;
    
    ofEnableAlphaBlending();
    
    fbo.begin();
        drawFBO();
    fbo.end();
}

//--------------------------------------------------------------
void mb_10_02::drawFBO(){
    ofFill();
    ofSetColor(0, 0, 0, fade);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    for (float j=0; j<m; j+=1.0) {
        for (float i=0; i<n; i+=1.0) {
            float ds = ofMap(sin(dt*TWO_PI), -1, 1, -vel[j][i].y, vel[j][i].y);
            //1
            float y = pos[j][i].y + (ds * 0.25);
            if (xUp[j][i]) { pos[j][i].y += vel[j][i].x; }
            else { pos[j][i].y -= vel[j][i].x; }
            
            float pct;
            if (int(j)%2 == 0 ) { pct = pos[j][i].y/ofGetHeight();}
            else { pct = 1.0 - pos[j][i].y/ofGetHeight();}
            if (pct >= 1.0) { pct = 0.99; }
            if (pct <= -1.0) { pct = -0.99; }
            ofSetColor(gradient.getColorAtPercent(pct));
            ofDrawIcoSphere(pos[j][i].y, pos[j][i].x, 5);
            
            if (pos[j][i].y >= ofGetWidth() * 1.05) { xUp[j][i] = false; }
            else if (pos[j][i].y <= -0.05 * ofGetWidth()) { xUp[j][i] = true; }
        }
    }
}

//--------------------------------------------------------------
void mb_10_02::draw(){
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void mb_10_02::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_10_02::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_10_02::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_10_02::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_02::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_02::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_10_02::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_10_02::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_10_02::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_10_02::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_10_02::dragEvent(ofDragInfo dragInfo){

}
