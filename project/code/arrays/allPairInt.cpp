#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


vector<pair<int,int>> findAllPair( vector<int> input, int target )
{
  vector<pair<int,int>> toReturn;
  int targetSum, valToStore, currentValue, otherValue;
  targetSum = target;
  unordered_map<int, int> map;
  vector<int> dups;


  for( unsigned int i = 0; i < input.size(); i++ )
  {
    currentValue = input[i];
    valToStore = targetSum - currentValue;

    if( valToStore < 0 ){
      continue;
    }

    //check to see if we've seen this value before
    auto itt = map.find(valToStore);
    if( itt == map.end() )
    {
      map.insert({valToStore, currentValue});
      map.insert({currentValue, valToStore});
    }

    else
    { 
      pair<int,int> toAdd;
      int first = itt->first;
      int second = itt->second;

      toAdd = {first, second};
      toReturn.push_back(toAdd);
     }

   }
  

  for(int x = 0; x < toReturn.size(); x++)
  {
    pair<int,int> tmp = toReturn[x];
    int one = tmp.first;
    int two = tmp.second;

    dups.push_back(one);
    dups.push_back(two);
   
    for( int j = 0; j < dups.size(); j++ )
    {
      if( (one or two) == dups[j] )
      {
        toReturn.erase(toReturn.begin() + j );
      }

    }


  }

  return toReturn;
}






int main()
{
  vector<int> tester;
  tester.push_back(3);
  tester.push_back(7);
  tester.push_back(9);
  tester.push_back(2);
  tester.push_back(8);
  tester.push_back(2);
  tester.push_back(1);
  tester.push_back(6);
  tester.push_back(5);
  tester.push_back(3);
  
  vector<pair<int,int>> list;
  list = findAllPair( tester, 11 );


  for( unsigned int i = 0; i < list.size(); i++ )
  {
    pair<int,int> sumPair = list[i];
    cout << "First # is: " << sumPair.first << " ";
    cout << "Second # is: " << sumPair.second << endl;
  }

  
  
  return 0;
}



