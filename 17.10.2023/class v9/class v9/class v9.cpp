#include <iostream>

using namespace std;

class Figure {
protected:
	char* line;
	char** box;
public:
	string type;
	char symbol;
	Figure(string type, char symbol) {
		this->symbol = symbol;
		if (type == "line") { 
			this->type = type;
			this->line = new char[4];
			for (int i = 0; i < 4; i++) {
				this->line[i] = this->symbol;
			}
			delete[] box;
		}
		else if (type == "box") {
			this->type = type;
			this->box = new char* [2];
			for (int i = 0; i < 2; i++) {
				this->box[i] = new char[2];
				for (int j = 0; j < 2; j++) {
					this->box[i][j] = symbol;
				}
			}
			delete[] line;
		}
		else { this->type = "error"; }
	}
};
class Field {
public:
	char** array = new char* [10];
	Field() {
		for (int i = 0; i < 10; i++) {
			this->array[i] = new char[10];
			for (int j = 0; j < 10; j++) {
				this->array[i][j] = ' ';
			}
		}
	}
	void addFigure(Figure figure) {
		int x = rand() % 10,
			y = rand() % 10;
		
		bool write = false;

		if (this->array[x][y] == ' ') {
		
			if (figure.type == "line") {
			
				if (x < 7) {
				
					for (int i = x; i < x + 4; i++) {
						if (this->array[y][i] == ' ') {
							write = true;
						}
						else {
							write = false;
							break;
						}
					}

					if (write == true) {
						
						for (int i = x; i < x + 4; i++) {
							this->array[y][i] = figure.symbol;
						}
					
					}
				}
			}
		}
	}
	void showField() {
		for (int i = 0; i < 30; i++) {
			cout << '-';
		}
		cout << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << '|' << array[i][j] << '|';
			}
			cout << endl;
		}
		for (int i = 0; i < 30; i++) {
			cout << '-';
		}
	}
	void addChar(char symbol = '-', int x = 0, int y = 0, int iterator = 4, int start = 3) {
		for (int i = start; i < iterator + start; i++) {
			this->array[y][i] = symbol;
		}
	}
};

int main()
{
	srand(time(NULL));
	Field game;
	Figure first{ "line",'c' };
	game.showField();
	game.addFigure(first);
	cout << endl;
	game.showField();
}
