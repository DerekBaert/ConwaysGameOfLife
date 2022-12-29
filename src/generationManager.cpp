#include "generationManager.h"

generationManager::generationManager(int rows, int columns, float width, float height) : mRows{rows}, mColumns{columns}
{
	// Setting amount of rows and columns;
	int headerBuffer = 50;
	// int generationCount = 1;
	float gridWidth = width / columns;
	float gridHeight = height / rows;
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

int generationManager::checkNeighbours(int row, int column)
{
	int liveNeighbours = 0;

	// Check if there is a row above the cell
	if (row - 1 >= 0)
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
		if (column + 1 < mColumns)
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
	if (column + 1 < mColumns)
	{
		liveNeighbours += currentGen[row][column + 1].isAlive() ? 1 : 0;
	}

	// Check if there is a row below the cell
	if (row + 1 < mRows)
	{
		// SW
		if (column - 1 >= 0)
		{
			liveNeighbours += currentGen[row + 1][column - 1].isAlive() ? 1 : 0;
		}

		// S
		liveNeighbours += currentGen[row + 1][column].isAlive() ? 1 : 0;

		// SE
		if (column + 1 < mColumns)
		{
			liveNeighbours += currentGen[row + 1][column + 1].isAlive() ? 1 : 0;
		}
	}

	return liveNeighbours;
}

void generationManager::killCheck(int row, int column)
{
	int liveNeighbours = checkNeighbours(row, column);

	if ((liveNeighbours < 2 || liveNeighbours > 3) && currentGen[row][column].isAlive())
	{
		nextGen[row][column].deadAliveToggle();
	}
}

void generationManager::reviveCheck(int row, int column)
{
	int liveNeighbours = checkNeighbours(row, column);

	if (liveNeighbours == 3 && !currentGen[row][column].isAlive())
	{
		nextGen[row][column].deadAliveToggle();
	}
}

void generationManager::determineNextGeneration()
{
	nextGen = currentGen;
	for (int i = 0; i < mRows; i++)
	{
		for (int j = 0; j < mColumns; j++)
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
	currentGen = nextGen;
}

void generationManager::drawGrid(const ofColor& cellColor) const
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
			cell.drawCell(cellColor);
		}
	}
	ofSetColor(0);
}

void generationManager::mouseClicked(int x, int y)
{
	for (auto& row : currentGen)
	{
		for (Cell& cell : row)
		{
			ofRectangle cellRect{ cell.getRectangle() };
			if (mouseInBounds(cellRect.x, cellRect.y, cellRect.width, cellRect.height, x, y))
			{
				cell.deadAliveToggle();
				break;
			}
		}
	}
}

void generationManager::reset()
{
	for (auto& row : currentGen)
	{
		for (Cell& cell : row)
		{
			cell.reset();
		}
	}
}

void generationManager::randomize()
{
	for (auto& row : currentGen)
	{
		for (Cell& cell : row)
		{
			cell.reset();
			if (ofRandom(100) < 30)
			{
				cell.deadAliveToggle();
			}
		}
	}
}

bool generationManager::mouseInBounds(float x, float y, float width, float height, int mouseX, int mouseY)
{
	return mouseX > x && mouseX < (x + width) && mouseY > y && mouseY < (y + height);
}
