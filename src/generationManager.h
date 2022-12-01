#pragma once
#include "Cell.h"
#include "ofxSliderGroup.h"

class generationManager
{
	std::vector<std::vector<Cell>> currentGen;
	std::vector<std::vector<Cell>> nextGen;
	int mRows;
	int mColumns;
public:
	generationManager(int rows, int columns, float width, float height);
	int checkNeighbours(int row, int column);
	void killCheck(int row, int column);
	void reviveCheck(int row, int column);
	void determineNextGeneration();
	void drawGrid(ofColor cellColor);
	void mouseClicked(int x, int y);
	void reset();
	void randomize();

private:
	bool mouseInBounds(float x, float y, float width, float height, int mouseX, int mouseY);
};

