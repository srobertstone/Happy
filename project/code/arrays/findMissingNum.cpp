#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


using namespace std;


/**
 *  How to find missing # in integer array 1 through 99?
 *
 * */

int findMissing( int *array )  
{
  
  int toReturn = 0;
  int REF = 4950; //specific to the question asking 1 through 100  
  int sum = 0;


  for( unsigned int i = 0; i < 100; i++)
  {
    sum = sum + array[i];
  }


  toReturn = REF - sum;

  return toReturn;
}


/* Tester */
int main()
{
  srand ( time(NULL) );
  int ran;
  ran = rand() % 100;
  
  int tester[100];

  cout << "Random # is: " << ran << endl;


  for( int x = 0; x < 100; x++ )
  {
    if( x == ran )
      tester[x] = 0;
      
    else
      tester[x] = x;
  }


 cout << findMissing(tester) << endl;

 return ran;

}




