#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
  string answer = "";

  vector<int> list(number.size());
  vector<int>::iterator iter;

  // vector 초기화
  for (int i = 0; i < number.size(); i++)
  {
    list[i] = number[i] - '0';
  }

  iter = list.begin();

  int idx = 0;
  bool flag = true;
  while (k != 0)
  {
    if (idx >= list.size() - 1)
    {
      break;
    }

    for (int j = idx; j <= idx + k; j++)
    {
      if (j >= list.size() - 1)
      {
        break;
      }

      if (list[j] < list[j + 1])
      {
        list.erase(iter + j);
        idx = j - k;

        if (idx < 0)
        {
          idx = 0;
        }
        k--;
        flag = false;
        break;
      }
    }

    if (flag)
    {
      idx += k + 1;
    }
    flag = true;
  }

  if (k != 0)
  {
    for (int i = 0; i < k; i++)
    {
      list.pop_back();
    }
  }

  // vector to string
  for (auto i : list)
  {
    answer += to_string(i);
  }

  return answer;
}

int main()
{
  string number = "42";
  int k = 1;

  string a = solution(number, k);

  cout << a;
}