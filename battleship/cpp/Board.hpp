#ifndef board_hpp
#define board_hpp

#include <vector>
#include <utility> // for std::pair<T, T>()
#include "Ship.hpp"


class Board{
public:
  // The board manages ships...
  // needs to have a set of functions to act on those ships
  // provides some useful functions like getShots() and isAlive()
  Board(const int board_width, const int board_height){
    init(board_width, board_height);
  }
  
  Board(const int board_width, const int board_height, const std::vector<Ship*>& ships){
    init(board_width, board_height, ships);
  }
  
  std::pair<int, std::string> checkHitUpdate(const std::pair<int, int>& coord);

  int getBoardHeight() const{ return m_board_height; }
  
  int getBoardWidth() const{ return m_board_width; }
  
  std::vector<Ship*> getShips() const{ return m_ships; }
  
  int getShots() const;
  
  bool isAlive() const{ return m_alive; }
  
  void setShips(const std::vector<Ship*>& ships){
    init(ships);
  }


private:
  void init(const int board_width, const int board_height);
  void init(const int board_width, const int board_height, const std::vector<Ship*>& ships);
  void init(const std::vector<Ship*>& ships);
  
  void layoutShips();
  std::vector<std::pair<int, int> > makeCellsVec(const int size);
  bool checkShipOverlap(const std::vector<std::pair<int, int> > cells);

  int m_board_width;
  int m_board_height;
  bool m_alive;
  std::vector<Ship*> m_ships;
  
  static const int SHIP_LAYOUT_TIMEOUT = 100; // iterations to attempt placing a ship
  
};


#endif
