#ifndef minesweeper_hpp
#define minesweeper_hpp


#include "Ship.hpp"
#include <vector>
#include <string>

class Minesweeper : public Ship{
public:
  Minesweeper(){ init(); }

protected:
  void init();

private:
  static const int MINESWEEPER_SHOTS;

  static const int MINESWEEPER_SIZE;
  
  static const std::vector<std::string> MINESWEEPER_NAMES;

};



#endif
