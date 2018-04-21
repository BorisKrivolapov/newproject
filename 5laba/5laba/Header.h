#include <iostream>
#include <cmath>
using namespace std;

template<typename T1>
class PointOnThePlane {
protected:
	T1 x;
	T1 y;

public:
	int forCompare(T1 a, T1 b) {
		if (a > b) {
			return 1;
		}
		else if (a < b) {
			return -1;
		}
		else if (a == b) {
			return 0;
		}
	}



	PointOnThePlane(T1 X, T1 Y) {
		x = X;
		y = Y;
	}





	void ToConsole() {
		cout << "Points with coordinates:";
		cout << "\nX = " << x << "\nY = " << y << endl;
	}

	bool Ecuals(PointOnThePlane &point) {
		return this->x == point.x && this->y == point.y;
	}

	int CompareToX(PointOnThePlane &point) {
		int pointThis = this->x;
		int pointOther = point.x;
		return forCompare(pointThis, pointOther);
	}
	int CompareToY(PointOnThePlane &point) {
		int pointThis = this->y;
		int pointOther = point.y;
		return forCompare(pointThis, pointOther);
	}
	double Distance(PointOnThePlane &point) {
		int d = 2;
		int forX = pow((point.x - this->x), d);
		int forY = pow((point.y - this->y), d);
		return sqrt(forX + forY);
	}

	bool operator == (const PointOnThePlane &point) {
		return point.x == this->x && point.y == this->y;
	}
	bool operator != (const PointOnThePlane &point) {
		return !(point.x == this->x && point.y == this->y);
	}
	bool operator < (const PointOnThePlane &point) {
		return point.x + point.y > this->x + this->y;
	}
	bool operator > (const PointOnThePlane &point) {
		return point.x + point.y < this->x + this->y;
	}
	bool operator <= (const PointOnThePlane &point) {
		return point.x + point.y >= this->x + this->y;
	}
	bool operator >= (const PointOnThePlane &point) {
		return point.x + point.y <= this->x + this->y;
	}
	// Доп операторы
	PointOnThePlane operator + (const PointOnThePlane &point) {
		PointOnThePlane temp;
		temp.x = point.x + this->x;
		temp.y = point.y + this->y;
		return temp;
	}

	PointOnThePlane operator - (const PointOnThePlane &point) {
		PointOnThePlane temp;
		temp.x = this->x - point.x;
		temp.y = this->y - point.y;
		return temp;
	}
	PointOnThePlane operator * (const PointOnThePlane &point) {
		PointOnThePlane temp;
		temp.x = point.x * this->x;
		temp.y = point.y * this->y;
		return temp;
	}
	PointOnThePlane operator / (const PointOnThePlane &point) {
		PointOnThePlane temp;
		temp.x = this->x / point.x;
		temp.y = this->y / point.y;
		return temp;
	}
	PointOnThePlane operator % (const PointOnThePlane &point) {
		PointOnThePlane temp;
		temp.x = this->x % point.x;
		temp.y = this->y % point.y;
		return temp;
	}
	PointOnThePlane  operator ++() {
		this->x++;
		this->y++;
		return *this;
	}
	PointOnThePlane  operator --() {
		this->x--;
		this->y--;
		return *this;
	}
};

template<typename T1>
class PointInSpace : public PointOnThePlane<T1> {
protected:
	T1 z;
public:

	PointInSpace(T1 X, T1 Y, T1 Z) : PointOnThePlane(X, Y) {
		z = Z;

	}

	void ToConsole() {
		cout << "Points with coordinates:";
		cout << "\nX = " << x << "\nY = " << y << "\nZ = " << z << endl;
	}
	bool Ecuals(PointInSpace point) {
		return this->x == point.x && this->y == point.y && this->z == point.z;
	}

	int CompareToZsp(PointInSpace point) {
		T1 pointThis = this->z;
		T1 pointOther = point.z;
		return forCompare(pointThis, pointOther);
	}
};

