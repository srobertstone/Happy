/**
 *
 *
 *
 *
 *
 *
 * */

#include <string>
#include <iostream>

using namespace std;


void reverseString( string &toReverse, int count )
{
  char c = toReverse[count];
  if(  c != NULL )
  {
    string *tmp;
    //tmp->append( toReverse,toReverse.begin() +count, toReverse.end());
    reverseString(tmp, count+1); 
  }

  cout << toReverse[count];
}




int main()
{
  string test = "hello";


  reverseString(test, 0 );

  return 0;

}








