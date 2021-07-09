#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
  int answer = 0;

  sort(lost.begin(), lost.end());
  sort(reserve.begin(), reserve.end());

  vector<int> lost_set(lost.size());
  vector<int> reserve_set(reserve.size());

  // 겹치는 학생 제거
  set_difference(lost.begin(), lost.end(), reserve.begin(), reserve.end(), lost_set.begin());
  set_difference(reserve.begin(), reserve.end(), lost.begin(), lost.end(), reserve_set.begin());

  answer = n - lost_set.size();

  // 빌려주기
  while (true)
  {
    // reserve가 더 크면, lost를 버림
    // lost가 더 크면, reserve를 버림
    // (둘 다 +- 1 범위 내에서 )
    if (lost_set.empty() || reserve_set.empty())
    {
      break;
    }

    int l = lost_set.back();
    int r = reserve_set.back();

    if (l > r + 1)
    {
      lost_set.pop_back();
    }
    else if (l < r - 1)
    {
      reserve_set.pop_back();
    }
    else
    {
      lost_set.pop_back();
      reserve_set.pop_back();
      answer++;
    }
  }

  return answer;
}

int main()
{
  int n = 5;
  vector<int> lost = {2, 4};
  vector<int> reserve = {1, 3, 5};

  int a = solution(n, lost, reserve);

  cout << a;
}