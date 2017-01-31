#include "Cruiser.hpp"
#include <random>
#include <vector>
#include <string>


const int Cruiser::CRUISER_SHOTS = 4;

const int Cruiser::CRUISER_SIZE = 4;

const std::vector<std::string> Cruiser::CRUISER_NAMES({"USS Juneau", "USS Lake Erie", "USS Lake Champlain", "USS Astoria", "USS Indianapolis"});

void Cruiser::init(){
  alive = true;
  shots = CRUISER_SHOTS;
  size = CRUISER_SIZE;
  name = CRUISER_NAMES[rand() % CRUISER_NAMES.size()];
}
