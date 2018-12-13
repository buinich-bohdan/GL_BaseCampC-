#include "golf.hpp"

int main(int argc, char const *argv[])
{
	golf a;
	setGolf(a,"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbb", 10);
	showGolf(a);
	golf b;
	int i  = setGolf(b);
	handicap(a,1);
	showGolf(a);
	return 0;
}