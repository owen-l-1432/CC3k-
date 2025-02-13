#include "player.h"
#include "item.h"

Player::Player(char type): Character(type){
	//determine player type
	switch(type){
		case 'd':
			this->type = 'D';
			this->health = 100;
			this->attack = 20;
			this->defence = 30;
			break;
		case 'e':
			this->type = 'E';
			this->health = 140;
			this->attack = 30;
			this->defence = 10;
			break;
		case 'o':
			this->type = 'O';
			this->health = 180;
			this->attack = 30;
			this->defence = 25;
			break;
		case 'h':
			this->type = 'H';
			this->health = 140;
			this->attack = 20;
			this->defence = 20;
	}
}

Player::~Player(){}

int Player::death(){
	if (this->health <= 0){
		return 1;
	} else {
		return 0;
	}
}

void Player::equip(Item* t){
	//determine type of item then equip it accordingly
	switch(t->getType()){
		case 'P':
			if (this->type == 'E'){
				this->health += std::abs(t->health());
				this->pot_defence += std::abs(t->defence());
				this->pot_attack += std::abs(t->attack());

			} else {
				this->health += t->health();
				this->pot_defence += t->defence();
				this->pot_attack += t->attack();
			}
			break;
		case 'G':
			if (this->type == 'D'){
				this->gold += t->gold()*2;

			} else if(this->type == 'O'){
				this->gold += t->gold()/2;
			} else {
				this->gold += t->gold();
			}
			break;
		case 'C':
			this->compass = true;
		case 'B':
			this->barrier = true;
		default:
			break;
		
	}
}

void Player::drop(){
	this->pot_attack = 0;
	this->pot_defence = 0;
	this->compass = false;
}

bool Player::getCompass(){
	return compass;
}

