#include "Carrier.hpp"
#include <random>
#include <vector>
#include <string>


const int Carrier::CARRIER_SHOTS = 5;

const Carrier::Ship_sz Carrier::CARRIER_SIZE = 5;
  
const std::vector<std::string> Carrier::CARRIER_NAMES({"USS Wasp", "USS Hornet", "USS Lexington", "USS Saratoga", "USS Yorktown"});

void Carrier::init(){
  alive = true;
  shots = CARRIER_SHOTS;
  size = CARRIER_SIZE;
  name = CARRIER_NAMES[rand() % CARRIER_NAMES.size()];
}

