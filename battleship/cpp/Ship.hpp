#ifndef ship_hpp
#define ship_hpp

#include <string>
#include <vector>
#include <utility> // for pair


class Ship{
  // Ship class is an abstract class which provides a common interface for all derived Ships to implement.
  
public:
  //  Ship(){ initRand(); }

  //  virtual ~Ship() = 0; // originally included as a way to force Ship to be an abstract class without a pure virtual function.
  
  int checkHitUpdate(const std::pair<int, int>& coord);
    
  std::vector<std::pair<int, int> > getCells() const { return cells; }
  std::vector<std::pair<int, int> > getHitCells() const { return hitCells; }
  std::string getName() const { return name; }
  int getShots() const { return shots; }
  int getSize() const { return size; }
  bool isAlive() const { return alive; }
  
  // note that setCells() should be called before any call to getCells() or checkHit() or checkHitUpdate()
  void setCells(const std::vector<std::pair<int, int> >& shipCells);


protected:
  virtual void init() = 0;
  int checkHit(const std::pair<int, int>& coord) const;
    
  std::string name;
  int shots;
  int size;
  bool alive;
  std::vector<std::pair<int, int> > cells;
  std::vector<std::pair<int, int> > hitCells;

// private:
//   void initRand();
//   static bool initRandCalled;

};


#endif
