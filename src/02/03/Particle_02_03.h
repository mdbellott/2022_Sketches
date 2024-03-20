#pragma once
#include "ofMain.h"

class Particle_02_03 {
    
public:
    Particle_02_03();
    
    void setPoints( vector <glm::vec3> * attract );
    
    void reset();
    void update();
    void draw();
    
    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 frc;
    
    float drag;
    float uniqueVal;
    float scale;
    
    vector<glm::vec3> * points;
};
