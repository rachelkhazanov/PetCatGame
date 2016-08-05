
#include <iostream>>
#include <string> 
#include <thread>
#include <chrono>

#include "player.h"
#include "enemy.h"

using namespace std;

void delayScroll(int delayMS, int lineCount);
character* generateEnemy();
void encounterEnemy(character *player, character *enemy);
void fightDecisions(character *player);
void nextDecision(character *player);

void delayScroll(int delayMS, int lineCount)
{
	for (int i = 0; i < lineCount; i++)
	{
		cout << "" << endl;
		this_thread::sleep_for(chrono::milliseconds(delayMS));
	}
}

character* generateEnemy()
{
	character *e = new enemy("the alley cats", "Wet cats are never happy");
	e->setStats(1);
	return e;
}

void encounterEnemy(character *player, character *enemy)
{
	while (player->isAlive() && enemy->isAlive())
	{
		player->fight(enemy);
		if (enemy->isAlive()) {
			enemy->fight(player);
			nextDecision(player);
		}
		delayScroll(1000, 1);
	}
	cout << "Kitty runs out of the alley and finds his way home. You dry, cuddle, and pet him. Yay!" << endl;
	
}

void nextDecision(character *player)
{
	if (player->isAlive())
	{
		character *anEnemy = generateEnemy();
		int option = 0;
		delayScroll(1000, 1);
		cout << "Should kitty continue fighting or run away?" << endl;
		cout << "1. Continue fighting." << endl;
		cout << "2. Run away." << endl;
		cout << ">";
		cin >> option;

		if (option == 1)
			encounterEnemy(player, anEnemy);
		else
			cout << "He quickly finds his way home and you dry, cuddle, and pet him." << endl;
	}
	else
	{
		cout << "Kitty dies. Sorry." << endl;
	}
}



void fightDecisions(character *player)
{
	if (player->isAlive())
	{
		character *anEnemy = generateEnemy();
		int option = 0;
		cout << "It starts to rain. What should kitty do?" << endl;
		cout << "1. Hide under the awning in the alleyway." << endl;
		cout << "2. Keep looking for your home in the rain." << endl;
		cout << ">";
		cin >> option;

		if (option == 1)
		{
			cout << "Several alley cats jump out of a dumpster and attack your kitty." << endl;
			encounterEnemy(player, anEnemy);
			delayScroll(4000, 1);
		}
		else
			cout << "He quickly finds his way home and you dry, cuddle, and pet him." << endl;
	}
	else
	{
		cout << "You win! Hope you enjoyed!" << endl;
	}
}

int main()
{
	srand(time(NULL));
	string intro =

		"			_             _				\n"
		"          | '-.       .-' |			\n"
		"           \'-.'-" " - '.-'	_		\n"
		"            |= _:'.':_ =|    /:`)		\n"
		"            \ <6>   <6> /   /  /		\n"
		"            |=   |_|   =|   |:'\		\n"
		"            >\:. ''  .: /<   ) .|		\n"
		"             /'-._^_.-'\    /.:/		\n"
		"            /::.     .::\  /' /		\n"
		"          .| '::.  .::'  |;.:/			\n"
		"         /`\:.         .:/`\(			\n"
		"        |:. | ':.   .:' | .:|			\n"
		"        | ` |:.;     ;.:| ` |			\n"
		"         \:.|  |:. .:|  |.:/			\n"
		"          \ |:.|     |.:| /			\n"
		"          /'|  |\   /|  |`\			\n"
		"         (,,/:.|.-'-.|.:\,,)			\n"
		"           (,,,/     \,,,)				\n"

		"  Adventure Time with Kitty \n";

	cout << intro << endl;

	string playerName;

	cout << "What is your pet cat's name?" << endl;
	cout << "> ";
	cin >> playerName;
	cout << "Excellent! Let's get started with " << playerName << "'s Adventure! " << playerName << " accidentally got lost. Help him get home!" << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	delayScroll(10, 30);

	character *petCat = new player(playerName, "just a cat on his own...");
	petCat->setStats(4);

	fightDecisions(petCat);
}