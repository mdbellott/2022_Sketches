#pragma once
#include "ofMain.h"

class Shape_02_11 {
    
public:
    Shape_02_11(glm::vec2 p,
          float s,
          float inc,
          float off,
          float max,
          bool up);
    
    void update();
    void draw();
    
    glm::vec2 pos;
    
    float unique;
    
    float size;
    float inc;
    float offset;
    float maxOffset;
    
    bool isUp;
    bool incUp;
};
