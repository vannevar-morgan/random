#include "ViewScreen.hpp"
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include <utility>


using namespace std;

int main(){
  int board_width = 10;
  int board_height = 10;
  ViewScreen vs(board_width, board_height);
  //  void update(const std::string& shipName, const coord& pt, const bool isHit, const bool isKill);
  
  Player* p = new HumanPlayer(vs, "admiral dipshit");
  
  
  vs.print();
  pair<int, int> c = p->getGuess();
  //void ViewScreen::update(const std::string& shipName, const ViewScreen::coord& c, const bool isHit, const bool isKill);
  vs.update("uss cole", c, false, false);
  vs.print();
  c = p->getGuess();
  vs.update("uss cole", c, false, false);

  vs.print();
  c = p->getGuess();
  vs.update("uss cole", c, true, false);

  vs.print();
  c = p->getGuess();
  vs.update("uss cole", c, true, false);

  vs.print();
  c = p->getGuess();
  vs.update("uss cole", c, true, true);
  vs.print();




  
  return 0;
}
