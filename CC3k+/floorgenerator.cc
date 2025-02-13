#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "cell.h"
#include "floor.h"
#include "enemy.h"
#include "floorgenerator.h"
#include "potiongenerator.h" 
#include "seed.h"

using namespace std;


void floorgenerator(Floor *f){
    const int row = 25;
    const int col = 79;
    vector<Cell*> v;
    //player spawning
    for (int i = 0; i < row;  i++){
        for (int j = 0; j < col; j++){
            if (f->vv[i][j]->getType() == 'F'){
                v.emplace_back(f->vv[i][j]);
            }
        }
    }
    std::shuffle( v.begin(), v.end(), rng);
    v[0]->changeState('P');
    char chamber = v[0]->getChamber();
    v.clear();
    for (int i = 0; i < row;  i++){
            for (int j = 0; j < col; j++){
                if (f->vv[i][j]->getState() == 'P'){
                    f->c = j;
                    f->r = i;
             }
        }           
    }
    //stair generator
    for (int i = 0; i < row;  i++){
        for (int j = 0; j < col; j++){
            if (f->vv[i][j]->getType() == 'F' && f->vv[i][j]->getState() == 'Y' && f->vv[i][j]->getChamber() != chamber){
                v.emplace_back(f->vv[i][j]);
            }
        }
    }
    std::shuffle( v.begin(), v.end(), rng);
    v[0]->changeStair(); 
    for (int i = 0; i < row;  i++){
            for (int j = 0; j < col; j++){
                if (f->vv[i][j]->getStair()){
                    f->sc = j;
                    f->sr = i;
             }
        }           
    }  
    v.clear();
    //generate potion
    for (int k = 0; k < 10; k++){
        vector<char> r = {'1', '2', '3', '4' ,'5'};
        std::shuffle(r.begin(), r.end(), rng);
        char c = r[0];
        for (int i = 0; i < row;  i++){
            for (int j = 0; j < col; j++){
                if ((f->vv[i][j]->getType() == 'F' && f->vv[i][j]->getState() == 'Y') && f->vv[i][j]->getChamber() == c && !f->vv[i][j]->getStair()){
                    v.emplace_back(f->vv[i][j]);
                }
            }           
        }        
        std::shuffle( v.begin(), v.end(), rng);
        v[0]->changeState('O');
        v[0]->changeDecorator(potionGenerator());
        v.clear();      
    }
    //Generate gold
    for (int k = 0; k < 10; k++){
        vector<char> r = {'1', '2', '3', '4' ,'5'};
        std::shuffle(r.begin(), r.end(), rng);
        char c = r[0];
        for (int i = 0; i < row;  i++){
            for (int j = 0; j < col; j++){
                if ((f->vv[i][j]->getType() == 'F' && f->vv[i][j]->getState() == 'Y') && f->vv[i][j]->getChamber() == c && !f->vv[i][j]->getStair()){
                    v.emplace_back(f->vv[i][j]);
                }
            }           
        }        
        std::shuffle( v.begin(), v.end(), rng);
        v[0]->changeState('G');
        v[0]->changeDecorator(goldGenerator());
        v.clear();      
    }
    //Dragon generator
    for (int i = 0; i < row;  i++){
        for (int j = 0; j < col; j++){
            if (f->vv[i][j]->getState() == 'G'){
                if (f->vv[i][j]->getDecorator()->getType() == 'D'){
                    for (int a = -1; a < 2; a++){
                        for (int b = -1; b < 2; b++){
                            if(f->vv[i+a][j+b]->getType() == 'F' && f->vv[i+a][j+b]->getState() == 'Y' && !f->vv[i+a][j+b]->getStair()){
                                v.emplace_back(f->vv[i+a][j+b]);
                            }
                        }
                    }
                    std::shuffle( v.begin(), v.end(), rng);
                    v[0]->changeState('D');
                    Enemy * e = new Enemy('D');
                    v[0]->changeEnemy(e);

                }

            }
            v.clear();
        }
    }
    //generate enemy
    for (int i = 0; i < row;  i++){
        for (int j = 0; j < col; j++){
            if (f->vv[i][j]->getType() == 'F' && f->vv[i][j]->getState() == 'Y'){
                v.emplace_back(f->vv[i][j]);
            }
        }
    }
    std::shuffle( v.begin(), v.end(), rng);
    for (int i = 0; i < 20; i++){
        v[i]->changeState('E');
        v[i]->changeEnemy(enemyGenerator());
    }
    v[0]->getEnemy()->changeCompass(true);
    v.clear();

}
