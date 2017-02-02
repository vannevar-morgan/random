#ifndef submarine_hpp
#define submarine_hpp

#include "Ship.hpp"
#include <vector>
#include <string>


class Submarine : public Ship{
public:
  Submarine(){ init(); }

protected:
  void init();

private:
  static const int SUBMARINE_SHOTS;

  static const Ship_sz SUBMARINE_SIZE;
  
  static const std::vector<std::string> SUBMARINE_NAMES;
  
};



#endif
