#include "Cell.h"

#include "ofGraphics.h"

Cell::Cell(Coordinates coordinates, RectangleSize size) : mPosition{ coordinates }, mSize{ size }, mIsAlive{ false }
{
	mRectangle = { coordinates.x, coordinates.y, size.width, size.height };
}

void Cell::deadAliveToggle()
{
	mIsAlive = !mIsAlive;
}

void Cell::drawCell()
{
	ofDrawRectangle(mRectangle);
}

bool Cell::isAlive()
{
	return mIsAlive;
}

ofRectangle Cell::getRectangle()
{
	return mRectangle;
}
