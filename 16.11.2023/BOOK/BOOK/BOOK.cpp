#include <iostream>

using namespace std;
class Entry {
private:
	string title;
	string description;
public: 
	Entry getEntry(string title = "", string discription = "") {
		Entry newEntry;
		newEntry.title = title;
		newEntry.description = discription;
		return newEntry;
	}
};


class Time: public Entry {
private:
	static int hours;
	static int minutes;
	string time;
	Entry entry = this->getEntry();
public:
	Time(int hours, int minutes) {
		hours >= 0 && hours <= 24 ? this->hours = hours : this->hours = 0;
		minutes >= 0 && minutes <= 60 ? this->minutes = minutes : this->minutes = 0;
		time = hours + ":" + minutes;
	}
};

class Minutes {
private:
	Entry array[60];
};

class Hours {
private:
	Minutes minutes[60];
};

class Day{
private:
	Hours hours[24];
};

class Month {
private:
	string nameList[12] = { "January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December", };
	Day day[12];
public:
	string name;
	Month(int number = 0) {
		this->name = nameList[number];
	}
};
class Year {
private:
	int year;
	Month month[12];
public:
	Year(int year = 1950) {
		this->year = year;
		for (int i = 0; i < 12; i++) {
			this->month[i] = i;

		}
	}
	int SetYear(int year) {
		this->year = year;
	}
	int getYear() {
		return this->year;
	}
	string getmont(int number) {
		return this->month->name;
	}
};
class Book {
private:
	Year year;
public:
	void create(int year) {
		this->year = year;
	}
	void showInfo() {
		cout << this->year.getYear();
	}
};
int main()
{
  
}