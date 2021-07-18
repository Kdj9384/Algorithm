#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

string Answer;
bool visited[4002];
vector<int> adj_arr[40001];
bool hasCycle;

void dfs(int start)
{
  if (visited[start])
  {
    // 사이클이다.
    hasCycle = 1;
    return;
  }

  visited[start] = 1;

  for (int i = 0; i < adj_arr[start].size(); i++)
  {
    dfs(adj_arr[start][i]);
  }
}

bool isCycle(int start)
{
  // 1. visited, hasCycle 초기화
  hasCycle = 0;
  memset(visited, 0, 1000 * sizeof(bool));
  dfs(start);

  if (hasCycle)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main(int argc, char **argv)
{
  int T, test_case;

  freopen("input.txt", "r", stdin);

  cin >> T;

  for (test_case = 0; test_case < T; test_case++)
  {

    // Answer = 0;
    Answer = "";
    /////////////////////////////////////////////////////////////////////////////////////////////
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;

    for (int i = 0; i < m; i++)
    {
      int first, second;
      cin >> first;
      cin >> second;
      adj_arr[first].push_back(second);
    }

    vector<pair<int, int>> non_link;
    for (int i = 0; i < k; i++)
    {
      int first, second;
      cin >> first;
      cin >> second;

      non_link.push_back(make_pair(first, second));
    }

    for (int i = 0; i < k; i++)
    {
      int first = non_link[i].first;
      int second = non_link[i].second;
      adj_arr[first].push_back(second);
    }

    isCycle(1);

    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}