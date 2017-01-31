#ifndef game_hpp
#define game_hpp

// outline of basic game objects:
// + main objects are the game, player, board, ship
// + a game has two players
// + a player has a board and a viewscreen
// + a board has a list of ships, and functions to manipulate those ships
// + a ship has a list of coordinates representing its position, some properties such as a name and firepower, and functions to manipulate those properties
// + a viewscreen has a list of hits a list of misses, some functions to interact, and a printing function

#include "Player.hpp"
#include "Ship.hpp"
#include <vector>

class Game{
public:
  //  Game(const int board_width, const int board_height, const std::vector<Ship*>& p1Ships, const std::vector<Ship*>& p2Ships);
  Game(Player* p1, Player* p2, Board* b1, Board* b2){
    m_p1 = p1;
    m_p2 = p2;
    m_b1 = b1;
    m_b2 = b2;
    //    initRand();
  }
  
  Game(const Game& g);
  
  Game& operator= (const Game& rhs);
  
  ~Game(){
    delete m_p1;
    delete m_p2;
    delete m_b1;
    delete m_b2;
  }
  
  Player* getPlayer1() const { return m_p1; }
  Player* getPlayer2() const { return m_p2; }
  Board* getBoard1() const { return m_b1; }
  Board* getBoard2() const { return m_b2; }
  
  bool continueGame() const { return m_b1->isAlive() && m_b2->isAlive(); }
  
  void start();

  void doTurn(Player* p1, Board* b1, Player* p2, Board* b2);

private:
  //  void initPlayer(Player* p, Board* b, const int board_width, const int board_height, const std::vector<Ship*>& ships);
  //  static void initRand();
  
  //  static bool initRandCalled;
  Player* m_p1;
  Player* m_p2;
  Board* m_b1;
  Board* m_b2;
  
};



#endif
