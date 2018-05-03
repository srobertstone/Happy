#include <vector>
#include <iostream>
#include <utility>
#include <limits>

using namespace std;


std::pair<int,int> findSmallLarge( vector<int> input )
{
  int smallN, largeN;
  smallN = numeric_limits<int>::max();
  largeN = 0;
  
  for(unsigned int i = 0; i < input.size(); i++ )
  {
    if( input[i] < smallN )
      smallN = input[i];
    
    if( input[i] > largeN )
      largeN = input[i];
  }

  return pair<int,int> {smallN, largeN};

}


int main()
{

  vector<int> tester;
  tester.push_back(2);
  tester.push_back(5);
  tester.push_back(4);
  tester.push_back(2);
  tester.push_back(3);
  tester.push_back(7);
  tester.push_back(5);
  tester.push_back(1);
  tester.push_back(2);
  tester.push_back(9);


  for( int i = 0; i < tester.size(); i++ )
  {
    cout << tester[i] << endl;
  }


  pair<int,int> answer = findSmallLarge( tester );

  cout << answer.first << " " << answer.second << endl;


  return 0;
}



