#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
  vector<int> answer;

  for (auto i : commands)
  {
    vector<int> temp;

    // i[0]번째 부터 i[1]번째까지 잘라냄
    for (int j = i[0] - 1; j < i[1]; j++)
    {
      temp.push_back(array[j]);
    }

    // 정렬시킴
    sort(temp.begin(), temp.end());

    // i[2]번째 값을 answer에 추가 .
    answer.push_back(temp.at(i[2] - 1));
  }

  return answer;
}

int main()
{
  vector<int> array = {1, 5, 2, 6, 3, 7, 4};
  vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

  vector<int> a = solution(array, commands);

  for (auto i : a)
  {
    cout << i << " ";
  }
}