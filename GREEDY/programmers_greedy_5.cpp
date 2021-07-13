#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int d[100];

bool cmp(vector<int> a, vector<int> b)
{
  return a[2] < b[2];
}

bool checkCycle(vector<int> line)
{
  int a = d[line[0]];
  int b = d[line[1]];

  if (a == b)
  {
    return false;
  }

  else if (a < b)
  {
    // d에서 d[line[1]]의 값과 일치하는 모든 원소의 값을 d[line[0]으로 바꾸어 준다.]
    for (int i = 0; i < 100; i++)
    {
      if (d[i] == b)
      {
        d[i] = a;
      }
    }

    return true;
  }
  else
  {
    for (int i = 0; i < 100; i++)
    {
      if (d[i] == a)
      {
        d[i] = b;
      }
    }

    return true;
  }
}

int solution(int n, vector<vector<int>> costs)
{
  int answer = 0;

  sort(costs.begin(), costs.end(), cmp);

  for (int i = 0; i < 100; i++)
  {
    d[i] = i;
  }

  for (auto i : costs)
  {
    if (checkCycle(i))
    {
      answer += i[2];
    }
  }

  return answer;
}

int main()
{
  int n = 4;
  vector<vector<int>> costs = {{0, 1, 1}, {5, 3, 1}, {3, 4, 2}, {1, 2, 2}, {0, 4, 100}};

  int a = solution(n, costs);

  cout << a;
}