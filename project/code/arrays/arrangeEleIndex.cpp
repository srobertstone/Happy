#include <iostream>

using namespace std;
void rearrange(int arr[], int size)
{
  for( int i = 0; i < size; i++ )
  {
    if(arr[i] < 0)
      continue;
    if( arr[i] == i )
      continue;
    int tmp = 0;
    tmp = arr[i];
    arr[i] = arr[tmp];
    arr[tmp] = tmp;
  }
}

int main()
{
  int arr[] = {8,-1,0,-1,-1,6,5,7};
  rearrange(arr, 8);
  for( int i = 0; i < 8; i++)
  {
    cout << arr[i] << endl;
  }
  return 0;
}
