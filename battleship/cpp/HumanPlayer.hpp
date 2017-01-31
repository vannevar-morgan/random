#ifndef human_player_hpp
#define human_player_hpp


#include "Player.hpp"
#include "ViewScreen.hpp"
#include <utility>
#include <string>
#include <iostream> // for debugging
#include <cstddef> // for nullptr

class HumanPlayer : public Player{
public:
  HumanPlayer(){
    m_vs = nullptr;
  }
  
  HumanPlayer(ViewScreen* const vs){ m_vs = vs; }
  
  explicit HumanPlayer(ViewScreen* vs, const std::string& name){
    m_vs = vs;
    m_name = name; 
  }
  
  HumanPlayer(const HumanPlayer& hp);
  
  HumanPlayer& operator= (const HumanPlayer& rhs);
  
  ~HumanPlayer(){
    delete m_vs;
  }
  
  HumanPlayer* clone() const{
    return new HumanPlayer(*this);
  }
  
  std::pair<int, int> makeGuess();
  
  ViewScreen* getViewScreen() const{
    return m_vs;
  }
  
  void printViewScreen() const{ m_vs->print(); }
  
  void setViewScreen(ViewScreen* const vs){
    m_vs = vs;
  }

protected:
  ViewScreen* m_vs;
  
  void msgReceived();
  
private:
  void replace(std::string& guess, const std::string& old_tokenizers, const char new_token) const;
  
  const std::string m_prompt = ", enter a guess: ";
  
};



#endif
