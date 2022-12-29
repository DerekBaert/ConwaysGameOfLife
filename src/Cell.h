#pragma once
#include "ofRectangle.h"
#include "Coordinates.h"
#include "RectangleSize.h"
#include "enum.h"
#include "ofColor.h"

BETTER_ENUM(State, int, Alive, Dead);

class Cell
{
	Coordinates mPosition;
	RectangleSize mSize;
	ofRectangle mRectangle;
	State status;

public:
	/**
	 * \brief Creates cell to be drawn to canvas
	 * \param coordinates Location to draw cell
	 * \param size Size of cell
	 */
	Cell(Coordinates coordinates, RectangleSize size);

	/**
	 * \brief Toggles the cell between dead and alive states
	 */
	void deadAliveToggle();

	/**
	 * \brief Draws the cell to the canvas
	 * \param color Color to draw the cell
	 */
	void drawCell(ofColor color) const;

	/**
	 * \brief Gets the state of the cell
	 * \return True if cell is alive, false if not.
	 */
	bool isAlive();

	/**
	 * \brief Gets the rectangle being drawn to the canvas.
	 * \return ofRectangle being drawn to the canvas.
	 */
	ofRectangle getRectangle() const;

	/**
	 * \brief Resets the cell to default state (dead)
	 */
	void reset();

};

