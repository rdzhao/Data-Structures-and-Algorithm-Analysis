#include "Vector.h"

int main(int argc, char* argv[])
{
	cout << "Test the big five ..." << endl;

	std::cout << "Test default constructor..."<< std::endl;
	DSAA::Vector<int> v(5);
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


	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Test reserve(), resize() ..."<< endl;
	DSAA::Vector<int> vec(100);
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "Size: " << vec.size() << endl;


	return 1;
}