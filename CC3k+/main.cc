#include <iostream>
#include <string>
#include "floor.h"
#include "item.h"
#include "player.h"
#include "enemy.h"
#include "character.h"
#include "cell.h"
#include "floorgenerator.h"

using namespace std;

int main(int argc, char *argv[])
{
  cin.exceptions(ios::eofbit | ios::failbit);
  char c;
  Player *p;
  cout << "Please choose your character" << endl;
  cin >> c;
  switch (c)
  {
  case 'h':
    p = new Player(c);
    break;
  case 'd':
    p = new Player(c);
    break;
  case 'p':
    p = new Player(c);
    break;
  case 'o':
    p = new Player(c);
    break;
  default:
    break;
  }
  Floor *f = new Floor();
  f->changePlayer(p);
  floorgenerator(f);
  f->print();
  cout << "Player has been spawned" << endl;
  bool use = false;
  bool attack = false;
  string cmd;
  try
  {
    while (true)
    {
      cin >> cmd;
      if (f->r == f->sr && f->c == f->sc)
      {
        if (f->getLevel() == 6){
          cout << "Congrats! You have beaten the game." << endl;
          delete f;
          return 0;
        }
        f->newLevel();
        floorgenerator(f);
        f->print();
        cout << "Player has been spawned" << endl;
        use = false;
        attack = false;
        continue;
      }
      if (cmd == "u")
      {
        use = true;
      }
      if (cmd == "a")
      {
        attack = true;
      }
      if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
          cmd == "se" || cmd == "sw" || cmd == "ne" || cmd == "nw")
      {
        if (attack)
        {
          f->attack(cmd);
          attack = false;
          continue;
        }
        if (use)
        {
          f->useItem(cmd);
          use = false;
          continue;
        }
        f->move(cmd);
      }
      if (cmd == "r")
      {
        f->restart();
        Player *p;
        cout << "Please choose your character" << endl;
        cin >> c;
        switch (c)
        {
        case 'h':
          p = new Player(c);
          break;
        case 'd':
          p = new Player(c);
          break;
        case 'p':
          p = new Player(c);
          break;
        case 'o':
          p = new Player(c);
          break;
        default:
          break;
        }
        f->changePlayer(p);
        floorgenerator(f);
        f->print();
        cout << "Player has been spawned" << endl;
        use = false;
        attack = false;
        continue;
      }
      if (cmd == "q")
      {
        
        cout << "You have quit the game." << endl;
        
        delete f;
        return 0;
      }
    }
  }
  catch (ios::failure &)
  {
  } // Any I/O failure quits
}
