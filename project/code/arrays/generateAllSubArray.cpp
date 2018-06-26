#include <iostream>


using namespace std;


void genSubArray( int array[], int size )
{
  for( int i = 0; i < size; i++ )
  {
    for( int x = 0; x < size; x++ )
    {
      for( int j = i; j <= x; j++ )
      {
        cout << array[j] << " ";
      }
      cout << endl;
    }
  } 
}




int main()
{
  int array[] = {1,2,3,4};
  genSubArray(array, 4);
  return 0;
}
