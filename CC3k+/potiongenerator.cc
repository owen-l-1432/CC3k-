#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "item.h"
#include "potiongenerator.h"
#include "enemy.h"
#include "seed.h"
using namespace std;

Decorator* potionGenerator(){
    Decorator* d;
    vector<int> v = { 1, 2, 3, 4, 5, 6};
    std::shuffle( v.begin(), v.end(), rng );
    // generates potion according to probability required
    int r = v[0] ;
    if (r == 1){
        d = new RH();
    } 
    else if (r == 2){
        d =  new PH();
    }
    else if (r == 3){
        d =  new BA();
    }
    else if (r == 4){
        d =   new BD();
    }
    else if (r == 5){
        d =  new WA();
    }
    else if (r == 6){
        d =  new WD();
    }
    return d;
}

Decorator* goldGenerator(){
    Decorator* d;
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8};
    std::shuffle( v.begin(), v.end(), rng);
    int r = v[0] ;
    //generates gold according to probability required
    if (r == 1){
        d = new DHoard();
    } 
    else if (r == 2 || r == 3){
        d = new Small();
    } else {
        d = new Normal();
    }
    return d;
}

Enemy* enemyGenerator(){
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12, 13, 14, 15, 16, 17, 18};
    std::shuffle( v.begin(), v.end(), rng );
    int r = v[0] ;
    Enemy* e;
    //generate enemy according to prabability required
    if (r == 1 || r == 2 || r == 3 || r == 4){
        e = new Enemy('w');
    }  else if (r == 5 || r == 6 || r == 7){
        e =  new Enemy('v');
    } else if (r == 8 || r == 9){
        e =  new Enemy('t');
    } else if (r == 10 || r == 11){
        e =  new Enemy('p');
    } else if (r == 12 || r == 13){
        e =  new Enemy('m');
    } else {
        e =  new Enemy('g');
    } 
    return e;
}





