//#include <iostream>
//#include <Windows.h>
//#include <time.h>
//#include <stdlib.h>
//#include <cstdlib>
//#include <ctime>   
//
//using namespace std;
//
//class Student {
//public:
//    string name;
//    int mathAssessment;
//    int physicsAssessment;
//};
//
//class SchoolClass {
//public:
//    Student allStudent[15]; 
//
//    SchoolClass() {
//        string studentNames[] = { "Кирило", "Володимир", "Влад", "Денис", "Дмитро", "Влада", "Аліса", "Юля", "Маша", "Рома", "Максим", "Кира", "Андриан", "Тарас", "Катя" };
//
//        srand(time(nullptr)); 
//
//        for (int i = 0; i < 15; ++i) {
//            int randomIndex = rand() % 15; 
//            allStudent[i].name = studentNames[randomIndex];
//            allStudent[i].mathAssessment = rand() % 12;
//            allStudent[i].physicsAssessment = rand() % 12;
//        }
//    }
//
//    Student BestStudent() {
//        Student bestStudent = allStudent[0];
//        for (int i = 1; i < 15; ++i) {
//            if (allStudent[i].mathAssessment + allStudent[i].physicsAssessment >
//                bestStudent.mathAssessment + bestStudent.physicsAssessment) {
//                bestStudent = allStudent[i];
//            }
//        }
//        return bestStudent;
//    }
//
//    float calculateClass() {
//        float totalMath = 0;
//        float totalPhysics = 0;
//        for (int i = 0; i < 15; ++i) {
//            totalMath += allStudent[i].mathAssessment;
//            totalPhysics += allStudent[i].physicsAssessment;
//        }
//        return (totalMath + totalPhysics) / (15 * 2);
//    }
//};
//
//
//int main() {
//
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    SchoolClass myClass;
//
//    Student bestStudent = myClass.BestStudent();
//    cout << "Найкращий студент: " << bestStudent.name << endl;
//    cout << "Оцінка за математику: " << bestStudent.mathAssessment << endl;
//    cout << "Оцінка за фізику: " << bestStudent.physicsAssessment << endl;
//
//    float classAverage = myClass.calculateClass();
//    cout << "Середня оцінка класу: " << classAverage << endl;
//
//    return 0;
//}

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>   

using namespace std;

class Student {
public:
    string name;
    int mathAssessment;
    int physicsAssessment;
};

bool compareStudents(const Student& a, const Student& b) {

    return (a.mathAssessment + a.physicsAssessment) < (b.mathAssessment + b.physicsAssessment);
}

class SchoolClass {
public:
    Student allStudent[15];

    SchoolClass() {
        string studentNames[] = { "Кирило", "Володимир", "Влад", "Денис", "Дмитро", "Влада", "Аліса", "Юля", "Маша", "Рома", "Максим", "Кира", "Андриан", "Тарас", "Катя" };

        srand(time(nullptr));

        for (int i = 0; i < 15; ++i) {
            int randomIndex = rand() % 15;
            allStudent[i].name = studentNames[randomIndex];
            allStudent[i].mathAssessment = rand() % 12;
            allStudent[i].physicsAssessment = rand() % 12;
        }
    }

    void printStudentsByGrades() {
        for (int i = 0; i < 15 - 1; ++i) {
            for (int j = 0; j < 15 - i - 1; ++j) {
                if (compareStudents(allStudent[j], allStudent[j + 1])) {
                    Student temp = allStudent[j];
                    allStudent[j] = allStudent[j + 1];
                    allStudent[j + 1] = temp;
                }
            }
        }

        
        for (int i = 0; i < 15; ++i) {
            cout << allStudent[i].name << ": Оцінка за математику: " << allStudent[i].mathAssessment << ", Оцінка за фізику: " << allStudent[i].physicsAssessment << endl;
        }
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SchoolClass myClass;

    myClass.printStudentsByGrades();

    return 0;
}