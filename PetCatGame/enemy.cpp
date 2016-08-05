#include "enemy.h"

using namespace std;

void enemy::fight(character *other)
{
	other->currentHealth -= damage;
	cout << "They attack " << other->name << " for " << damage << " damage." << endl;
	cout << other->name << " is at " << other->currentHealth << "/" << other->totalHealth << " health." << endl;
}

void enemy::setStats(int level)
{
	int baseStat = 2 * level;
	int x = rand() % baseStat + 1;

	damage = x;
	currentHealth = totalHealth = x * 2;
}

bool enemy::isAlive()
{
	if (currentHealth > 0)
		return true;
	else
		
		return false;
}