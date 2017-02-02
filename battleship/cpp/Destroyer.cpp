#include "Destroyer.hpp"
#include <vector>
#include <string>
#include <random>


const int Destroyer::DESTROYER_SHOTS = 3;

const Destroyer::Ship_sz Destroyer::DESTROYER_SIZE = 3;

const std::vector<std::string> Destroyer::DESTROYER_NAMES({"USS Cole", "USS Fitzgerald", "USS Arleigh Burke", "USS John Paul Jones", "USS Laboon"});

void Destroyer::init(){
  alive = true;
  shots = DESTROYER_SHOTS;
  size = DESTROYER_SIZE;
  name = DESTROYER_NAMES[rand() % DESTROYER_NAMES.size()];
}
