#include "player.h"
#include "enemy.h"
#include "character.h"

Enemy::Enemy(char type): Character(type){
	// for different type of enemies
	switch(type){
		case 'v':
			this->type = 'V';
			this->health = 50;
			this->attack = 25;
			this->defence = 25;
			hostile = true;
			break;
		case 'w':
			this->type = 'W';
			this->health = 120;
			this->attack = 30;
			this->defence = 5;
			hostile = true;
			break;
		case 'g':
			this->type = 'N';
			this->health = 70;
			this->attack = 5;
			this->defence = 10;
			hostile = true;
			break;
		case 't':
			this->type = 'T';
			this->health = 120;
			this->attack = 25;
			this->defence = 15;
			hostile = true;
			break;
		case 'm':
			this->type = 'M';
			this->health = 30;
			this->attack = 70;
			this->defence = 5;
			hostile = false;
			break;
		case 'd':
			this->type = 'D';
			this->health = 150;
			this->attack = 20;
			this->defence = 20;
			hostile = true;
			break;
		case 'p':
			this->type = 'X';
			this->health = 50;
			this->attack = 35;
			this->defence = 20;
			hostile = true;
			break;
		default:
			break;
	}
}

int Enemy::death(){
	if (compass && health <= 0){
		return 4;
	}
	//death of different types of enemy
	switch(this->type){
		case 'M':
				if (this->health <= 0){
					return 2;
				} else {
					return 0;
				}
				break;
		case 'D':
			if (this->health <= 0){
					return 3;
				} else {
					return 0;
				}
			break;
		default:
			break;
	}
	if (this->health <= 0){
		return 1;
	} else {
		return 0;
	}
}

int Enemy::getCol(){
	return col;
}

int Enemy::getRow(){
	return row;
}

void Enemy::changeCol(int col){
	this->col = col;
}

void Enemy::changeRow(int row){
	this->row = row;
}

bool Enemy::getMoved(){
	return moved;
}

void Enemy::changeMoved(bool moved){
	this->moved = moved;
}

bool Enemy::getCompass(){
	return this->compass;
}

void Enemy::changeCompass(bool compass){
	this->compass = compass;
}
