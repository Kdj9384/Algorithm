#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

int mySolution(vector<vector<string>> clothes)
{
  map<string, int> map1;
  int cloth_type_num;
  int length = clothes.size();
  int total = 1;
  int temp = 0;

  for (auto i : clothes)
  {
    int cnt = map1.count(i[1]);

    if (cnt)
    {
      map1[i[1]] += 1;
    }
    else
    {
      map1.insert(make_pair(i[1], 1));
    }
  }

  // 옷의 종류의 개수
  cloth_type_num = map1.size();

  // 각 옷의 종류에, 옷을 안 입는 종류 추가.
  for (auto i : map1)
  {
    total *= i.second + 1;
  }

  // 모든 종류의 옷을 안입는 경우 제외.
  total -= 1;

  return total;
}

int solution(vector<vector<string>> clothes)
{
  int answer = 0;

  answer = mySolution(clothes);

  return answer;
}

int main()
{
  vector<vector<string>> clothes = {{"yellowhat", "face"}, {"bluesunglasses", "face"}, {"green_turban", "face"}};
  int answer = solution(clothes);
}