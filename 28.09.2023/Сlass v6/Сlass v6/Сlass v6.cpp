#include <iostream>
using namespace std;

class Bird {
public:
    string color;
    float weight;
    float height;

    Bird(string _color, float _weight, float _height)
        : color(_color), weight(_weight), height(_height) {
        printInfo();
    }

    void printInfo() {
        cout << "Color: " << color << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Height: " << height << " meters" << endl;
    }
};

class HomeParrot : public Bird {
public:
    string name;
    bool isSpeak;
    bool trained;

    HomeParrot(string _color, float _weight, float _height, string _name, bool _isSpeak, bool _trained)
        : Bird(_color, _weight, _height), name(_name), isSpeak(_isSpeak), trained(_trained) {
        cout << endl << "HomeParrot" << endl;
        cout << "Name: " << name << endl;
        cout << "Can speak: " << (isSpeak ? "Yes" : "No") << endl;
        cout << "Trained: " << (trained ? "Yes" : "No") << endl;
    }

    void Say(string word) {
        cout << word << endl;
    }
};

class Chicken : public Bird {
public:
    string name;
    bool isEgg;
    bool flying;

    Chicken(string _color, float _weight, float _height, string _name, bool _isEgg, bool _flying)
        : Bird(_color, _weight, _height), name(_name), isEgg(_isEgg), flying(_flying) {
        cout << endl << "Chicken" << endl;
        cout << "Name: " << name << endl;
        cout << "Can lay eggs: " << (isEgg ? "Yes" : "No") << endl;
        cout << "Can fly: " << (flying ? "Yes" : "No") << endl;
    }
};

class Woodpecker : public Bird {
public:
    bool woodcutter;
    bool singing;

    Woodpecker(string _color, float _weight, float _height, bool _woodcutter, bool _singing)
        : Bird(_color, _weight, _height), woodcutter(_woodcutter), singing(_singing) {
        cout << endl << "Woodpecker" << endl;
        cout << "Is a woodcutter: " << (woodcutter ? "Yes" : "No") << endl;
        cout << "Can sing: " << (singing ? "Yes" : "No") << endl;
    }
};

class Penguin : public Bird {
public:
    bool swimming;
    bool eatfish;
    bool walkonice;

    Penguin(string _color, float _weight, float _height, bool _swimming, bool _eatfish, bool _walkonice)
        : Bird(_color, _weight, _height), swimming(_swimming), eatfish(_eatfish), walkonice(_walkonice) {
        cout << endl << "Penguin" << endl;
        cout << "Can swim: " << (swimming ? "Yes" : "No") << endl;
        cout << "Eats fish: " << (eatfish ? "Yes" : "No") << endl;
        cout << "Can walk on ice: " << (walkonice ? "Yes" : "No") << endl;
    }
};

class Eagle : public Bird {
public:
    bool fliesfast;
    bool predator;
    bool strong;

    Eagle(string _color, float _weight, float _height, bool _fliesfast, bool _predator, bool _strong)
        : Bird(_color, _weight, _height), fliesfast(_fliesfast), predator(_predator), strong(_strong) {
        cout << endl << "Eagle" << endl;
        cout << "Flies fast: " << (fliesfast ? "Yes" : "No") << endl;
        cout << "Is a predator: " << (predator ? "Yes" : "No") << endl;
        cout << "Is strong: " << (strong ? "Yes" : "No") << endl;
    }
};

int main() {
    HomeParrot myParrot("Brown", 0.5, 0.2, "Billy", true, true);

    Chicken myChicken("White", 0.2, 0.3, "Choka", true, false);

    Woodpecker myWoodpecker("Red", 0.1, 0.15, true, true);

    Penguin myPenguin("Black&White", 1.5, 0.6, true, true, true);

    Eagle myEagle("Brown", 0.5, 1, true, true, true);

    return 0;
}