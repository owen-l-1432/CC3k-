#include "floor.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include <cmath>
#include "player.h"
#include "seed.h"
using namespace std;
//please refer to the .h file for information

const int column = 79;
const int row = 25;

Floor::~Floor(){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            delete(vv[i][j]);
        }
    }
    delete p;
}

Floor::Floor() {
    vector<Cell*> v;
    for (int i = 0; i < row; i++) {
        vv.emplace_back(v);
        for (int j = 0; j < column; j++) {
            Cell * c = new Cell('E', 'Y');
            vv[i].emplace_back(c);
        }
    }

    for (int i = 0; i < row; i++) {
        if (i == 0) { // row1
            for (int j = 0; j < column; j++) {
                if (j == 0 || j == 78) {
                    vv[i][j]->changeType('V');
                } else {
                    vv[i][j]->changeType('H');
                }
            }
        }
        
        if (i == 1) { //row2
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
        } 

        if (i == 2) { //row3
             for (int j = 2; j < 30; j++) {
                 if (j == 2 || j == 29) {
                     vv[i][j]->changeType('V');
                 } else {
                     vv[i][j]->changeType('H');
                 }
             }
             for (int j = 38; j < 63; j++) {
                 if (j == 38 || j == 62) {
                     vv[i][j]->changeType('V');
                 } else {
                     vv[i][j]->changeType('H');
                 }
             } 
             vv[i][0]->changeType('V');
             vv[i][78]->changeType('V');
        }

        if (i == 3) { //row4
            for (int j = 3; j < 29; j++) {
                vv[i][j]->changeType('F');
            }
            for (int j = 39; j < 62; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][0]->changeType('V');
            vv[i][2]->changeType('V');
            vv[i][29]->changeType('V');
            vv[i][38]->changeType('V');
            vv[i][62]->changeType('V');
            vv[i][78]->changeType('V');
        }

        if (i == 4) { //row5
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][2]->changeType('V');
            for (int j = 3; j < 29; j++) {
                vv[i][j]->changeType('F');
            }
            for (int j = 29; j < 39; j++) {
                if (j == 29 || j == 38) {
                    vv[i][j]->changeType('D');
                } else {
                    vv[i][j]->changeType('P');
                }
            }
            for (int j = 39; j < 62; j++) {
                vv[i][j]->changeType('F');
            }
            for (int j = 62; j < 71; j++) {
                if (j == 62 || j == 70) {
                    vv[i][j]->changeType('V');
                } else {
                    vv[i][j]->changeType('H');
                }
            }
        }

        if (i == 5) { //row6
            for (int j = 3; j < 29; j++) {
                vv[i][j]->changeType('F');
            }
            for (int j = 39; j < 70; j++) {
                vv[i][j]->changeType('F');
            }//0, 2, 29, 38, 70, 71, 72, 73, 78
            vv[i][0]->changeType('V');
            vv[i][2]->changeType('V');
            vv[i][29]->changeType('V');
            vv[i][38]->changeType('V');
            vv[i][70]->changeType('V');
            vv[i][71]->changeType('H');
            vv[i][72]->changeType('H');
            vv[i][73]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][33]->changeType('P');
    }

        if (i == 6) { //row7
            for (int j = 3; j < 29; j++) {
                vv[i][j]->changeType('F');
            }
            for (int j = 39; j < 73; j++) {
                vv[i][j]->changeType('F');
            }//0, 2, 29, 38, 70, 71, 72, 73, 78
            vv[i][0]->changeType('V');
            vv[i][2]->changeType('V');
            vv[i][29]->changeType('V');
            vv[i][38]->changeType('V');
            vv[i][73]->changeType('V');
            vv[i][74]->changeType('H');
            vv[i][75]->changeType('H');
            vv[i][76]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][33]->changeType('P');
        }

        if (i == 7) { //row 8
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            for (int j = 2; j < 30; j++) {
                if (j == 2 || j == 29) {
                    vv[i][j]->changeType('V');
                } else {
                vv[i][j]->changeType('H');
                }
            }
            vv[i][13]->changeType('D');
            vv[i][33]->changeType('P');
            for (int j = 38; j < 61; j++) {
                if (j == 38 || j == 60) {
                    vv[i][j]->changeType('V');
                } else {
                vv[i][j]->changeType('H');
                }
            }
            vv[i][43]->changeType('D');
            for (int j = 61; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 8) { //row 9
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][13]->changeType('P');
            for (int j = 31; j < 44; j++) {
                vv[i][j]->changeType('P');
            }
            vv[i][60]->changeType('V');
            for (int j = 61; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }
        
        if (i == 9) { //row 10
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][13]->changeType('P');
            vv[i][31]->changeType('P');
            for(int j = 37; j < 51; j++) {
                if (j == 37 || j == 50) {
                    vv[i][j]->changeType('V');
                } else {
                    vv[i][j]->changeType('H');
                }
            }
            vv[i][43]->changeType('D');
            vv[i][60]->changeType('V');
            for (int j = 61; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 10) { //row 11
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][13]->changeType('P');
            vv[i][31]->changeType('P');
            vv[i][37]->changeType('V');
            for (int j = 38; j < 50; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][50]->changeType('V');
            vv[i][60]->changeType('V');
            for (int j = 61; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 11) {//row 12
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            for (int j = 13; j < 32; j++) {
                vv[i][j]->changeType('P');
            }
            vv[i][37]->changeType('V');
            for (int j = 38; j < 50; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][50]->changeType('V');
            for(int j = 54; j < 60; j++) {
                vv[i][j]->changeType('P');
            }
            vv[i][60]->changeType('D'); 
            for (int j = 61; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 12) {//row 13
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][13]->changeType('P');
            vv[i][31]->changeType('P');
            vv[i][37]->changeType('V');
            for (int j = 38; j < 50; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][50]->changeType('V');
            vv[i][54]->changeType('P');
            vv[i][60]->changeType('V');
            for (int j = 61; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 13) {//row14
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][13]->changeType('P');
            vv[i][31]->changeType('P');
            vv[i][37]->changeType('V');
            for (int j = 38; j < 50; j++) {
                vv[i][j]->changeType('H');
            }
            vv[i][43]->changeType('D');
            vv[i][50]->changeType('V');
            vv[i][54]->changeType('P');
            vv[i][60]->changeType('V');
            for (int j = 61; j < 76; j++) {
                vv[i][j]->changeType('H');
            }
            vv[i][69]->changeType('D');
            vv[i][76]->changeType('V');
        }

        if (i == 14) {//row15
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            for(int j = 3; j < 26; j++) {
                if (j == 3 || j == 25) {
                    vv[i][j]->changeType('V');
                } else {
                    vv[i][j]->changeType('H');
                }
            }
            vv[i][13]->changeType('D');
            vv[i][31]->changeType('P');
            vv[i][43]->changeType('P');
            vv[i][54]->changeType('P');
            vv[i][69]->changeType('P');
        }

        if (i == 15) {//row 16
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][3]->changeType('V');
            for (int j = 4; j < 25; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][25]->changeType('V');
            vv[i][31]->changeType('P');
            vv[i][43]->changeType('P');
            vv[i][54]->changeType('P');
            for (int j = 64; j < 77; j++) {
                if (j == 64 || j == 76) {
                    vv[i][j]->changeType('V');
                } else {
                    vv[i][j]->changeType('H');
                }
            }
            vv[i][69]->changeType('D');
        }

        if (i == 16) {//row 17
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][3]->changeType('V');
            for (int j = 4; j < 25; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][25]->changeType('V');
            for (int j = 31; j < 55; j++) {
                vv[i][j]->changeType('P');
            }
            vv[i][64]->changeType('V');
            for (int j = 65; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 17){//row18
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][3]->changeType('V');
            for (int j = 4; j < 25; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][25]->changeType('V');
            vv[i][31]->changeType('P');
            vv[i][43]->changeType('P');
            vv[i][64]->changeType('V');
            for (int j = 65; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 18) {//row19
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][3]->changeType('V');
            for (int j = 4; j < 25; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][25]->changeType('V');
            vv[i][31]->changeType('P');
            for (int j = 36; j < 65; j++) {
                if (j == 36 || j == 64) {
                    vv[i][j]->changeType('V');
                } else {
                    vv[i][j]->changeType('H');
                }
            }
            vv[i][43]->changeType('D');
            for (int j = 65; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }
        if (i == 19) {//row 20
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][3]->changeType('V');
            for (int j = 4; j < 25; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][25]->changeType('V');
            vv[i][31]->changeType('P');
            vv[i][36]->changeType('V');
            for (int j = 37; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 20) {//row 21
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][3]->changeType('V');
            for (int j = 4; j < 25; j++) {
                vv[i][j]->changeType('F');
            }
            for (int j = 25; j < 37; j++) {
                if (j == 25 || j == 36) {
                    vv[i][j]->changeType('D');
                } else {
                    vv[i][j]->changeType('P');
                }
            }
            for (int j = 37; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if(i == 21){//row 22
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][3]->changeType('V');
            for (int j = 4; j < 25; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][25]->changeType('V');
            vv[i][36]->changeType('V');
            for (int j = 37; j < 76; j++) {
                vv[i][j]->changeType('F');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 22) {//row 23
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
            vv[i][3]->changeType('V');
            for (int j = 4; j < 25; j++) {
                vv[i][j]->changeType('H');
            }
            vv[i][25]->changeType('V');
            vv[i][36]->changeType('V');
            for (int j = 37; j < 76; j++) {
                vv[i][j]->changeType('H');
            }
            vv[i][76]->changeType('V');
        }

        if (i == 23) {//row 24
            vv[i][0]->changeType('V');
            vv[i][78]->changeType('V');
        }

        if (i == 24) {//row25
            for (int j = 0; j < 79; j++) {
                if (j == 0 || j == 78) {
                    vv[i][j]->changeType('V');
                } else {
                    vv[i][j]->changeType('H');
                }
            }
        }
    }
    for (int k = 3; k < 7; k++) {
    for (int l = 3; l < 29; l++) {
        (vv[k][l])->changeChamber('1');
    }
}



for (int k = 15; k < 22; k++) {
    for (int l = 4; l < 25; l++) {
        (vv[k][l])->changeChamber('2');
    }
}



for (int k = 3; k < 7; k++) {
    for (int l = 39; l < 62; l++) {
        (vv[k][l])->changeChamber('3');
    }
}

for(int l = 62; l < 70; l++) {
    (vv[5][l])->changeChamber('3');
}

for(int l = 62; l < 73; l++) {
    (vv[6][l])->changeChamber('3');
}

for (int k = 7; k < 13; k++) {
    for (int l = 61; l < 76; l++) {
        (vv[k][l])->changeChamber('3');
    }
}



for (int k = 10; k < 13; k++) {
    for (int l = 38; l < 50; l++) {
        (vv[k][l])->changeChamber('4');
    }
}



for (int k = 16; k < 19; k++) {
    for (int l = 65; l < 76; l++) {
        (vv[k][l])->changeChamber('5');
    }
}

for (int k = 19; k < 22; k++) {
    for (int l = 37; l < 76; l++) {
        (vv[k][l])->changeChamber('5');
    }
}
}

void Floor::print(){
    for (int i = 0; i < 25; i++)  {
        for (int j = 0; j < 79; j++) {
            if (/*p->getCompass() &&*/ i == sr && j == sc){
                cout << '\\';
                continue;
            }           
            if (vv[i][j]->getType() == 'V') {
                cout << '|';
            } else if (vv[i][j]->getType() == 'H') {
                cout << '-';
            } else if (vv[i][j]->getType() == 'D') {
                if (vv[i][j]->getState() == 'P'){
                    cout << '@';
                } else {
                    cout << '+';
                }
            } else if (vv[i][j]->getType() == 'P') {
                if (vv[i][j]->getState() == 'P'){
                    cout << '@';
                } else {
                    cout << '#';
                }
            } else if (vv[i][j]->getType() == 'E') {
                cout << ' ';
            } else if (vv[i][j]->getType() == 'F') {
                if (vv[i][j]->getState() == 'Y'){
                    cout << '.';
                } else if (vv[i][j]->getState() == 'O'){
                    cout << 'P';
                } else if (vv[i][j]->getState() == 'G'){
                    cout << 'G';
                } else if (vv[i][j]->getState() == 'P'){
                    cout << "@";
                } else if (vv[i][j]->getState() == 'E'){
                    cout << vv[i][j]->getEnemy()->type;
                } else if (vv[i][j]->getState() == 'D'){
                    cout << 'D';
                } else if (vv[i][j]->getState() == 'C'){
                    cout << 'C';
                }
            }
        }
        cout << '\n';
    }
        cout << "Race: ";
        if (p->type == 'H'){
            cout << "Human";
        }
        if (p->type == 'O'){
            cout << "Orc";
        }
        if (p->type == 'E'){
            cout << "Elves";
        }
        if (p->type == 'D'){
            cout << "Dwarf";
        }
        cout << " Gold: " << p->gold;
        cout << "                                                    " << "Floor " << level << endl; 
        cout << "HP: " << p->getHealth() << endl;
        cout << "Atk: " << p->getAttack() << endl;
        cout << "Def: " << p->getDefence() << endl;
        cout << "Action:";
        if (p->death() == 1) {
            cout << "You have died. Please choose to restart(r), or quit(q):" << endl;
        }
}

void Floor::restart() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            if (vv[i][j]->getType() == 'F' && vv[i][j]->getState() != 'Y') {
                if (vv[i][j]->getEnemy() != nullptr){
                    delete vv[i][j]->getEnemy();
                }
                if (vv[i][j]->getDecorator() != nullptr){
                    delete vv[i][j]->getDecorator();
                }
                vv[i][j]->changeEnemy(nullptr);
                vv[i][j]->changeDecorator(nullptr);
                vv[i][j]->changeState('Y');
            }
        }
    }
    level = 1;
}

void Floor::newLevel() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            if (vv[i][j]->getType() == 'F' && vv[i][j]->getState() != 'Y') {
                if (vv[i][j]->getEnemy() != nullptr){
                    delete vv[i][j]->getEnemy();
                }
                if (vv[i][j]->getDecorator() != nullptr){
                    delete vv[i][j]->getDecorator();
                }

                vv[i][j]->changeEnemy(nullptr);
                vv[i][j]->changeDecorator(nullptr);
                vv[i][j]->changeState('Y');
            }
        }
    }
    p->drop();
    level += 1;
}

int Floor::getLevel() {
    return level;
}

void Floor::move(string Direction){
    bool valid = false;
    if (Direction == "so"){
        if ((vv[r+1][c]->getType() == 'F' || vv[r+1][c]->getType() == 'P' 
        || vv[r+1][c]->getType() == 'D') && vv[r+1][c]->getState() == 'Y'){
            vv[r][c]->changeState('Y');
            vv[r+1][c]->changeState('P');
            r++;
            enemyMove();
            valid = true;
        }
    } 
    if (Direction == "no"){
        if ((vv[r-1][c]->getType() == 'F' || vv[r-1][c]->getType() == 'P' || vv[r-1][c]->getType() == 'D')
         && (vv[r-1][c]->getState() == 'Y')){
            vv[r][c]->changeState('Y');
            vv[r-1][c]->changeState('P');
            r--;
            enemyMove();
            valid = true;
        }
    }
    if (Direction == "ea"){
        if ((vv[r][c+1]->getType() == 'F' || vv[r][c+1]->getType() == 'P' || vv[r][c+1]->getType() == 'D')
         && (vv[r][c+1]->getState() == 'Y')){
            vv[r][c]->changeState('Y');
            vv[r][c+1]->changeState('P');
            c++;
            enemyMove();
            valid = true;
        }
    }
    if (Direction == "we"){
        if ((vv[r][c-1]->getType() == 'F' || vv[r][c-1]->getType() == 'P' || vv[r][c-1]->getType() == 'D')
         && (vv[r][c-1]->getState() == 'Y')){
            vv[r][c]->changeState('Y');
            vv[r][c-1]->changeState('P');
            c--;
            enemyMove();
            valid = true;
        }
    }
    if (Direction == "se"){
        if ((vv[r+1][c+1]->getType() == 'F' || vv[r+1][c+1]->getType() == 'P' || vv[r+1][c+1]->getType() == 'D')
         && (vv[r+1][c+1]->getState() == 'Y')){
            vv[r][c]->changeState('Y');
            vv[r+1][c+1]->changeState('P');
            r++;
            c++;
            enemyMove();
            valid = true;
        }
    }
    if (Direction == "sw"){
        if ((vv[r+1][c-1]->getType() == 'F' || vv[r+1][c-1]->getType() == 'P' || vv[r+1][c-1]->getType() == 'D')
         && (vv[r+1][c-1]->getState() == 'Y')){
            vv[r][c]->changeState('Y');
            vv[r+1][c-1]->changeState('P');
            r++;
            c--;
            enemyMove();
            valid = true;
        }
    }
    if (Direction == "ne"){
        if ((vv[r-1][c+1]->getType() == 'F' || vv[r-1][c+1]->getType() == 'P' || vv[r-1][c+1]->getType() == 'D')
         && (vv[r-1][c+1]->getState() == 'Y')){
            vv[r][c]->changeState('Y');
            vv[r-1][c+1]->changeState('P');
            r--;
            c++;
            enemyMove();
            valid = true;
        }
    }
    if (Direction == "nw"){
        if ((vv[r-1][c-1]->getType() == 'F' || vv[r-1][c-1]->getType() == 'P' || vv[r-1][c-1]->getType() == 'D')
         && (vv[r-1][c-1]->getState() == 'Y')){
            vv[r][c]->changeState('Y');
            vv[r-1][c-1]->changeState('P');
            r--;
            c--;
            enemyMove();
            valid = true;
        }
    }
    if (valid){
        enemyAttack();
        print();
        cout << "PC moved.";
        for (unsigned i = 0; i < enemies.size(); i++){
            if (damage[i] != 0){
                cout << "PC receives " << damage[i] << " damage from " << enemies[i] << " ";
            } else {
                cout << enemies[i] << " missed their attack!";
            }
        }
        damage.clear();
        enemies.clear();
        cout << endl;
    } else {
        print();
        cout << "invalid move" << endl;
    }

}

void Floor::indEnemyMove(int i, int j) {
    int result;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    while (true) {
        std::shuffle( v.begin(), v.end(), rng );
        result = v[0];
        if (result == 1) {
            if ((vv[i-1][j-1])->getType() != 'F') {
                continue;
            } else if ((vv[i-1][j-1])->getState() != 'Y') {
                continue;
            } else {
                vv[i-1][j-1]->changeState('E');
                vv[i-1][j-1]->changeEnemy(vv[i][j]->getEnemy());
                (vv[i-1][j-1]->getEnemy())->changeMoved(true);
                vv[i][j]->changeState('Y');
                vv[i][j]->changeEnemy(nullptr);
                break;
            }
        } else if (result == 2) {
            if ((vv[i-1][j])->getType() != 'F') {
                continue;
            } else if ((vv[i-1][j])->getState() != 'Y') {
                continue;
            } else {
                vv[i-1][j]->changeState('E');
                vv[i-1][j]->changeEnemy(vv[i][j]->getEnemy());
                (vv[i-1][j]->getEnemy())->changeMoved(true);
                vv[i][j]->changeState('Y');
                vv[i][j]->changeEnemy(nullptr);
                break;
            }
        } else if (result == 3) {
            if ((vv[i-1][j+1])->getType() != 'F') {
                continue;
            } else if ((vv[i-1][j+1])->getState() != 'Y') {
                continue;
            } else {
                vv[i-1][j+1]->changeState('E');
                vv[i-1][j+1]->changeEnemy(vv[i][j]->getEnemy());
                (vv[i-1][j+1]->getEnemy())->changeMoved(true);
                vv[i][j]->changeState('Y');
                vv[i][j]->changeEnemy(nullptr);
                break;
            }
        } else if (result == 4) {
            if ((vv[i][j-1])->getType() != 'F') {
                continue;
            } else if ((vv[i][j-1])->getState() != 'Y') {
                continue;
            } else {
                vv[i][j-1]->changeState('E');
                vv[i][j-1]->changeEnemy(vv[i][j]->getEnemy());
                (vv[i][j-1]->getEnemy())->changeMoved(true);
                vv[i][j]->changeState('Y');
                vv[i][j]->changeEnemy(nullptr);
                break;
            }
        } else if (result == 5) {
            if ((vv[i][j+1])->getType() != 'F') {
                continue;
            } else if ((vv[i][j+1])->getState() != 'Y') {
                continue;
            } else {
                vv[i][j+1]->changeState('E');
                vv[i][j+1]->changeEnemy(vv[i][j]->getEnemy());
                (vv[i][j+1]->getEnemy())->changeMoved(true);
                vv[i][j]->changeState('Y');
                vv[i][j]->changeEnemy(nullptr);
                break;
            }
        } else if (result == 6) {
            if ((vv[i+1][j-1])->getType() != 'F') {
                continue;
            } else if ((vv[i+1][j-1])->getState() != 'Y') {
                continue;
            } else {
                vv[i+1][j-1]->changeState('E');
                vv[i+1][j-1]->changeEnemy(vv[i][j]->getEnemy());
                (vv[i+1][j-1]->getEnemy())->changeMoved(true);
                vv[i][j]->changeState('Y');
                vv[i][j]->changeEnemy(nullptr);
                break;
            }
        } else if (result == 7) {
            if ((vv[i+1][j])->getType() != 'F') {
                continue;
            } else if ((vv[i+1][j])->getState() != 'Y') {
                continue;
            } else {
                vv[i+1][j]->changeState('E');
                vv[i+1][j]->changeEnemy(vv[i][j]->getEnemy());
                (vv[i+1][j]->getEnemy())->changeMoved(true);
                vv[i][j]->changeState('Y');
                vv[i][j]->changeEnemy(nullptr);
                break;
            }
        } else {
            if ((vv[i+1][j+1])->getType() != 'F') {
                continue;
            } else if ((vv[i+1][j+1])->getState() != 'Y') {
                continue;
            } else {
                vv[i+1][j+1]->changeState('E');
                vv[i+1][j+1]->changeEnemy(vv[i][j]->getEnemy());
                (vv[i+1][j+1]->getEnemy())->changeMoved(true);
                vv[i][j]->changeState('Y');
                vv[i][j]->changeEnemy(nullptr);
                break;
            }
        }
    }
}

Player* Floor::getPlayer(){
    return p;
}

void Floor::changePlayer(Player* p){
    this->p = p;
}

void Floor::attack(string Direction){
    Enemy *e = nullptr;
    int r1 = r; 
    int c1 = c;
    if (Direction == "so"){
        if (vv[r+1][c]->getState() == 'E'){
            e = vv[r+1][c]->getEnemy();
            r1 = r+1;
        }
    }
    if (Direction == "no"){
        if (vv[r-1][c]->getState() == 'E'){
            e = vv[r-1][c]->getEnemy();
            r1 = r-1;
        }
    }
    if (Direction == "ea"){
        if (vv[r][c+1]->getState() == 'E'){
            e = vv[r][c+1]->getEnemy();
            c1 = c+1;
        }
    }
    if (Direction == "we"){
        if (vv[r][c-1]->getState() == 'E'){
            e = vv[r][c-1]->getEnemy();
            c1 = c-1;
        }
    }
    if (Direction == "sw"){
        if (vv[r+1][c-1]->getState() == 'E'){
            e = vv[r+1][c-1]->getEnemy();
            r1 = r + 1;
            c1 = c - 1;
        }
    }
    if (Direction == "se"){
        if (vv[r+1][c+1]->getState() == 'E'){
            e = vv[r+1][c+1]->getEnemy();
            r1 = r + 1;
            c1 = c + 1;
        }
    }
    if (Direction == "ne"){
        if (vv[r-1][c+1]->getState() == 'E'){
            e = vv[r-1][c+1]->getEnemy();
            r1 = r - 1;
            c1 = c + 1;
        }
    }
    if (Direction == "nw"){
        if (vv[r-1][c-1]->getState() == 'E'){
            e = vv[r-1][c-1]->getEnemy();
            r1 = r - 1;
            c1 = c - 1;
        }
    }
    if (e != nullptr){
        double d = e->getDefence();
        double r = 100/(100 + d);
        double a = p->getAttack();
        int damage1 = ceil(r*a);
        int health = e->getHealth() - damage1;
        e->changeHealth(health);
        if(e->death() == 1){
            vv[r1][c1]->changeEnemy(nullptr);
            Decorator * d = new Normal();
            vv[r1][c1]->changeDecorator(d);
            vv[r1][c1]->changeState('G');
        } else if (e->death() == 2){
            vv[r1][c1]->changeEnemy(nullptr);
            Decorator * d = new MHoard();
            vv[r1][c1]->changeDecorator(d);
            vv[r1][c1]->changeState('G');
        } else if (e->death() == 4){
            vv[r1][c1]->changeEnemy(nullptr);
            Decorator * d = new Compass();
            vv[r1][c1]->changeDecorator(d);
            vv[r1][c1]->changeState('C');
        }
        enemyMove();
        enemyAttack();
        print();
        cout << "PC deals " << damage1 << " to " << e->type << " (" << health << "HP). ";
        if (health <= 0){
            cout << e->type << " is killed. ";
            delete e;
        }
        for (unsigned i = 0; i < enemies.size(); i++){
            if (damage[i] != 0){
                cout << "PC receives " << damage[i] << " damage from " << enemies[i] << " ";
            } else {
                cout << enemies[i] << " missed their attack! ";
            }
        }
        damage.clear();
        enemies.clear();
        cout << endl; 
        //delete e;
    }
    else {
        print();
        cout << "invalid move" << endl;
    }

}


void Floor::enemyMove() {
    for (int i = 0 ; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            if (vv[i][j]->getState() == 'E') {
                if (vv[i][j]->getEnemy()->type == 'D') {
                    continue;
                } 
                if (playerCheck(i, j) == true) {
                    continue;
                }
                if ((vv[i][j]->getEnemy())->getMoved() == true) {
                    continue;
                } else {
                        indEnemyMove(i, j);            
                }
            }
        }
    }

    for (int i =0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            if (vv[i][j]->getState() == 'E') {
                (vv[i][j]->getEnemy())->changeMoved(false);
            }
        }
    }
}

bool Floor::playerCheck(int i, int j) {
    if ((i-1 == r && j-1 == c) || (i-1 == r && j == c) || (i-1 == r && j+1 == c) || (i == r && j-1 == c)
    || (i == r && j+1 == c) || (i+1 == r && j-1 == c) || (i+1 == r && j == c) || (i+1 == r && j+1 == c)) {
        return true;
    } else {
        return false;
    }
}

void Floor::indEnemyAttack(int i, int j) {
    vector<int> v = {1, 2};
    std::shuffle( v.begin(), v.end(), rng);
    int healthMinus;
    if (v[0] == 1) {
        healthMinus = 0;
        //cout << vv[i][j]->getEnemy()->type << "missed their attack!" << endl;
        damage.push_back(healthMinus);
        enemies.push_back(vv[i][j]->getEnemy()->type);

    } else {
    double pdefense = p->getDefence();
    double healthMinus1 = (100/(100+pdefense));
    double aenemy = vv[i][j]->getEnemy()->getAttack();
    healthMinus = ceil(healthMinus1 * aenemy);
    p->changeHealth(p->getHealth() - healthMinus);
    damage.push_back(healthMinus);
    enemies.push_back(vv[i][j]->getEnemy()->type);
    //cout << "PC receives " << healthMinus << " damage from " << vv[i][j]->getEnemy()->type << " ";
    }
}

void Floor::enemyAttack() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            if (vv[i][j]->getState() == 'E' || vv[i][j]->getState() == 'D') {
                if (playerCheck(i, j) == true) {
                    indEnemyAttack(i, j);
                }
            }
        }
    }
}

void Floor::useItem(string Direction){
    Decorator *d = nullptr;
    int r1, c1;
    if (Direction == "so"){
        if (vv[r+1][c]->getState() == 'G' || vv[r+1][c]->getState() == 'O' || vv[r+1][c]->getState() == 'C'){
            d = vv[r+1][c]->getDecorator();
            r1 = r+1;
            c1 = c;
        }
    }
    if (Direction == "no"){
        if (vv[r-1][c]->getState() == 'G' || vv[r-1][c]->getState() == 'O' || vv[r-1][c]->getState() == 'C'){
            d = vv[r-1][c]->getDecorator();
            r1 = r-1;
            c1 = c;
        }
    }
    if (Direction == "ea"){
        if (vv[r][c+1]->getState() == 'G' || vv[r][c+1]->getState() == 'O' || vv[r][c+1]->getState() == 'C'){
            d = vv[r][c+1]->getDecorator();
            r1 = r;
            c1 = c + 1;
        }
    }
    if (Direction == "we"){
        if (vv[r][c-1]->getState() == 'G' || vv[r][c-1]->getState() == 'O' || vv[r][c-1]->getState() == 'C'){
            d = vv[r][c-1]->getDecorator();
            r1 = r;
            c1 = c-1;
        }
    }
    if (Direction == "sw"){
        if (vv[r+1][c-1]->getState() == 'G' || vv[r+1][c-1]->getState() == 'O' || vv[r+1][c-1]->getState() == 'C'){
            d = vv[r+1][c-1]->getDecorator();
            r1 = r+1;
            c1 = c-1;
        }
    }
    if (Direction == "se"){
        if (vv[r+1][c+1]->getState() == 'G' || vv[r+1][c+1]->getState() == 'O' || vv[r+1][c+1]->getState() == 'C'){
            d = vv[r+1][c+1]->getDecorator();
            r1 = r+ 1;
            c1 = c+1;
        }
    }
    if (Direction == "ne"){
        if (vv[r-1][c+1]->getState() == 'G' || vv[r-1][c+1]->getState() == 'O' || vv[r-1][c+1]->getState() == 'C'){
            d = vv[r-1][c+1]->getDecorator();
            r1 = r-1;
            c1 = c+1;
        }
    }
    if (Direction == "nw"){
        if (vv[r-1][c-1]->getState() == 'G' || vv[r-1][c-1]->getState() == 'O' || vv[r-1][c-1]->getState() == 'C'){
            d = vv[r-1][c-1]->getDecorator();
            r1 = r-1;
            c1 = c-1;
        }
    }
    if (d != nullptr){
        p->equip(d);
        vv[r][c]->changeState('Y');
        vv[r][c]->changeEnemy(nullptr);
        r = r1;
        c = c1;
        vv[r][c]->changeState('P');
        enemyMove();
        enemyAttack();
        print();
        if (d->gold() == 1){
            cout << "PC picked a Normal gold. ";
        } else if(d->gold() == 2){
            cout << "PC picked a Small gold. ";
        } else if(d->gold() == 4){
            cout << "PC picked a merchant Hoard. ";
        } else if(d->gold() == 6){
            cout << "PC picked a Dragon Hoard. ";
        } else if(d->health() == 10){
            cout << "PC used a RH potion. ";
        } else if(d->health() == -10){
            cout << "PC used a PH potion. ";
        } else if(d->attack() == 5){
            cout << "PC used a BA potion. ";
        } else if(d->attack() == -5){
            cout << "PC used a WA potion. ";
        } else if(d->defence() == 5){
            cout << "PC used a BD potion. ";
        } else if(d->defence() == -5){
            cout << "PC used a WD potion. ";
        } else {
            cout << "PC picked up a compass. ";
        }
        for (unsigned i = 0; i < enemies.size(); i++){
            if (damage[i] != 0){
                cout << "PC receives " << damage[i] << " damage from " << enemies[i] << " ";
            } else {
                cout << enemies[i] << " missed their attack!";
            }
        }
        damage.clear();
        enemies.clear();
        cout << endl;
        delete d;
    } else {
        print();
        cout << "invalid move." << endl;
    }

}
