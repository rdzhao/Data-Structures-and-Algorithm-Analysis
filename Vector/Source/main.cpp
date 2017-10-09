#include "Vector.h"

int main(int argc, char* argv[])
{
	std::cout << "Test default constructor..."<< std::endl;
	DSAA::Vector<int> v;
	std::cout << std::endl;

	std::cout << "Test copy constructor..." << std::endl;
	DSAA::Vector<int> u(v);
	std::cout << std::endl;

	std::cout << "Test copy assignment..." << std::endl;
	DSAA::Vector<int> w;
	w = v;
	std::cout << std::endl;

	std::cout << "Test move constructor..." << std::endl;
	DSAA::Vector<int> x = DSAA::Vector<int>();
	DSAA::Vector<int> xx(std::move(x));
	std::cout << std::endl;

	std::cout << "Test move assignment..." << std::endl;
	DSAA::Vector<int> y;
	y = DSAA::Vector<int>();
	std::cout << std::endl;

	return 1;
}