#ifndef BATTLEARENA_H
#define BATTLEARENA_H

class Team; 

class BattleArena {
private:
	Team* team1;
	Team* team2;
public:
	BattleArena(Team* t1, Team* t2);
	void startBattle();
};

#endif // BATTLEARENA_H