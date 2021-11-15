#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  int arr[N + 1]; // mod 15746 -> int 범위 커버

  arr[1] = 1;
  arr[2] = 2;

  for (int i = 3; i <= N; i++)
  {
    arr[i] = (arr[i - 1] % 15746) + (arr[i - 2] % 15746);
  }

  std::cout << arr[N] % 15746;
  return 0;
}