#include "mb_03_18.h"

//--------------------------------------------------------------
void mb_03_18::setup(){
    gradient.addColor(ofColor(187, 92, 113));          // F7CD82
    gradient.addColor(ofColor(247, 205, 130));          // F7CD82
    gradient.addColor(ofColor(82, 160, 172));           // 52A0AC
    
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
    
    m = 10;
    n = 1000;
    
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
            p.push_back(glm::vec2((0 - (j/m) * (ofGetWidth()*2)) + ofRandom(-100, 100), (i/n) * ofGetHeight()));
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
void mb_03_18::update(){
    dt += inc;
    
    ofEnableAlphaBlending();
    
    fbo.begin();
        drawFBO();
    fbo.end();
}

//--------------------------------------------------------------
void mb_03_18::drawFBO(){
    ofFill();
    ofSetColor(141, 73, 61, fade);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    for (float j=0; j<m; j+=1.0) {
        for (float i=0; i<n; i+=1.0) {
            float ds = ofMap(sin(dt*TWO_PI), -1, 1, -vel[j][i].y, vel[j][i].y);
            float dc = ofMap(cos(dt*TWO_PI), -1, 1, -vel[j][i].x, vel[j][i].x);
            //1
            float y = pos[j][i].y + ds;
            if (xUp[j][i]) { pos[j][i].x += vel[j][i].x; }
            else { pos[j][i].x -= vel[j][i].x; }
            
            float x = pos[j][i].x + dc;
            if (xUp[j][i]) { pos[j][i].x += vel[j][i].x; }
            else { pos[j][i].x -= vel[j][i].x; }
            
            float pct;
            if (int(j)%2 == 0 ) { pct = pos[j][i].y/ofGetHeight();}
            else { pct = 1.0 - pos[j][i].y/ofGetHeight();}
            if (pct >= 1.0) { pct = 0.99; }
            if (pct <= -1.0) { pct = -0.99; }
            ofSetColor(gradient.getColorAtPercent(pct));
            ofDrawBox(pos[j][i].y, x*y, 0, 20, 20, 20);
            
            if (pos[j][i].x >= ofGetWidth() * 1.05) { xUp[j][i] = false; }
            else if (pos[j][i].x <= -0.05 * ofGetWidth()) { xUp[j][i] = true; }
        }
    }
}

//--------------------------------------------------------------
void mb_03_18::draw(){
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void mb_03_18::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_03_18::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_03_18::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_03_18::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_18::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_18::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_18::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_03_18::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_03_18::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_03_18::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_03_18::dragEvent(ofDragInfo dragInfo){

}
