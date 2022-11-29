#pragma once
#include "ofRectangle.h"
#include "Coordinates.h"
#include "RectangleSize.h"
#include "enum.h"

BETTER_ENUM(State, int, Alive, Dead);

class Cell
{
	Coordinates mPosition;
	RectangleSize mSize;
	ofRectangle mRectangle;
	State status;

public:
	Cell(Coordinates coordinates, RectangleSize size);

	/// <summary>
	/// Getters
	/// </summary>
	void deadAliveToggle();
	void drawCell();

	/// <summary>
	/// Getters
	/// </summary>
	bool isAlive();
	ofRectangle getRectangle();
	

};

