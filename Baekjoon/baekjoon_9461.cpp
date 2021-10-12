/**
 * @date 2021-10-12
 * @brief
 * 1. 주어진 방법대로 쭉 나열해 보면 점화식을 구할 수 있었다. 
 * 2. 점화식을 통해 구한다.
 * 
 */

#include <iostream>

long long arr[101];

int main()
{
  int N, T;
  std::cin >> T;

  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 1;
  arr[4] = arr[3] + arr[1];
  arr[5] = arr[4];

  while (T--)
  {
    std::cin >> N;

    for (int i = 6; i <= N; i++)
    {
      arr[i] = arr[i - 1] + arr[i - 5];
    }

    std::cout << arr[N] << "\n";
  }
}