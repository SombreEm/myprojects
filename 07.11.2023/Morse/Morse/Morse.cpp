#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>
using namespace std;

class Alpahabets {

public:

	char getChar(int index) {
		return letterUKR[index];
	}
	string getMorseUKR(int index) {
		return morseUKR[index];
	}

private:
	char letterUKR[33] = { 'а','б','в','г','Ґ','д','е','є','ж','з',
						  'и','і','ї','й','к','л','м','н','о','п',
						  'р','с','т','у','ф','х','ц','ч','ш','щ',
						  'ь','ю','я' };
	string morseUKR[33] = { "•- ","-••• ","•-- ","•••• ","--• ","-•• ","• ","••-•• ","•••- ","--•• ",
						   "-•-- ","•• ","•---• ","•--- ","-•- ","•-•• ","-- ","-• ","--- ","•--• ",
						   "•-• ","••• ","-","••- ","••-• ","---- ","-•-• ","---• ","--•- ","--•-- ",
						   "-••- ","••-- ","•-•- " };
};





	//Alpahabets() {
	//	Latalphabet[0] = "•-", // A
	//	Latalphabet[1] = "-•••",// B
	//	Latalphabet[2] = "-•-•",// C
	//	Latalphabet[3] = "-••",// D
	//	Latalphabet[4] = "•",// E
	//	Latalphabet[5] = "••-•",// F
	//	Latalphabet[6] = "--•",// G
	//	Latalphabet[7] = "••••",// H
	//	Latalphabet[8] = "••",// I
	//	Latalphabet[9] = "•---",// J
	//	Latalphabet[10] = "-•-",// K
	//	Latalphabet[11] = "•-••",// L
	//	Latalphabet[12] = "--",// M
	//	Latalphabet[13] = "-•",// N
	//	Latalphabet[14] = "---",// O
	//	Latalphabet[15] = "•--•",// P
	//	Latalphabet[16] = "--•-",// Q
	//	Latalphabet[17] = "•-•",// R
	//	Latalphabet[18] = "•••",// S
	//	Latalphabet[19] = "-",// T
	//	Latalphabet[20] = "••-",// U
	//	Latalphabet[21] = "•••-",// V
	//	Latalphabet[22] = "•--",// W
	//	Latalphabet[23] = "-••-",// X
	//	Latalphabet[24] = "-•--",// Y
	//	Latalphabet[25] = "--••",// Z
	////-----------------------------------------------

	//};



class MorseCoding : public Alpahabets {
private:
	string result;
public:
	MorseCoding(string word) {
		this->result = this->newWord(word);
	}
	string newWord(string word) {
		for (int _char = 0; _char <= word.length(); _char++) {
			for (int letter = 0; letter <= 33; letter++) {
				if (word[_char] == this->getChar(letter)) {
					result+= this->getMorseUKR(letter);
				}
			}
		}
		return result;
	}
	string getResult() {
		return this->result;
	}
};
class MorseDecoding : public Alpahabets {
private:
	string result;

public:
	MorseDecoding(string morseCode) {
		this->result = this->decodeWord(morseCode);
		cout << "Progres NOW" << endl;
	}

	string decodeWord(string morseCode) {
		string decodeword;
		string WordNow ;

		for (int i = 0; i < morseCode.length(); i++) {
			if (morseCode[i] == ' ' || i == morseCode.length() - 1) {
				if (i == morseCode.length() - 1) {
					WordNow += morseCode[i];
					cout << "Progres NOW1" << endl;
				}
				for (int letter = 0; letter < 33; letter++) {
					if (WordNow == this->getMorseUKR(letter)) {
						decodeword += this->getChar(letter);
						break;
					}
				}
				cout << "Progres NOW3" << endl;
				WordNow = "";
			}
			else {
				WordNow += morseCode[i];
			}
		}

		return decodeword;
	}

	string getResult() {
		return this->result;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string word = "новий";
	cout << word<< endl;
	MorseCoding uncoder(word);
	cout << "Morse Code: " << uncoder.getResult() << endl;
	MorseDecoding decoder(word);
	cout << "Ukraine Code: " << decoder.getResult() << endl;
}

