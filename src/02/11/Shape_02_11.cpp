#include "Shape_02_11.h"

Shape_02_11::Shape_02_11(glm::vec2 p,
             float s,
             float i,
             float off,
             float max,
             bool up) {
    
    unique = ofRandom(-10, 10);
    
    pos = p;
    size = s;
    inc = i;
    offset = off;
    maxOffset = max;
    incUp = up;
}

void Shape_02_11::update() {
    if (incUp) {
        offset += inc;
    }
    else {
        offset -= inc;
    }
    
}

void Shape_02_11::draw() {
    ofSetColor(255);
    
    float w = size - 100;
    float h = size/2 - 20;
    
    if (offset >= h*2 + 5) { incUp = false; }
    else if (offset <= 0 - 5) { incUp = true; }
    
    float u = 0;
    if (incUp) { u = unique; }
    else { u = -1 * unique; }
    
    ofDrawTriangle(pos.x,
                   pos.y,
                   pos.x + (w/2) - offset + u,
                   pos.y + h,
                   pos.x - (w/2) + offset + u,
                   pos.y + h);
}
