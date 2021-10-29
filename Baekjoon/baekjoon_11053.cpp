/*
* dp를 통해 문제 해결.
* dp[i] : i 길이의 집합에서의 가장 긴 증가하는 수열의 길이
* dp[i] = max(dp[j]) + 1 (j < i && arr[j] < arr[i])
* 
* arr[i] 보다 작은 수는  arr[i] 을 다음 수로 연결시킬 수 있다. 
* --> 즉, dp[i]는 max(dp[j]) + 1 이다.
*/

#include <iostream>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;

  int arr[N];
  int dp[N];

  for (int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    dp[i] = 0;
  }

  dp[0] = 1;
  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[j] < arr[i])
      {
        dp[i] = std::max(dp[j], dp[i]);
      }
    }
    dp[i]++;
  }

  std::sort(dp, dp + N);
  std::cout << dp[N - 1];
}