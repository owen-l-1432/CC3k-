#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "enemy.h"

Decorator* potionGenerator(); // randomly generates a potion
Decorator* goldGenerator(); // randomly generates a pile of gold
Enemy* enemyGenerator(); // randomly generates an enemy

#endif
