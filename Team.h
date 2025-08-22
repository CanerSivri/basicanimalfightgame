#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>

class Animal; 

class Team {
private:
	std::string teamName;
	std::vector<Animal*> animals;
public:
	Team(std::string name);
	~Team(); // Orijinalde boþtu

	std::string getTeamName() const;
	void addAnimal(Animal* animal);
	void removeAnimalfromTeam(int i);
	int getTotalHealth() const;
	int getTotalAttackPower() const;
	double getAverageCondition() const;
	void displayTeamStatus() const;
	std::vector<Animal*>& getAnimals();
};

#endif // TEAM_H