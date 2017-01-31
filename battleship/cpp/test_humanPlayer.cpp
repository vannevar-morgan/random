#include <iostream>
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include <utility>


using namespace std;

int main(){
  Player* p = new HumanPlayer("Admiral Dipshit");
  pair<int, int> guess = p->getGuess();
  cout << "human guessed: (" << guess.first << ", " << guess.second << ")" << endl;
  
  p->msgResultCallback(pair<int, string>(0, "carrier"));
  
  delete p;
    
  return 0;
}
