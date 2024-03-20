#pragma once
#include "ofMain.h"

class Particle_03_27 {
    
public:
    Particle_03_27();
    
    void setPoints( vector <glm::vec3> * attract );
    
    void reset();
    void update();
    void draw(ofColor color);
    
    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 frc;
    
    float drag;
    float uniqueVal;
    float scale;
    
    vector<glm::vec3> * points;
};
