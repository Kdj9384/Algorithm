#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>

using namespace std;

int Answer;

int find(int x, int par[])
{
  if (par[x] == x)
    return x;
  else
    return find(par[x], par);
}

void link(int x, int y, int par[])
{
  par[x] = y;
}

int main(int argc, char **argv)
{
  int T, test_case;

  freopen("sample_input.txt", "r", stdin);

  cin >> T; // T = 2

  for (test_case = 0; test_case < T; test_case++)
  {
    Answer = 0;
    ////////////////////////////////////////////////////////////////////////
    int n;
    cin >> n; // n = 5
    int par[n + 1];
    int D[n + 1];

    for (int i = 1; i <= n; i++)
    {
      int a;
      cin >> a;

      D[i] = a;
      par[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
      int fr = i + D[i];

      if (fr <= n)
        link(i, fr, par);
    }

    set<int> s;
    for (int i = 1; i <= n; i++)
    {
      s.insert(find(i, par));
    }

    Answer = s.size();

    ////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0; //Your program should return 0 on normal termination.
}
