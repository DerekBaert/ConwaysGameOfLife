#pragma once

#include "ofMain.h"
#include "Cell.h"
#include "Coordinates.h"
#include "RectangleSize.h"
#include "ofxCenteredTrueTypeFont.h"
#include "enum.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void killCheck(int row, int column);
		void reviveCheck(int row, int column);
		int  checkNeighbours(int row, int column);
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);;

		/**
		 * \brief Checks if the mouse is over the given cell
		 * \param x X coordinate of cell
		 * \param y Y coordinate of cell
		 * \param width Width of cell
		 * \param height Height of cell
		 * \return 
		 */
		bool mouseInBounds(float x, float y, float width, float height);

		std::vector<std::vector<Cell>> currentGen;
		std::vector<std::vector<Cell>> nextGen;

		int columns{};
		int rows{};
		int generationCount;
		int headerBuffer;

		float width = ofGetWidth();
		float height = ofGetHeight() - 50;
		float gridWidth;
		float gridHeight;
		bool start = false;
		ofxCenteredTrueTypeFont generation;
	
		ofxSlider<int> frameSlider;
		ofxColorSlider colorSlider;
};
