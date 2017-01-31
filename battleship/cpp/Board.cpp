#include <iostream> // for debugging
#include <stdexcept>
#include <utility> // for pair
#include <vector>
#include <random>
//#include <ctime>
//#include <unistd.h>
#include <string> // for std::to_string()

#include "Board.hpp"


std::pair<int, std::string> Board::checkHitUpdate(const std::pair<int, int>& coord){
  int hitCode = -1;
  std::string shipName = "";
  for(int i = 0; i < m_ships.size(); ++i){
    hitCode = m_ships[i]->checkHitUpdate(coord);
    if(hitCode != -1){
      // then it's a hit
      shipName = m_ships[i]->getName();
      if(hitCode == 1){
	// then it's a kill
	m_ships.erase(m_ships.begin() + i);
	if(m_ships.size() == 0){
	  // the the player lost
	  m_alive = false;
	}
      }
      break;
    }
  }
  
  return std::pair<int, std::string>(hitCode, shipName);
}


int Board::getShots() const{
  // Returns the number of shots available to the player.
  //  std::cout << "getShots()" << std::endl;
  int shots = 0;
  for(Ship* s : m_ships){
    shots += s->getShots();
  }
  return shots;
}


void Board::init(const int board_width, const int board_height){
  //  std::cout << "init(board_width, board_height)" << std::endl;
  m_alive = true;
  
  if(board_width < 1 || board_height < 1){
    throw std::invalid_argument("specified board dimensions are out of range...");
  }
  m_board_width = board_width;
  m_board_height = board_height;
}


void Board::init(const int board_width, const int board_height, const std::vector<Ship*>& ships){
  //  std::cout << "init(board_width, board_height, ships)" << std::endl;
  Board::init(board_width, board_height);
  Board::init(ships);
}


void Board::init(const std::vector<Ship*>& ships){
  //  std::cout << "init(ships)" << std::endl;
  m_ships = ships;
  Board::layoutShips();
}


void Board::layoutShips(){
  // layout ships on the board
  //
  // go through the list of ships, choose a random location and orientation, try to place the ship.
  // if the ship cells contain a cell of another ship already on the board, try again until timeout
  //  std::cout << "layoutShips()" << std::endl;
  std::vector<std::pair<int, int> > cells;
  for(Ship* s : m_ships){
    if(s != nullptr){
      for(int i = 0; i < SHIP_LAYOUT_TIMEOUT; ++i){
	int size = s->getSize();
	cells = Board::makeCellsVec(size);
	if(!Board::checkShipOverlap(cells)){
	  s->setCells(cells);
	  break;
	}
      }
    }else{
      // ship is nullptr
      std::cout << "ship is nullptr while laying out ships..." << std::endl;
    }
  }
}

std::vector<std::pair<int, int> > Board::makeCellsVec(const int size){
  // Returns a vector of pairs representing coordinates of cells of a ship.
  //
  // The cells are chosen at a random origin on the board and layed out
  // either vertically or horizontally.
  //  std::cout << "makeCellsVec(size)" << std::endl;
  std::vector<std::pair<int, int> > cells;
  if(size > m_board_width && size > m_board_height){
    throw std::invalid_argument("can't place ship... specified ship size is greater than the board size.\nboard_width = " + std::to_string(m_board_width) + "\tboard_height = " + std::to_string(m_board_height) + "\tship_size = " + std::to_string(size));
  }

  int orientVertical = rand() % 2;
  if(orientVertical){
    if(size > m_board_height){
      orientVertical = false;
    }    
  }else{
    if(size > m_board_width){
      orientVertical = true;
    }
  }
  std::pair<int, int> origin;
  if(orientVertical){
    //    std::cout << "orienting vertical" << std::endl;
    //    std::cout << "board_height - (size - 1) = " << std::to_string(board_height - (size - 1)) << std::endl;
    origin = std::pair<int, int>(rand() % m_board_width, rand() % (m_board_height - (size - 1)));
    //    std::cout << "origin x: " << origin.first << "\ty: " << origin.second << std::endl;
    cells.push_back(origin);
    for(int i = 1; i < size; ++i){
      cells.push_back(std::pair<int, int>(origin.first, origin.second + i));
    }
  }else{
    //    std::cout << "orienting horizontal" << std::endl;
    //    std::cout << "board_width - (size - 1) = " << std::to_string(board_height - (size - 1)) << std::endl;
    origin = std::pair<int, int>(rand() % (m_board_width - (size - 1)), rand() % m_board_height);
    //    std::cout << "origin x: " << origin.first << "\ty: " << origin.second << std::endl;
    cells.push_back(origin);
    for(int i = 1; i < size; ++i){
      cells.push_back(std::pair<int, int>(origin.first + i, origin.second));
    }
  }
  //  std::cout << "exiting makeCellsVec()" << std::endl;
  return cells;
}

bool Board::checkShipOverlap(const std::vector<std::pair<int, int> > cells){
  // Returns true if any coordinate in cells overlaps with a coordinate owned by another ship.
  // False otherwise.
  //  std::cout << "checkShipOverlap(cells)" << std::endl;
  std::vector<std::pair<int, int> > temp_cells;
  std::pair<int, int> temp_coord;
  for(Ship* s : m_ships){
    temp_cells = s->getCells();
    for(std::pair<int, int> temp_coord : temp_cells){
      for(std::pair<int, int> coord : cells){
	if(coord == temp_coord){
	  return true;
	}
      }
    }
  }
  return false;
}
