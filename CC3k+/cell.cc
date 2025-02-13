#include "cell.h"

Cell::Cell(char type, char state): type{type}, state{state} {}

Cell::~Cell() {
    if(e != nullptr){
        delete e;
    }
    if(d != nullptr){
        delete d;
    }
}

char Cell::getState(){
    return state;
}

void Cell::changeState(char state){
    this->state = state;
}

char Cell::getType(){
    return type;
}

void Cell::changeType(char type) {
    this->type = type;
}

char Cell::getChamber(){
    return chamber;
}

void Cell::changeStair(){
    stair = true;
}

bool Cell::getStair(){
    return stair;
}

void Cell::changeChamber(char chamber){
    this->chamber = chamber;
}

void Cell::changeEnemy(Enemy* e){
    this->e = e;
}

void Cell::changeDecorator(Decorator* d){
    this->d = d;
}

Enemy* Cell::getEnemy(){
    return e;
}

Decorator* Cell::getDecorator(){
    return d;
}
