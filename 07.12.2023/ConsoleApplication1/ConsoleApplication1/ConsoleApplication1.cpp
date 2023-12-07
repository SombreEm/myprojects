#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Point {

private:

	int x = 0,

		y = 0;

public:

	Point() {

	}

	Point(int x, int y) {

		this->x = x;

		this->y = y;

	}

	void showCoords() {

		cout << "x: " << this->x << endl;

		cout << "y: " << this->y << "\n" << endl;

	}
	double searchlong(const Point& second) const {
		return sqrt(pow(this->x - second.x, 2) + pow(this->y - second.y, 2));
	}

	Point createCentral(const Point& second) const {
		double midx = (this->x + second.x) / 2;
		double midy = (this->y + second.y) / 2;
		return Point(midx, midy);
	}
};


int main()

{

	vector <Point> system = { {0,0},{10,7},{-3,5},{8,0},{1,11},{-10,-10},{2,25} };
		cout << system[1].searchlong(system[2]) << endl;
		Point createCentral =  system[0].createCentral(system[3]);
		createCentral.showCoords();
		system.push_back(createCentral);
	}