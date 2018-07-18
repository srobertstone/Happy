#include <iostream>
#include <array>
using namespace std;
class Queue
{
private:
  int MAXSIZ;
  int head;
  int tail;
  int *arr;
  int numOfElements;

public:

  Queue()
  {
    MAXSIZ = 10;
    head = -1;
    tail = -1;
    arr = new int[MAXSIZ];
    numOfElements = 0;
  }


  void enqueue( int data )
  {
    if( this->empty() )
      head = head + 1;
    
    else if( tail == (MAXSIZ - 1) )
    {
      MAXSIZ = MAXSIZ * 2;
      int *doubleSizeArray = new int[MAXSIZ];

      for(int i = 0; i < numOfElements; i++)
      {
        doubleSizeArray[i] = arr[i];
      }

      delete(arr);
      arr = doubleSizeArray;
    }

    tail = tail + 1;
    arr[tail] = data;
    numOfElements++;
  }


  void dequeue()
  {
    if( this->empty() )
    {
      head = -1;
    }
    else if( head == tail )
    {
      head = -1;
      tail = -1;
      numOfElements = 0;
    }

    else
    {
      head = head + 1;
      numOfElements = numOfElements - 1;
    }
  }

  bool empty()
  {
    if( (head == -1) && (tail == -1) )
      return true;
    return false;
  }

  int front()
  {
    if( this->empty() )
    {
      head = -1;
    }

    else
      return arr[head];
  }


  ~Queue()
  {
    delete(arr);
  }


};



int main()
{
  Queue q;
 
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  cout << q.front() << endl;
  q.dequeue();
  q.enqueue(6);
  cout << q.front() << endl;
  q.dequeue();
  cout << q.front() << endl;
  q.dequeue();
  cout << q.front() << endl;
  q.dequeue();
  cout << q.front() << endl;
  q.dequeue();
  cout << q.front() << endl;
  q.dequeue();

  return 0;
}
