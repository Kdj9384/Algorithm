#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name)
{
  int answer = 0;
  vector<char> vec_name;
  vector<int> answer_list;

  // A ~ M or N ~ Z
  for (int i = 0; i < name.size(); i++)
  {
    char tmp = name.at(i);
    vec_name.push_back(tmp);

    if (tmp > 'N')
    {
      answer += 'Z' - tmp + 1;
    }
    else
    {
      answer += tmp - 'A';
    }
  }

  if (name.size() == 1)
  {
    return answer;
  }

  // 이동 카운트
  int start = 1;
  int end = vec_name.size() - 1;
  int dir = 0;

  while (true)
  {
    // 앞에서
    if (start == vec_name.size())
    {
      break;
    }

    if (vec_name.at(start) == 'A')
    {
      start++;
    }
    else
    {
      break;
    }
  }

  while (true)
  {
    // 뒤에서
    if (end == -1)
    {
      break;
    }

    if (vec_name.at(end) == 'A')
    {
      end--;
    }
    else
    {
      break;
    }
  }

  // 모두 A일 때
  if (end == -1)
  {
    return 0;
  }

  // 연속된 최대의 A의 개수 파악
  int max_a = 0;
  pair<int, int> max_pair = make_pair(1, 1);
  int temp = 0;
  pair<int, int> temp_pair;

  for (int i = 1; i < vec_name.size(); i++)
  {
    if (vec_name.at(i) == 'A')
    {
      if (temp == 0)
      {
        temp_pair.first = i;
      }
      temp++;
    }
    else
    {
      temp_pair.second = i - 1;
      if (temp > max_a)
      {
        max_a = temp;
        max_pair.first = temp_pair.first;
        max_pair.second = temp_pair.second;
      }

      temp = 0;
      temp_pair.first = 0;
      temp_pair.second = 0;
    }
  }

  answer_list.push_back(end);
  answer_list.push_back(vec_name.size() - start);

  if (max_a != 0)
  {
    answer_list.push_back(2 * (max_pair.first - 1) + vec_name.size() - max_pair.second - 1);
    answer_list.push_back(max_pair.first - 1 + 2 * (vec_name.size() - max_pair.second - 1));
  }

  vector<int>::iterator iter = min_element(answer_list.begin(), answer_list.end());

  answer += *iter;

  return answer;
}

int main()
{

  string name = "JEROEN";

  int a = solution(name);

  cout << a;
}