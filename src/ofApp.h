#pragma once

#include "ofMain.h"
#include "Cell.h"
#include "Coordinates.h"
#include "RectangleSize.h"
#include "ofxCenteredTrueTypeFont.h"
#include "enum.h"
#include "generationManager.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void createGui();
		void setup();
		void determineNextGeneration();
		void displayError(std::string message);
		void update();
		void draw();
		void mousePressed(int x, int y, int button);;
		void resetGame();
		void playPause();
		void randomizeCells();
		void stepThrough();
		void incrementColumns();
		void incrementRows();
		void decrementColumns();
		void decrementRows();

		int columns = 50;
		int rows = 50;
		float width = ofGetWidth();
		float height = ofGetHeight() - 50;
		generationManager generationManager = { rows, columns, width, height };

		int generationCount = 1;

		bool start = false;
		ofxCenteredTrueTypeFont generation;
	
		ofxSlider<int> frameSlider;
		ofxColorSlider colorSlider;
		ofColor cellColor;

		ofxButton reset;
		ofxButton play;
		ofxButton randomize;
		ofxButton nextFrame;
		ofxButton addColumn;
		ofxButton addRow;
		ofxButton removeColumn;
		ofxButton removeRow;
		std::vector< std::vector<ofxButton>> buttons;
};
