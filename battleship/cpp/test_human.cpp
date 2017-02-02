#include <iostream>
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include "ViewScreen.hpp"
#include <utility>


using namespace std;

int main(){
  int board_width = 10, board_height = 10;
  Player* p = new HumanPlayer(new ViewScreen(board_width, board_height), "Admiral Horatio");
  pair<int, int> guess = p->makeGuess();
  cout << "human guessed: (" << guess.first << ", " << guess.second << ")" << endl;
  
  p->msgResultCallback(pair<int, string>(0, "carrier"));
  
  delete p;
    
  return 0;
}
