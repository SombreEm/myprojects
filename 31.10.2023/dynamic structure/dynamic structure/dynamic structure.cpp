#include <iostream>
using namespace std;

class Progression {
private:
    unsigned long first;
    unsigned long second;

public:
    Progression(unsigned long first, unsigned long second) {
        this->first = first;
        this->second = second;
    }

    unsigned long getNumberByOrdinal(unsigned int ordinal) {
        if (ordinal == 1) {
            return first;
        }
        if (ordinal == 2) {
            return second;
        }

        unsigned long third = first;
        for (unsigned int i = 3; i <= ordinal; i++) {
            third = first + second;
            first = second;
            second = third;
        }

        return third;
    }
};

int main() {
    Progression progression1 = { 1, 1 };
    cout << progression1.getNumberByOrdinal(1) << endl;
    cout << progression1.getNumberByOrdinal(6) << endl;
    
}
