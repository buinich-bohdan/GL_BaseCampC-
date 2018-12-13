#include "myString.hpp"

int main(int argc, char const *argv[])
{

	myString a = "text";
	myString b("123");

	std::cout << b.size() << std::endl;
	std::cout << b.length() << std::endl;
	
	myString c(b);
	std::cout << c << std::endl;
	myString d(std::move(b));
	std::cout << d << std::endl;
	
	b = "test";
	std::cout << b << std::endl;

	b = d;
	std::cout << b << std::endl;

	b = std::move(c);
	std::cout << b << std::endl;

	b = b + b;
	std::cout << b << std::endl;
	
	b+=b;
	std::cout << b << std::endl;
	
	if (b!=c) std::cout << "b!=c\n";

	b.append(a);   
	std::cout << b << std::endl;

	myString compb = b;
	if (b.compare(compb) == 0) std::cout << "true\n";

	b.resize(4);
	std::cout << b << std::endl;

	std::cout << "pos ab " << b.substr("23") << std::endl;

	b.insert(2," 11 ");
	std::cout << b << std::endl;

	b.swap(a);
	std::cout << b << std::endl;

}