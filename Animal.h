#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream> 

class Animal {
private:
	std::string name;
	std::string gender;
	int health;
	int attackPower;
	int speed;
	int condition;
public:
	static int totalAnimals;
	Animal(std::string n, std::string g, int h, int power, int s, int c);
	virtual ~Animal();

	std::string getName() const;
	std::string getGender() const;
	int getHealth() const;
	void setHealth(int new_health);
	void increaseHealth(int h);
	int getPower() const;
	void increasePower(int power);
	int getSpeed() const;
	void increaseSpeed(int increase);
	int getCondition() const;
	void increaseCondition(int amount);
	void decreaseCondition(int amount);

	virtual void displayInfo() const;
	virtual void performAttack(Animal* target) = 0;
	virtual void bite(Animal* other) = 0;
	virtual void useSpecialAbility() = 0;
	static void getAnimalCount();
};

#endif // ANIMAL_H