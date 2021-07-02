#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
  // 1. 가장 큰 자릿수를 비교

  int bigger_size = (a.size() > b.size() ? a.size() : b.size());
  int smaller_size = (a.size() < b.size() ? a.size() : b.size());

  for (int i = 0; i < bigger_size; i++)
  {
    // 한쪽이 작을 때
    if (i == smaller_size)
    {
      int aa = stoi(a + b);
      int bb = stoi(b + a);

      return aa > bb;
    }

    // 같을 때
    if (a[i] - '0' == b[i] - '0')
    {
      continue;
    }
    else
    {
      return a[i] - '0' > b[i] - '0';
    }
  }

  // 두 원소가 일치하는 경우.
  return true;
}

bool cmp2(string a, string b)
{
  return a + b > b + a;
}

string solution(vector<int> numbers)
{
  string answer = "";
  vector<string> numbers_s(numbers.size());
  int check_zero = 0;

  for (int i = 0; i < numbers.size(); i++)
  {
    numbers_s[i] = to_string(numbers[i]);
    check_zero += numbers[i];
  }

  if (check_zero == 0)
  {
    return "0";
  }

  sort(numbers_s.begin(), numbers_s.end(), cmp2);

  for (auto i : numbers_s)
  {
    answer += i;
  }

  return answer;
}

int main()
{
  vector<int> numbers = {10, 0, 0, 1, 2, 3, 4, 5, 6, 10};
  string a = solution(numbers);
  cout << a;
}
// 10, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10