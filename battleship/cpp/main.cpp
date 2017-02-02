#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <unistd.h>

#include "Ship.hpp"
#include "Carrier.hpp"
#include "Cruiser.hpp"
#include "Destroyer.hpp"
#include "Submarine.hpp"
#include "Minesweeper.hpp"
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include "ViewScreen.hpp"
#include "Board.hpp"
#include "Game.hpp"

using namespace std;


// command line battleship game

// outline of basic game objects:
// + main objects are the game, player, board, ship
// + a game has two players
// + a player has a board and a viewscreen (devs should be able to create their own ai players by extending player class)
// + a board has a list of ships, and functions to manipulate those ships
// + a ship has a list of coordinates representing its position, some properties such as a name and firepower, and functions to manipulate those properties
// + a ship is abstract and must be extended by a more specific class to be used
// + a viewscreen has a list of hits a list of misses, some functions to interact, and a printing function

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

const int MIN_BOARD_WIDTH = 5;
const int MIN_BOARD_HEIGHT = 5;


int main(int argc, char* argv[]){
  if(argc != 5){
    cout << "usage: ./battleship board_width board_height player1_name player2_name" << endl;
    return -1;
  }
  int board_width = atoi(argv[1]);
  int board_height = atoi(argv[2]);
  if(board_width < MIN_BOARD_WIDTH || board_height < MIN_BOARD_HEIGHT){
    cout << "specified board dimensions are less than minimum board dimensions... min board size is " << MIN_BOARD_WIDTH << " X " << MIN_BOARD_HEIGHT << endl;
    return -1;
  }
  
  std::string p1Name(argv[3]);
  std::string p2Name(argv[4]);

  // init prng
  srand(time(0) ^ getpid());

  // init game
  vector<Ship*> p1Ships;
  p1Ships.push_back(new Carrier());
  p1Ships.push_back(new Cruiser());
  p1Ships.push_back(new Destroyer());
  p1Ships.push_back(new Submarine());
  p1Ships.push_back(new Minesweeper());

  vector<Ship*> p2Ships;
  p2Ships.push_back(new Carrier());
  p2Ships.push_back(new Cruiser());
  p2Ships.push_back(new Destroyer());
  p2Ships.push_back(new Submarine());
  p2Ships.push_back(new Minesweeper());
  
  Player* p1 = new HumanPlayer(new ViewScreen(board_width, board_height), p1Name);
  //  p1->setName(p1Name);

  Player* p2 = new HumanPlayer(new ViewScreen(board_width, board_height), p2Name);
  //  p2->setName(p2Name);
  
  Board* b1 = new Board(board_width, board_height, p1Ships);
  Board* b2 = new Board(board_width, board_height, p2Ships);
  
  Game g(p1, p2, b1, b2);

  // run the game
  g.start();

  return 0;
}
