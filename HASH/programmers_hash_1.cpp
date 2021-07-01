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

int main(void)
{
  cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"});
}