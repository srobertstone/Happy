#include "vertex.cpp"


bool isTherePath( Vertex* & start, Vertex* & end )
{



  return false;
}







int main()
{
  Vertex *one = new Vertex(1);
  Vertex *two = new Vertex(2);
  Vertex *three = new Vertex(3);
  Vertex *four = new Vertex(4);
  Vertex *five = new Vertex(5);
  
  one->addEdge(two);
  two->addEdge(three);
  two->addEdge(four);
  four->addEdge(three);
  four->addEdge(five);

  return 0;
};









