#include <iostream>
#include <BoolVector.hpp>

int main()
{
    ///Шеин Артём 6 лаба
	BoolVector v;
	v.append(false);
	v.append(true);
	v.append(false);
	std::cout << v.toString() << '\n';
	v.set(0, true);
	std::cout << v.toString() << " " << v.get(0)  << " " << v.getLength() << '\n';
	v.insert(1, false);
	std::cout << v.toString() << '\n';
	v.erase(1, 2);
	std::cout << v.toString() << '\n';
	return 0;
}