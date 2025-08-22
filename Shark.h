#ifndef SHARK_H
#define SHARK_H

#include "Animal.h"
#include "Swimable.h"
#include "Strong_Jaws.h"
#include <string>

enum sharkSpecies { Mako, Bull, Great_White, Nurse };

class Shark : public Animal, public Swimable, public Strong_Jaws {
private:
	sharkSpecies specy;
public:
	Shark(std::string n, std::string g, int h, int power, int s, int c, sharkSpecies spec);
	~Shark() override;

	std::string getSpecy() const;
	void displayInfo() const override;
	void bite(Animal* other) override;
	void performAttack(Animal* target) override;
	void swim() override;
	void useSpecialAbility() override;
};

#endif // SHARK_H