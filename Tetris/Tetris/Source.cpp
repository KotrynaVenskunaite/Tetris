#include <SFML\Graphics.hpp>
#include<iostream>
#include <string>
#include<cstdlib>
#include "Block.h"
#include "Grid.h"
#include "Function.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Tetris");
	
	sf::Text GuideW, GuideA, GuideS, GuideD, Score, Stext;  
	sf::Font font;
	if (!font.loadFromFile("Fonts/PressStart2P-Regular.ttf"))
		throw("No FONT FOUND");
	GuideW.setFont(font); GuideA.setFont(font); GuideS.setFont(font); GuideD.setFont(font); Score.setFont(font); Stext.setFont(font);                                                
	GuideW.setCharacterSize(30); GuideA.setCharacterSize(30); GuideS.setCharacterSize(30); GuideD.setCharacterSize(30); Score.setCharacterSize(30); Stext.setCharacterSize(30);
	GuideW.setString("Rotate W"); GuideA.setString("Move Left A"); GuideS.setString("Move Down S"); GuideD.setString("Move Right D"); Stext.setString("Score ");
	Stext.setPosition(500, 30); Score.setPosition(750, 30); GuideA.setPosition(470, 200); GuideD.setPosition(470, 250); GuideW.setPosition(470, 350); GuideS.setPosition(470, 300);
	//Created a text, set its font, size and position
	
	sf::Clock clock;
	sf::Time elapsed;
	
	Block block(1);  //Block entity
	Grid grid;       //Grid (walls)
	Grid fallen;     //Fallen block entity

	grid.walls();
	block.Tetrimino_T(); //base block

	//T=0
	//S=1
	//Z=2
	//L=3
	//J=4
	//I=5
	//square = 6

	int Cubes[LineYMax][LineXMax];      //Fallen Blocks that show on screen
	int r_nr = 0, hasTheBlockFallen = 0;//rotation number and the name of the next one
	int r_nrPLUS;                       //rotation number + 1
	int random = 0;                     //random number/next block
	int matrixNumber = 0;               //coordinate sheet number
	int yRow = 0;
	int TetrisScore = 0;
	int LinesCleared;
	int WasLineCleared = 0;
	double Seconds = 1;
	double MakeTimeFaster = 0;
	int mistake = 0;                    //fix a small mistake bc idk how else to do it
	std::string ConvertToText;

	int Position = 5; //x axis position
	int fall_all = 10; //base info for block position, fall all is the position on the y axis

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			
			
			//--------------------------------------------------------
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::D)
				{
					//move blocks and stop moving when they hit a wall
					if (random == 0) 
					{
						if (block.T_collision_R(r_nr) == 1)
							break;
						if (IsBlockOnRight_T(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_T_right(r_nr);
						
					}
					if (random == 1) {
						
						if (block.S_collision_R(r_nr) == 1)
							break;
						if (IsBlockOnRight_S(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_S_right(r_nr);
					}
					if (random == 2) {
						if (block.Z_collision_R(r_nr) == 1)
							break;
						if (IsBlockOnRight_Z(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_Z_right(r_nr);
					}
					if (random == 3) {
						if (block.L_collision_R(r_nr) == 1)
							break;
						if (IsBlockOnRight_L(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_L_J_right(r_nr);
					}
					if (random == 4) {
						if (block.J_collision_R(r_nr) == 1)
							break;
						if (IsBlockOnRight_J(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_L_J_right(r_nr);
					}
					if (random == 5)
					{
						if (block.square_collision_right() == 1)
							break;
						if (IsBlockOnRight_square(Cubes, yRow, Position) == 1)
							break;
						block.move_square_right();
					}
					if (random == 6) {
						if (block.I_collision_R(r_nr) == 1)
							break;
						if (IsBlockOnRight_I(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_I_right(r_nr);
					}

					//change position when moved
					Position++;
				}
				//------------------------
				if (event.key.code == sf::Keyboard::A)
				{
					if (random == 0)
					{
						if (block.T_collision_L(r_nr) == 1)
							break;
						if (IsBlockOnLeft_T(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_T_left(r_nr);
						
					}
					if (random == 1)
					{
						if (block.S_collision_L(r_nr) == 1)
							break;
						if (IsBlockOnLeft_S(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_S_left(r_nr);
					}
					if (random == 2)
					{
						if (block.Z_collision_L(r_nr) == 1)
							break;
						if (IsBlockOnLeft_Z(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_Z_left(r_nr);
					}
					if (random == 3)
					{
						if (block.L_collision_L(r_nr) == 1)
							break;
						if (IsBlockOnLeft_L(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_L_J_left(r_nr);
					}
					if (random == 4)
					{
						if (block.J_collision_L(r_nr) == 1)
							break;
						if (IsBlockOnLeft_J(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_L_J_left(r_nr);
					}
					if (random == 5)
					{
						if (block.square_collision_left() == 1)
							break;
						if (IsBlockOnLeft_square(Cubes, yRow, Position) == 1)
							break;
						block.move_square_left();
					}
					if (random == 6)
					{
						if (block.I_collision_L(r_nr) == 1)
							break;
						if (IsBlockOnLeft_I(Cubes, yRow, Position, r_nr) == 1)
							break;
						block.move_I_left(r_nr);
					}
					Position--;
				}
				//-------------------------
				if (event.key.code == sf::Keyboard::W)
				{
					//check if rotated there will be collision, if yes, don't rotate
					r_nrPLUS = r_nr + 1;
					if (r_nrPLUS == 4) {
						r_nrPLUS = 0;
					}

					//rotate that block
					if (random == 0) {
						if (fallen.fallen_T(Cubes, fall_all, Position, yRow, r_nrPLUS) == 1 || IsBlockOnLeft_T(Cubes, yRow, Position, r_nr) == 1 || IsBlockOnRight_T(Cubes, yRow, Position, r_nr) == 1)
							break;
					}
					if (random == 1) {
						if (fallen.fallen_S(Cubes, fall_all, Position, yRow, r_nrPLUS) == 1 || IsBlockOnLeft_S(Cubes, yRow, Position, r_nr) == 1 || IsBlockOnRight_S(Cubes, yRow, Position, r_nr) == 1)
							break;
					} 
					if (random == 2) {
						if (fallen.fallen_Z(Cubes, fall_all, Position, yRow, r_nrPLUS) == 1 || IsBlockOnLeft_Z(Cubes, yRow, Position, r_nr) == 1 || IsBlockOnRight_Z(Cubes, yRow, Position, r_nr) == 1)
							break;
					}
					if (random == 3) {
						if (fallen.fallen_L(Cubes, fall_all, Position, yRow, r_nrPLUS) == 1 || IsBlockOnLeft_L(Cubes, yRow, Position, r_nr) == 1 || IsBlockOnRight_L(Cubes, yRow, Position, r_nr) == 1)
							break;
					}
					if (random == 4) {
						if (fallen.fallen_J(Cubes, fall_all, Position, yRow, r_nrPLUS) == 1 || IsBlockOnLeft_J(Cubes, yRow, Position, r_nr) == 1 || IsBlockOnRight_J(Cubes, yRow, Position, r_nr) == 1)
							break;
					}
					if (random == 6) {
						if (fallen.fallen_I(Cubes, fall_all, Position, yRow, r_nrPLUS) == 1 || IsBlockOnLeft_I(Cubes, yRow, Position, r_nr) == 1 || IsBlockOnRight_I(Cubes, yRow, Position, r_nr) == 1)
							break;
					}

					//update rotation number
					r_nr++;
					if (r_nr == 4) {
						r_nr = 0;
						if(random == 0 || random == 1|| random == 2)
							fall_all -= 40;
					}

					//update fall all
					if (random == 0 || random == 1 || random == 2)
					{
						if (r_nr == 3) {
							fall_all += 40;
						}
					}
					if (random == 3 || random == 4) {
						if(r_nr==2)
						fall_all += 40;
						if (r_nr == 3)
							fall_all -= 40;
					}
					if (random == 6) {
						if (r_nr == 1) {fall_all -= 80;}
						if (r_nr == 2) {fall_all += 80;}
						if (r_nr == 3) { fall_all -= 40; }
						if (r_nr == 0) { fall_all += 40; }
					}

					//adjust block when rotated
					block.rotate(matrixNumber, random);
					if (random == 0) { block.T_adjust(r_nr, Position); }
					if (random == 1) { block.S_adjust(r_nr); }
					if (random == 2) { block.Z_adjust(r_nr, Position); }
					if (random == 3) { block.L_adjust(r_nr, Position); }
					if (random == 4) { block.J_adjust(r_nr, Position); }
					if (random == 6) { block.I_adjust(r_nr, Position); }
					
				}
				if (event.key.code == sf::Keyboard::S)
				{
					//make blocks fall
					if (random == 0)
					{
						if (fallen.fallen_T(Cubes, fall_all, Position, yRow, r_nr) == 1)
							break;
						block.fall_T(r_nr, fall_all);
					}
					if (random == 1)
					{
						if (fallen.fallen_S(Cubes, fall_all, Position, yRow, r_nr) == 1)
							break;
						block.fall_S(r_nr, fall_all);
					}
					if (random == 2)
					{
						if (fallen.fallen_Z(Cubes, fall_all, Position, yRow, r_nr) == 1)
							break;
						block.fall_Z(r_nr, fall_all);
					}
					if (random == 3)
					{
						if (fallen.fallen_L(Cubes, fall_all, Position, yRow, r_nr) == 1) { break; }
						block.fall_L(r_nr, fall_all);
					}
					if (random == 4)
					{
						if (fallen.fallen_J(Cubes, fall_all, Position, yRow, r_nr) == 1)
							break;
						block.fall_L(r_nr, fall_all);
					}
					if (random == 5)
					{
						if (fallen.fallen_square(Cubes, fall_all, Position, yRow) == 1)
							break;
						block.fall_square(fall_all);
					}
					if (random == 6)
					{
						if (fallen.fallen_I(Cubes, fall_all, Position, yRow, r_nr) == 1)
							break;
						block.fall_I(r_nr, fall_all);
					}
				}

				if (event.key.code == sf::Keyboard::Escape || GameOver(Cubes) == 1)
				{
					exit(0);
				}

			}

			//--------------------------------------------------------
		}
	
		//Time
		//Just Time

		elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() >= Seconds - MakeTimeFaster)  //update the game when time passes
		{
			//checks if a block has fallen, then randomises the next block, cleares lines if there are any and calculates how many where cleared
			if (random == 0)
			{
				if (fallen.fallen_T(Cubes, fall_all, Position, yRow, r_nr) == 1)
				{
					WayOfT(r_nr, Position, Cubes, yRow);
					Position = 5; fall_all = 10;
					for (int i = 0; i <= 4; i++)
					{   
						if (IsLineFull(Cubes) == 1) //clear all lines, tetris or less
						{
							LinesCleared++;
							WasLineCleared = 1;
						}
					}
					fallen.clear();
					fallen.BlockCubes(Cubes);
					block.clear();
					block.reset(r_nr);
					matrixNumber++;
					random = 0;
					block.Tetrimino_T();
					hasTheBlockFallen = 1;
					random = rand() % 7;
					if (random == 0) { block.Tetrimino_T(); Position = 5; }
					if (random == 1) { block.Tetrimino_S(); Position = 4; }
					if (random == 2) { block.Tetrimino_Z(); Position = 4; }
					if (random == 3) { block.Tetrimino_L(); Position = 4; }
					if (random == 4) { block.Tetrimino_J(); Position = 4; }
					if (random == 5) { block.Tetrimino_square(); Position = 4; }
					if (random == 6) { block.Tetrimino_I(); Position = 4; }
				}
				if (hasTheBlockFallen == 0) {
					block.fall_T(r_nr, fall_all);
				}
			}
			if (random == 1)
			{
				if (fallen.fallen_S(Cubes, fall_all, Position, yRow, r_nr) == 1)
				{
					if (mistake == 1) { Position -= 1; mistake = 0; }
					WayOfS(r_nr, Position, Cubes, yRow);
					Position = 4; fall_all = 10;
					for (int i = 0; i <= 4; i++)
					{
						if (IsLineFull(Cubes) == 1) //clear all lines, tetris or less
						{
							LinesCleared++;
							WasLineCleared = 1;
						}
					}
					fallen.clear();
					fallen.BlockCubes(Cubes);
					block.clear();
					block.reset(r_nr);
					matrixNumber++;
					random = 1;
					block.Tetrimino_T();
					hasTheBlockFallen = 1;
					random = rand() % 7;
					if (random == 0) { block.Tetrimino_T(); Position = 5; }
					if (random == 1) { block.Tetrimino_S(); Position = 4; }
					if (random == 2) { block.Tetrimino_Z(); Position = 4; }
					if (random == 3) { block.Tetrimino_L(); Position = 4; }
					if (random == 4) { block.Tetrimino_J(); Position = 4; }
					if (random == 5) { block.Tetrimino_square(); Position = 4; }
					if (random == 6) { block.Tetrimino_I(); Position = 4; }
				}
				if (hasTheBlockFallen == 0) {
					block.fall_S(r_nr, fall_all);
				}
			}
			if (random == 2)
			{
				if (fallen.fallen_Z(Cubes, fall_all, Position, yRow, r_nr) == 1)
				{
					if (mistake == 1) { Position -= 1; mistake = 0; }
					WayOfZ(r_nr, Position, Cubes, yRow);
					Position = 4; fall_all = 10;
					for (int i = 0; i <= 4; i++)
					{
						if (IsLineFull(Cubes) == 1) //clear all lines, tetris or less
						{
							LinesCleared++;
							WasLineCleared = 1;
						}
					}

					fallen.clear();
					fallen.BlockCubes(Cubes);
					block.clear();
					block.reset(r_nr);
					matrixNumber++;
					random = 2;
					block.Tetrimino_Z();
					hasTheBlockFallen = 1;
					random = rand() % 7;
					if (random == 0) { block.Tetrimino_T(); Position = 5; }
					if (random == 1) { block.Tetrimino_S(); Position = 4; }
					if (random == 2) { block.Tetrimino_Z(); Position = 4; }
					if (random == 3) { block.Tetrimino_L(); Position = 4; }
					if (random == 4) { block.Tetrimino_J(); Position = 4; }
					if (random == 5) { block.Tetrimino_square(); Position = 4; }
					if (random == 6) { block.Tetrimino_I(); Position = 4; }
				}
				if (hasTheBlockFallen == 0) {
					block.fall_Z(r_nr, fall_all);
				}
			}
			if (random == 3)
			{
				if (fallen.fallen_L(Cubes, fall_all, Position, yRow, r_nr) == 1)
				{
					WayOfL(r_nr, Position, Cubes, yRow);
					Position = 4; fall_all = 10;
					for (int i = 0; i <= 4; i++)
					{
						if (IsLineFull(Cubes) == 1) //clear all lines, tetris or less
						{
							LinesCleared++;
							WasLineCleared = 1;
						}
					}

					fallen.clear();
					fallen.BlockCubes(Cubes);
					block.clear();
					block.reset(r_nr);
					matrixNumber++;
					random = 3;
					block.Tetrimino_L();
					hasTheBlockFallen = 1;
					random = rand() % 7;
					if (random == 0) { block.Tetrimino_T(); Position = 5; }
					if (random == 1) { block.Tetrimino_S(); Position = 4; }
					if (random == 2) { block.Tetrimino_Z(); Position = 4; }
					if (random == 3) { block.Tetrimino_L(); Position = 4; }
					if (random == 4) { block.Tetrimino_J(); Position = 4; }
					if (random == 5) { block.Tetrimino_square(); Position = 4; }
					if (random == 6) { block.Tetrimino_I(); Position = 4; }
				}

				if (hasTheBlockFallen == 0) {
					block.fall_L(r_nr, fall_all);
				}
				
			}
			if (random == 4)
			{
				if (fallen.fallen_J(Cubes, fall_all, Position, yRow, r_nr) == 1)
				{
					WayOfJ(r_nr, Position, Cubes, yRow);
					Position = 4; fall_all = 10;
					for (int i = 0; i <= 4; i++)
					{
						if (IsLineFull(Cubes) == 1) //clear all lines, tetris or less
						{
							LinesCleared++;
							WasLineCleared = 1;
						}
					}

					fallen.clear();
					fallen.BlockCubes(Cubes);
					block.clear();
					block.reset(r_nr);
					matrixNumber++;
					random = 4;
					block.Tetrimino_J();
					hasTheBlockFallen = 1;
					random = rand() % 7;
					if (random == 0) { block.Tetrimino_T(); Position = 5; }
					if (random == 1) { block.Tetrimino_S(); Position = 4; }
					if (random == 2) { block.Tetrimino_Z(); Position = 4; }
					if (random == 3) { block.Tetrimino_L(); Position = 4; }
					if (random == 4) { block.Tetrimino_J(); Position = 4; }
					if (random == 5) { block.Tetrimino_square(); Position = 4; }
					if (random == 6) { block.Tetrimino_I(); Position = 4; }
				}
				if (hasTheBlockFallen == 0) {
					block.fall_L(r_nr, fall_all);
				}
			}
			if (random == 5)
			{
				if (fallen.fallen_square(Cubes, fall_all, Position, yRow) == 1)
				{
					WayOfSquare(Position, Cubes, yRow);
					Position = 4; fall_all = 10;
					for (int i = 0; i <= 4; i++)
					{
						if (IsLineFull(Cubes) == 1) //clear all lines, tetris or less
						{
							LinesCleared++;
							WasLineCleared = 1;
						}
					}
					fallen.clear();
					fallen.BlockCubes(Cubes);
					block.clear();
					block.reset(r_nr);
					matrixNumber++;
					random = 5;
					block.Tetrimino_square();
					hasTheBlockFallen = 1;
					random = rand() % 7;
					if (random == 0) { block.Tetrimino_T(); Position = 5; }
					if (random == 1) { block.Tetrimino_S(); Position = 4; }
					if (random == 2) { block.Tetrimino_Z(); Position = 4; }
					if (random == 3) { block.Tetrimino_L(); Position = 4; }
					if (random == 4) { block.Tetrimino_J(); Position = 4; }
					if (random == 5) { block.Tetrimino_square(); Position = 4; }
					if (random == 6) { block.Tetrimino_I(); Position = 4; }
				}
				if (hasTheBlockFallen == 0) {
					block.fall_square(fall_all);
				}
			}
			if (random == 6)
			{
				if (fallen.fallen_I(Cubes, fall_all, Position, yRow, r_nr) == 1)
				{
					WayOfI(r_nr, Position, Cubes, yRow);
					Position = 4; fall_all = 10;
					for (int i = 0; i <= 4; i++)
					{
						if (IsLineFull(Cubes) == 1) //clear all lines, tetris or less
						{
							LinesCleared++;
							WasLineCleared = 1;
						}
					}

					fallen.clear();
					fallen.BlockCubes(Cubes);
					block.clear();
					block.reset(r_nr);
					matrixNumber++;
					random = 6;
					block.Tetrimino_I();
					hasTheBlockFallen = 1;
					random = rand() % 7;
					if (random == 0) { block.Tetrimino_T(); Position = 5; }
					if (random == 1) { block.Tetrimino_S(); Position = 4; }
					if (random == 2) { block.Tetrimino_Z(); Position = 4; }
					if (random == 3) { block.Tetrimino_L(); Position = 4; }
					if (random == 4) { block.Tetrimino_J(); Position = 4; }
					if (random == 5) { block.Tetrimino_square(); Position = 4; }
					if (random == 6) { block.Tetrimino_I(); Position = 4; }
				}
				if (hasTheBlockFallen == 0) {
					block.fall_I(r_nr, fall_all);
				}
			}
			
			hasTheBlockFallen = 0;
			clock.restart();
		}
		//make time faster if line was cleared
		if (WasLineCleared == 1) { MakeTimeFaster += 0.01; WasLineCleared = 0;}
		CalculateScore(LinesCleared, TetrisScore);
		ConvertToText = std::to_string(TetrisScore);
		Score.setString(ConvertToText);
		
		//draws everything on screen
		window.clear();
		block.draw(window, matrixNumber);
		fallen.draw(window);
		grid.draw(window);
		window.draw(GuideW);
		window.draw(GuideA);
		window.draw(GuideS);
		window.draw(GuideD);
		window.draw(Stext);
		window.draw(Score);
		window.display();

		
	}
	return 0;
}