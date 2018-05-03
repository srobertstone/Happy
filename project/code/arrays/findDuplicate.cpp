#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;


int findDuplicate( vector<int> input )
{
  unordered_map<int, bool> map;

  for( unsigned int i = 0; i < input.size(); i++ )
  {
    auto itt = map.find(input[i]);
    
    //not found
    if( itt == map.end() )
    {
      map.insert({input[i], true});
    }

    else
    {
      return input[i];
    }

  }
    
  return -1;
}



int main()
{
   
  vector<int> tester(10);

  for( int i = 0; i < 10; i++ )
  {
    tester[i] = i + 1;
  }
 
  tester.push_back(5);


  cout << findDuplicate(tester) << endl;

  return 0;
}

