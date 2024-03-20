#include "mb_06_23.h"

//--------------------------------------------------------------
void mb_06_23::setup(){
    gradient.addColor(ofColor(244, 244, 105));          // F4F469
    gradient.addColor(ofColor(92, 177, 114));          // 5CB172
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

    dt = 0.0;
    inc = 0.025;
    
    rad = 10.0;
    fade = 5;
    
    m = 4;
    n = 50;
    
    float x = 1.0;
    float dx = 0.5;
    float y = 100;
    float dy = 50;
    
    for(float j = 0; j<m; j+=1.0) {
        vector<bool> up;
        vector<glm::vec2> p;
        vector<glm::vec2> v;
        for(float i = 0; i<n; i+=1.0) {
            up.push_back(true);
            p.push_back(glm::vec2((0 - (j/m) * (ofGetWidth()*2)) + ofRandom(-100, 100), (i/n) * ofGetHeight()));
            v.push_back(glm::vec2(x + ofRandom(-dx, dx), y + ofRandom(-dy, dy)));
        }
        xUp.push_back(up);
        pos.push_back(p);
        vel.push_back(v);
    }
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    fbo.begin();
        ofClear(8, 45, 72, 0);
    fbo.end();
}

//--------------------------------------------------------------
void mb_06_23::update(){
    dt += inc;
    
    ofEnableAlphaBlending();
    
    fbo.begin();
        drawFBO();
    fbo.end();
}

//--------------------------------------------------------------
void mb_06_23::drawFBO(){
    ofFill();
    ofSetColor(8, 45, 72, fade);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    int size = 50;
    
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
            ofDrawBox(pos[j][i].y, pos[j][i].x, 0, size, size, size);
            
            if (pos[j][i].x >= ofGetWidth() * 1.05) { xUp[j][i] = false; }
            else if (pos[j][i].x <= -0.05 * ofGetWidth()) { xUp[j][i] = true; }
        }
    }
}

//--------------------------------------------------------------
void mb_06_23::draw(){
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void mb_06_23::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_06_23::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_06_23::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_06_23::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_06_23::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_06_23::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_06_23::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_06_23::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_06_23::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_06_23::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_06_23::dragEvent(ofDragInfo dragInfo){

}
