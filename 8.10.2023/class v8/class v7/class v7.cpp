#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;


class Point {
public:
    int x;
    int y;
    int thickness = 1;
    string color;

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
        this->color = "black";
    }
};

class Line : public Point {
public:
    Point p1;
    Point p2;
    double length;

    Line(Point p1, Point p2) : p1(p1), p2(p2) {
        this->p1 = p1;
        this->p2 = p2;
        int newX = p1.x > p2.x ? p1.x - p2.x : p2.x - p1.x;
        int newY = p1.y > p2.y ? p1.y - p2.y : p2.y - p1.y;
        this->length = sqrt(((newX * newX) + (newY * newY)));
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Point point1(3,0);
    Point point2(5,3);

    Line line(point1, point2);

    cout << "Довжина лінії: " << line.length << endl;

    return 0;
}