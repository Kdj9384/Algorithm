#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
  vector<int> answer;

  int prog_idx = 0;

  while (prog_idx != progresses.size())
  {
    // 하루 경과
    for (int i = 0; i < progresses.size(); i++)
    {
      progresses[i] += speeds[i];
    }

    // 결과 확인
    if (progresses[prog_idx] >= 100)
    {
      // 뒤에 완료된 작업이 있는지 확인
      int bonus = 1;

      if (prog_idx != (progresses.size() - 1))
      {
        while (progresses[prog_idx + bonus] >= 100)
        {
          bonus++;
        }
      }

      prog_idx += bonus;
      answer.push_back(bonus);
    }
  }

  return answer;
}

int main()
{

  vector<int> progresses = {93, 30, 55};
  vector<int> speeds = {1, 30, 5};

  // 2, 1
  auto answer = solution(progresses, speeds);

  for (auto i : answer)
  {
    cout << i << " ";
  }

  return 0;
}
