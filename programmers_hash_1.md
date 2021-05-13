# 프로그래머스\_해시\_완주하지\_못한\_선수

Level 1

#### 문제설명

> 수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다. <br>
> 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

#### 제한사항

> 1. 마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
> 2. completion의 길이는 participant의 길이보다 1 작습니다.
> 3. 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
> 4. 참가자 중에는 동명이인이 있을 수 있습니다.

#### 문제 풀이

> 해시를 사용하여 해결해 보자.

https://gamdekong.tistory.com/73
https://woo-dev.tistory.com/106 참고

- 기본적으로 Key 와 Value 가 짝을 이뤄서 저장함. 따라서 자료를 넣거나 뺄때 그 Key 값이 필요하다.

- map, set, 등을 사용할 때 : 정렬된 상태롤 저장하고 싶을때
  hash_map, hash_set 등을 사용할 때 : 정렬되지 않고, 빠른 검색을 원할 때

- multi_map, multi_set, hash_multimap, hash_multiset 등은 중복을 허용하여 사용하고 싶을때 사용한다.

- map => Key & Value
  set => Key 만 존재 -> Key의 존재 유무만 확인하고 싶을 때 사용 (목적에 비해 map은 공간을 많이 차지함.)

- key 값은 정수 말고 string등 도 가능 -> 탐색(검색)이 오래걸림,,, -> key값을 어떤 값이 간에 해시함수를 통해 정수로 변경하고, 해당 정수를 인덱스로 가지는 bucket에 저장한다. -> key값이 정수이기 때문에 O(1) 의 복잡도로 Value에 접근가능하다.

```c++
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
  string answer = "";
  unordered_map<string, int> *participant_hash = new unordered_map<string, int>();

  // 비어있는 hash_map에 추가
  for (auto i : participant)
  {
    // 있는 경우, value + 1
    if (participant_hash->count(i))
    {
      participant_hash->find(i)->second = participant_hash->find(i)->second + 1;
    }
    // 없는 경우 insert
    else
    {
      participant_hash->insert(make_pair(i, 1));
    }
  }

  // 있는 경우, Value -1 , 0이면, erase.
  for (auto i : completion)
  {

    participant_hash->find(i)->second = participant_hash->find(i)->second - 1;
    if (participant_hash->find(i)->second == 0)
    {
      participant_hash->erase(i);
    }
  }

  // 남아있는 pair를 answer에 추가.
  for (auto i = participant_hash->begin(); i != participant_hash->end(); i++)
  {
    answer.append(i->first);
  }
  return answer;
}
```

### 알고리즘

1. `hash_map<string, int>` 를 하나 만든다.
2. 참가자 이름을 hash_map에 넣어주는데,
3. 이미 key에 해당하는 값이 있는 경우, value++.
4. key에 해당하는 값이 없는 경우, insert해준다.
5. 완주자 이름을 하나씩 hash_map에 넣고, value--.
6. value가 0인 pair는 삭제한다.
7. 남은 pair들의 first를 answer에 추가한다.
