#include "move.hpp"

int main(int argc, char const *argv[])
{
	Move test;
	test.showmove();
	test.reset(10.2,11.3);
	test.showmove();
	Move tmp(1,2);
	test.add(tmp);
	test.showmove();
	
	return 0;
}