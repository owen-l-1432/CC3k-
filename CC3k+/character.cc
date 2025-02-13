#include "character.h"

Character::Character(char type):type{type}{}

int Character::getHealth(){
	return this->health;
}

int Character::getDefence(){
	return this->defence+this->pot_defence;
}

int Character::getAttack(){
	return this->attack+this->pot_attack;
}

void Character::changeHealth(int health){
	this->health = health;
}
