#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
  return a.second > b.second;
}

vector<int> solution(vector<int> answers)
{
  vector<int> answer;

  string a = "12345";
  string b = "21232425";
  string c = "3311224455";

  vector<pair<int, int>> k;

  k.push_back(make_pair(1, 0));
  k.push_back(make_pair(2, 0));
  k.push_back(make_pair(3, 0));

  for (int i = 0; i < answers.size(); i++)
  {
    if (answers[i] == a[i % 5] - '0')
    {
      k.at(0).second += 1;
    }

    if (answers[i] == b[i % 8] - '0')
    {
      k.at(1).second += 1;
    }

    if (answers[i] == c[i % 10] - '0')
    {
      k.at(2).second += 1;
    }
  }

  sort(k.begin(), k.end(), cmp);

  answer.push_back(k.at(0).first);

  if (k.at(0).second == k.at(1).second)
  {
    answer.push_back(k.at(1).first);
  }

  if (k.at(0).second == k.at(2).second)
  {
    answer.push_back(k.at(2).first);
  }

  sort(answer.begin(), answer.end());

  return answer;
}

int main()
{
  vector<int> answers = {1, 3, 2, 4, 2};

  vector<int> a = solution(answers);

  for (auto i : a)
  {
    cout << i << " ";
  }
}