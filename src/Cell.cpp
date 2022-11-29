#include "Cell.h"

#include "ofGraphics.h"

Cell::Cell(Coordinates coordinates, RectangleSize size) : mPosition{ coordinates }, mSize{ size }, status{ State::Dead }
{
	mRectangle = { coordinates.x, coordinates.y, size.width, size.height };
}

void Cell::deadAliveToggle()
{
	switch (status)
	{
	case State::Alive:
		status = State::Dead;
		break;
	case State::Dead:
		status = State::Alive;
		break;
	default:
		break;
	}
}

void Cell::drawCell(ofColor color)
{

	ofSetColor(color); // Fill color
	ofDrawRectangle(mRectangle);

	ofNoFill();
	ofSetColor(0); // contour (stroke) color  
	ofDrawRectangle(mRectangle);
}

bool Cell::isAlive()
{
	bool isAlive;
	switch(status)
	{
		case State::Alive:
			isAlive = true;
			break;
		case State::Dead:
			isAlive = false;
			break;
		default:
			break;
	}
	return isAlive;
}

ofRectangle Cell::getRectangle()
{
	return mRectangle;
}
