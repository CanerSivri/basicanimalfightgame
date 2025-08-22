#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>

class Animal;

class Trainer {
private:
	std::string name;
	std::vector<Animal*> trainedAnimals;
public:
	Trainer(std::string n);
	~Trainer();

	std::string getTrainerName() const;
	void addAnimal(Animal* animal);
	void buffAttack(int amount);
	void buffHealth(int amount);
	void buffCondition(int amount);
	void buffAll(int amountAttack, int amountHealth, int amountCondition);
	void displayTrainedAnimals() const;
	bool hasTrainedAnimals() const;
};

#endif // TRAINER_H