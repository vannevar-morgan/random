#include "Tree.hpp"
#include <iostream>


using namespace std;

int main(void){
  Tree<int> bst(7);
  cout << "Tree data (operator <<): " << endl;
  cout << bst << endl;

  auto tree_data = bst.get_data();
  cout << "size of tree data: " << tree_data.size() << endl;
  cout << "Tree data (get_data): " << endl;
  for(auto i : tree_data){
    cout << i << " ";
  }
  cout << endl;
  
  cout << "Enter some numbers to test binary search tree with..." << endl;
  int n;
  while(cin >> n){
    bst.insert(n);
  }

  cout << "Tree data: " << endl;
  cout << bst << endl;
  
  if(bst.has_left()){
    auto left_child = bst.get_left_node();
    cout << "Left Node data: " << endl;
    cout << left_child << endl;
  }

  if(bst.has_right()){
    auto right_child = bst.get_right_node();
    cout << "Right Node data: " << endl;
    cout << right_child << endl;
    // Tree<int> right_child2;
    // right_child2 = right_child;
  }


  return 0;
}
