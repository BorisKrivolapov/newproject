#include <iostream>
#include "Header.h"



int main() {
	PointOnThePlane<int> a(2, 3);


	a.ToConsole();


	PointOnThePlane<double> b(2.5, 3.7);

	b.ToConsole();

	system("pause");
	return 0;
}

