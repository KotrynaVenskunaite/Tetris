#pragma once

using namespace std;
const static int LineXMax = 10;
const static int LineYMax = 20;
//calculates where each block has fallen
void WayOfT(int r_nr, int Position, int Cubes[][LineXMax], int y);
void WayOfS(int r_nr, int Position, int Cubes[][LineXMax], int y);
void WayOfZ(int r_nr, int Position, int Cubes[][LineXMax], int y);
void WayOfL(int r_nr, int Position, int Cubes[][LineXMax], int y);
void WayOfJ(int r_nr, int Position, int Cubes[][LineXMax], int y);
void WayOfI(int r_nr, int Position, int Cubes[][LineXMax], int y);
void WayOfSquare(int Position, int Cubes[][LineXMax], int y);
bool IsBlockOnLeft_T(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnRight_T(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnLeft_S(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnRight_S(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnLeft_Z(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnRight_Z(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnLeft_L(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnRight_L(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnLeft_J(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnRight_J(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnLeft_I(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnRight_I(int Cubes[][LineXMax], int y, int Position, int r_nr);
bool IsBlockOnLeft_square(int Cubes[][LineXMax], int y, int Position);
bool IsBlockOnRight_square(int Cubes[][LineXMax], int y, int Position);
bool IsLineFull(int Cubes[][LineXMax]);
void newLineOrder(int Cubes[][LineXMax], int j);
bool GameOver(int Cubes[][LineXMax]);
void CalculateScore(int & ClearedLines, int & Score);