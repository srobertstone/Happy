#include <vector>


using namespace std;

class Vertex
{
  int data;
  vector<Vertex*> listOfEdges; 

public:

  Vertex(int d)
  {
    this->data = d;
  }

  void addEdge( Vertex* &  v )
  {
    listOfEdges.push_back(v);
  }

};
