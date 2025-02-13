#ifndef _FLOOR_H_
#define _FLOOR_H_

#include "cell.h"
#include <vector>
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

class Floor{
    Player * p;
    int level = 1;
    vector <int> damage;
    vector <char> enemies;
    public:
     int c = 0; //coordinate of player
     int r = 0;
     int sc = 1;// coordinate of stairway
     int sr = 1;
     vector<vector<Cell*>> vv;
     Floor(); //constructor
     void move(string Direction);//move to the direction
     void attack(string Direction);//attack enemy in the direction
     void print();
     ~Floor(); //destructor
     void indEnemyMove(int i, int j); //function for individual enemy to move
     void enemyMove(); //function for all enemies to move
     Player* getPlayer();
     void changePlayer(Player*);
     bool playerCheck(int i, int j); //check if player is within one unit radius
     void indEnemyAttack(int i, int j);
     void enemyAttack(); //funcion for all enemies to attack
     void useItem(string Direction);//use the item in the direction
     void restart();//reset floor for new game
     void newLevel();//reset floor for next level
     int getLevel();
};

#endif
