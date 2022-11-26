#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetBackgroundColor(255);
	rows = 5;
	columns = 5;

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
