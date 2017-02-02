#ifndef cruiser_hpp
#define cruiser_hpp


#include "Ship.hpp"
#include <vector>
#include <string>


class Cruiser : public Ship{
public:
  Cruiser(){ init(); }

protected:
  void init();

private:
  static const int CRUISER_SHOTS;

  static const Ship_sz CRUISER_SIZE;
  
  static const std::vector<std::string> CRUISER_NAMES;
};



#endif
