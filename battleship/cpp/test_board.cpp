#include <iostream>
#include <utility>
#include <vector>
#include <random>
#include <ctime>
#include <unistd.h>
#include "Ship.hpp"
#include "Carrier.hpp"
#include "Cruiser.hpp"
#include "Destroyer.hpp"
#include "Submarine.hpp"
#include "Minesweeper.hpp"
#include "Board.hpp"


using namespace std;

int main(int argc, char* argv[]){
  srand(time(0) ^ getpid());
  
  int board_width = 10;
  int board_height = 10;

  vector<Ship*> ships;
  ships.push_back(new Carrier());
  ships.push_back(new Cruiser());
  ships.push_back(new Destroyer());
  ships.push_back(new Submarine());
  ships.push_back(new Minesweeper());
  
  Board b(board_width, board_height, ships);
  
  cout << "fleet consists of: " << endl;
  vector<Ship*> bShips = b.getShips();
  for(Ship* s : bShips){
    cout << s->getName() << endl;
  }

  cout << "total firepower: " << b.getShots() << endl;
  
  cout << "board width: " << b.getBoardWidth() << endl;
  cout << "board height: " << b.getBoardHeight() << endl;
  
  vector<pair<int, int> > shipCells;
  for(Ship* s : bShips){
    shipCells = s->getCells();
    cout << "cells of " << s->getName() << ": " << endl;
    for(pair<int, int>& p : shipCells){
      cout << "(" << p.first << ", " << p.second << ")" << endl;
    }    
  }
  
  //  Board c; // shouldn't compile
  //  Board d(board_width, board_height); // no ships set yet, shouldn't be able to place ships, what errors occur?

  return 0;
}
