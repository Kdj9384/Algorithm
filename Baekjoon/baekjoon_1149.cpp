#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

// IN[N][3] - IN[N][R], IN[N][G], IN[N][B]
// M[N][3] - M[N][R], M[N][G], M[N][B]
// M[i][R] = MIN( M[i-1][G] + IN[i][R], M[i-1][B] + IN[i][R] )
// M[i][G] = MIN( M[i-1][R] + IN[i][G], M[i-1][B] + IN[i][G] )
// M[i][B] = MIN( M[i-1][G] + IN[i][B], M[i-1][R] + IN[i][B] )

#define R 0
#define G 1
#define B 2

int main(void)
{
  int N;
  std::cin >> N;

  int IN[N][3];
  int M[N][3];

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      std::cin >> IN[i][j];
    }
  }

  for (int i = 0; i < N; i++)
  {
    std::memset(M[i], 0, 3);
  }

  M[0][R] = IN[0][R];
  M[0][G] = IN[0][G];
  M[0][B] = IN[0][B];

  for (int i = 1; i < N; i++)
  {
    M[i][R] = std::min(M[i - 1][G] + IN[i][R], M[i - 1][B] + IN[i][R]);
    M[i][G] = std::min(M[i - 1][R] + IN[i][G], M[i - 1][B] + IN[i][G]);
    M[i][B] = std::min(M[i - 1][G] + IN[i][B], M[i - 1][R] + IN[i][B]);
  }

  // M[N]r, g, b 중에 최소값을 출력
  std::cout << std::min({M[N - 1][R], M[N - 1][G], M[N - 1][B]});
}