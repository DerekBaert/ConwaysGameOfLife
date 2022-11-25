#include "Cell.h"

Cell::Cell(Coordinates coordinates, RectangleSize size) : mPosition{ coordinates }, mSize{ size }, mIsAlive{ false }
{}

void Cell::deadAliveToggle()
{
	mIsAlive = !mIsAlive;
}

bool Cell::isAlive()
{
	return mIsAlive;
}
