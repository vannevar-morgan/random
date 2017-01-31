#include <cstddef>
#include <vector>
#include <random>
//#include <ctime>
//#include <unistd.h>
#include <utility>
#include <string>

#include "Ship.hpp"
#include "Board.hpp"
#include "ViewScreen.hpp"
#include "Game.hpp"

// bool Game::initRandCalled = false;


// Game::Game(const int board_width, const int board_height, const std::vector<Ship*>& p1Ships, const std::vector<Ship*>& p2ships) : p1(nullptr), p2(nullptr) {
// Game::initPlayer(p1, b1, board_width, board_height, p1Ships);
// Game::initPlayer(p2, b2, board_width, board_height, p2Ships);
// Game::initRand();
// }


Game::Game(const Game& g){
  m_p1 = (g.getPlayer1())->clone();
  m_p2 = (g.getPlayer2())->clone();
  //  Game::initRand();
}


Game& Game::operator= (const Game& rhs){
  if(&rhs != this){
    delete m_p1;
    delete m_p2;
    m_p1 = rhs.getPlayer1();
    m_p2 = rhs.getPlayer2();
  }
  //  Game::initRand();
  return *this;
}

// void Game::initPlayer(Player* p, Board* b, const int board_width, const int board_height, const std::vector<Ship*>& ships){
//   b = new Board(board_width, board_height);
//   for(Ship* const s : ships){
//     b->addShip(s);
//   }
  
//   p = new HumanPlayer(new ViewScreen(board_width, board_height));
// }

// void Game::initRand(){
//   // Initialize the RNG if it hasn't been seeded yet...
//   std::cout << "initializing random seed..." << std::endl;
//   std::cout << "time(0): " << time(0) << std::endl;
//   std::cout << "pid: " << getpid() << std::endl;
//   if(!initRandCalled){
//     srand(time(0) ^ getpid());
//     initRandCalled = true;
//   }
// }

void Game::start(){
// outline of basic game logic:
// - get the desired board size
// - setup and initialize players (devs should be able to create their own ai players by extending player class)
// - loop while both players are alive:
//     - on each players turn:
//         - print the player viewscreen
//         - get player shots
//         - for each player shot:
//             - prompt for a guess
// 	    - test the guess on the other player's board
// 	    - display an appropriate message (hit / miss / sink)
// 	    - update the viewscreen
// 	    - print the updated viewscreen
// 	    - if it's a sink, check if the opposite player is alive:
// 	        - end the game if the opposite player is dead:
// 		    - provide an appropriate message
// - do any cleanup necessary
  int coinFlip = rand() % 2;
  if(coinFlip){
    Game::doTurn(m_p2, m_b2, m_p1, m_b1);
    if(!Game::continueGame()){
      // player 2 wins
      //      m_p2->printViewScreen();
      std::cout << m_p2->getName() << " wins..." << std::endl;
    }
  }
  
  while(true){
    Game::doTurn(m_p1, m_b1, m_p2, m_b2);
    if(!Game::continueGame()){
      // player 1 wins
      //      m_p1->printViewScreen();
      std::cout << m_p1->getName() << " wins..." << std::endl;
      break;
    }
    Game::doTurn(m_p2, m_b2, m_p1, m_b1);
    if(!Game::continueGame()){
      // player 2 wins
      //      m_p2->printViewScreen();
      std::cout << m_p2->getName() << " wins..." << std::endl;
      break;
    }
  }

}


void Game::doTurn(Player* p1, Board* b1, Player* p2, Board* b2){
  int shots = b1->getShots();
  std::pair<int, std::string> guess_result;
  for(int i = 0; i < shots; ++i){
    guess_result = b2->checkHitUpdate(p1->makeGuess());
    p1->msgResultCallback(guess_result);
    // check if the targeted player is dead
    if(guess_result.first == 1){
      if(!b2->isAlive()){
	return;
      }
    }
  }
}
