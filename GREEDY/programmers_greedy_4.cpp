#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
  int answer = 0;
  vector<int>::iterator iter;
  int small = 0;
  int big = people.size() - 1;

  sort(people.begin(), people.end());

  while (true)
  {
    if (small == big)
    {
      return answer + 1;
    }
    else if (small > big)
    {
      return answer;
    }

    int biggest = people[big];
    int smallest = people[small];

    if (biggest + smallest > limit)
    {
      answer++;
      big--;
    }
    else
    {
      answer++;
      big--;
      small++;
    }
  }

  return answer;
}

int main()
{
  vector<int> people = {70, 50, 80, 50};
  int limit = 100;

  int a = solution(people, limit);
  cout << a;
}