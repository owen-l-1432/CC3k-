#include "item.h"

void Item::setType(char Type){
    this->Type = Type;
}

char Item::getType(){
    return Type;
}

int Decorator ::attack(){
    return 0;
}

int Decorator ::health(){
    return 0;
}

int Decorator ::gold(){
    return 0;
}

int Decorator ::defence(){
    return 0;
}


RH::RH(){
    setType('P');
}

int RH::health(){
    return 10;
}

BA::BA(){
    setType('P');
}

int BA::attack(){
    return  5;
}

BD::BD(){
    setType('P');
}

int BD::defence(){
    return  5;
}

PH::PH(){
    setType('P');
}

int PH::health(){
    return - 10;
}

WA::WA(){
    setType('P');
}

int WA::attack(){
    return - 5;
}

WD::WD(){
    setType('P');
}

int WD::defence(){
    return - 5;
}

Normal::Normal(){
    setType('G');
}

int Normal::gold(){
    return 1;
}

Small::Small(){
    setType('G');
}

int Small::gold(){
    return 2;
}

MHoard::MHoard(){
    setType('G');
}

int MHoard::gold(){
    return 4;
}

DHoard::DHoard(){
    setType('D');
}

int DHoard::gold(){
    return 6;
}

Compass::Compass(){
    setType('C');
}

bool Compass::PickedCompass(){
    return true;
}

BarrierSuit::BarrierSuit(){
    setType('B');
}

bool BarrierSuit::PickedBarrierSuit(){
    return true;
}


