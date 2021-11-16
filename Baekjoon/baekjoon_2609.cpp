#include <iostream>
#include <algorithm>

int main()
{
  int a, b, temp, ab_mul;
  std::cin >> a >> b;

  // a*b = gcd(a,b) * lcm(a, b);
  ab_mul = a * b;

  //gcd(a, b) = gcd(b, a%b)
  while (b != 0)
  {
    temp = a;
    a = b;
    b = temp % b;
  }

  std::cout << a << "\n"
            << ab_mul / a;
  return 0;
}