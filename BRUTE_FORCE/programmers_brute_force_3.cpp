#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow)
{
  vector<int> answer(2);

  vector<int> rows;
  vector<int> cols;
  vector<int> browns;

  for (int i = 1; i <= yellow * yellow; i++)
  {
    if (yellow % i == 0)
    {
      int a1 = i;
      int a2 = yellow / i;

      if (a1 > a2)
      {
        rows.push_back(a1);
        cols.push_back(a2);
      }
      else
      {
        rows.push_back(a2);
        cols.push_back(a1);
      }
    }
  }

  // 2. 가능한 인수분해 갯수 만큼 가능한 brown을 구함.
  for (int i = 0; i < rows.size(); i++)
  {
    int tmp_brown = 2 * rows[i] + 2 * cols[i] + 4;
    browns.push_back(tmp_brown);
  }

  // 3. 주어진 brown과 일치하는 row, col을 선택.
  int indx = -1;
  for (int i = 0; i < browns.size(); i++)
  {
    if (browns[i] == brown)
    {
      indx = i;
    }
  }

  // 4. row+2, col+2의 결과를 answer에 저장.
  answer[0] = rows[indx] + 2;
  answer[1] = cols[indx] + 2;

  return answer;
}

int main()
{
  int brown = 8;
  int yellow = 1;

  vector<int> a = solution(brown, yellow);

  for (auto i : a)
  {
    cout << i << " ";
  }
}