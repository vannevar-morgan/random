#include "Ship.hpp"
#include <utility>
#include <vector>
#include <string> // for std::to_string()
#include <stdexcept>
//#include <random> // for srand, to initialize random before any ships are constructed
//#include <ctime>  // for time, to initialize random before any ships are constructed
//#include <unistd.h> // for getpid(), to initialize random before any ships are constructed
#include <iostream> // for debugging output


//Ship::~Ship(){}

// bool Ship::initRandCalled = false;

// void Ship::initRand(){
//   // initialize the random seed if it hasn't been initialized yet.
//   // should be moved to the game class.
//   if(!initRandCalled){
//     std::cout << "initializing random seed..." << std::endl;
//     srand(time(0) ^ getpid());
//     initRandCalled = true;
//   }
// }

int Ship::checkHit(const std::pair<int, int>& coord) const{
  // Checks if a guess represents a hit on a ship.
  // Returns:
  // -1 = miss
  // 0 = hit
  // 1 = sink
  //
  // Note that any previous guesses (those in hitCells) will evaluate as a miss.
  // Note that it is assumed that the ship cells have been set.
  for(const std::pair<int, int> c : hitCells){
    if(c == coord){
      return -1; // it's a miss because it's been guessed previously
    }
  }
  
  for(const std::pair<int, int> c : cells){
    if(c == coord){
      if(hitCells.size() + 1 == cells.size()){
	return 1; // it's a sink
      }
      return 0; // it's a hit but not a sink
    }
  }
  
  return -1; // it's a miss
}

int Ship::checkHitUpdate(const std::pair<int, int>& coord){
  // Calls checkHit() to check if coord represents a hit.
  // Updates the values of hitCells and alive.
  int hitCode = checkHit(coord);
  if(hitCode >= 0){
    hitCells.push_back(coord);
  }
  if(hitCode == 1){
    alive = false;
  }
  return hitCode;
}


void Ship::setCells(const std::vector<std::pair<int, int> >& shipCells){
  //
  // set the coordinates for a ship, representing its position on the board.
  //
  // note that setCells() should be called before any call to getCells() or checkHit() or checkHitUpdate()
  //
  if(shipCells.size() == this->size){
    cells = shipCells;
  }else{
    throw std::invalid_argument("the number of cells in the vector of coordinates passed to setCells() must match the size of the ship...\nship size = " + std::to_string(this->size) + " but the size of shipCells passed = " + std::to_string(shipCells.size()));
  }
}
