#include "mb_09_28.h"

//--------------------------------------------------------------
void mb_09_28::setup(){
    gradient.addColor(ofColor(139, 46, 18));        // 8B2E12
    gradient.addColor(ofColor(130, 143, 76));       // 828F4C
    gradient.addColor(ofColor(225, 197, 98));       // E1C562
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
    n = 50;
    
    float x = 2.0;
    float dx = 0.25;
    float y = 25;
    float dy = 12.5;
    
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
        yUp.push_back(up);
        pos.push_back(p);
        vel.push_back(v);
    }
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    fbo.begin();
        ofClear(141, 73, 61, 0);
    fbo.end();
}

//--------------------------------------------------------------
void mb_09_28::update(){
    dt += inc;
    
    ofEnableAlphaBlending();
    
    fbo.begin();
        drawFBO();
    fbo.end();
}

//--------------------------------------------------------------
void mb_09_28::drawFBO(){
    ofFill();
    ofSetColor(141, 73, 61, fade);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    for (float j=0; j<m; j+=1.0) {
        for (float i=0; i<n; i+=1.0) {

            float y = 0.025;
            if (xUp[j][i]) { pos[j][i].x += vel[j][i].x; }
            else { pos[j][i].x -= vel[j][i].x; }
            if (yUp[j][i]) { pos[j][i].y += vel[j][i].y*y; }
            else { pos[j][i].y -= vel[j][i].y*y; }
            
            float pct;
            if (int(j)%2 == 0 ) { pct = pos[j][i].y/ofGetHeight();}
            else { pct = 1.0 - pos[j][i].y/ofGetHeight();}
            if (pct >= 1.0) { pct = 0.99; }
            if (pct <= -1.0) { pct = -0.99; }
            ofSetColor(gradient.getColorAtPercent(pct));
            int size = 20;
            ofDrawTriangle(pos[j][i].y, pos[j][i].x, pos[j][i].y+size, pos[j][i].x, pos[j][i].y+size/2, pos[j][i].x+size/2);
            
            if (pos[j][i].x >= ofGetWidth() * 1.05) { xUp[j][i] = false; }
            else if (pos[j][i].x <= -0.05 * ofGetWidth()) { xUp[j][i] = true; }
            if (pos[j][i].y >= ofGetHeight() * 1.05) { yUp[j][i] = false; }
            else if (pos[j][i].y <= -0.5 * ofGetHeight()) { yUp[j][i] = true; }
        }
    }
}

//--------------------------------------------------------------
void mb_09_28::draw(){
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void mb_09_28::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_09_28::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_09_28::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_09_28::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_28::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_28::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_09_28::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_09_28::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_09_28::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_09_28::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_09_28::dragEvent(ofDragInfo dragInfo){

}
