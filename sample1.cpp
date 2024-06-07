// sample1.cpp : 
// 
// This program demonstarate simple task of class, inheritance, setter/getter, polymorthism.
// 
// There are three animal classes in this program, DOG, CAT and ELEPHANT each inherited from a parent class MAMMAL
// They all have a name and color. And they introduce themselves and explain how they hunt. 
// 
// Runing this program shows the following.
// Althogh same name methods are called, they all behave differently.
// ----------------------------------------------------------------
// I am Jack, just a mammal and my fur(or skin) is white.
// I hunt in various ways.
// 
// I am a dog named Ken and my fur(or skin) is black.
// I hunt other animals and I hunt in group.
// 
// I am a cat named Leon and my fur(or skin) is brown.
// I hunt other animals and I hunt alone.
// 
// I am an elephant named Mikey and my fur(or skin) is pink.
// I graze grass.
// ----------------------------------------------------------------
//

#include <iostream>
using namespace std;

class Mammal {
protected:
    string Name;
    string Color;
public:
    Mammal(string name, string color) {
        Name = name;
        Color = color;
    }
    virtual void Introduce() {
        cout << "I am " << Name << ", just a mammal and my fur(or skin) is " << Color << "." << endl;
    }
    virtual void Hunt() {
        cout << "I hunt in various ways." << endl;
    }

    // Encapsulation <Setter and Getter>
    void setName(string name) {
        cout << "Name is changed from " << Name << " to " << name << "." << endl;
        Name = name;
    }
    string getName() {
        return Name;
    }
    void setColor(string color) {
        if (color != "") {
            cout << "Color is changed from " << Color << " to " << color << "." << endl;
            Color = color;
        }
    }
    string getColor() {
        return Color;
    }
};

class Dog : public Mammal {
public:
    Dog(string name, string color) :Mammal(name, color) {

    }
    void Introduce() {
        cout << "I am a dog named " << Name << " and my fur(or skin) is " << Color << "." << endl;
    }
    void Hunt() {
        cout << "I hunt other animals and I hunt in group." << endl;
    }
};

class Cat : public Mammal {
public:
    Cat(string name, string color) :Mammal(name, color) {

    }
    void Introduce() {
        cout << "I am a cat named " << Name << " and my fur(or skin) is " << Color << "." << endl;
    }
    void Hunt() {
        cout << "I hunt other animals and I hunt alone." << endl;
    }
};

class Elephant : public Mammal {
public:
    Elephant(string name, string color) :Mammal(name, color) {

    }
    void Introduce() {
        cout << "I am an elephant named " << Name << " and my fur(or skin) is " << Color << "." << endl;
    }
    void Hunt() {
        cout << "I graze grass." << endl;
    }
};

int main()
{
    // Setting four amimals  (  NAME, COLOR )
    Mammal one = Mammal("Jack", "white");
    Dog two = Dog("Ken", "black");
    Cat three = Cat("Leon", "brown");
    Elephant four = Elephant("Mac", "gray");

    // Setter Demonstration
    four.setColor("pink");
    four.setName("Mikey");

    // list of animals
    Mammal* list[] = {&one, &two, &three, &four};

    for (int i = 0; i < sizeof(list)/sizeof(list[0]); i++) {
        cout << endl;
        list[i]->Introduce();
        list[i]->Hunt();
    }

    return 0;
}

