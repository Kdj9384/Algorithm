#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
  return a[0] < b[0];
}
int solution(vector<vector<int>> routes)
{
  int answer = 0;

  sort(routes.begin(), routes.end(), cmp);

  // 1. 기준의 시작, 끝을 정함.
  int start = routes[0][0];
  int end = routes[0][1];

  for (int i = 1; i < routes.size(); i++)
  {
    // 포함되는 경우.
    if (routes[i][1] <= end)
    {
      end = routes[i][1];
    }
    // 걸치는 경우
    else if (routes[i][0] <= end && routes[i][1] > end)
    {
      // nothing
    }
    // 아예 바깥에 있는 경우.
    else
    {
      answer++;
      start = routes[i][0];
      end = routes[i][1];
    }
  }

  // 마지막 경로의 차량을 감시할 카메라 추가
  answer++;

  return answer;
}

int main()
{
  vector<vector<int>> routes = {{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}};

  int a = solution(routes);
}