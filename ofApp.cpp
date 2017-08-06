#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	this->noise_source = ofRandom(10);
	this->noise_step = 0.02;
}

//--------------------------------------------------------------
void ofApp::update(){
	this->noise_source += noise_step;
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float tmp_noise_source = this->noise_source;
	float color_valiue;
	float color_step = 255.f / 360.f;

	for (int i = 10; i > 0; i--) {
		float len = i * 50;
		float deg_noise = ofNoise(tmp_noise_source) * 360;
		tmp_noise_source += this->noise_step;
		color_valiue = 0;

		for (int deg = 0; deg < 360; deg += 10) {
			float x = len * cos((deg + deg_noise) * DEG_TO_RAD);
			float y = len * sin((deg + deg_noise) * DEG_TO_RAD);

			ofColor c;
			c.setHsb((deg * color_step), 255, 255);
			ofSetColor(c);

			ofEllipse(ofVec3f(x, y, 0), 10 + i * 3, 10 + i * 3);
		}
	}

	this->cam.end();
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
