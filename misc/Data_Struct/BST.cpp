/**
 *
 *
 *
 *
 **/

class BSTNode
{
  
public:

  BSTNode *left;
  BSTNode *right;
  BSTNode *parent;

  int data;

  BSTNode(int d) { left = 0; right = 0; parent = 0; data = 0;} 

  //might need to make deconstructor here




};


class BST
{
public:

  BSTNode *root;
  int isize;

  BST() { root = 0; isize = 0;}

  int size()
  {
    return this->isize;
  }


  bool empty()
  {
    if( this->isize != 0 )
      return false;
    return true;
  }


  bool insert( int d  )
  { 
    BSTNode *toInsert = new BSTNode(d);
    BSTNode *current = this->root;
    BSTNode *chaser;


    while( current != 0 )
    {
      chaser = current;
      if( current->data > d )
        current = current->left;
      else if( current->data < d )
        current = current->right;
      else{
        delete(toInsert);
        return false;
      }


    }

    isize++;
    return true;
  }

 
  


};


int main()
{
  BST b;
  b.insert(100);
  b.insert(50);
  b.insert(150);
  return 0;
}
