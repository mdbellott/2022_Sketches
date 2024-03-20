#include "Particle_02_03.h"

Particle_02_03::Particle_02_03() {
    points = NULL;
}

void Particle_02_03::setPoints( vector <glm::vec3> * p ){
    points = p;
}

void Particle_02_03::reset() {
    uniqueVal = ofRandom(-10000, 10000);
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    pos.z = 0;
    
    vel.x = 0;
    vel.y = 0;
    vel.z = 0;
    
    frc = glm::vec3(0,0,0);
    scale = ofRandom(0.5, 1.0);
    
    drag  = ofRandom(0.25, 0.5);
}

void Particle_02_03::update() {
    float m = 0.01;
    float k = 0.01;
    float w = 0.25;
    
    float windX = ofSignedNoise(pos.x * m, pos.y * m, ofGetElapsedTimef());
    frc.x = windX * w + ofSignedNoise(uniqueVal, pos.y) * k;
    
    frc.y = ofSignedNoise(uniqueVal, pos.x, ofGetElapsedTimef()) * k;
    
    vel *= drag;
    vel += frc;
    
    if (pos.y + vel.y > ofGetHeight()) {
        pos.y -= ofGetHeight();
    }

    pos += vel;
    
    if (pos.x > ofGetWidth() + 50) {
        pos.x = ofGetWidth() + 50;
        vel.x *= -1.0;
    }else if (pos.x < -50) {
        pos.x = -50;
        vel.x *= -1.0;
    }
    if (pos.y > ofGetHeight() + 50) {
        pos.y = ofGetHeight() + 50;
        vel.y *= -1.0;
    }
    else if (pos.y < -50) {
        pos.y = -50;
        vel.y *= -1.0;
    }
}

void Particle_02_03::draw() {
    ofSetColor(255);
    ofDrawCircle(pos.x, pos.y, scale * 4);
}

