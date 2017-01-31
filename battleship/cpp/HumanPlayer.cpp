#include "HumanPlayer.hpp"
#include <utility>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
//#include <cstring>
#include <cstddef> // for std::size_t

//const std::string HumanPlayer::m_prompt = "enter a guess: ";


HumanPlayer::HumanPlayer(const HumanPlayer& hp){
  m_vs = new ViewScreen(*(hp.getViewScreen()));
}


HumanPlayer& HumanPlayer::operator= (const HumanPlayer& rhs){
  if(&rhs != this){
    delete m_vs;
    m_vs = rhs.getViewScreen();
  }
  return *this;
}


std::pair<int, int> HumanPlayer::makeGuess(){
  while(true){
    // should probably have a timeout for too many wrong inputs
    m_vs->print();
    std::cout << m_name << m_prompt << std::endl;
    std::string s = "";
    std::getline(std::cin, s);
    HumanPlayer::replace(s, ";.-", ',');
    
    try{
      std::vector<int> coords;
      std::istringstream data(s);
      std::string temp;
      while(getline(data, temp, ',')){
	std::size_t first_num = temp.find_first_of("0123456789");
	temp = temp.substr(first_num);
	coords.push_back(atoi(temp.c_str()));
      }
      if(coords.size() == 2){
	m_current_guess = std::pair<int, int>(coords[0], coords[1]);
	return m_current_guess;
      }else{
	std::cout << "enter your guess as: x, y" << std::endl;
      }
    }catch(const std::exception& e){
      std::cout << e.what() << std::endl;
    }
  }
  
}


void HumanPlayer::replace(std::string& guess, const std::string& old_tokenizers, const char new_token) const{
  std::size_t index = guess.find_first_of(old_tokenizers);
  while(index != std::string::npos){
    guess[index] = new_token;
    index = guess.find_first_of(old_tokenizers);
  }
}


void HumanPlayer::msgReceived(){
  // check m_result, update viewscreen accordingly
  if(m_result.first == -1){
    m_vs->update(m_result.second, m_current_guess, false, false);
    std::cout << "Miss..." << std::endl;
  }else if(m_result.first == 0){
    m_vs->update(m_result.second, m_current_guess, true, false);
    std::cout << "Hit the " << m_result.second << "!" << std::endl;
  }else if(m_result.first == 1){
    m_vs->update(m_result.second, m_current_guess, true, true);
    std::cout << "Sank the " << m_result.second << "!" << std::endl;
  }else{
    std::cout << "hitCode isn't defined... error in HumanPlayer::msgReceived?  check hitCode=1000?" << std::endl;
  }
  //  m_vs->print();
  //
  //
  //  std::pair<int, std::string> m_result; // result of a guess is represented by the hitcode and either an empty string or the name of the ship hit.
  //  void update(const std::string& shipName, const coord& pt, const bool isHit, const bool isKill);
}
