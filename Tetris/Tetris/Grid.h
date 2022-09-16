#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Grid
{
private:
	sf::VertexArray quads;

	float space_1 = 810; //floor/bottom bounds

	const static int LineXMax = 10; //number of x positions


public:
	Grid();
	~Grid();

	virtual void draw(sf::RenderTarget& target) const;

	bool fallen_T(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr);
	bool fallen_S(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr);
	bool fallen_Z(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr);
	bool fallen_L(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr);
	bool fallen_J(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr);
	bool fallen_I(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow, int r_nr);
	bool fallen_square(int Cubes[][LineXMax], int Fall_all, int Position, int & yRow);
	void BlockCubes(int Cubes[][LineXMax]);//draws cubes on the screen
	void clear();
	void walls();

};

