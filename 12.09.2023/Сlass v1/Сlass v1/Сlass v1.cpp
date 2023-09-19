//#include <iostream>
//using namespace std;
//class Student {
//public:
//    string name;
//    int age;
//    void sayHi(){
//        cout << "Hello, my name is " << name;
//    }
//};
//Student olderStudent(Student student[], int age) {
//    Student oldest = student[0];
//    for (int i = 1; i < age; i++) {
//        if (student[i].age > oldest.age) {
//            oldest = student[i];
//       }
//    }
//    return oldest;
//}
//int main()
//{
//    Student newList[3]{
//        {"Vlad", 18},
//        {"Maxim", 16},
//        {"Oleg", 20}
//    };
//    Student oldestStudent = olderStudent(newList, 3);
//    cout << oldestStudent.age;
//}
// 
// 
// 
//--------------------------------------------------------------------------------------------------------------------



#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    void sayHi() {
        cout << "Hello, my name is " << name << endl;
    }
};

void oldest(Student student[], int age) {
    for (int i = 0; i < age - 1; i++) {
        for (int j = 0; j < age - i - 1; j++) {
            if (student[j].age > student[j + 1].age) {
                Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student newList[3]{
        {"Vlad", 18},
        {"Maxim", 16},
        {"Oleg", 20}
    };

    oldest(newList, 3);

    for (int i = 0; i < 3; i++) {
        cout << newList[i].name<< "\t" << newList[i].age << endl;
    }

    return 0;
}
