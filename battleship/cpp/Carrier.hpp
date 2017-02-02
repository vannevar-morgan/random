#ifndef carrier_hpp
#define carrier_hpp


#include "Ship.hpp"
#include <vector>
#include <string>


class Carrier : public Ship{
public:
  Carrier(){ init(); }
  
protected:
  void init();
  

private:
  static const int CARRIER_SHOTS;
  static const Ship_sz CARRIER_SIZE;
  
  static const std::vector<std::string> CARRIER_NAMES;
  
};





#endif
