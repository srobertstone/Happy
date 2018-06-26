#include <iostream>


using namespace std;

void reverse( int arr[], int size )
{
  int left, right;
  left = 0;
  right = size - 1;

  while ( left < right )
  {
    int tmp = 0;
    tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
    left++;
    right = right - 1;
  }

}


int main()
{

  int array[] = {1,2,3,4,5};
  
  reverse(array, 5);
  for(int i = 0; i < 5; i++ )
  {
    cout << array[i] << endl;
  }

  return 0;
}

