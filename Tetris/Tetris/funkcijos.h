#include <SFML\Graphics.hpp>
#include<iostream>
#include "Block.h"
#include "Function.h"



void WayOfT(int r_nr, int Position, int Cubes[][LineXMax], int y)
{
	y += 1;
	if (r_nr == 0) {
		Cubes[y][Position - 1] = 1;
		Cubes[y + 1][Position - 2] = 1;
		Cubes[y + 1][Position - 1] = 1;
		Cubes[y + 1][Position] = 1;
	}
	if (r_nr == 1) {
		Cubes[y][Position] = 1;
		Cubes[y + 1][Position - 1] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 2][Position] = 1;
	}

	if (r_nr == 2) {
		Cubes[y][Position - 1] = 1;
		Cubes[y][Position] = 1;
		Cubes[y][Position + 1] = 1;
		Cubes[y + 1][Position] = 1;
	}

	if (r_nr == 3) {
		Cubes[y][Position - 1] = 1;
		Cubes[y + 1][Position - 1] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y+ 2][Position - 1] = 1;
	}
}

void WayOfS(int r_nr, int Position, int Cubes[][LineXMax], int y)
{
	y += 1;
	//Position -= 1;
	if (r_nr == 0) {
		Cubes[y][Position] = 1;
		Cubes[y][Position - 1] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 1][Position + 1] = 1;
	}
	if (r_nr == 1) {
		Cubes[y + 1][Position] = 1;
		Cubes[y + 2][Position] = 1;
		Cubes[y + 1][Position + 1] = 1;
		Cubes[y][Position + 1] = 1;
	}

	if (r_nr == 2) {
		Cubes[y][Position+1] = 1;
		Cubes[y][Position] = 1;
		Cubes[y + 1][Position+1] = 1;
		Cubes[y + 1][Position + 2] = 1;
	}

	if (r_nr == 3) {
		Cubes[y + 1][Position] = 1;
		Cubes[y + 2][Position] = 1;
		Cubes[y + 1][Position + 1] = 1;
		Cubes[y][Position + 1] = 1;
	}
}

void WayOfZ(int r_nr, int Position, int Cubes[][LineXMax], int y)
{
	y += 1;
	//Position -= 1;
	if (r_nr == 0) {
		Cubes[y][Position] = 1;
		Cubes[y ][Position + 1] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 1][Position -1] = 1;
	}
	if (r_nr == 1) {
		Cubes[y][Position] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 1][Position + 1] = 1;
		Cubes[y + 2][Position + 1] = 1;
	}

	if (r_nr == 2) {
		Position += 1;
		Cubes[y][Position] = 1;
		Cubes[y][Position + 1] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 1][Position - 1] = 1;
	}

	if (r_nr == 3) {
		Cubes[y][Position] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 1][Position + 1] = 1;
		Cubes[y + 2][Position + 1] = 1;
	}

}

void WayOfL(int r_nr, int Position, int Cubes[][LineXMax], int y)
{
	y += 1;
	if (r_nr == 0) {
		Cubes[y][Position] = 1;
		Cubes[y][Position + 1] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 2][Position] = 1;
	}
	if (r_nr == 1) {
		Cubes[y][Position] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 1][Position + 1] = 1;
		Cubes[y + 1][Position + 2] = 1;
	}

	if (r_nr == 2) {
		Position += 1;
		Cubes[y][Position] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 2][Position] = 1;
		Cubes[y + 2][Position - 1] = 1;
	}

	if (r_nr == 3) {
		Cubes[y][Position] = 1;
		Cubes[y][Position - 1] = 1;
		Cubes[y][Position + 1] = 1;
		Cubes[y + 1][Position + 1] = 1;
	}
}

void WayOfJ(int r_nr, int Position, int Cubes[][LineXMax], int y)
{
	y += 1;
	if (r_nr == 0) {
		Cubes[y][Position] = 1;
		Cubes[y][Position - 1] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 2][Position] = 1;
	}
	if (r_nr == 1) {
		Cubes[y][Position] = 1;
		Cubes[y][Position + 1] = 1;
		Cubes[y][Position - 1] = 1;
		Cubes[y + 1][Position - 1] = 1;
	}

	if (r_nr == 2) {
		Position -= 1;
		Cubes[y][Position] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 2][Position] = 1;
		Cubes[y + 2][Position + 1] = 1;
	}

	if (r_nr == 3) {
		Position -= 1; y -= 1;
		Cubes[y+1][Position] = 1;
		Cubes[y+1][Position - 1] = 1;
		Cubes[y+1][Position + 1] = 1;
		Cubes[y][Position + 1] = 1;
	}
}

void WayOfI(int r_nr, int Position, int Cubes[][LineXMax], int y)
{
	y += 1;
	if (r_nr == 0 ) {
		Cubes[y][Position] = 1;
		Cubes[y+1][Position] = 1;
		Cubes[y+2][Position] = 1;
		Cubes[y+3][Position] = 1;
	}
	if (r_nr == 1) {
		Cubes[y][Position] = 1;
		Cubes[y][Position - 1] = 1;
		Cubes[y][Position + 1] = 1;
		Cubes[y][Position + 2] = 1;
	}

	if (r_nr == 2) {
		Position += 1;
		Cubes[y][Position] = 1;
		Cubes[y + 1][Position] = 1;
		Cubes[y + 2][Position] = 1;
		Cubes[y + 3][Position] = 1;
	}

	if (r_nr == 3) {
		Cubes[y][Position] = 1;
		Cubes[y][Position - 1] = 1;
		Cubes[y][Position + 1] = 1;
		Cubes[y][Position + 2] = 1;
	}
}

void WayOfSquare(int Position, int Cubes[][LineXMax], int y)
{
	y += 1;
	Position -= 1;
	Cubes[y][Position] = 1;
	Cubes[y][Position + 1] = 1;
	Cubes[y + 1][Position] = 1;
	Cubes[y + 1][Position + 1] = 1;
}

bool IsLineFull(int Cubes[][LineXMax])
{
	int FullLineCount = 0;

	for (int j = 0; j <= 19; j++) {
		for (int i = 0; i <= 9; i++)
		{
			if (Cubes[j][i] == 1)
				FullLineCount++;
		}
		if (FullLineCount == 10) {
			newLineOrder(Cubes, j);
			return 1;
		}
		FullLineCount = 0;
	}
}

void newLineOrder(int Cubes[][LineXMax],int ClearedLineNR)
{
	for (int k = ClearedLineNR; k <= 19; k++) {
		for (int i = 0; i <= 9; i++) {
			Cubes[k][i] = Cubes[k + 1][i];
		}
	}
}

bool IsBlockOnLeft_T(int Cubes[][LineXMax], int y, int Position, int r_nr )
{
	if (r_nr == 0) {
		Position -= 2;
		if (Cubes[y + 1][Position - 1] == 1)
			return 1;
		else if (Cubes[y][Position] == 1)
			return 1;
	}
	if (r_nr == 1) {
		
		Position -= 1;
		if (Cubes[y + 1][Position - 1] == 1)
			return 1;
		else if (Cubes[y][Position] == 1)
			return 1;
	}

	if (r_nr == 2) {
		Position -= 1;
		if (Cubes[y + 1][Position] == 1)
			return 1;
		else if (Cubes[y][Position - 1] == 1)
			return 1;
	}

	if (r_nr == 3) {
		Position -= 1;
		if (Cubes[y + 1][Position] == 1)
			return 1;
		else if (Cubes[y][Position] == 1)
			return 1;
	}
}

bool IsBlockOnRight_T(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y + 1][Position + 1] == 1)
			return 1;
		else if (Cubes[y][Position] == 1)
			return 1;
	}
	if (r_nr == 1) {
		y += 1;
		if (Cubes[y - 1][Position + 1] == 1)
			return 1;
		else if (Cubes[y][Position + 1] == 1)
			return 1;
		else if (Cubes[y + 1][Position + 1] == 1)
			return 1;
	}

	if (r_nr == 2) {
		Position += 1;
		if (Cubes[y + 1][Position] == 1)
			return 1;
		else if (Cubes[y][Position + 1] == 1)
			return 1;
	}

	if (r_nr == 3) {
		Position += 1;
		if (Cubes[y + 1][Position] == 1)
			return 1;
		else if (Cubes[y][Position] == 1)
			return 1;
	}
}

bool IsBlockOnRight_S(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position + 1] == 1 || Cubes[y + 1][Position + 2] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y][Position + 2] == 1 || Cubes[y+1][Position + 2] == 1|| Cubes[y + 3][Position + 1] == 1)
			return 1;
	}

	if (r_nr == 2) {
		if (Cubes[y-1][Position + 1] == 1 || Cubes[y][Position + 2] == 1)
			return 1;
	}

	if (r_nr == 3) {
		if (Cubes[y][Position + 2] == 1 || Cubes[y+1][Position + 2] == 1|| Cubes[y + 3][Position + 1] == 1)
			return 1;
	}
}

bool IsBlockOnLeft_S(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		Position -= 2;
		if (Cubes[y + 1][Position - 1] == 1)
			return 1;
		else if (Cubes[y][Position] == 1)
			return 1;
	}
	if (r_nr == 1) {

		Position -= 1;
		if (Cubes[y + 1][Position - 1] == 1)
			return 1;
		else if (Cubes[y][Position] == 1)
			return 1;
	}

	if (r_nr == 2) {
		Position -= 1;
		if (Cubes[y + 1][Position] == 1)
			return 1;
		else if (Cubes[y][Position - 1] == 1)
			return 1;
	}

	if (r_nr == 3) {
		Position -= 1;
		if (Cubes[y + 1][Position] == 1)
			return 1;
		else if (Cubes[y][Position] == 1)
			return 1;
	}
}

bool IsBlockOnRight_Z(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position + 2] == 1 || Cubes[y + 1][Position + 1] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y][Position + 1] == 1 || Cubes[y + 1][Position + 2] == 1 || Cubes[y + 2][Position + 2] == 1)
			return 1;
	}

	if (r_nr == 2) {
		Position += 1;
		if (Cubes[y][Position + 2] == 1 || Cubes[y + 1][Position + 1] == 1)
			return 1;
	}

	if (r_nr == 3) {
		if (Cubes[y][Position + 1] == 1 || Cubes[y + 1][Position + 2] == 1 || Cubes[y + 2][Position + 2] == 1)
			return 1;
	}
}

bool IsBlockOnLeft_Z(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position - 1] == 1 || Cubes[y + 1][Position - 2] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y][Position - 1] == 1 || Cubes[y + 1][Position - 1] == 1 || Cubes[y + 2][Position] == 1)
			return 1;
	}

	if (r_nr == 2) {
		Position += 1;
		if (Cubes[y][Position - 1] == 1 || Cubes[y + 1][Position - 2] == 1)
			return 1;
	}

	if (r_nr == 3) {
		if (Cubes[y][Position - 1] == 1 || Cubes[y + 1][Position - 1] == 1 || Cubes[y + 2][Position] == 1)
			return 1;
	}
}

bool IsBlockOnLeft_L(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position - 1] == 1 || Cubes[y+1][Position-1] == 1 || Cubes[y + 2][Position - 1] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y][Position - 1 ] == 1 || Cubes[y+1][Position - 1] == 1)
			return 1;
	}

	if (r_nr == 2) {
		Position += 1;
		if (Cubes[y][Position - 1] == 1 || Cubes[y + 1][Position - 1] == 1 || Cubes[y + 2][Position - 2] == 1)
			return 1;
	}

	if (r_nr == 3) {
		if (Cubes[y][Position - 2] == 1 )
			return 1;
	}
}

bool IsBlockOnRight_L(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position + 2] == 1 || Cubes[y + 1][Position + 1] == 1 || Cubes[y + 2][Position + 1] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y+1][Position + 3] == 1 || Cubes[y][Position + 1] == 1)
			return 1;
	}

	if (r_nr == 2) {
		if (Cubes[y][Position + 2] == 1 || Cubes[y + 1][Position + 2] == 1 || Cubes[y + 2][Position + 2] == 1)
			return 1;
	}

	if (r_nr == 3) {
		if (Cubes[y][Position + 2] == 1 || Cubes[y+1][Position + 2] == 1 || Cubes[y + 2][Position + 2] == 1)
			return 1;
	}
}

bool IsBlockOnLeft_J(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position - 2] == 1 || Cubes[y + 1][Position - 1] == 1 || Cubes[y + 2][Position - 1 ] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y][Position - 2] == 1 || Cubes[y + 1][Position - 2] == 1)
			return 1;
	}
	if (r_nr == 2) {
		if (Cubes[y][Position - 2] == 1 || Cubes[y + 1][Position - 2] == 1 || Cubes[y + 2][Position - 2] == 1)
			return 1;
	}
	if (r_nr == 3) {
		if (Cubes[y - 1][Position - 1] == 1 || Cubes[y][Position-3] == 1)
			return 1;
	}
}

bool IsBlockOnRight_J(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position + 1] == 1 || Cubes[y + 1][Position + 1] == 1 || Cubes[y + 2][Position + 1] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y][Position + 2] == 1 || Cubes[y][Position + 1] == 1)
			return 1;
	}

	if (r_nr == 2) {
		if (Cubes[y][Position] == 1 || Cubes[y + 1][Position] == 1 || Cubes[y + 2][Position + 1] == 1)
			return 1;
	}

	if (r_nr == 3) {
		if (Cubes[y][Position + 1 ] == 1 || Cubes[y -1 ][Position + 1] == 1)
			return 1;
	}
}

bool IsBlockOnLeft_I(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position - 1] == 1 || Cubes[y + 1][Position - 1] == 1 || Cubes[y + 2][Position - 1] == 1 || Cubes[y + 3][Position - 1] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y][Position - 2] == 1 )
			return 1;
	}
	if (r_nr == 2) {
		Position += 1;
		if (Cubes[y][Position - 1] == 1 || Cubes[y + 1][Position - 1] == 1 || Cubes[y + 2][Position - 1] == 1 || Cubes[y + 3][Position - 1] == 1)
			return 1;
	}
	if (r_nr == 3) {
		y -= 1;
		if (Cubes[y][Position - 2] == 1)
			return 1;
	}
}

bool IsBlockOnRight_I(int Cubes[][LineXMax], int y, int Position, int r_nr)
{
	if (r_nr == 0) {
		if (Cubes[y][Position + 1] == 1 || Cubes[y + 1][Position + 1] == 1 || Cubes[y + 2][Position + 1] == 1 || Cubes[y + 3][Position + 1] == 1)
			return 1;
	}
	if (r_nr == 1) {
		if (Cubes[y][Position + 3] == 1 )
			return 1;
	}

	if (r_nr == 2) {
		Position += 1;
		if (Cubes[y][Position + 1] == 1 || Cubes[y + 1][Position + 1] == 1 || Cubes[y + 2][Position + 1] == 1 || Cubes[y + 3][Position + 1] == 1)
			return 1;
	}

	if (r_nr == 3) {
		y -= 1;
		if (Cubes[y][Position + 3] == 1)
			return 1;
	}
}

bool IsBlockOnLeft_square(int Cubes[][LineXMax], int y, int Position)
{
	if (Cubes[y][Position - 2] == 1 || Cubes[y + 1][Position - 2] == 1 )
		return 1;
}

bool IsBlockOnRight_square(int Cubes[][LineXMax], int y, int Position)
{
	if (Cubes[y][Position + 1] == 1 || Cubes[y + 1][Position + 1] == 1)
		return 1;
}

bool GameOver(int Cubes[][LineXMax])
{
	for (int i = 0; i <= 9; i++)
	{
		if (Cubes[20][i] == 1)
		{
			return 1;
		}
	}
}

void CalculateScore(int & ClearedLines, int & Score)
{
	if (ClearedLines == 1) {Score += 40;}
	if (ClearedLines == 2) {Score += 100;}
	if (ClearedLines == 3) {Score += 300;}
	if (ClearedLines == 4) {Score += 1200;}
	ClearedLines = 0;
}





