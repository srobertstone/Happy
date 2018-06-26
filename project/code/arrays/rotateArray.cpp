#include <iostream>

using namespace std;

void rotation( int  array[], int d, int n )
{
  int tmp;

  for( int i = 0; i < d; i++ )
  {
     for( int x = 0 ; x < n -1; x++ )
     {
       tmp = array[x];
       array[x] = array[x+1];
       array[x+1] = tmp;
     }
  }

}



int main()
{
  int arr[] = {1,2,3,4,5,6,7};
  for( int i = 0; i < 7; i++ )
  {
    cout << arr[i] << endl;
  }
  rotation( arr, 2, 7 );
  cout << "rotated" << endl;
  
  for( int x = 0; x < 7; x++ )
  {
    cout << arr[x] << endl;
  }

  return 0;
}
