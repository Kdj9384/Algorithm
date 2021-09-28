#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef struct PointInfo
{
  int key;
  int target_point;
  int origin_index;
} PointInfo;

bool cmp(PointInfo a1, PointInfo a2)
{
  return a1.key < a2.key;
}

bool cmp2(PointInfo a1, PointInfo a2)
{
  return a1.origin_index < a2.origin_index;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, input;
  std::cin >> N;
  std::vector<int> vec;
  std::map<int, int> m;

  for (int i = 0; i < N; i++)
  {
    std::cin >> input;
    vec.push_back(input);
    m[input] = -1;
  }

  int cnt = 0;
  for (auto i = m.begin(); i != m.end(); i++)
  {
    i->second = cnt;
    cnt++;
  }

  for (auto i : vec)
  {
    auto k = m.find(i);
    std::cout << k->second << " ";
  }
}