/**
 *  There are three types of edits that can be performed on strings:
 *  insert a character, remove a character, or replace a character.
 *  Given two strings, write a function to check if they are one
 *  edit (or zero edits) away.
 *
 *  EX: 
 *  pale, ple -> true
 *  pales, pale -> true
 *  pale, bale -> true
 *  pale, bake -> false
 **/

#include <string.h>
#include <iostream>

class Node{

public:

  Node *root;
  Node *child = 0;
  char c = 0;
  
  Node (char c ) { c = c; }

void helpDelete( Node *root )
{
  root = root->child;
  delete(root); 
}

  ~Node()
  {
    helpDelete(root); 
  }
 

};




//Node *root = new Node(0);
//root->parent = 0;  

Node *createTree( std::string stringOne )
{

  std::cout << "Made it into createTree" << std::endl;
  
  Node *root =  new Node(0);

  //std::cout << "Set root" << std::endl;

  Node *stepper = 0;  
  root = stepper; 

  //std::cout << "Set stepper" << std::endl;

  for( int step = 0; step < stringOne.size(); step++ )
  {
    std::cout << "Made it into the loop" << std::endl;
    stepper->c = stringOne[step];
    std::cout << stepper->c << std::endl;   

    Node *child =  new Node(0);
    stepper->child = child;

    stepper = stepper->child;
   
   
    
  }

  /*
  while ( root->child != 0 )
  {
    std::cout << root->c << std::endl;
  }
  */
  return root;
}






bool oneAway( std::string stringOne, std::string stringTwo )
{

  std::cout << "Made it into oneAway" << std::endl;
  
  createTree( stringOne );

  // Going through the strings each character at a time
  for( int step = 0; step < stringOne.size() && step < 
       stringTwo.size();  step++ )
  {
    char charOfOne = stringOne[step];
    char charOfTwo = stringTwo[step];

    // Comparing the two characters to see if we need to do anything    
    if( charOfOne != charOfTwo )
    {
            



    }

  }

  return false;
}

int main( int argc, char **argv )
{
  std::string inputOne = "";
  std::string inputTwo = "";
 
  inputOne = "hello";

 
  std::cout << oneAway(inputOne, inputTwo) << std::endl;
  return 0;
}
