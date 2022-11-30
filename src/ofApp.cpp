#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup()
{	
	ofSetBackgroundColor(255);

	createGui();

	generateGrid();
}

//--------------------------------------------------------------
void ofApp::update()
{
	ofSetFrameRate(frameSlider);
	nextGen = currentGen;
	if(start)
	{
		determineNextGeneration();
	}
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	generation.drawStringCentered("Generation: " + std::to_string(generationCount), 75, 20);
	frameSlider.draw();
	colorSlider.draw();

	// Draw buttons
	for (auto& row : buttons)
	{
		for (ofxButton& button : row)
		{
			button.draw();
		}
	}

	drawGrid();
}

void ofApp::killCheck(int row, int column)
{
	int liveNeighbours = checkNeighbours(row, column);

	if ((liveNeighbours < 2 || liveNeighbours > 3) && currentGen[row][column].isAlive())
	{
		nextGen[row][column].deadAliveToggle();
	}
}


void ofApp::reviveCheck(int row, int column)
{
	int liveNeighbours = checkNeighbours(row, column);

	if(liveNeighbours == 3 && !currentGen[row][column].isAlive())
	{
		nextGen[row][column].deadAliveToggle();
	}
}

int ofApp::checkNeighbours(int row, int column)
{
	int liveNeighbours = 0;

	// Check if there is a row above the cell
	if(row - 1 >= 0)
	{
		// NW
		// Checking if there is a column to the west or if we are at the beginning
		if (column - 1 >= 0)
		{
			liveNeighbours += currentGen[row - 1][column - 1].isAlive() ? 1 : 0;
		}

		// N
		liveNeighbours += currentGen[row - 1][column].isAlive() ? 1 : 0;

		// NE
		// Checking if there is a column to the east or if we are at the end.
		if (column + 1 < columns)
		{
			liveNeighbours += currentGen[row - 1][column + 1].isAlive() ? 1 : 0;
		}
	}	

	// W
	if (column - 1 >= 0)
	{
		liveNeighbours += currentGen[row][column - 1].isAlive() ? 1 : 0;
	}


	// E
	if (column + 1 < columns)
	{
		liveNeighbours += currentGen[row][column + 1].isAlive() ? 1 : 0;
	}

	// Check if there is a row below the cell
	if (row + 1 < rows)
	{
		// SW
		if (column - 1 >= 0)
		{
			liveNeighbours += currentGen[row + 1][column - 1].isAlive() ? 1 : 0;
		}

		// S
		liveNeighbours += currentGen[row + 1][column].isAlive() ? 1 : 0;

		// SE
		if (column + 1 < columns)
		{
			liveNeighbours += currentGen[row + 1][column + 1].isAlive() ? 1 : 0;
		}
	}

	return liveNeighbours;

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	for (auto& row : currentGen)
	{
		for(Cell& cell : row)
		{
			ofRectangle cellRect{ cell.getRectangle() };
			if (mouseInBounds(cellRect.x, cellRect.y, cellRect.width, cellRect.height))
			{
				cell.deadAliveToggle();
				break;
			}
		}
	}
}

bool ofApp::mouseInBounds(float x, float y, float width, float height)
{
	return ofGetMouseX() > x && ofGetMouseX() < (x + width) && ofGetMouseY() > y && ofGetMouseY() < (y + height);
}

void ofApp::resetGame()
{
	for (auto& row : currentGen)
	{
		for (Cell& cell : row)
		{
			cell.reset();
		}
	}
	generationCount = 1;
}

void ofApp::playPause()
{
	start = !start;
}

void ofApp::randomizeCells()
{
	for (auto& row : currentGen)
	{
		for (Cell& cell : row)
		{
			cell.reset();
			if(ofRandom(100) < 30)
			{
				cell.deadAliveToggle();
			}
		}
	}
	generationCount = 1;
}

void ofApp::stepThrough()
{
	start = false;
	determineNextGeneration();
	drawGrid();
}
void ofApp::incrementColumns()
{
	start = false;
	resetGame();
	columns++;
	generateGrid();
	drawGrid();
}
void ofApp::incrementRows()
{
	start = false;
	resetGame();
	columns++;
	generateGrid();
	drawGrid();
}
void ofApp::decrementColumns()
{
	start = false;
	resetGame();
	columns++;
	generateGrid();
	drawGrid();
}
void ofApp::decrementRows()
{
	start = false;
	resetGame();
	columns++;
	generateGrid();
	drawGrid();
}

void ofApp::generateGrid()
{
	// Setting amount of rows and columns;
	headerBuffer = 50;
	generationCount = 1;
	gridWidth = width / columns;
	gridHeight = height / rows;
	RectangleSize cellSize{ gridHeight, gridWidth };

	currentGen.clear();
	for (int y = 0; y < rows; y++)
	{
		std::vector<Cell> row;
		row.reserve(columns);
		for (int x = 0; x < columns; x++)
		{
			Coordinates cellPosition{ x * gridWidth, (y * gridHeight) + headerBuffer };
			Cell cell{ cellPosition, cellSize };
			row.push_back(cell);
		}
		currentGen.push_back(row);
	}
}

void ofApp::createGui()
{
	// Creating and setting up sliders
	frameSlider.setup("Frame rate: ", 1, 1, 4, 125, 15);
	frameSlider.setPosition(width - (frameSlider.getWidth() + 10), 5);
	colorSlider.setup("Cell Color", ofColor(50, 50, 50), ofColor(0, 0), ofColor(200, 200));
	colorSlider.setWidthElements(125);
	colorSlider.setPosition(width - (colorSlider.getWidth() + 10), 25);

	int buttonWidth = 175;
	int buttonHeight = 15;

	// Setting up buttons
	play.addListener(this, &ofApp::playPause);
	play.setup("Play/Pause", buttonWidth, buttonHeight);

	reset.addListener(this, &ofApp::resetGame);
	reset.setup("Reset", buttonWidth, buttonHeight);

	randomize.addListener(this, &ofApp::randomizeCells);
	randomize.setup("Randomize/Reset", buttonWidth, buttonHeight);

	nextFrame.addListener(this, &ofApp::stepThrough);
	nextFrame.setup("Next Frame", buttonWidth, buttonHeight);

	addColumn.addListener(this, &ofApp::incrementColumns);
	addColumn.setup("Add  Column/Reset", buttonWidth, buttonHeight);

	addRow.addListener(this, &ofApp::incrementRows);
	addRow.setup("Add Row/Reset", buttonWidth, buttonHeight);

	removeColumn.addListener(this, &ofApp::decrementColumns);
	removeColumn.setup("Remove Column/Reset", buttonWidth, buttonHeight);

	removeRow.addListener(this, &ofApp::decrementRows);
	removeRow.setup("Remove Row/Reset", buttonWidth, buttonHeight);

	// Placing buttons in array to loop through for setting position and color
	buttons.push_back({play,randomize,addColumn,removeColumn});
	buttons.push_back({ reset,nextFrame,addRow, removeRow });

	int y = 5;
	for(auto& row : buttons)
	{
		int x = 175;
		for(ofxButton& button:  row)
		{
			button.setPosition(x, y);
			button.setBackgroundColor(255);
			button.setBorderColor(0);
			button.setTextColor(0);

			x += 176;
		}
		y += 20;
	}
	generation.load("pixel2.ttf", 15);
}

void ofApp::drawGrid()
{
	for (auto row : currentGen)
	{
		for (Cell cell : row)
		{
			ofRectangle cellRect{ cell.getRectangle() };
			if (cell.isAlive())
			{
				ofFill();
			}
			else
			{
				ofNoFill();
			}
			cell.drawCell(colorSlider);
		}
	}
	ofSetColor(0);
}

void ofApp::determineNextGeneration()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (currentGen[i][j].isAlive())
			{
				killCheck(i, j);
			}
			else
			{
				reviveCheck(i, j);
			}
		}
	}
	generationCount++;
	currentGen = nextGen;
}

void ofApp::displayError(std::string message)
{
	ofDrawBitmapString(message, 200, 5);
}