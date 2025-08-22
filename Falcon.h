#ifndef FALCON_H
#define FALCON_H

#include "Animal.h"
#include "Flyable.h" 
#include <string>    

enum tailColour { Black, Gray, Brown };

class Falcon : public Animal, public Flyable {
private:
	tailColour tail_Colour;
public:
	Falcon(std::string n, std::string g, int h, int power, int s, int c, tailColour tail);
	~Falcon() override;

	std::string getTailColour() const;
	void displayInfo() const override;
	void performAttack(Animal* target) override;
	void bite(Animal* other) override;
	void fly() override;
	void useSpecialAbility() override;
};

#endif // FALCON_H