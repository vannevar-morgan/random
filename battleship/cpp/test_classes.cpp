#include "Ship.hpp"
#include "Carrier.hpp"
#include "Cruiser.hpp"
#include "Destroyer.hpp"
#include "Submarine.hpp"
#include "Minesweeper.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <ctime>

using namespace std;

void testCarrier();
void testCruiser();
void testDestroyer();
void testSubmarine();
void testMinesweeper();
void testPolymorphic();

int main(int argc, char* argv[]){
  srand(time(0));
  cout << "\n\ntesting carrier class..." << endl;
  testCarrier();
  cout << "\n\ntesting cruiser class..." << endl;
  testCruiser();
  cout << "\n\ntesting destroyer class..." << endl;
  testDestroyer();
  cout << "\n\ntesting submarine class..." << endl;
  testSubmarine();
  cout << "\n\ntesting minesweeper class..." << endl;
  testMinesweeper();
  cout << "\n\ntesting polymorphic vector using all ship classes..." << endl;
  testPolymorphic();
  
  return 0;
}

void testCarrier(){
  //
  // test Carrier.cpp / .hpp and Ship.cpp / .hpp
  //
  Carrier c;
  cout << "carrier name: " << c.getName() << endl;
  cout << "carrier shots: " << c.getShots() << endl;
  cout << "carrier size: " << c.getSize() << endl;
  cout << "is carrier alive: " << c.isAlive() << endl;
  vector<pair<int, int> > shipCells;
  shipCells.push_back(pair<int, int>(1,1));
  shipCells.push_back(pair<int, int>(1,2));
  shipCells.push_back(pair<int, int>(1,3));
  shipCells.push_back(pair<int, int>(1,4));
  shipCells.push_back(pair<int, int>(1,5));

  c.setCells(shipCells);
  vector<pair<int, int> > carrierCells = c.getCells();
  vector<pair<int, int> > hitCells = c.getHitCells();
  
  cout << "carrier cells: " << endl;
  for(pair<int, int> p : carrierCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "hit cells: " << endl;
  for(pair<int, int> p : hitCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "going to take some shots at the carrier..." << endl;
  
  pair<int, int> p1(8, 4); // miss
  pair<int, int> p2(1, 1); // hit
  pair<int, int> p3(1, 1); // miss because it's the same guess as the prior hit
  pair<int, int> p4(1, 2); // hit
  pair<int, int> p5(1, 3); // hit
  pair<int, int> p6(1, 4); // hit
  pair<int, int> p7(1, 5); // sink
  vector<pair<int, int> > guesses {p1, p2, p3, p4, p5, p6, p7};
  for(pair<int, int> p : guesses){
    cout << "(" << p.first << ", " << p.second << ") ";
    int hitCode = c.checkHitUpdate(p);
    if(hitCode == -1){
      cout << "miss" << endl;
    }else if(hitCode == 0){
      cout << "hit" << endl;
    }else if(hitCode == 1){
      cout << "sunk the " << c.getName() << endl;
    }
    cout << "is carrier alive?: " << c.isAlive() << endl;
  }
}

void testCruiser(){
  //
  // test Cruiser.cpp / .hpp
  //
  Cruiser c;
  cout << "cruiser name: " << c.getName() << endl;
  cout << "cruiser shots: " << c.getShots() << endl;
  cout << "cruiser size: " << c.getSize() << endl;
  cout << "is cruiser alive: " << c.isAlive() << endl;
  vector<pair<int, int> > shipCells;
  shipCells.push_back(pair<int, int>(1,1));
  shipCells.push_back(pair<int, int>(1,2));
  shipCells.push_back(pair<int, int>(1,3));
  shipCells.push_back(pair<int, int>(1,4));
  
  c.setCells(shipCells);
  vector<pair<int, int> > cruiserCells = c.getCells();
  vector<pair<int, int> > hitCells = c.getHitCells();
  
  cout << "cruiser cells: " << endl;
  for(pair<int, int> p : cruiserCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "hit cells: " << endl;
  for(pair<int, int> p : hitCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "going to take some shots at the cruiser..." << endl;
  
  pair<int, int> p1(8, 4); // miss
  pair<int, int> p2(1, 1); // hit
  pair<int, int> p3(1, 1); // miss because it's the same guess as the prior hit
  pair<int, int> p4(1, 2); // hit
  pair<int, int> p5(1, 3); // hit
  pair<int, int> p6(1, 4); // sink
  pair<int, int> p7(1, 5); // miss
  vector<pair<int, int> > guesses {p1, p2, p3, p4, p5, p6, p7};
  for(pair<int, int> p : guesses){
    cout << "(" << p.first << ", " << p.second << ") ";
    int hitCode = c.checkHitUpdate(p);
    if(hitCode == -1){
      cout << "miss" << endl;
    }else if(hitCode == 0){
      cout << "hit" << endl;
    }else if(hitCode == 1){
      cout << "sunk the " << c.getName() << endl;
    }
    cout << "is cruiser alive?: " << c.isAlive() << endl;
  }
}


void testDestroyer(){
  //
  // test Destroyer.cpp / .hpp
  //
  Destroyer c;
  cout << "destroyer name: " << c.getName() << endl;
  cout << "destroyer shots: " << c.getShots() << endl;
  cout << "destroyer size: " << c.getSize() << endl;
  cout << "is destroyer alive: " << c.isAlive() << endl;
  vector<pair<int, int> > shipCells;
  shipCells.push_back(pair<int, int>(1,1));
  shipCells.push_back(pair<int, int>(1,2));
  shipCells.push_back(pair<int, int>(1,3));
  
  c.setCells(shipCells);
  vector<pair<int, int> > destroyerCells = c.getCells();
  vector<pair<int, int> > hitCells = c.getHitCells();
  
  cout << "destroyer cells: " << endl;
  for(pair<int, int> p : destroyerCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "hit cells: " << endl;
  for(pair<int, int> p : hitCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "going to take some shots at the destroyer..." << endl;
  
  pair<int, int> p1(8, 4); // miss
  pair<int, int> p2(1, 1); // hit
  pair<int, int> p3(1, 1); // miss because it's the same guess as the prior hit
  pair<int, int> p4(1, 2); // hit
  pair<int, int> p5(1, 3); // sink
  pair<int, int> p6(1, 4); // miss
  pair<int, int> p7(1, 5); // miss
  vector<pair<int, int> > guesses {p1, p2, p3, p4, p5, p6, p7};
  for(pair<int, int> p : guesses){
    cout << "(" << p.first << ", " << p.second << ") ";
    int hitCode = c.checkHitUpdate(p);
    if(hitCode == -1){
      cout << "miss" << endl;
    }else if(hitCode == 0){
      cout << "hit" << endl;
    }else if(hitCode == 1){
      cout << "sunk the " << c.getName() << endl;
    }
    cout << "is destroyer alive?: " << c.isAlive() << endl;
  }
}

void testSubmarine(){
  //
  // test Submarine.cpp / .hpp
  //
  Submarine c;
  cout << "submarine name: " << c.getName() << endl;
  cout << "submarine shots: " << c.getShots() << endl;
  cout << "submarine size: " << c.getSize() << endl;
  cout << "is submarine alive: " << c.isAlive() << endl;
  vector<pair<int, int> > shipCells;
  shipCells.push_back(pair<int, int>(1,1));
  shipCells.push_back(pair<int, int>(1,2));
  shipCells.push_back(pair<int, int>(1,3));
  
  c.setCells(shipCells);
  vector<pair<int, int> > submarineCells = c.getCells();
  vector<pair<int, int> > hitCells = c.getHitCells();
  
  cout << "submarine cells: " << endl;
  for(pair<int, int> p : submarineCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "hit cells: " << endl;
  for(pair<int, int> p : hitCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "going to take some shots at the submarine..." << endl;
  
  pair<int, int> p1(8, 4); // miss
  pair<int, int> p2(1, 1); // hit
  pair<int, int> p3(1, 1); // miss because it's the same guess as the prior hit
  pair<int, int> p4(1, 2); // hit
  pair<int, int> p5(1, 3); // sink
  pair<int, int> p6(1, 4); // miss
  pair<int, int> p7(1, 5); // miss
  vector<pair<int, int> > guesses {p1, p2, p3, p4, p5, p6, p7};
  for(pair<int, int> p : guesses){
    cout << "(" << p.first << ", " << p.second << ") ";
    int hitCode = c.checkHitUpdate(p);
    if(hitCode == -1){
      cout << "miss" << endl;
    }else if(hitCode == 0){
      cout << "hit" << endl;
    }else if(hitCode == 1){
      cout << "sunk the " << c.getName() << endl;
    }
    cout << "is submarine alive?: " << c.isAlive() << endl;
  }
}


void testMinesweeper(){
  //
  // test Minesweeper.cpp / .hpp
  //
  Minesweeper c;
  cout << "minesweeper name: " << c.getName() << endl;
  cout << "minesweeper shots: " << c.getShots() << endl;
  cout << "minesweeper size: " << c.getSize() << endl;
  cout << "is minesweeper alive: " << c.isAlive() << endl;
  vector<pair<int, int> > shipCells;
  shipCells.push_back(pair<int, int>(1,1));
  shipCells.push_back(pair<int, int>(1,2));
  
  c.setCells(shipCells);
  vector<pair<int, int> > minesweeperCells = c.getCells();
  vector<pair<int, int> > hitCells = c.getHitCells();
  
  cout << "minesweeper cells: " << endl;
  for(pair<int, int> p : minesweeperCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "hit cells: " << endl;
  for(pair<int, int> p : hitCells){
    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  
  cout << "going to take some shots at the minsweeper..." << endl;
  
  pair<int, int> p1(8, 4); // miss
  pair<int, int> p2(1, 1); // hit
  pair<int, int> p3(1, 1); // miss because it's the same guess as the prior hit
  pair<int, int> p4(1, 2); // sink
  pair<int, int> p5(1, 3); // miss
  pair<int, int> p6(1, 4); // miss
  pair<int, int> p7(1, 5); // miss
  vector<pair<int, int> > guesses {p1, p2, p3, p4, p5, p6, p7};
  for(pair<int, int> p : guesses){
    cout << "(" << p.first << ", " << p.second << ") ";
    int hitCode = c.checkHitUpdate(p);
    if(hitCode == -1){
      cout << "miss" << endl;
    }else if(hitCode == 0){
      cout << "hit" << endl;
    }else if(hitCode == 1){
      cout << "sunk the " << c.getName() << endl;
    }
    cout << "is minesweeper alive?: " << c.isAlive() << endl;
  }
}


void testPolymorphic(){
  //
  // test polymorphic vector using all ship classes
  // 
  vector<Ship*> ships;
  ships.push_back(new Carrier());
  ships.push_back(new Cruiser());
  ships.push_back(new Destroyer());
  ships.push_back(new Submarine());
  ships.push_back(new Minesweeper());
  
  cout << "Making some new ships...\nList of all ship names: " << endl;
  for(Ship* s : ships){
    cout << s->getName() << endl;
  }
}
