#include "Particle_02_06.h"

Particle_02_06::Particle_02_06() {
    points = NULL;
}

void Particle_02_06::setPoints( vector <glm::vec3> * p ){
    points = p;
}

void Particle_02_06::reset() {
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

void Particle_02_06::update() {
    float m = 0.005;
    float k = 0.005;
    float w = 0.25;
    float d = 0.5;
    
    float wind = ofSignedNoise(pos.x * m, pos.y * m, ofGetElapsedTimef());
    frc.x = d * wind * w + ofSignedNoise(uniqueVal, pos.y) * k;
    
    frc.y =  -d * wind * w + ofSignedNoise(uniqueVal * pos.y * m, pos.x * m, ofGetElapsedTimef()) * k;
    
    vel *= drag;
    vel += frc;
    
    if (pos.y + vel.y > ofGetHeight()) {
        pos.y -= ofGetHeight();
    }

    pos += vel;
    
    int lim = 50;
    if (pos.x > ofGetWidth() + lim) {
        pos.x = ofGetWidth() + lim;
        vel.x *= -1.0;
    }else if (pos.x < -lim) {
        pos.x = -lim;
        vel.x *= -1.0;
    }
    if (pos.y > ofGetHeight() + lim) {
        pos.y = ofGetHeight() + lim;
        vel.y *= -1.0;
    }
    else if (pos.y < -lim) {
        pos.y = -lim;
        vel.y *= -1.0;
    }
}

void Particle_02_06::draw() {
    ofSetColor(255);
    ofDrawCircle(pos.x, pos.y, scale * 4);
}

