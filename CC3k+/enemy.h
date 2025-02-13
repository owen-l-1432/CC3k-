#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"


class Enemy: public Character {
  int row;
  int col;
  bool hostile;
  bool moved;
  bool compass; //if the enemy holds compass
 public:
  Enemy(char type); //constructor
  ~Enemy(){}; //destructor
  int getRow();
  int getCol();
  void changeRow(int row);
  void changeCol(int col);
  bool getCompass();
  void changeCompass(bool compass);
  bool getMoved();
  void changeMoved(bool moved);
  int death() override;
  
};
#endif
