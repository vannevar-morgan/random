#include "Submarine.hpp"
#include <random>
#include <vector>
#include <string>


const int Submarine::SUBMARINE_SHOTS = 3;

const Submarine::Ship_sz Submarine::SUBMARINE_SIZE = 3;

const std::vector<std::string> Submarine::SUBMARINE_NAMES({"USS Ohio", "USS Los Angeles", "USS Seawolf", "USS Gato", "USS Texas"});

void Submarine::init(){
  alive = true;
  shots = SUBMARINE_SHOTS;
  size = SUBMARINE_SIZE;
  name = SUBMARINE_NAMES[rand() % SUBMARINE_NAMES.size()];
}
