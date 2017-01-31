#include "ViewScreen.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


void ViewScreen::update(const std::string& shipName, const ViewScreen::coord& c, const bool isHit, const bool isKill){
  if(!isHit){
    // push pt to "miss"
    ViewScreen::updateMiss(c);
  }else{
    if(isKill){
      // push pt to "dead"
      ViewScreen::updateKill(c, shipName);
    }else{
      // push pt to shipName
      ViewScreen::updateShip(c, shipName);
    }
  }
}


void ViewScreen::print(){
  // print m_board_map to screen
  for(int i = 0; i < m_board_height; ++i){
    for(int j = 0; j < m_board_width; ++j){
      ViewScreen::coord c(j, i);
      auto it = find(m_misses.begin(), m_misses.end(), c);
      if(it != m_misses.end()){
	std::cout << " " << m_missChar << " ";
      }else{
	it = find(m_hits.begin(), m_hits.end(), c);
	if(it != m_hits.end()){
	  std::cout << " " << m_hitChar << " ";
	}else{
	  it = find(m_kills.begin(), m_kills.end(), c);
	  if(it != m_kills.end()){
	    std::cout << " " << m_killChar << " ";
	  }else{
	    std::cout << " " << m_fogChar << " ";
	  }
	}
      }
    }
    std::cout << std::endl;
  }
}


void ViewScreen::updateMiss(const ViewScreen::coord& c){
  auto it = find(m_hits.begin(), m_hits.end(), c);
  if(it != m_hits.end()){
    // is a miss because it's been guessed previously
    return;
  }
  it = find(m_kills.begin(), m_kills.end(), c);
  if(it != m_kills.end()){
    // is a miss because it's been guessed previously
    return;
  }
  m_misses.push_back(c);
}


void ViewScreen::updateKill(const ViewScreen::coord& c, const std::string& shipName){
  m_kills.push_back(c);
  // need to push back all points from the map and remove the key for that ship
  if(m_board_map.count(shipName) > 0){
    //    std::cout << "appending previously hit cells..." << std::endl;
    std::vector<ViewScreen::coord> shipCells = m_board_map[shipName];
    for(auto& cell : shipCells){
      //      std::cout << "appending cell...\t(" << cell.first << ", " << cell.second << ")" << std::endl;
      m_kills.push_back(cell);
      auto it = find(m_hits.begin(), m_hits.end(), cell);
      m_hits.erase(it);
    }
    m_board_map.erase(shipName);
  }else{
    //    std::cout << "ship hasn't been hit before..." << std::endl;
  }
}


void ViewScreen::updateShip(const ViewScreen::coord& c, const std::string& shipName){
  m_hits.push_back(c);
  // need to add an entry for the ship
  if(m_board_map.count(shipName) > 0){
    (m_board_map[shipName]).push_back(c);
  }else{
    (m_board_map[shipName]).push_back(c);
  }
}
