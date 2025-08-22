#include "BattleArena.h"
#include "Team.h"   
#include "Animal.h" 
#include <iostream>
#include <vector> 

using namespace std;

BattleArena::BattleArena(Team* t1, Team* t2) {
	team1 = t1;
	team2 = t2;
}

void BattleArena::startBattle() {
	cout << "\n~~~ BATTLE STARTED BETWEEN TEAMS ~~~" << endl;
	vector<Animal*>& animals1 = team1->getAnimals();
	vector<Animal*>& animals2 = team2->getAnimals();
	int i = 0, j = 0; 
	while (i < animals1.size() && j < animals2.size()) { 
		Animal* a1 = animals1[i];
		Animal* a2 = animals2[j];
		cout << "\n~~~ ROUND " << (i + j + 1) << " ~~~" << endl; 
		cout << team1->getTeamName() << "'s " << a1->getName() << " attacks " << a2->getName() << "!" << endl;
		a1->useSpecialAbility();
		a1->bite(a2);
		a1->performAttack(a2); 
		if (a2->getHealth() <= 0) {
			cout << a2->getName() << " has fainted!" << endl;
			j++;
			continue; 
		}
		cout << team2->getTeamName() << "'s " << a2->getName() << " attacks " << a1->getName() << "!" << endl;
		a2->useSpecialAbility();
		a2->bite(a1);
		a2->performAttack(a1); 
		if (a1->getHealth() <= 0) {
			cout << a1->getName() << " has fainted!" << endl;
			i++;
		}
	}
	cout << "\n~~~ BATTLE ENDED ~~~" << endl;
	if (i == animals1.size() && j == animals2.size()) {
		cout << "It's a draw! All animals have fainted." << endl;
	}
	else if (i == animals1.size()) {
		cout << team2->getTeamName() << " wins the battle!" << endl;
	}
	else {
		cout << team1->getTeamName() << " wins the battle!" << endl;
	}
}