#include "Minesweeper.hpp"
#include <random>
#include <vector>
#include <string>


const int Minesweeper::MINESWEEPER_SHOTS = 2;

const int Minesweeper::MINESWEEPER_SIZE = 2;

const std::vector<std::string> Minesweeper::MINESWEEPER_NAMES({"USS Obstructor", "USS Barricade", "USS Barbican", "USS Camanche", "USS Planter"});

void Minesweeper::init(){
  alive = true;
  shots = MINESWEEPER_SHOTS;
  size = MINESWEEPER_SIZE;
  name = MINESWEEPER_NAMES[rand() % MINESWEEPER_NAMES.size()];
}
