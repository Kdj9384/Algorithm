#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(string numbers)
{
  // 최대 길이가 1 ~ 7 인 문자열
  int answer = 0;
  int flag = 0;
  int numbers_size = numbers.size();
  vector<int> num;
  vector<int> candidate;

  for (int i = 0; i < numbers_size; i++)
  {
    char tmp = numbers.at(i);
    num.push_back(tmp - '0');
  }

  sort(num.begin(), num.end(), less<>());

  // 가능한 조합 찾기
  for (int i = 2; i < 10000000; i++)
  {
    int remain = 0;
    int val = i;
    vector<int> tmp_num = num;
    vector<int>::iterator iter;

    while (val != 0)
    {
      remain = val % 10;
      val = val / 10;

      iter = find(tmp_num.begin(), tmp_num.end(), remain);

      if (iter == tmp_num.end())
      {
        flag = 1;
        break;
      }
      else
      {
        *iter = -1;
      }
    }

    if (flag == 0)
    {
      candidate.push_back(i);
    }

    flag = 0;
  }

  // candidate에서 소수만 찾기
  for (int i = 2; i < sqrt(10000000); i++)
  {
    for (int j = 0; j < candidate.size(); j++)
    {
      if (candidate[j] % i == 0 && candidate[j] != i)
      {
        candidate[j] = -1;
      }
    }
  }

  for (auto i : candidate)
  {
    if (i != -1)
    {
      answer++;
    }
  }

  return answer;
}

int main()
{
  string numbers = "011";

  int a = solution(numbers);
  cout << a;
}
