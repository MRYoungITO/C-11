#include <iostream>
#include <Windows.h>

using namespace std;

class Animal {
public:
	virtual void cry() = 0;
};

class Cat : public Animal {
public:
	virtual void cry() {
		cout << "������" << endl;
	}

	void play() {
		cout << "������" << endl;
	}

};

class Dog : public Animal {
public:
	virtual void cry() {
		cout << "������" << endl;
	}

	void play() {
		cout << "������" << endl;
	}
};

void animalPlay(Animal& animal) {
	animal.cry();

	try {
		Dog& pDog = dynamic_cast<Dog&>(animal);
		pDog.play();
	}
	catch (std::bad_cast bc) {
		cout << "���ǹ�, ��Ӧ����è" << endl;
	}
	

	try {
		Cat& pCat = dynamic_cast<Cat&>(animal);
		pCat.play();
	}
	catch (std::bad_cast bc) {
		cout << "����è, ��Ӧ��������Ĺ�" << endl;
	}
}

void animalPlay(Animal* animal) {
	animal->cry();

	Dog* pDog = dynamic_cast<Dog*>(animal);
	if (pDog) {
		pDog->play();
	}
	else { //pDog == NULL
		cout << "���ǹ�, ��ƭ��! " << endl;
	}

	Cat* pCat = dynamic_cast<Cat*>(animal);
	if (pCat) {
		pCat->play();
	}
	else { //pCat == NULL
		cout << "����è, ��ƭ��! " << endl;
	}
}

int main(void) {

	Dog* dog1 = new Dog();
	Animal* a1 = dog1;

	//animalPlay(a1);
	Dog dog2;
	animalPlay(dog2);

	Cat* cat1 = new Cat();
	Animal* a2 = cat1;

	//animalPlay(a2);
	Cat cat2;
	animalPlay(cat2);

	system("pause");
	return 0;
}