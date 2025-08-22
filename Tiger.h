#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"
#include "Terrestrial.h"
#include "Strong_Jaws.h"
#include <string>

class Tiger : public Animal, public Terrestrial, public Strong_Jaws {
private:
	double max_jump;
public:
	Tiger(std::string n, std::string g, int h, int power, int s, int c, double jump);
	~Tiger() override;

	double getJumpHeight() const;
	void increaseJumpHeight(double height);
	void displayInfo() const override;
	void performAttack(Animal* target) override;
	void run() override;
	void useSpecialAbility() override;
	void bite(Animal* other) override;
};

#endif // TIGER_H