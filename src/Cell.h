#pragma once
#include "ofRectangle.h"
#include "Coordinates.h"
#include "RectangleSize.h"

class Cell
{
	Coordinates mPosition;
	RectangleSize mSize;
	ofRectangle mRectangle;
	bool mIsAlive;

public:
	Cell(Coordinates coordinates, RectangleSize size);

	void deadAliveToggle();
	bool isAlive();
};

