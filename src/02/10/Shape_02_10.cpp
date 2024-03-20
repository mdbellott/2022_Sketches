#include "Shape_02_10.h"

Shape_02_10::Shape_02_10(glm::vec2 p,
             float s,
             float i,
             float off,
             float max,
             bool up) {
    pos = p;
    size = s;
    inc = i;
    offset = off;
    maxOffset = max;
    incUp = up;
}

void Shape_02_10::update() {
    if (incUp) {
        offset += inc;
    }
    else {
        offset -= inc;
    }
    
}

void Shape_02_10::draw() {
    ofSetColor(255);
    
    float w = size;
    float h = size/2;
    
    if (offset >= h*2 + 5) { incUp = false; }
    else if (offset <= 0 - 5) { incUp = true; }
    
    ofDrawTriangle(pos.x,
                   pos.y + offset,
                   pos.x + (w/2),
                   pos.y + h,
                   pos.x - (w/2),
                   pos.y + h);
}
