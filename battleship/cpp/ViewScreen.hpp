#ifndef viewscreen_hpp
#define viewscreen_hpp

#include <map>
#include <vector>
#include <utility>
#include <string>


class ViewScreen{
  typedef std::pair<int, int> coord;

public:
  ViewScreen(const int board_width, const int board_height): m_board_width(board_width), m_board_height(board_height){
  }  
  
  
  void update(const std::string& shipName, const coord& pt, const bool isHit, const bool isKill);
  
  void print();


protected:
  int m_board_width;
  int m_board_height;
  std::map<std::string, std::vector<coord> > m_board_map;
  std::vector<coord> m_misses;
  std::vector<coord> m_hits;
  std::vector<coord> m_kills;
  
  
  void updateMiss(const ViewScreen::coord& c);
  void updateKill(const ViewScreen::coord& c, const std::string& shipName);
  void updateShip(const ViewScreen::coord& c, const std::string& shipName);
  
  
  static const char m_fogChar = '~'; // character to display for fog of war
  static const char m_missChar = '.'; // character to display for a miss
  static const char m_hitChar = 'H'; // character to display for a hit
  static const char m_killChar = 'X'; // character to display for a kill



};



#endif
