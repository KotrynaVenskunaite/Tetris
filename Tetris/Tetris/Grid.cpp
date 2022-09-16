#include "Grid.h"



Grid::Grid()
{
}


Grid::~Grid()
{
}

void Grid::draw(sf::RenderTarget& window) const
{
	window.draw(quads);
}

void Grid::walls()
{
	quads.clear();

	quads.setPrimitiveType(sf::LinesStrip);
	quads.resize(4);

	quads[0].position = sf::Vector2f(10.f, 10.f);
	quads[1].position = sf::Vector2f(10.f, 810.f);
	quads[2].position = sf::Vector2f(410.f, 810.f);
	quads[3].position = sf::Vector2f(410.f, 10.f);
}

bool Grid::fallen_T(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr)// int protectFromChange
{
	yRow = Fall_all;
	yRow -= 10;
	yRow = yRow / 40;
	yRow = 20 - yRow;
	yRow -= 1;

	if (r_nr == 0) {
		Position -= 1;
		if (Cubes[yRow][Position] == 1|| Cubes[yRow + 1][Position - 1] == 1 || Cubes[yRow + 1][Position + 1] == 1) {
			return 1;
		}
	}

	if (r_nr == 1) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow + 1][Position - 1] == 1) {
			return 1;
		}
	}

	if (r_nr == 2) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position - 1] == 1 || Cubes[yRow][Position + 1] == 1) {
			return 1;
		}
	}
	if (r_nr == 3) {
		if (Cubes[yRow][Position - 1] == 1 || Cubes[yRow + 1][Position] == 1) {
			return 1;
		}
	}
	 if (Fall_all == space_1) {
		return 1;
	}
}

bool Grid::fallen_S(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr)// int protectFromChange
{
	yRow = Fall_all;
	yRow -= 10;
	yRow = yRow / 40;
	yRow = 20 - yRow;
	yRow -= 1;
	//std::cout << Cubes[yRow][Position]<<" "<<Position << std::endl;
	//std::cout << yRow << std::endl;

	if (r_nr == 0) {
		Position -= 1;
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position + 1] == 1 || Cubes[yRow + 1][Position + 2] == 1) {
			return 1;
		}
	}
	if (r_nr == 1) {
		if (Cubes[yRow + 1][Position] == 1 || Cubes[yRow][Position + 1] == 1) {
			return 1;
		}
	}
	if (r_nr == 2) {
		if (Cubes[yRow ][Position + 1] == 1 || Cubes[yRow + 1][Position - 1] == 1 || Cubes[yRow + 1][Position+2] == 1) {
			return 1;
		}
	}
	if (r_nr == 3) {
		if (Cubes[yRow + 1][Position] == 1 || Cubes[yRow][Position + 1] == 1) {
			return 1;
		}
	}
	if (Fall_all == space_1) {
		return 1;
	}
}

bool Grid::fallen_Z(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr)
{
	yRow = Fall_all;
	yRow -= 10;
	yRow = yRow / 40;
	yRow = 20 - yRow;
	yRow -= 1;

	if (r_nr == 0) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position + 1] == 1 || Cubes[yRow + 1][Position - 1] == 1) {
			return 1;
		}
	}
	if (r_nr == 1) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow+1][Position + 1] == 1) {
			return 1;
		}
	}
	if (r_nr == 2) {
		Position += 1;
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position + 1] == 1 || Cubes[yRow + 1][Position - 1] == 1) {
			return 1;
		}
	}
	if (r_nr == 3) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow + 1][Position + 1] == 1) {
			return 1;
		}
	}
	if (Fall_all == space_1) {
		return 1;
	}
}

bool Grid::fallen_L(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr)
{
	yRow = Fall_all;
	yRow -= 10;
	yRow = yRow / 40;
	yRow = 20 - yRow;
	yRow -= 1;

	if (r_nr == 0) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position + 1] == 1 ) {
			return 1;
		}
	}
	if (r_nr == 1) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow + 1][Position + 1] == 1 || Cubes[yRow + 1][Position + 2] == 1) {
			return 1;
		}
	}
	if (r_nr == 2) {
		Position += 1;
		if (Cubes[yRow][Position] == 1 || Cubes[yRow+2][Position - 1] == 1 ) {
			return 1;
		}
	}
	if (r_nr == 3) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position + 1] == 1 || Cubes[yRow][Position - 1] == 1) {
			return 1;
		}
	}
	if (Fall_all == space_1) {
		return 1;
	}
}

bool Grid::fallen_J(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr)
{
	yRow = Fall_all;
	yRow -= 10;
	yRow = yRow / 40;
	yRow = 20 - yRow;
	yRow -= 1;

	if (r_nr == 0) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position - 1] == 1) {
			return 1;
		}
	}
	if (r_nr == 1) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position + 1] == 1 || Cubes[yRow][Position -1] == 1) {
			return 1;
		}
	}
	if (r_nr == 2) {
		Position -= 1;
		if (Cubes[yRow][Position] == 1 || Cubes[yRow + 2][Position + 1] == 1) {
			return 1;
		}
	}
	if (r_nr == 3) {
		Position -= 1; yRow += 1;
		if (Cubes[yRow][Position] == 1 || Cubes[yRow-1][Position + 1] == 1 || Cubes[yRow][Position - 1] == 1) {
			return 1;
		}
	}
	if (Fall_all == space_1) {
		return 1;
	}
}

bool Grid::fallen_I(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr)
{
	yRow = Fall_all;
	yRow -= 10;
	yRow = yRow / 40;
	yRow = 20 - yRow;
	yRow -= 1;

	if (r_nr == 0) {
		if (Cubes[yRow][Position] == 1 ) {
			return 1;
		}
	}
	if (r_nr == 1) {
		if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position + 1] == 1 || Cubes[yRow][Position + 2] == 1 || Cubes[yRow][Position - 1] == 1) {
			return 1;
		}
	}
	if (r_nr == 2) {
		Position += 1;
		if (Cubes[yRow][Position] == 1) {
			return 1;
		}
	}
	if (r_nr == 3) {
	 if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position + 1] == 1 || Cubes[yRow][Position + 2] == 1 || Cubes[yRow][Position - 1] == 1) {
		 return 1;
	 }
	}
	if (Fall_all == space_1){ return 1; } 
	
}

bool Grid::fallen_square(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow)
{
	yRow = Fall_all;
	yRow -= 10;
	yRow = yRow / 40;
	yRow = 20 - yRow;
	yRow -= 1;

	if (Cubes[yRow][Position] == 1 || Cubes[yRow][Position - 1] == 1) {
			return 1;
	}

	if (Fall_all == space_1) {
		return 1;
	}
}

void Grid::BlockCubes(int Cubes[][LineXMax])
{
	quads.setPrimitiveType(sf::Quads);
	int y = 770; int x = 10;

	for (int j = 0; j <= 19; j++) {
		for (int i = 0; i <= 9; i++)
		{
			if (Cubes[j][i] == 1)
			{
				quads.append(sf::Vector2f(x, y));
				quads.append(sf::Vector2f(x, y + 40));
				quads.append(sf::Vector2f(x + 40, y + 40));
				quads.append(sf::Vector2f(x + 40, y));
			}
			x += 40;
		}
		y -= 40; x = 10;
	}
}

void Grid::clear()
{
	quads.clear();
}