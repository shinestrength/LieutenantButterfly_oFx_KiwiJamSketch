#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    game_state = "title";
    splatLimit = 50;
    
    paint1.loadImage("images/paint1B.png");
    paint2.loadImage("images/paint2B.png");
    
    cam.setDistance(1000);
    ofSetFrameRate(60);
    
    ofHideCursor();
    ofEnableAlphaBlending();
    ofDisableAntiAliasing();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetBackgroundAuto(false);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
     lerpValue = ofSignedNoise(ofGetElapsedTimef());
    
    
    // Show the LerpValue;
    
   // string str = "lerpValue is ";
   // str += ofToString(lerpValue, 2)+"fps";
   // ofSetWindowTitle(str);

    
    
    if(game_state == "start"){
        
        //ofSetWindowShape(mouseX, 200);
        
        
    }
    
    else if (game_state == "step1"){
        
        
        
    }

    else if (game_state == "step2"){
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //_____________________________________________________________________START STEP
    
    //ofTriangle(50,10,10,40,mouseX,mouseY);
    
    if(game_state == "title"){
        
        
        //Draw Butterfly Symbol (1px, staticBG)
        
       ofBackgroundGradient(ofColor::pink,ofColor::seaShell);

       // ofSetBackgroundAuto(true);
        ofSetLineWidth(1);
        ofSetColor(76,34,98);
        ofNoFill();
        
        ofPushMatrix();
        
        float angle = ofGetElapsedTimef();
       // ofRotate(angle);
        
        ofTriangle(ofGetWidth()/2,ofGetWindowHeight()/2,(ofGetWidth()/2)-mouseX, (ofGetWindowHeight()/2)+mouseX,(ofGetWidth()/2)-mouseX, (ofGetWindowHeight()/2)-mouseX);
        ofTriangle(ofGetWidth()/2,ofGetWindowHeight()/2,(ofGetWidth()/2)+mouseX, (ofGetWindowHeight()/2)+mouseX,(ofGetWidth()/2)+mouseX, (ofGetWindowHeight()/2)-mouseX);
        
        ofPopMatrix();
        
    
        
        
        
        
    }
    
    if(game_state == "start"){
        
        
      //  ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
        
      //  ofBackgroundGradient(ofColor::pink,ofColor::seaShell);
        screenGrab.draw(ofGetScreenWidth()/2,ofGetScreenHeight()/2);
       
        
        
        
        
        
        
        
        
     //   ofSetColor((int)ofRandom(0,mouseX),(int)ofRandom(0,mouseY),(int)ofRandom(0,255),255*lerpValue);
        
        for(int i = 0; i < splatLimit; i++){
            ofSetColor((int)ofRandom(25,255),(int)ofRandom(78,255),(int)ofRandom(128,255),128);
            paint1.draw(ofRandom(-500,500),ofRandom(-500,500));
            paint2.draw(ofRandom(0,1000),ofRandom(0,1000));
            
            
            
        }
        
        
        screenGrab.draw(ofGetScreenWidth()/2,ofGetScreenHeight()/2);
        
        ofSetColor((int)ofRandom(0,mouseX),(int)ofRandom(0,mouseY),(int)ofRandom(0,255),25);
        
        ofScale(0.9*ofGetScreenWidth() ,0.9*ofGetScreenHeight());
        ofRect(0, 0, lerpValue*2000, lerpValue*700);
        ofRect(100, 0, lerpValue*2000, lerpValue*700);
        ofRect(200, 0, lerpValue*2000, lerpValue*700);
        ofRect(300, 0, lerpValue*2000, lerpValue*700);
        ofRect(400, 0, lerpValue*2000, lerpValue*700);
        ofRect(500, 0, lerpValue*2000, lerpValue*700);
        ofRect(600, 0, lerpValue*2000, lerpValue*700);
        
        
       
        
    }
    
    
    //_____________________________________________________________________STEP 1
    
    else if (game_state == "step1"){
        
      //  ofBackgroundGradient(ofColor::pink,ofColor::seaShell);
        
        //ofRect(0, 0, 0, 200, 200);
       ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
        //screenGrab.resize(0.9 * screenGrab.width, 0.9 *screenGrab.height);
        screenGrab.draw(mouseX,mouseY);
        //screenGrab.setCompression(OF_COMPRESS_SRGB);
        
        
    }
    
    
    //_____________________________________________________________________STEP 2
    
    else if (game_state == "step2"){
        
        //ofBackgroundGradient(ofColor::pink,ofColor::seaShell);
       
        ofSetColor((int)ofRandom(0,mouseX),(int)ofRandom(0,mouseY),(int)ofRandom(0,255),25);
        
        screenGrab.draw(mouseX-512,mouseY-512);
        
        ofRect(0, 0, lerpValue*2000, lerpValue*700);
        ofRect(0, 100, lerpValue*2000, lerpValue*700);
        ofRect(0, 200, lerpValue*2000, lerpValue*700);
        ofRect(0, 300, lerpValue*2000, lerpValue*700);
        ofRect(0, 400, lerpValue*2000, lerpValue*700);
        ofRect(0, 500, lerpValue*2000, lerpValue*700);
        ofRect(0, 600, lerpValue*2000, lerpValue*700);

       
        
        
        
    }

    
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    screenGrab.setAnchorPoint(screenGrab.getWidth()/2, screenGrab.getHeight()/2);
    screenGrab.grabScreen(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
    screenGrab.resize(0.9 * screenGrab.width, 0.9 *screenGrab.height);
    //screenGrab.saveImage("images/testImage.bmp");
    
    screenGrab.setCompression(OF_COMPRESS_SRGB);
    ofSaveFrame();
    
   // ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    
    
    for (int i = 0; i < screenGrab.width; i++){
        for (int j = 0; j <screenGrab.height; j++) {
            
            if (screenGrab.getColor(i,j) != ofColor(25, 128, 128)){
                screenGrab.setColor(i, j, ofColor(64,ofRandom(0,255),ofRandom(0,255)));
            }
            
        }
        
    }

    
    
    
    
    
    
    
    //ofSaveFrame();
   // ofSaveScreen("screen.bmp");
    
    
    //switch gamestate on mouse down
    
    
    if(game_state == "title")
    {game_state = "start";}
    
    if(game_state == "start")
    {game_state = "step1";}
    
    else if(game_state == "step1")
    {game_state = "step2";}
    
    else if(game_state == "step2")
    {game_state = "title";}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
