#pragma once

#include "ofMain.h"
#include "Cell.h"
#include "Coordinates.h"
#include "RectangleSize.h"
#include "ofxCenteredTrueTypeFont.h"
#include "enum.h"
#include "generationManager.h"
#include "ofxGui.h"

// ofxTrueTypeFont: https://github.com/armadillu/ofxCenteredTrueTypeFont/blob/master/src/ofxCenteredTrueTypeFont.h
// Better Enums:	http://aantron.github.io/better-enums/

class ofApp : public ofBaseApp{

	public:
	/**
	 * \brief Creates GUI elements to be drawn on canvas.
	 */
	void createGui();
	/**
	 * \brief Sets up application.
	 */
	void setup();

	/**
	 * \brief Runs once per frame to update variables and determine next generation of cells.
	 */
	void update();

	/**
	 * \brief Draws elements to canvas.
	 */
	void draw();

	/**
	 * \brief Handles click event of mouse.
	 * \param x x position of mouse
	 * \param y y position of mouse
	 * \param button mouse button pressed
	 */
	void mousePressed(int x, int y, int button);

	/**
	 * \brief Handles the reset button being pressed. Resets the game with a blank grid at generation 1.
	 */
	void resetGame();

	/**
	 * \brief Handles the Play/Pause button being pressed. Starts the game after a seed has been set.
	 */
	void playPause();

	/**
	 * \brief Handles the Randomize/Reset button being pressed. Randomizes the cells on the screen.
	 */
	void randomizeCells();

	/**
	 * \brief Handles the Next Frame button being pressed. Draws a single frame to the canvas.
	 */
	void stepThrough();

	/**
	 * \brief Handles the Add Column/Reset button being pressed. Increases the column amount by 1.
	 */
	void incrementColumns();

	/**
	 * \brief Handles the Add Row/Reset button being pressed. Increases the row amount by 1.
	 */
	void incrementRows();

	/**
	 * \brief Handles the Remove Column/Reset button being pressed. Decreases the column amount by 1.
	 */
	void decrementColumns();

	/**
	 * \brief Handles the Remove Row/Reset button being pressed. Decreases the row amount by 1.
	 */
	void decrementRows();

		bool start = false;
		int columns = 50;
		int rows = 50;
		float width = ofGetWidth();
		float height = ofGetHeight() - 50;

		generationManager generationManager = { rows, columns, width, height };
		int generationCount = 1;

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
