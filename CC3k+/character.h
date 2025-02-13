#ifndef CHARACTER_H
#define CHARACTER_H
#include "item.h"

class Character {
  public:
  char type;
	int health = 0;
	int attack = 0;
	int defence = 0;
	int gold = 0;

protected:
	int pot_defence = 0; // temporary potion effects
	int pot_attack = 0; 

public:
  Character(char type); //constructor
  virtual ~Character(){} //destructor

  int getHealth();    // access health
  int getAttack();    // access attack
  int getDefence();	//access defence
  void changeHealth(int health);

  int virtual death() = 0;
};
#endif

