#ifndef _CELL_H_
#define _CELL_H_
#include <iostream>
#include "enemy.h"
#include "item.h"
using namespace std;

class Cell{
  char type;
  char state;
  char chamber;
  Enemy* e = nullptr;
  Decorator* d = nullptr;
  bool stair = false;
 
 public:
  char getState();
  void changeState(char state);
  char getType();
  void changeType(char type);
  char getChamber();
  void changeChamber(char chamber);
  void changeStair();
  bool getStair();
  Enemy* getEnemy();
  void changeEnemy(Enemy* e);
  Decorator* getDecorator();
  void changeDecorator(Decorator* d);
  Cell(char type, char state); //constructor
  ~Cell(); // destructor
};

#endif
