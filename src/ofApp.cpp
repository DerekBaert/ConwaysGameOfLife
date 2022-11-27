#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(4);
	ofSetBackgroundColor(255);
	rows = 50;
	columns = 50;

	gridWidth = width / columns;
	gridHeight = height / rows;
	RectangleSize cellSize{ gridHeight, gridWidth };
	
	for (int y = 0; y < rows; y++)
	{
		std::vector<Cell> row;
		row.reserve(columns);
		for (auto x = 0; x < columns; x++)
		{
			Coordinates cellPosition{ x * gridWidth, y * gridHeight };
			Cell cell{ cellPosition, cellSize };
			row.push_back(cell);
		}
		grid.push_back(row);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	toggleList.clear();
	if(start)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (grid[i][j].isAlive())
				{
					killCheck(i, j);
				}
				else
				{
					reviveCheck(i, j);
				}
			}
		}

		for(Intersection position : toggleList)
		{
			grid[position.row][position.column].deadAliveToggle();
		}
	}
}

void ofApp::killCheck(int row, int column)
{
	int liveNeighbours = checkNeighbours(row, column);

	if ((liveNeighbours < 2 || liveNeighbours > 3) && grid[row][column].isAlive())
	{
		Intersection cellPosition{ row,column };
		toggleList.push_back(cellPosition);
	}
}


void ofApp::reviveCheck(int row, int column)
{
	int liveNeighbours = checkNeighbours(row, column);

	if(liveNeighbours == 3 && !grid[row][column].isAlive())
	{
		Intersection cellPosition{ row,column };
		toggleList.push_back(cellPosition);
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
			liveNeighbours += grid[row - 1][column - 1].isAlive() ? 1 : 0;
		}

		// N
		liveNeighbours += grid[row - 1][column].isAlive() ? 1 : 0;

		// NE
		// Checking if there is a column to the east or if we are at the end.
		if (column + 1 < columns)
		{
			liveNeighbours += grid[row - 1][column + 1].isAlive() ? 1 : 0;
		}
	}	

	// W
	if (column - 1 >= 0)
	{
		liveNeighbours += grid[row][column - 1].isAlive() ? 1 : 0;
	}


	// E
	if (column + 1 < columns)
	{
		liveNeighbours += grid[row][column + 1].isAlive() ? 1 : 0;
	}

	// Check if there is a row below the cell
	if (row + 1 < rows)
	{
		// SW
		if (column - 1 >= 0)
		{
			liveNeighbours += grid[row + 1][column - 1].isAlive() ? 1 : 0;
		}

		// S
		liveNeighbours += grid[row + 1][column].isAlive() ? 1 : 0;

		// SE
		if (column + 1 < columns)
		{
			liveNeighbours += grid[row + 1][column + 1].isAlive() ? 1 : 0;
		}
	}

	return liveNeighbours;

}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (auto row : grid)
	{
		for (Cell cell : row)
		{
			ofSetColor(0, 0, 0);
			ofRectangle cellRect{ cell.getRectangle() };
			if (cell.isAlive())
			{
				ofFill();
			}
			else
			{
				ofNoFill();
			}
			cell.drawCell();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if(key == OF_KEY_RETURN)
	{
		start = !start;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	for (auto& row : grid)
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

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}
