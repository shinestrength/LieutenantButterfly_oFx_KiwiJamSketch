#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    string game_state;
    int splatLimit;
    
    //Assets
    
    ofImage paint1;
    ofImage paint2;
    ofImage screenGrab;
    
    ofEasyCam cam;
    
    ofColor pixelColor;
    
    float lerpValue;
		
};
