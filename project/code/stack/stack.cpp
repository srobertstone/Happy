#include <array>
#include <iostream>
/**
 *
 *
 *
 *
 *
 * **/

class Stack
{

private:
  
  int *arr;
  int head;
  int MAXSIZ;
  int numOfElements;

public:
  

  Stack ()
  {
    head = -1;
    MAXSIZ = 10;
    numOfElements = 0;
    arr = new int[MAXSIZ];
  }


  void push( int data )
  {
    if( head == (MAXSIZ - 1) )
    {
      MAXSIZ = MAXSIZ * 2;
      int *twiceSizeArray = new int[MAXSIZ];
      for( int i = 0; i < numOfElements; i++ )
      {
        twiceSizeArray[i] = arr[i];
      }
      delete(arr);
      arr = twiceSizeArray;
    }

    head = head + 1;
    arr[head] = data;
    numOfElements++;
  }

  bool pop()
  {
    if( this->empty() )
      return false;
    head = head - 1;
    numOfElements--;
    return true;
  }

  int top()
  {
    return arr[head];
  }


  bool empty()
  {
    if( numOfElements == 0 )
      return true;
    return false;
  }

  ~Stack()
  {
    delete(arr);
  }




};


int main()
{
  Stack s;

  for( int i = 0; i < 50; i++ )
  {
    s.push(i);
  }

  for( int i = 0; i < 50; i++ )
  {
    std::cout << s.top() << std::endl;
    s.pop();
   } 

}













