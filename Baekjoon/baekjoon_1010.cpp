#include <iostream>
#include <algorithm>

int main()
{
  int T;
  std::cin >> T;
  while (T--)
  {
    int m, n;
    std::cin >> n >> m;
    int arr[m + 1][n + 1];

    for (int i = 1; i <= m; i++)
    {
      for (int j = 0; j <= std::min(n, i); j++)
      {
        if (j == 0 || i == j)
          arr[i][j] = 1;
        else
          arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
      }
    }

    std::cout << arr[m][n] << "\n";
  }
  return 0;
}