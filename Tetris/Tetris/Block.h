#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>



class Block : public sf::Transformable
{

private:
	sf::VertexArray quads;
	sf::Transform transform[10000]; // <-- pro gamer move (200 iq)
	
	//coordinates of blocks
	int x, y,
		x1, y1,
		x2, y2,
		x3, y3;

	//bounds of walls and other measurments for rotation
	int xx = 410,
		yy = 10,
		ri = 0,
		li = 0,
		fi = 0;
	    
	
	

public:
	Block(float number);
	~Block();
	
	virtual void draw(sf::RenderTarget& target, int matrixNumber) const;
	
	void rotate(int matrixNumber, int random);
	void reset(int & r_nr);
	
	void Tetrimino_J();
	bool J_collision_R(int r_nr);
	bool J_collision_L(int r_nr);
	void J_adjust(int r_nr, int& position);

	void Tetrimino_S();
	void move_S_left(int r_nr);
	void move_S_right(int r_nr);
	bool S_collision_R(int r_nr);
	bool S_collision_L(int r_nr);
	void S_adjust(int r_nr);

	void Tetrimino_Z();
	void move_Z_left(int r_nr);
	void move_Z_right(int r_nr);
	bool Z_collision_R(int r_nr);
	bool Z_collision_L(int r_nr);
	void Z_adjust(int r_nr, int & position);

	void Tetrimino_I();
	void move_I_left(int r_nr);
	void move_I_right(int r_nr);
	bool I_collision_R(int r_nr);
	bool I_collision_L(int r_nr);
	void I_adjust(int r_nr, int & position);

	void Tetrimino_T();
	void move_T_left(int r_nr);
	void move_T_right(int r_nr);
	bool T_collision_R(int r_nr);
	bool T_collision_L(int r_nr);
	void T_adjust(int r_nr, int & position);
	void getT(int & gx, int & gy, int & gx1, int & gy1, int & gx2, int & gy2, int & gx3);

	void Tetrimino_L();
	void move_L_J_left(int r_nr);
	void move_L_J_right(int r_nr);
	bool L_collision_R(int r_nr);
	bool L_collision_L(int r_nr);
	void L_adjust(int r_nr, int & position);
	void get_T_L(int & s1, int r_nr);

	void Tetrimino_square();
	void move_square_left();
	void move_square_right();
	bool square_collision_right();
	bool square_collision_left();

	void fall_L(int r_nr, int & fall_all);
	void fall_Z(int r_nr,int & fall_all);
	void fall_T(int r_nr, int & fall_all);
	void fall_S(int r_nr,int & fall_all);
	void fall_I(int r_nr, int & fall_all);
	void fall_square(int & fall_all);

	void clear();
	
};

