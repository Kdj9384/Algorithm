#include <iostream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, K;
  int cnt = 0;
  std::cin >> N >> K;
  int arr[N];

  for (int i = N - 1; i >= 0; i--)
    std::cin >> arr[i];

  if (N == 1)
  {
    std::cout << K;
    return 0;
  }

  for (auto i : arr)
  {
    if (K == 0)
      break;

    if (i <= K)
    {
      cnt += K / i;
      K = K % i;
    }
  }

  std::cout << cnt;
  return 0;
}