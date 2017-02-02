#ifndef destroyer_hpp
#define destroyer_hpp

#include "Ship.hpp"
#include <vector>
#include <string>

class Destroyer : public Ship{
public:
  Destroyer(){ init(); }

protected:
  void init();

private:
  static const int DESTROYER_SHOTS;

  static const Ship_sz DESTROYER_SIZE;
  
  static const std::vector<std::string> DESTROYER_NAMES;
};





#endif
