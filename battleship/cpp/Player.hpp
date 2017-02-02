#ifndef player_hpp
#define player_hpp


#include <utility>
#include <string>
#include <iostream> // for debugging

class Player{
public:
  Player() : m_result(std::pair<int, std::string>(1000, "")), m_name("") {} // m_result is initialized to (1000, "") because -1, 0, 1 are used for hitcodes, 1000 signifies no guess has been made.

  virtual ~Player() {}

  virtual Player* clone() const = 0;

  virtual std::pair<int, int> makeGuess() = 0;
  
  std::string getName() const { return m_name; }
  
  void msgResultCallback(const std::pair<int, std::string>& result){
    m_result = result;
    msgReceived();
  }
  
  void setName(const std::string& name){ m_name = name; }

protected:
  virtual void msgReceived(){
    std::cout << "message received by PLAYER..." << std::endl;
  }
  
  std::pair<int, std::string> m_result; // result of a guess is represented by the hitcode and either an empty string or the name of the ship hit.
  std::pair<int, int> m_current_guess;
  
  std::string m_name;


};



#endif
