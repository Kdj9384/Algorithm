#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

// 시간 초과 - O(n^2) 알고리즘
bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
  if (a.first == b.first)
  {
    return a.second < b.second;
  }

  return a.first < b.first;
}
int Dynamic_Approch()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> arr(N);
  int dp[N];

  memset(dp, -1, N);

  for (int i = 0; i < N; i++)
  {
    std::cin >> arr[i].first >> arr[i].second;
  }

  std::sort(arr.begin(), arr.end(), cmp);

  dp[0] = 1;
  for (int i = 0; i < N; i++)
  {
    int max_cnt = 0;
    for (int j = 0; j < i; j++)
    {
      if (arr[j].second <= arr[i].first)
      {
        max_cnt = std::max(dp[j], max_cnt);
      }
    }
    dp[i] = max_cnt + 1;
  }

  std::sort(dp, dp + N);
  std::cout << dp[N - 1];

  return 0;
}

// Greedy Approach
// 종료 시간기준으로 오름차순으로 정렬, 작은것 부터 선택
// 선택할때 feasibility check 하기 (시작시간 >= 종료시간)
bool cmp2(std::pair<int, int> a, std::pair<int, int> b)
{
  if (a.second == b.second)
  {
    return a.first < b.first;
  }

  return a.second < b.second;
}
int main()
{
  int N;
  int max_cnt = 1;
  int criteria;
  std::cin >> N;
  std::vector<std::pair<int, int>> arr(N);

  for (int i = 0; i < N; i++)
  {
    std::cin >> arr[i].first >> arr[i].second;
  }
  std::sort(arr.begin(), arr.end(), cmp2);

  criteria = arr[0].second;
  for (int j = 1; j < N; j++)
  {
    if (arr[j].first >= criteria)
    {
      max_cnt++;
      criteria = arr[j].second;
    }
  }

  std::cout << max_cnt;

  return 0;
}