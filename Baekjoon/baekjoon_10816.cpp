#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::cin;
using std::cout;

/* #1
음수 + 알파 => 양수 => 배열의 random access -> 빠름 공간 많이차지
#include <stdio.h>
int a[20000010];
int main()
{
	int n,m,k;
	scanf("%d",&n);
	for(;n--;)scanf("%d",&k),++a[k+10000000];
	scanf("%d",&m);
	for(;m--;)scanf("%d",&k),printf("%d ",a[k+10000000]);
	return 0;
}
*/

/* #2
map을 사용함 
	while(n--){
		cin>>num;
		mp[num]++; // map에 없는 key인 경우, pair쌍을 만들어 준다. 
    mp.at(num)++;
	}
*/

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, K, tmp;

  // 행렬 A 입력
  cin >> N;
  std::map<int, int> n_map;
  // std::vector<int> m_vec;

  while (N--)
  {
    cin >> K;
    auto target = n_map.find(K);
    if (target == n_map.end())
    {
      n_map.insert(std::make_pair(K, 1));
    }
    else
    {
      target->second += 1;
    }
  }
  cin >> M;

  while (M--)
  {
    cin >> tmp;

    auto i = n_map.find(tmp);

    if (i == n_map.end())
    {
      cout << "0 ";
    }
    else
    {
      cout << i->second << " ";
    }
  }
}