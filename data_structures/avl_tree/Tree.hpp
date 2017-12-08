#ifndef guard_tree_hpp
#define guard_tree_hpp

#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>


template <class T>
class Tree{
  // friend std::ostream& operator<<(std::ostream& os, const Tree<T>& tree);

  std::list<T>* node_data;
  Tree<T>* parent_node;
  Tree<T>* left_node;
  Tree<T>* right_node;

public:
  Tree() : node_data(nullptr), parent_node(nullptr), left_node(nullptr), right_node(nullptr) {}
  Tree(const T& data) : node_data(new std::list<T>), parent_node(nullptr), left_node(nullptr), right_node(nullptr) { node_data->push_back(data); }
  ~Tree(){
    delete node_data;
    delete left_node;
    delete right_node;
  }
  Tree(const Tree<T>& copy);
  // Tree<T>& operator=(const Tree<T>& rhs);

  std::list<T>& get_data() { return *node_data; }
  Tree<T>& get_parent_node() {
    //
    // Check is_root() before calling get_parent_node().
    //
    if(parent_node){
      return *parent_node;
    }else{
      throw std::logic_error("request to get_parent_node() but this node is root (parent_node is nullptr)...");
    }
  }

  Tree<T>& get_left_node() {
    if(left_node){
      return *left_node;
    }else{
      throw std::logic_error("request to get_left_node() but left_node does not exist (left_node is nullptr)...");
    }
  }

  Tree<T>& get_right_node() {
    if(right_node){
      return *right_node;
    }else{
      throw std::logic_error("request to get_right_node() but right_node does not exist (right_node is nullptr)...");
    }
  }

  bool has_left() const{
    return left_node;
  }

  bool has_right() const{
    return right_node;
  }
  
  bool is_root() const{
    return !parent_node;
  }

  friend std::ostream& operator<<(std::ostream& os, const Tree& tree){
    //
    // Print the Tree<T> data to ostream.
    //
    if(!tree.node_data){
      // If there's no node data for this node then this is the root node of an empty tree.
      return os;
    }
    
    // print left_node
    if(tree.left_node){
      os << *tree.left_node;
    }
    // print node_data
    for(auto i : *tree.node_data){
      os << i << " ";
    }
    // print right_node
    if(tree.right_node){
      os << *tree.right_node;
    }
    return os;
  }


  void insert(const T& value);


private:
  void insert_left(const T& value);
  void insert_right(const T& value);



};


// template <class T>
// Tree<T>::Tree(Tree<T> copy){
//   std::swap(node_data, copy.node_data);
//   std::swap(parent_node, copy.parent_node);
//   std::swap(left_node, copy.left_node);
//   std::swap(right_node, copy.right_node);
// }

template <class T>
Tree<T>::Tree(const Tree<T>& copy){
  node_data = new std::list<T>(*copy.node_data);
  parent_node = copy.parent_node;
  left_node = copy.left_node;
  right_node = copy.right_node;
  if(left_node){
    left_node = new Tree<T>(*left_node);
  }
  if(right_node){
    right_node = new Tree<T>(*right_node);
  }
}

// template <class T>
// Tree<T>& Tree<T>::operator=(const Tree<T>& rhs){
//   if(&rhs != this){
//     delete node_data;
//     delete left_node;
//     delete right_node;
//     node_data = rhs.node_data;
//     parent_node = rhs.parent_node;
//     left_node = rhs.left_node;
//     right_node = rhs.right_node;
//   }
//   return *this;
// }

// template <class T>
// std::ostream& Tree<T>::operator<<(std::ostream& os, const Tree<T>& tree){
//   //
//   // Print the Tree<T> data to ostream.
//   //
//   if(!tree.node_data){
//     // If there's no node data for this node then this is the root node of an empty tree.
//     return os;
//   }

//   // print left_node
//   if(tree.left_node){
//     os << *tree.left_node;
//   }
//   // print node_data
//   for(auto i : *tree.node_data){
//     os << i << " ";
//   }
//   // print right_node
//   if(tree.right_node){
//     os << *tree.right_node;
//   }
//   return os;
// }

template <class T>
void Tree<T>::insert(const T& value){
  //
  // Insert a value into the tree.
  //
  // The value will be inserted as:
  // value < node_value will be inserted on the left node.
  // value = node_value (or node_value is empty) will be push_back() to the list of the current node.
  // value > node_value will be inserted on the right node.
  //
  if(!node_data){
    node_data = new std::list<T>;
    node_data->push_back(value);
    return;
  }
  if(node_data->size() > 0){
    if(value < node_data->front()){
      // insert left
      insert_left(value);
    }else if(value > node_data->front()){
      // insert right
      insert_right(value);
    }else{
      // insert to current node
      node_data->push_back(value);
    }
  }else{
    node_data->push_back(value);
  }
}

template <class T>
void Tree<T>::insert_left(const T& value){
  //
  // Insert value to the left of the current node.
  //
  if(!left_node){
    left_node = new Tree<T>;
  }
  left_node->insert(value);
}

template <class T>
void Tree<T>::insert_right(const T& value){
  //
  // Insert value to the right of the current node.
  //
  if(!right_node){
    right_node = new Tree<T>;
  }
  right_node->insert(value);
}



#endif
