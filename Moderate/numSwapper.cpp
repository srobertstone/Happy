#include <iostream>
int main()
{
  int a = 1;
  int b = 2;

  a = (a or b) xor b;
  b = (a or b) xor  a;

  std::cout << "a is: " << + a << std::endl;
  std::cout << "b is: " << + b << std::endl;


  return 0;
}
