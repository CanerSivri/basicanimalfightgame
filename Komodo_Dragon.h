#ifndef KOMODO_DRAGON_H
#define KOMODO_DRAGON_H

#include "Animal.h"
#include "Terrestrial.h"
#include "Strong_Jaws.h"
#include <string>

class Komodo_Dragon : public Animal, public Terrestrial, public Strong_Jaws {
private:
	bool isItVenomous;
public:
	Komodo_Dragon(std::string n, std::string g, int h, int power, int s, int c, bool venom);
	~Komodo_Dragon() override;

	void displayInfo() const override;
	bool getVenomState() const;
	void performAttack(Animal* target) override;
	void bite(Animal* other) override;
	void run() override;
	void useSpecialAbility() override;
};

#endif // KOMODO_DRAGON_H