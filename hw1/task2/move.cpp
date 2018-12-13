#include "move.hpp"
#include <iostream>

Move::Move(double a, double b): x(a), y(b){
}

void Move::showmove() const{
	std::cout << "x = " << x << " y = " << y << std::endl; 
};

Move Move::add(const Move &m) const{
	x = x + m.x;
	y = y + m.y;
	return *this;

}

void Move::reset(double a = 0, double b = 0){
	x = a; 
	y = b;
}