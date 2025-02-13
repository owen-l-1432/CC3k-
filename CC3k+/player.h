#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"
#include "character.h"
#include <cmath>


class Player: public Character {
protected:
  bool barrier=false;
  bool compass=false;

public:
  Player(char type); // constructor
  ~Player(); // destructor
  int death() override; // death function of player
  void equip(Item* t) ; // equip an item the PC picked up
  void drop(); // drop potion effects at end of level
  bool getCompass();// whether PC has a compass
};
#endif
