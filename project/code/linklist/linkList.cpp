/**
 *  Double Link List implementation.
 *
 *  This data structure will be used to as a basis to solve the 
 *  other questions in Chapter 2 which require a constructed link
 *  list.
 *
 *  I will implement it as a doubly link list.
 *
 *  Date started: 1/10/2018
 *  Date completed: 1/17/2018
 **/

#include <iostream>
#include <unordered_map>
#include <vector>
/**
 *  Node class to represent each component in the list.
 *
 **/

class Node
{
public:

  /* Member Variables */
  int data;
  Node *prev;
  Node *next;

  /* Default and Only Constructor */
  Node ( int d ) { data = d; prev = 0; next = 0; }
 
  /**
   *  Connects three unique nodes together.
   *
   *  input: one - the left side node
   *         two - the right side node
   *         calling object - the middle node
   *
   *  Side Effects: Changes the member variables next, and prev for each node.
   *  Error: None.
   *  Return: N/A
   **/
  void connectNode( Node* one, Node *two ) 
  {
    this->prev = one;
    this->next = two;

    one->next = this;
    two->prev = this;
  }

  /**
   *  Used in the deconstructor of LinkList to handle hanging pointers and
   *  the deletion of each node individually.
   *
   *  input: N/A
   *  Side Effects: sets the node's member variables to null and deletes the
   *  calling object from memory.
   *  Error: None. 
   *  Return: N/A
   **/
  void deleteNode() 
  {
    this->prev = 0;
    this->next = 0;
    this->data = 0;
    delete(this);
  }


};

/**
 *  Uses the Node class to represent each individual element. This class is
 *  the implementation of a collection of nodes.  
 *
 *  The list is default implemented as a doubly linked list but several of the
 *  methods will be solved assuming only a singly linked list.
 *
 *  This implementation will have the head and tail nodes be dummy nodes with 
 *  no actual value.
 *
 *  This class has 4 native methods.
 *      int size():
 *      bool insert(int d):
 *      bool remove():
 *      void printAll():
 *
 **/


class LinkList{
  
public:

  /* Member variables */
  Node *head;  //start of list
  Node *tail;  //end of list
  int isize;

  /* Defauly Constructor */
  LinkList () 
  {
    
    /* Initializing and assigning member variables */
    head =  new Node(0);
    tail =  new Node(0);
    isize = 0;

    /* Have to connect the head to tail */
    head->next = tail;
    tail->prev = head;

  }

  /**
   *  Deconstructor. Calls deleteNode in Node class to handle the deletion of
   *  each of the nodes.
   *
   *  Goes through the LinkList from head to tail and deletes each node.
   **/

  ~LinkList() 
  {
    Node *toDelete = head;

    while( toDelete->next != 0 )
    {
      Node *tmp = 0;
      tmp = toDelete;

      toDelete = toDelete->next;
      tmp->deleteNode();
    }

    toDelete = 0;
  }

  /**
   *  Calculates the size of the LinkList.
   *  input: N/A
   *  Error: N/A
   *  Side Effects: N/A
   *  Return: isize - LinkList member variable used to keep track of size
   **/

  int size()
  {
    return this->isize;
  }

  /**
   *  Prints to std out the data of each of the elements in the list.
   *
   *  input: N/A
   *  Error: N/A
   *  Side Effects: prints data to std out
   *  Return: N/A
   **/

  void printAll()
  {
    Node *runner = head->next;

    while( runner->next != 0 )
    {
      std::cout << runner->data << std::endl;
      runner = runner->next;
    }
  }


  /**
   * Inserts a data element into the link list.
   * 
   * input: int d -- the data to be inputted
   * Error: none.
   * Side Effects: Rearranges the pointers in the nodes and
   *               calls the connectNode funtion to do so.
   * Return: bool true: if inserted successfully. (so far no duplicate check)
   *
   **/

  bool insert( int d )
  {
    Node *toInsert = new Node(d);

    //checking if the the list is empty
    if( this->isize == 0 )
      toInsert->connectNode(this->head, this->tail);
    else
      toInsert->connectNode(this->tail->prev, this->tail);
    
    isize++;
    return true;
  }

  /**
   * Removes an element from the end of the list.
   *
   * input: N/A
   * Error: None.
   * Side Effects: Rearranges pointers from the tail and tail->prev
   *               Deletes the node to remove from memory.
   * Return: bool true: if removed correctly.
   *              fakse: if there is nothing to remove
   **/
  bool remove()
  {
    Node *lastElement = this->tail->prev;

    /* Making sure the list isn't connected by comparing head->next to tail */
    if( lastElement != this->head )
    {
      lastElement->prev->next = this->tail;
      this->tail->prev = lastElement->prev;
      lastElement->deleteNode();
      isize--;
      return true;
    }
   
   /* Nothing else to remove */
    else
      return false;
  }

  /**
   * Remove duplicate elements from the link list.
   *
   * input: N/A
   * Error: None.
   * Side Effects: Deletes the nodes that are duplicates.
   * Return: N/A
   *
   **/

  void removeDuplicates()
  {
    Node *currentNode;
    Node *runner;
    
    //used to check if an element is a duplicate
    std::unordered_map<int, bool> hashmap;
 
    //starting at heads next because head is a dummy node
    currentNode = this->head->next;

    while( currentNode->next != 0 )
    {
      //check if currentNode data is in hashmap
      auto searchResult = hashmap.find(currentNode->data);
      
      if( searchResult == hashmap.end() )//not found in the hashmap
      {
        hashmap.insert({currentNode->data, true});
        runner = currentNode;
        currentNode = currentNode->next;
      }
      else
      {
        runner->next = currentNode->next;
        currentNode->deleteNode();
        currentNode = runner->next;
      }   
    }
  }

  /**
   * Returns the element in a list by calculating the difference between
   * the number of elements and the specificed offset.
   *
   * input: int offset: the kth to last 
   * Error: None.
   * Side Effects: doesn't alter the linked list in any way.
   * Return: Node *elementToReturn: the node kth to last.
   *
   **/

  Node* kthToLast(int offset)
  {
    Node *elementToReturn = 0;
    
    int delta = this->size() - offset;
    elementToReturn = this->head->next;   

    for(int i = 0; i < delta; i++)
    {
      elementToReturn = elementToReturn->next;
    }

    return elementToReturn;

  }


  /**
   * Deletes a the refNode from the list, which is somewhere in the list but
   * not the first or last element (hence "middle").
   *
   * input: Node *refNode: the node to delete
   * Error: None.
   * Side Effects: Removes and deletes refNode and rearranges the inner nodes
   *               to reflect that.
   *
   * Return: N/A
   **/
  void deleteMiddleNode( Node* refNode)
  {
    //using a current and runner technique to be able to swap the nodes later
    Node *currentNode;
    Node *runner;

    currentNode = this->head->next;
    runner = head;

    /* want to go until the end of the list */
    while( currentNode->next != 0 )
    {
      //the nodes are equal so we want to delete and leave the loop
      if( currentNode == refNode )
      {
        runner->next = currentNode->next;
        currentNode->deleteNode();
        currentNode = 0;
        break;
      }
      //we continue to step through the list
      else
      {
        runner = currentNode;
        currentNode = currentNode->next;
      }
    }
  }


   
  /*
   * Checks if a given linked list is a palindrome. 
   * i.e: the same forwards as backwards ex: kayak
   *
   * input: N/A
   * Error: None.
   * Side Effects: Does not change the list or inner nodes.
   * Return: bool true: if the list is a palindrome
   *              false: if the list is not a palindrome
   *
   **/

  bool isPalindrome()
  {
    Node *current = this->head->next; //starting at the next of the dummy node
    int position = 0; //used to keep the position of the node in the list
    bool toReturn = false;
     
    std::unordered_map<int, int> unique; //used to check if an ele is unique
    std::vector<int>  map(this->size()); //used to store the element

    //want to go through the entire linked list
    while( current->next != 0 )
    {
      //an iterator to check if we found the element in the the map: unique
      auto search = unique.find(current->data);

      //the element is unique!
      if( search == unique.end() )
      {
        //just need to to add the element into the map and array
        unique.insert({current->data, position});
        map[position] = current->data;
      }

      //we have seen the element before
      else
      {
        //this is the position of the element we need to compare to
        int refNumber = 0;
        refNumber = (this->size()) - position - 1;
         
        //the refnumber reflects an element not yet added 
        if( position < refNumber )
        {
          map[position] = current->data;
          current = current->next;
          position++;
          continue;
        }

        //answer reflects the actual node value
        int answer = map[refNumber];

        //they are the same, so it is still a palindrome
        if( answer == current->data )
        {
          toReturn = true;
          map[position] = current->data;
        }
        
        //they are not the same
        else
          toReturn = false;
       }

      //increase and move position
      position++;
      current = current->next;
     }
     
     return toReturn;
   }


  /**
   *  TO DO:::
   *
   *
   *
   *
   **/
  
   void partitionX(int x )
   { 
     Node *current = this->head->next;
     Node *runner = this->head;
     Node *start = this->head->next;


     while( current->next != 0 )
     {
       if( current->data < x )
       {
         if(start == current)
         {
           runner = current;
           current = current->next;
           continue;
         }

         runner->next = current->next;
         current->next = start->next;
         start->next = current;
       }

       else if( current->data > x )
       {
         while( current->next != 0 )
         {
           Node *swap = current->next;
           runner->next = swap;
           current->next = swap->next;
           swap->next = current;
           current = current->next;
         }
       }

       else
       {
         while( current->next->data != x )
         {
           Node *swap = current->next;
           runner->next = swap;
           current->next = swap->next;
           swap->next = current;
           current = swap;
         }

         runner = current->next;
         current = current->next->next;
         
       }

     }
 

   }


};



  /**
   *
   *
   *
   *
   *
   **/
int main()
{
  LinkList list;

  list.insert(3);
  list.insert(5);
  list.insert(8);
  list.insert(5);
  list.insert(10);
  list.insert(2);
  list.insert(1);

  list.partitionX(5);

  return 0;
}
