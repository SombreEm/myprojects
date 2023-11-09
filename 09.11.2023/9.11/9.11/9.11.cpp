#include <iostream>
#include <algorithm>
using namespace std;

class StringArray {
private:
    static const int SIZE = 6;
    string array[SIZE] = {"Hello", "A", " ", "123abc", "a B", ""};
public:
    void Show() const {
        for (int i = 0; i < SIZE; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    void SortByName() {
        sort(array, array + SIZE);
    }
    void SortByLength() {
        sort(array, array + SIZE, [](const string& a, const string& b) {
            return a.length() < b.length();
        });
    }
    void ShowEmpty() const {
        int emptyCount = 0;
        for (int i = 0; i < SIZE; ++i) {
            if (array[i].empty()) {
                ++emptyCount;
            }
        }
        cout << "Empty elements: " << emptyCount << endl;
    }
    void SortByUpperChar() {
        sort(array, array + SIZE, [](const string& a, const string& b) {
            return toupper(a[0]) < toupper(b[0]);
        });
    }
};

int main() { 
    StringArray myArray;
    cout << "Start array: ";
    myArray.Show();
    myArray.SortByName();
    cout << "Sorted by name: ";
    myArray.Show();
    myArray.SortByLength();
    cout << "Sorted by length: ";
    myArray.Show();
    myArray.ShowEmpty();
    myArray.SortByUpperChar();
    cout << "Sorted by upper char: ";
    myArray.Show();
    return 0;
}