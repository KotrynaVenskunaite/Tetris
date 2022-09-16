#include "Block.h"

Block::Block(float number)
{
}

Block::~Block()
{
}

 void Block::draw(sf::RenderTarget& window, int matrixNumber) const
{
	
	 window.draw(quads, transform[matrixNumber]);

}
 

 void Block::Tetrimino_T()
 {
	 quads.clear();

	 quads.setPrimitiveType(sf::LinesStrip);
	 quads.resize(9);

	// x = 10.f; x1 = 50.f; x2 = 90.f; x3 = 130.f;
	 x = 130.f; x1 = 170.f; x2 = 210.f; x3 = 250.f;
	 y = -70.f; y1 = -30.f; y2 = 10.f;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y1);
	 quads[6].position = sf::Vector2f(x3, y1);
	 quads[7].position = sf::Vector2f(x3, y);
	 quads[8].position = sf::Vector2f(x, y);

 }

 void Block::getT(int & gx,int & gy,int & gx1,int & gy1,int & gx2,int & gy2,int & gx3)
 {
	 gx = x; gx1 = x1; gx2 = x2; gx3 = x3;
	 gy = y; gy1 = y1; gy2 = y2;
 }

 void Block::move_T_right(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f;
	 }

	 if (r_nr == 1) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40; xx = xx - 40; yy = yy - 40;
	 }

	 if (r_nr == 2) {
		 x = x - 40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; x3 = x3 - 40.f; xx = xx - 80; yy = yy - 80;
	 }

	 if (r_nr == 3) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx - 40; yy = yy - 40;
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y1);
	 quads[6].position = sf::Vector2f(x3, y1);
	 quads[7].position = sf::Vector2f(x3, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 void Block::move_T_left(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; x3 = x3 - 40.f;
	 }

	 if (r_nr == 1) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx + 40;  yy = yy + 40;
	 }

	 if (r_nr == 2) {
		 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; xx = xx + 80; yy = yy + 80;

	 }

	 if (r_nr == 3) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f; xx = xx + 40; yy = yy + 40;
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y1);
	 quads[6].position = sf::Vector2f(x3, y1);
	 quads[7].position = sf::Vector2f(x3, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 bool Block::T_collision_R(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x3 >= xx)
			 return 1;
	 }

	 if (r_nr == 1)
	 {
		 if (x3 >= xx)
			 return 1;
		
	 }

	 if (r_nr == 2)
	 {
		 if (x3 + 40 >= xx)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x3 >= xx)
			 return 1;

	 }
 }

 bool Block::T_collision_L(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x <= yy)
			 return 1;

	 }

	 if (r_nr == 1)
	 {
		 if (x + 40 <= yy)
			 return 1;

	 }

	 if (r_nr == 2)
	 {
		 if (x1 <= yy)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x1 <= yy)
			 return 1;

	 }
 }

 void Block::T_adjust(int r_nr, int & position)
 {
	 if (r_nr == 1) {

	 }

	 if (r_nr == 2) {
		 if (x3 >= xx) {
			 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; xx = xx + 80; yy = yy + 80; position--;
		 }
	 }

	 if (r_nr == 3) {

	 }

	 if (r_nr == 0) {
		 if (x + 40 <= yy) {
			 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; ri = 0;
		 }
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y1);
	 quads[6].position = sf::Vector2f(x3, y1);
	 quads[7].position = sf::Vector2f(x3, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 void Block::Tetrimino_I()
 {
	 quads.clear();

	 quads.setPrimitiveType(sf::LinesStrip);
	 quads.resize(5);

	 x = 170.f; x1 = 210.f;  x2 = 190;
	 y = 10.f; y1 = - 150.f; y2 = - 90;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);
 }

 void Block::move_I_left(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x - 40.f; x1 = x1 - 40.f; x2 = x2 - 40.f;
	 }

	 if (r_nr == 1) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx + 40; yy = yy + 40;
	 }

	 if (r_nr == 2) {
		 x = x + 40.f; x1 = x1 + 40.f; x2 = x2 + 40.f; xx = xx + 80; yy = yy + 80;
	 }

	 if (r_nr == 3) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f; xx = xx + 40; yy = yy + 40;
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);
 }

 void Block::move_I_right(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x + 40.f; x1 = x1 + 40.f; x2 = x2 + 40.f;
	 }

	 if (r_nr == 1) {
	 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f;  xx = xx - 40; yy = yy - 40;
	 }

	 if (r_nr == 2) {
		 x = x - 40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; xx = xx - 80; yy = yy - 80;
	 }

	 if (r_nr == 3) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx - 40; yy = yy - 40;
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);
 }

 bool Block::I_collision_R(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x1 >= xx)
			 return 1;
	 }

	 if (r_nr == 1)
	 {
		 if (x1 + 80 >= xx)
			 return 1;
	 }

	 if (r_nr == 2)
	 {
		 if (x1 + 40 >= xx)
			 return 1;
	 }

	 if (r_nr == 3)
	 {
		 if (x1 + 80 >= xx)
			 return 1;
	 }
	
 }

 bool Block::I_collision_L(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x <= yy)
			 return 1;
	 }

	 if (r_nr == 1)
	 {
		 if (x - 40 <= yy)
			 return 1;
	 }

	 if (r_nr == 2)
	 {
		 if (x + 40 <= yy)
			 return 1;
	 }

	 if (r_nr == 3)
	 {
		 if (x - 40 <= yy)
			 return 1;
	 }
 }

 void Block::I_adjust(int r_nr, int & position)
 {
	 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f;
	 if (r_nr == 1)
	 {
		 if (x <= yy) {
			 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f;  xx = xx - 40; yy = yy - 40; position += 1;
		 }
		 if (x1 + 40 >= xx) {
			 y = y + 80.f; y1 = y1 + 80.f; y2 = y2 + 80.f; xx = xx + 80; yy = yy + 80; position -= 2;
		 }
	 }

	 if (r_nr == 2) {
		 if (x3 >= xx) {
			 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; li = 0; yy = yy + 80; xx = xx + 80;
		 }
	 }

	 if (r_nr == 3) {
		 if (x <= yy) {
			 y = y + 80.f; y1 = y1 + 80.f; y2 = y2 + 80.f; xx = xx - 80; yy = yy - 80; position += 2;
		 }
		 if (x1 + 40 >= xx ) {
			 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f; xx = xx + 40; yy = yy + 40; position -= 1;
		 }
	 }

	 if (r_nr == 0) {
		 if (x + 40 <= yy) {
			 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; ri = 0;
		 }
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);
 }

 void Block::Tetrimino_J()
 {
	 quads.clear();

	 quads.setPrimitiveType(sf::LinesStrip);
	 quads.resize(7);

	 x = 170.f; x1 = 130.f; x2 = 210.f;
	 y = - 110.f; y1 = - 30.f; y2 = 10.f;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y);
	 quads[6].position = sf::Vector2f(x, y);
 }

 void Block::Tetrimino_S()
 {
	 quads.clear();

	 quads.setPrimitiveType(sf::LinesStrip);
	 quads.resize(9);

	 x = 130.f; x1 = 170.f; x2 = 210.f; x3 = 250.f;
	 y = -70.f; y1 = -30.f; y2 = 10.f;

	 quads[0].position = sf::Vector2f(x, y1);
	 quads[1].position = sf::Vector2f(x, y2);
	 quads[2].position = sf::Vector2f(x2, y2);
	 quads[3].position = sf::Vector2f(x2, y1);
	 quads[4].position = sf::Vector2f(x3, y1);
	 quads[5].position = sf::Vector2f(x3, y);
	 quads[6].position = sf::Vector2f(x1, y);
	 quads[7].position = sf::Vector2f(x1, y1);
	 quads[8].position = sf::Vector2f(x, y1);
 }

 void Block::move_S_right(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f;
	 }

	 if (r_nr == 1) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40; xx = xx - 40; yy = yy - 40;
	 }

	 if (r_nr == 2) {
		 x = x - 40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; x3 = x3 - 40.f; xx = xx - 80; yy = yy - 80;
	 }

	 if (r_nr == 3) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx - 40; yy = yy - 40;
	 }

	 quads[0].position = sf::Vector2f(x, y1);
	 quads[1].position = sf::Vector2f(x, y2);
	 quads[2].position = sf::Vector2f(x2, y2);
	 quads[3].position = sf::Vector2f(x2, y1);
	 quads[4].position = sf::Vector2f(x3, y1);
	 quads[5].position = sf::Vector2f(x3, y);
	 quads[6].position = sf::Vector2f(x1, y);
	 quads[7].position = sf::Vector2f(x1, y1);
	 quads[8].position = sf::Vector2f(x, y1);
 }

 void Block::move_S_left(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; x3 = x3 - 40.f;
	 }

	 if (r_nr == 1) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx + 40;  yy = yy + 40;
	 }

	 if (r_nr == 2) {
		 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; xx = xx + 80; yy = yy + 80;

	 }

	 if (r_nr == 3) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f; xx = xx + 40; yy = yy + 40;
	 }

	 quads[0].position = sf::Vector2f(x, y1);
	 quads[1].position = sf::Vector2f(x, y2);
	 quads[2].position = sf::Vector2f(x2, y2);
	 quads[3].position = sf::Vector2f(x2, y1);
	 quads[4].position = sf::Vector2f(x3, y1);
	 quads[5].position = sf::Vector2f(x3, y);
	 quads[6].position = sf::Vector2f(x1, y);
	 quads[7].position = sf::Vector2f(x1, y1);
	 quads[8].position = sf::Vector2f(x, y1);
 }

 bool Block::S_collision_R(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x3 >= xx)
			 return 1;
	 }

	 if (r_nr == 1)
	 {
		 if (x3 >= xx)
			 return 1;
	 }

	 if (r_nr == 2)
	 {
		 if (x3 + 40 >= xx)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x3 >= xx)
			 return 1;

	 }
 }

 bool Block::S_collision_L(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x <= yy)
			 return 1;

	 }

	 if (r_nr == 1)
	 {
		 if (x + 40 <= yy)
			 return 1;

	 }

	 if (r_nr == 2)
	 {
		 if (x1 <= yy)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x1 <= yy)
			 return 1;

	 }
 }

 void Block::S_adjust(int r_nr)
 {
	 if (r_nr == 1) {
		
	 }

	 if (r_nr == 2) {
		 if (x3 >= xx) {
			 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; li = 0; yy = yy + 80; xx = xx + 80;
		 }
	 }

	 if (r_nr == 3) {
		
	 }

	 if (r_nr == 0) {
		 if (x + 40 <= yy) {
			 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; ri = 0;
		 }
	 }

	 quads[0].position = sf::Vector2f(x, y1);
	 quads[1].position = sf::Vector2f(x, y2);
	 quads[2].position = sf::Vector2f(x2, y2);
	 quads[3].position = sf::Vector2f(x2, y1);
	 quads[4].position = sf::Vector2f(x3, y1);
	 quads[5].position = sf::Vector2f(x3, y);
	 quads[6].position = sf::Vector2f(x1, y);
	 quads[7].position = sf::Vector2f(x1, y1);
	 quads[8].position = sf::Vector2f(x, y1);
 }

 void Block::Tetrimino_Z()
 {
	 quads.clear();

	 quads.setPrimitiveType(sf::LinesStrip);
	 quads.resize(9);

	 x = 130.f; x1 = 170.f; x2 = 210.f; x3 = 250.f;
	 y = -70.f; y1 = -30.f; y2 = 10.f;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x3, y2);
	 quads[5].position = sf::Vector2f(x3, y1);
	 quads[6].position = sf::Vector2f(x2, y1);
	 quads[7].position = sf::Vector2f(x2, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 void Block::move_Z_right(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f;
	 }

	 if (r_nr == 1) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40; xx = xx - 40; yy = yy - 40;
	 }

	 if (r_nr == 2) {
		 x = x - 40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; x3 = x3 - 40.f; xx = xx - 80; yy = yy - 80;
	 }

	 if (r_nr == 3) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx - 40; yy = yy - 40;
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x3, y2);
	 quads[5].position = sf::Vector2f(x3, y1);
	 quads[6].position = sf::Vector2f(x2, y1);
	 quads[7].position = sf::Vector2f(x2, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 void Block::move_Z_left(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; x3 = x3 - 40.f;
	 }

	 if (r_nr == 1) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx + 40;  yy = yy + 40;
	 }

	 if (r_nr == 2) {
		 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; xx = xx + 80; yy = yy + 80;

	 }

	 if (r_nr == 3) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f; xx = xx + 40; yy = yy + 40;
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x3, y2);
	 quads[5].position = sf::Vector2f(x3, y1);
	 quads[6].position = sf::Vector2f(x2, y1);
	 quads[7].position = sf::Vector2f(x2, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 bool Block::Z_collision_R(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x3 >= xx)
			 return 1;
	 }

	 if (r_nr == 1)
	 {
		 if (x3 >= xx)
			 return 1;
	 }

	 if (r_nr == 2)
	 {
		 if (x3 + 40 >= xx)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x3 >= xx)
			 return 1;
	 }
 }

 bool Block::Z_collision_L(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x <= yy)
			 return 1;

	 }

	 if (r_nr == 1)
	 {
		 if (x + 40 <= yy)
			 return 1;

	 }

	 if (r_nr == 2)
	 {
		 if (x1 <= yy)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x1 <= yy)
			 return 1;

	 }
 }

 void Block::Z_adjust(int r_nr, int & position)
 {
	 if (r_nr == 1) {

	 }

	 if (r_nr == 2) {
		 if (x3 >= xx) {
			 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; li = 0; yy = yy + 80; xx = xx + 80; position -= 1;
		 }
	 }

	 if (r_nr == 3) {

	 }

	 if (r_nr == 0) {
		 if (x + 40 <= yy) {
			 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; ri = 0;
		 }
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x3, y2);
	 quads[5].position = sf::Vector2f(x3, y1);
	 quads[6].position = sf::Vector2f(x2, y1);
	 quads[7].position = sf::Vector2f(x2, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 bool Block::J_collision_R(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x2 >= xx)
			 return 1;
	 }

	 if (r_nr == 1)
	 {
		 if (x2 >= xx)
			 return 1;
		 if (x2 >= xx - 40)
			 return 1;

	 }

	 if (r_nr == 2)
	 {
		 if (x2 >= xx)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x2 >= xx)
			 return 1;

	 }
 }

 bool Block::J_collision_L(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x1 <= yy)
			 return 1;

	 }

	 if (r_nr == 1)
	 {
		 if (x1 <= yy)
			 return 1;

	 }

	 if (r_nr == 2)
	 {
		 if (x1 <= yy)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x1 <= yy)
			 return 1;

	 }
 }

 void Block::J_adjust(int r_nr, int& position)
 {
	 if (r_nr == 1) {
		 if (x2 >= xx) {
			 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx + 40; yy = yy + 40; ri = 1; position -= 1;
		 }
		 if (x1 <= yy)
			 li = 1;
	 }

	 if (r_nr == 2) {
		 if (x2 + 40 >= xx && ri == 1) {
			 x = x - 40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; yy = yy - 80; xx = xx - 80;   position += 1;
		 }
		 else if (ri == 1) {
			 ri = 0;
		 }
	 }

	 if (r_nr == 3) {
		 yy = yy + 40;
		 if (x1 + 40 <= yy) {
			 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx - 40;  yy = yy - 40; li = 1; ri = 1; position += 1;
		 }
	 }

	 if (r_nr == 0) {
		 yy = yy - 40;
		 if (x2 >= xx) {
			 ri = 0;
		 }
		 if (x1 - 40 <= yy && li == 1) {
			 xx = xx - 40;
			 x = x - 40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; xx = xx + 40; li = 0; position -= 1;
		 }
		 if (x1 + 40 <= yy) {
			 yy = yy - 40;
		 }
	 }
	
	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y);
	 quads[6].position = sf::Vector2f(x, y);
 }

 void Block::Tetrimino_L()
 {
	 quads.clear();

	 quads.setPrimitiveType(sf::LinesStrip);
	 quads.resize(7);

	 x = 170.f; x1 = 250.f; x2 = 210.f;
	 y = - 110.f; y1 = 10; y2 = - 30.f;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y);
	 quads[6].position = sf::Vector2f(x, y);

 }

 void Block::move_L_J_right(int  r_nr)
 {
	
	 if (r_nr == 0){
		 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f;
	 }

	 if (r_nr == 1){
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40; xx = xx - 40; yy = yy - 40;
	 }

	 if (r_nr == 2) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; xx = xx - 80; yy = yy - 80;
	 }

	 if (r_nr == 3) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx - 40; yy = yy - 40;
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y);
	 quads[6].position = sf::Vector2f(x, y);
 }

 void Block::move_L_J_left(int r_nr)
 {
	 if (r_nr == 0) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f;
	 }

	 if (r_nr == 1) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx + 40;  yy = yy + 40;
	 }

	 if (r_nr == 2) {
		 x = x + 40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; xx = xx + 80; yy = yy + 80;

	 }

	 if (r_nr == 3) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40.f; xx = xx + 40; yy = yy + 40;
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y);
	 quads[6].position = sf::Vector2f(x, y);
 }

 bool Block::L_collision_R(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x1 >= xx)
			 return 1;
			 
	 }
	 if (r_nr == 1)
	 {
		 if (x1 >= xx)
			 return 1;
		 if (x1 >= xx - 40)
			 return 1;

	 }

	 if (r_nr == 2)
	 {
		 if (x1 >= xx)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x1 >= xx)
			 return 1;

	 }
 }
  
 bool Block::L_collision_L(int r_nr)
 {
	 if (r_nr == 0)
	 {
		 if (x <= yy)
			 return 1;
	 }

	 if (r_nr == 1)
	 {
		 if (x <= yy)
			 return 1;

	 }

	 if (r_nr == 2)
	 {
		 if (x <= yy)
			 return 1;

	 }

	 if (r_nr == 3)
	 {
		 if (x <= yy)
			 return 1;

	 }
 }

 void Block::L_adjust(int r_nr, int & position)
 {
	 
	 if (r_nr == 1){
		 if (x1 >= xx){
			 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx + 40; yy = yy + 40; ri = 1; position -= 1;
		 }
	 }

	 if (r_nr == 2){
		 if (x1 + 40 >= xx && ri == 1 ){
			 xx = xx - 40;
			 x = x - 40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; xx = xx - 40; yy = yy - 80; ri = 0; position += 1;
		 }
	 }

	 if (r_nr == 3){
		 if (x <= yy) {
			 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40.f; xx = xx - 40; li = 1; yy = yy + 40;
		 }
		 else yy = yy + 40; li = 1;
	 }

	 if (r_nr == 0) {
		 if (x + 40 <= yy && li == 1) {
			 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; li = 0; yy = yy - 80;
		 }
		 else if (li == 1) {
			 yy = yy - 40; li = 0;
		 }
	 }

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y);
	 quads[6].position = sf::Vector2f(x, y);
 }

 void Block::Tetrimino_square()
 {
	 quads.clear();

	 quads.setPrimitiveType(sf::LinesStrip);
	 quads.resize(5);

	 x = 130.f; x1 = 210.f;
	 y = 10.f; y1 = - 70.f;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);


 }

 void Block::move_square_left()
 {
	 x = x + -40.f; x1 = x1 - 40.f;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);
 }

 void Block::move_square_right()
 {
	 x = x + 40.f; x1 = x1 + 40.f;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);
 }

 bool Block::square_collision_right()
 {
	 if (x1 >= xx)
	 {
		 return 1;
	 }
 }

 bool Block::square_collision_left()
 {
	 if (x <= yy)
	 {
		 return 1;
	 }
 }

 void Block::rotate(int matrixNumber, int random)
 {
	 int rotate_x, rotate_y;
	 if (random == 0 || 1 || 2) { rotate_x = x2; rotate_y = y1; }
	 if (random == 3) { rotate_x = x2; rotate_y = y2; }
	 if (random == 4) { rotate_x = x; rotate_y = y1; }
	 if (random == 6) { rotate_x = x2; rotate_y = y2; }
	 
	 transform[matrixNumber].rotate(90, sf::Vector2f(rotate_x, rotate_y)); // T/S/Z = x2, y1 | L= x2,y2 | J= x, y1 | I= x, y2

 }

 void Block::reset(int & r_nr)
 {
	     xx = 410,
		 yy = 10,
		 ri = 0,
		 li = 0,
		 fi = 0;
		 r_nr = 0;
 }

 void Block::fall_L(int r_nr, int & fall_all)
 {
	 if (r_nr == 0) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40;
	 }
	 if (r_nr == 1) {
		 x = x + +40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; xx = xx + 40; yy = yy + 40;
	 }
	 if (r_nr == 2) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40;
	 }
	 if (r_nr == 3) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; xx = xx - 40; yy = yy - 40;
	 }
	 fall_all += 40;

		 quads[0].position = sf::Vector2f(x, y);
		 quads[1].position = sf::Vector2f(x, y1);
		 quads[2].position = sf::Vector2f(x1, y1);
		 quads[3].position = sf::Vector2f(x1, y2);
		 quads[4].position = sf::Vector2f(x2, y2);
		 quads[5].position = sf::Vector2f(x2, y);
		 quads[6].position = sf::Vector2f(x, y);
 }

 void Block::fall_Z(int r_nr, int & fall_all)
 {
	 if (r_nr == 0) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40;
	 }
	 if (r_nr == 1) {
		 x = x + +40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; xx = xx + 40; yy = yy + 40;
	 }
	 if (r_nr == 2) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40;
	 }
	 if (r_nr == 3) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f;  x3 = x3 - 40.f; xx = xx - 40; yy = yy - 40;
	 }
	 fall_all += 40;
	
	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x3, y2);
	 quads[5].position = sf::Vector2f(x3, y1);
	 quads[6].position = sf::Vector2f(x2, y1);
	 quads[7].position = sf::Vector2f(x2, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 void Block::fall_T(int r_nr, int & fall_all)
 {
	 if (r_nr == 0) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40;
	 }
	 if (r_nr == 1) {
		 x = x + +40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; xx = xx + 40; yy = yy + 40;
	 }
	 if (r_nr == 2) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40;
	 }
	 if (r_nr == 3) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f;  x3 = x3 - 40.f; xx = xx - 40; yy = yy - 40;
	 }
	 fall_all += 40;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y2);
	 quads[4].position = sf::Vector2f(x2, y2);
	 quads[5].position = sf::Vector2f(x2, y1);
	 quads[6].position = sf::Vector2f(x3, y1);
	 quads[7].position = sf::Vector2f(x3, y);
	 quads[8].position = sf::Vector2f(x, y);
 }

 void Block::fall_S(int r_nr, int & fall_all)
 {
	 if (r_nr == 0) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40;
	 }
	 if (r_nr == 1) {
		 x = x + +40.f; x1 = x1 + 40.f;  x2 = x2 + 40.f; x3 = x3 + 40.f; xx = xx + 40; yy = yy + 40;
	 }
	 if (r_nr == 2) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40;
	 }
	 if (r_nr == 3) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f;  x3 = x3 - 40.f; xx = xx - 40; yy = yy - 40;
	 }

	 fall_all += 40;

	 quads[0].position = sf::Vector2f(x, y1);
	 quads[1].position = sf::Vector2f(x, y2);
	 quads[2].position = sf::Vector2f(x2, y2);
	 quads[3].position = sf::Vector2f(x2, y1);
	 quads[4].position = sf::Vector2f(x3, y1);
	 quads[5].position = sf::Vector2f(x3, y);
	 quads[6].position = sf::Vector2f(x1, y);
	 quads[7].position = sf::Vector2f(x1, y1);
	 quads[8].position = sf::Vector2f(x, y1);
 }

 void Block::fall_I(int r_nr, int & fall_all)
 {
	 if (r_nr == 0) {
		 y = y + 40.f; y1 = y1 + 40.f; y2 = y2 + 40;
	 }
	 if (r_nr == 1) {
		 x = x + +40.f; x1 = x1 + 40.f; x2 = x2 + 40.f; xx = xx + 40; yy = yy + 40;
	 }
	 if (r_nr == 2) {
		 y = y - 40.f; y1 = y1 - 40.f; y2 = y2 - 40;
	 }
	 if (r_nr == 3) {
		 x = x + -40.f; x1 = x1 - 40.f;  x2 = x2 - 40.f; xx = xx - 40; yy = yy - 40;
	 }

	 fall_all += 40;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);
 }

 void Block::fall_square(int & fall_all)
 {
	 y = y + 40.f; y1 = y1 + 40.f;

	 fall_all += 40;

	 quads[0].position = sf::Vector2f(x, y);
	 quads[1].position = sf::Vector2f(x, y1);
	 quads[2].position = sf::Vector2f(x1, y1);
	 quads[3].position = sf::Vector2f(x1, y);
	 quads[4].position = sf::Vector2f(x, y);
 }

 void Block::clear()
 {
	 quads.clear();
 }

 void Block::get_T_L(int & s1, int r_nr)
 {
	 if(r_nr == 0)
		 s1 = y2;

	 if (r_nr == 1)
		 s1 = y2 ;
	 
 }