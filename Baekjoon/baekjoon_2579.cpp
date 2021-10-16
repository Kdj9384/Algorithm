#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

int main(void)
{
  int N;
  std::cin >> N;

  int IN[N], M[N];

  memset(M, 0, N);

  for (int i = 0; i < N; i++)
  {
    std::cin >> IN[i];
  }

  M[0] = IN[0];
  M[1] = IN[0] + IN[1];
  M[2] = std::max(IN[0] + IN[2], IN[1] + IN[2]);

  for (int i = 3; i < N; i++)
  {
    M[i] = std::max(M[i - 3] + IN[i - 1] + IN[i], M[i - 2] + IN[i]);
  }

  std::cout << M[N - 1];
}