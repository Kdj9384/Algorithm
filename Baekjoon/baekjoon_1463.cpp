#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

int main(void)
{
  int N;
  std::cin >> N;

  int M[N + 1];

  memset(M, 0, N + 1);
  M[1] = 0;
  M[2] = 1;
  M[3] = 1;

  for (int i = 4; i <= N; i++)
  {
    int two, three, other;
    two = three = other = 2147483647;

    if (i % 2 == 0)
    {
      two = 1 + M[i / 2];
    }

    if (i % 3 == 0)
    {
      three = 1 + M[i / 3];
    }

    other = 1 + M[i - 1];

    M[i] = std::min({two, three, other});
  }

  std::cout << M[N];
}