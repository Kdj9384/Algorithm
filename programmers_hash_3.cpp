#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

int mySolution(vector<vector<string>> clothes)
{
  int answer = 0;
  multimap<string, string> multimap1;
  set<string> set1;
  map<string, int> map1;

  int length = clothes.size();
  printf("입력 개수 : %d\n", length);

  for (auto i : clothes)
  {
    cout << "옷의 종료 : " << i[1] << "\n";

    int cnt = map1.count(i[1]);

    if (cnt)
    {
      map1[i[1]] = 1 + cnt;
    }
    else
    {
      map1.insert(make_pair(i[1], 1 + cnt));
    }
  }

  // 옷의 종류의 개수
  int cloth_type_num = map1.size();
  cout << cloth_type_num << "\n";

  // 옷의 종류 - 개수 로 매핑 되어있음.
  // 조합하는 알고리즘 개발 필요.
  int total = 0;

  // 1 ~ n개를 입을 경우,
  for (int i = 1; i <= cloth_type_num; i++)
  {
    if (i == 1)
    {
      // 1개만 입을 경우,
      for (auto i : map1)
      {
        total += i.second;
      }
    }
    else
    {
    }
  }

  return answer;
}

int solution(vector<vector<string>> clothes)
{
  int answer = 0;

  answer = mySolution(clothes);

  return answer;
}

int main()
{
  vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
  int answer = solution(clothes);
}