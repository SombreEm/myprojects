#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

//class Person {
//private:
//	string name;
//	int age;
//public:
//	/*Person(string n, int a) {
//		this->name = n;
//		this->age = a;
//	}*/
//	Person(string n, int a) : name(move(n)), age(a) {}
//	string getName() const { return name; }
//	int getAge() const { return age; }
//};
//------------------------------------------------------------------------------
//class Town {
//private:
//    int floor;
//    int apartments;
//    int firstFloor;
//
//public:
//    Town(int f, int a) : floor(f), apartments(a), firstFloor(rand() % 2) {}
//    int getFloor() const { return floor; }
//    int getApartments() const { return apartments; }
//};
//
//auto compareByApartments = [](const Town& town1, const Town& town2) {
//    return town1.getApartments() < town2.getApartments();
//    };
//
//int main() {
//    vector<Town> towns = {
//        Town(3, 10),
//        Town(2, 8),
//        Town(4, 12),
//    };
//
//    sort(towns.begin(), towns.end(), compareByApartments);
//
//    for (const auto& town : towns) {
//        cout << "Floor: " << town.getFloor() << ", Apartments: " << town.getApartments() << endl;
//    }
//
//}
//---------------------------------------------------------------------------------
struct Student {
    string name;
    vector<int> grades;
};

int main() {
    map<string, Student> students;

    auto addGrade = [&students](const string& name, int grade, int grade2) {
        students[name].grades.push_back(grade);
        students[name].grades.push_back(grade2);
        };
    auto calculateAverage = [&students](const string& name) -> double {
        const auto& student = students[name];
        if (student.grades.empty()) {
            return 0.0;
        }

        double sum = 0.0;
        for (int grade : student.grades) {
            sum += grade;
        }
        return sum / student.grades.size();
        };

    addGrade("Kirusha", 11,10);
    addGrade("Max", 12,8);
    addGrade("Volodia", 6,9);

    cout << calculateAverage("Kirusha") << endl;
    cout << calculateAverage("Max") << endl;
    cout << calculateAverage("Volodia") << endl;
}