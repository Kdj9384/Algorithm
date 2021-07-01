#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
  vector<int> answer;
  int length = prices.size();

  for (int i = 0; i < length; i++)
  {
    int j = i + 1;
    for (; j < length; j++)
    {
      if (prices[j] < prices[i])
      {
        answer.push_back(j - i);
        break;
      }
    }

    // 끝까지 가격이 떨어지지 않은 경우.
    if (j == length)
    {
      answer.push_back(length - i - 1);
    }
  }
  return answer;
}

int main()
{
  vector<int> prices = {1, 2, 3, 2, 3};

  vector<int> a = solution(prices);
}