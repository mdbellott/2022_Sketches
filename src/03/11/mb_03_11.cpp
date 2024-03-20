#include "mb_03_11.h"

//--------------------------------------------------------------
void mb_03_11::setup(){
    gradient.addColor(ofColor(28, 65, 150));        // 1C4196
    gradient.addColor(ofColor(88, 172, 187));       // 58ACBB
    gradient.drawDebug(0,
                       0,
                       0 - ofGetWidth(),
                       0 - ofGetHeight(),
                       100,
                       false,
                       true);
    ofBackground(ofColor(141, 73, 61));             // 8D493D
    
    ofSetWindowShape(1000, 1000);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

    dt = 0.0;
    inc = 0.001;
    
    rad = 10.0;
    fade = 5;
    
    m = 8;
    n = 40;
    
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
void mb_03_11::update(){
    dt += inc;
    
    ofEnableAlphaBlending();
    
    fbo.begin();
        drawFBO();
    fbo.end();
}

//--------------------------------------------------------------
void mb_03_11::drawFBO(){
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
            ofDrawCone(pos[j][i].x, pos[j][i].y, 10, 20);
            
            if (pos[j][i].x >= ofGetWidth() * 1.05) { xUp[j][i] = false; }
            else if (pos[j][i].x <= -0.05 * ofGetWidth()) { xUp[j][i] = true; }
        }
    }
}

//--------------------------------------------------------------
void mb_03_11::draw(){
    ofSetColor(255, 255, 255);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void mb_03_11::keyPressed(int key){

}

//--------------------------------------------------------------
void mb_03_11::keyReleased(int key){

}

//--------------------------------------------------------------
void mb_03_11::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void mb_03_11::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_11::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_11::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mb_03_11::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void mb_03_11::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void mb_03_11::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mb_03_11::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mb_03_11::dragEvent(ofDragInfo dragInfo){

}
