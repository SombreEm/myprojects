#include <iostream>
#include <string>

using namespace std;

class Figure {
public:
    string name;
    int square;
    double lineThickness;
    string lineColor;
    string fillColor;

    Figure(string _name, int _square, double _lineThickness, string _lineColor, string _fillColor)
        : name(_name), square(_square), lineThickness(_lineThickness), lineColor(_lineColor), fillColor(_fillColor) {}

    void FigureInfo() {
        cout << "Name: " << name << endl;
        cout << "Square: " << square << endl;
        cout << "Line Thickness: " << lineThickness << " px" << endl;
        cout << "Line Color: " << lineColor << endl;
        cout << "Fill Color: " << fillColor << endl << endl;
    }

    bool IsCopyPossible(const Figure& other) const {
       
        return (typeid(*this) == typeid(other)) &&
            (square == other.square) &&
            (lineThickness == other.lineThickness) &&
            (lineColor == other.lineColor) &&
            (fillColor == other.fillColor);
    }
};

class Rectangle : public Figure {
public:
    Rectangle(int height, int width)
        : Figure("Rectangle", height* width, 2.5, "Pink", "Brown") {}
};

class Circle : public Figure {
public:
    Circle(int radius)
        : Figure("Circle", 2 * 3.14 * radius, 5.0, "Yellow", "Black") {}
};

class Square : public Figure {
public:
    Square(int side)
        : Figure("Square", side* side, 1.0, "Black", "Grey") {}
};

class Rhombus : public Figure {
public:
    Rhombus(int diagonal1, int diagonal2)
        : Figure("Rhombus", diagonal1* diagonal2, 19.0, "Black", "Aquamain") {}
};

class Parallelogram : public Figure {
public:
    Parallelogram(int height, int side)
        : Figure("Parallelogram", height* side, 23.0, "Grey", "Yellow") {}
};

class Trapezoid : public Figure {
public:
    Trapezoid(int midline, int height)
        : Figure("Trapezoid", midline* height, 0.0023, "Brown", "Pink") {}
};

int main() {
    Rectangle rectangle1(10, 20);
    Rectangle rectangle2(5, 30);

    if (rectangle1.IsCopyPossible(rectangle2)) {
        cout << "It's possible to copy rectangle2 into rectangle1." << endl;
    }
    else {
        cout << "It's not possible to copy rectangle2 into rectangle1." << endl;
    }

    Circle circle1(10);
    Square square1(5);

    if (circle1.IsCopyPossible(square1)) {
        cout << "It's possible to copy square1 into circle1." << endl;
    }
    else {
        cout << "It's not possible to copy square1 into circle1." << endl;
    }
}