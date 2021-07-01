#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include <unordered_map>
#include <map>

using namespace std;

typedef struct
{
  string genre;
  int plays;
  int id;
} Music;

vector<string> genre_rank;
unordered_map<string, int> hash_map;

bool cmp(string a, string b)
{
  auto aa = hash_map.find(a);
  auto bb = hash_map.find(b);

  return aa->second > bb->second;
}

bool cmp2(Music a, Music b)
{
  return a.plays > b.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
  vector<int> answer;
  vector<Music> music_list(genres.size());
  multimap<string, Music> mul_map;

  // Music 구조체 생성
  for (int i = 0; i < genres.size(); i++)
  {
    Music temp;
    temp.genre = genres[i];
    temp.plays = plays[i];
    temp.id = i;

    music_list[i] = temp;
  }

  // hash_map에 삽입
  for (int i = 0; i < music_list.size(); i++)
  {
    // 해시 맵 -> 장르별 플레이 수 확인
    if (hash_map.count(genres[i]))
    {
      auto temp = hash_map.find(genres[i]);
      temp->second = temp->second + plays[i];
    }
    else
    {
      hash_map.insert(make_pair(genres[i], plays[i]));
    }

    mul_map.insert(make_pair(genres[i], music_list[i]));
  }

  // 장르 이름을 벡터에 저장.
  for (auto i : hash_map)
  {
    genre_rank.push_back(i.first);
  }

  // 장르의 total play수를 기준으로 내림차순으로 정렬
  sort(genre_rank.begin(), genre_rank.end(), cmp);

  // 정렬한 장르를 하나씩 꺼내면서 상위 2개만 answer에 추가.
  for (auto i : genre_rank)
  {
    auto iter = mul_map.equal_range(i);
    vector<Music> temp;

    for (auto k = iter.first; k != iter.second; k++)
    {
      temp.push_back(k->second);
    }

    sort(temp.begin(), temp.end(), cmp2);

    answer.push_back(temp.at(0).id);

    if (temp.size() >= 2)
    {
      answer.push_back(temp.at(1).id);
    }
  }

  // 순서대로 mul_map 에 해당 장르를 키로 접근,,
  return answer;
}

int main()
{
  vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
  vector<int> plays = {500, 600, 150, 800, 2500};

  vector<int> answer = solution(genres, plays);

  for (auto i : answer)
  {
    cout << i;
  }
}