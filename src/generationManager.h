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
	/**
	 * \brief Initializes a manager for the collection of cells being displayed to the screen.
	 * \param rows Amount of rows to draw
	 * \param columns Amount of Columns to draw
	 * \param width Width of canvas
	 * \param height Height of canvas
	 */
	generationManager(int rows, int columns, float width, float height);

	/**
	 * \brief Checks the neighbours of the cell in the given row and column and returns how many are alive.
	 * \param row Row of cell to check
	 * \param column Column of cell to check
	 * \return Amount of live cells
	 */
	int checkNeighbours(int row, int column);

	/**
	 * \brief Checks if an alive cell needs to be killed
	 * \param row Row of cell to check
	 * \param column Column of cell to check
	 */
	void killCheck(int row, int column);

	/**
	 * \brief Checks if a dead cell needs to be brought back to life
	 * \param row Row of cell to check
	 * \param column Column of cell to check
	 */
	void reviveCheck(int row, int column);

	/**
	 * \brief Calculates the next generation of cells and creates a new collection for them.
	 */
	void determineNextGeneration();

	/**
	 * \brief Draws collection of cells to the grid.
	 * \param cellColor Color to fill the cells
	 */
	void drawGrid(ofColor cellColor);

	/**
	 * \brief Checks each cell to see if mouse clicked the particular cell.
	 * \param x X position of mouse
	 * \param y Y position of mouse
	 */
	void mouseClicked(int x, int y);

	/**
	 * \brief Resets collection of cells to their default (dead) state
	 */
	 void reset();

	/**
	 * \brief Randomizes the state of the cells in the collection.
	 */
	void randomize();

private:
	/**
	 * \brief Checks if the mouse is in bounds for the given cell.
	 * \param x X position of cell
	 * \param y Y position of cell
	 * \param width Width of cell
	 * \param height Height of cell
	 * \param mouseX X position of mouse
	 * \param mouseY Y position of mouse
	 * \return True if mouse is in cell bounds, false if not.
	 */
	bool mouseInBounds(float x, float y, float width, float height, int mouseX, int mouseY);
};

