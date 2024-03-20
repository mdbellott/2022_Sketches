#include "Scratch.h"

//--------------------------------------------------------------
void Scratch::setup(){
    wavesMovie.load("videos/waves_low.mov");

    ofSetWindowShape(wavesMovie.getWidth()*2, wavesMovie.getHeight());
    ofBackground(255);
    dt = 0.0;
    
    setupVideo();
}

//--------------------------------------------------------------
void Scratch::setupVideo() {
    wavesMovie.setLoopState(OF_LOOP_NORMAL);
    wavesMovie.play();
    
    videoInverted.allocate(wavesMovie.getWidth(), wavesMovie.getHeight(), OF_PIXELS_RGB);
    videoTexture.allocate(videoInverted);
    videoTexture1.allocate(videoInverted);
    videoTexture2.allocate(videoInverted);
    videoTexture3.allocate(videoInverted);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void Scratch::update(){
    ofBackground(255);
    wavesMovie.update();

    if(wavesMovie.isFrameNew()){
        dt += 1.0;
        
        ofPixels & pixels = wavesMovie.getPixels();
        
        for(size_t i = 0; i < pixels.size(); i++){
            //invert the color of the pixel
            float s = sin(dt * TWO_PI);
            videoInverted[pixels.size() - i - 1] = pixels[i];
        }
        videoTexture.loadData(videoInverted);
        
        videoTexture1.loadData(videoInverted);
        for(size_t i = 0; i < pixels.size(); i++){
            //invert the color of the pixel
            float s = sin(dt * TWO_PI);
            videoInverted[i] = 255 - pixels[i] + dt;
        }
        videoTexture1.loadData(videoInverted);
        
        for(size_t i = 0; i < pixels.size(); i++){
            //invert the color of the pixel
            float s = sin(dt * TWO_PI);
            videoInverted[pixels.size() - i - 1] = 255 - pixels[i] + dt;
        }
        videoTexture2.loadData(videoInverted);
        
        for(size_t i = 0; i < pixels.size(); i++){
            //invert the color of the pixel
            float s = 10*sin(dt * TWO_PI);
            videoInverted[i] = 255 - pixels[i] + s;
        }
        videoTexture3.loadData(videoInverted);
    }
}

//--------------------------------------------------------------
void Scratch::draw(){
    
    ofSetHexColor(0xFFFFFF);
    
//    ofRotateDeg(90, 0.0, 0.0, 1.0);
//    wavesMovie.draw(0, -2160/4, 3840/4, 2160/4);
//    videoTexture.draw(0, -2160/2, 3840/4, 2160/4);
    videoTexture.draw(0, 0, wavesMovie.getWidth(), wavesMovie.getHeight()/2);
    videoTexture1.draw(0, wavesMovie.getHeight()/2, wavesMovie.getWidth(), wavesMovie.getHeight()/2);
    videoTexture2.draw(wavesMovie.getWidth(), 0, wavesMovie.getWidth(), wavesMovie.getHeight()/2);
    videoTexture3.draw(wavesMovie.getWidth(), wavesMovie.getHeight()/2, wavesMovie.getWidth(), wavesMovie.getHeight()/2);
    
//    ofPixels & pixels = wavesMovie.getPixels();
    
//    if (vidGrabber.isFrameNew()){
//        int totalPixels = camWidth*camHeight*3;
//        unsigned char * pixels = vidGrabber.getPixels();
//        for (int i = 0; i < totalPixels; i++){
//            videoInverted[i] = 255 - pixels[i];
//        }
//        texture.loadData(videoInverted, camWidth,camHeight, GL_RGB);
//    }
}

//void Scratch::setupShapes() {
//    n = 10;
//
//    float w = ofGetWidth()/n;
//    float h = (ofGetHeight()/n)/2;
//
//    for (int i=0-n; i<n*4; i++) {
//        for (int j=0-n; j<n*4; j++) {
//
//            float x = (i * w) + w/2;
//            float y = (j * h) + h/2;
//
//            float inc = 0.2;
//
//            shapes.push_back(ScratchShape(glm::vec2(x, y),
//                                   w,
//                                   inc + (i*0.001) + (j*0.005),
//                                   0,
//                                   h,
//                                   i%2 == 0));
//        }
//    }
//}
//
////--------------------------------------------------------------
//void Scratch::update(){
//    for(unsigned int i = 0; i < shapes.size(); i++){
//        shapes[i].update();
//    }
//}
//
////--------------------------------------------------------------
//void Scratch::draw(){
//    for(unsigned int i = 0; i < shapes.size(); i++){
//        shapes[i].draw();
//    }
//}

//--------------------------------------------------------------
void Scratch::keyPressed(int key){

}

//--------------------------------------------------------------
void Scratch::keyReleased(int key){

}

//--------------------------------------------------------------
void Scratch::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Scratch::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Scratch::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Scratch::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Scratch::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Scratch::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Scratch::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Scratch::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Scratch::dragEvent(ofDragInfo dragInfo){

}
