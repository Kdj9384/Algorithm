#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct
{
  int req_time;
  int need_time;
} Job;

struct cmp
{
  bool operator()(Job a, Job b)
  {
    if (a.req_time == b.req_time)
    {
      return a.need_time > b.need_time;
    }
    else
    {
      return a.req_time > b.req_time;
    }
  }
};

struct cmp2
{
  bool operator()(Job a, Job b)
  {
    return a.need_time > b.need_time;
  }
};

int solution(vector<vector<int>> jobs)
{
  int answer = 0;
  int curr_time = 0;

  priority_queue<Job, vector<Job>, cmp2> exe_que;
  priority_queue<Job, vector<Job>, cmp> wait_que;

  for (auto i : jobs)
  {
    Job temp;
    temp.req_time = i[0];
    temp.need_time = i[1];

    wait_que.push(temp);
  }

  while (!wait_que.empty() || !exe_que.empty())
  {
    // 실행큐가 비어있으면, jobs 중 가장 앞의 것을 pop
    if (exe_que.empty())
    {
      exe_que.push(wait_que.top());
      wait_que.pop();
    }

    // exe_que 중 실행시킬 작업을 선택.
    Job tmp = exe_que.top();
    exe_que.pop();

    // 작업을 실행 -> req_time ~ 작업 종료 시간 까지를 answer에 더함.
    if (tmp.req_time > curr_time)
    {
      curr_time = tmp.req_time;
    }
    curr_time += tmp.need_time;

    // 요청한 시점부터 작업이 종료된 현재 시점 사이의 시간을 더해줌.
    answer += curr_time - tmp.req_time;

    // 작업이 실행되는 동안, 요청된 작업을 exe_que애 삽입
    while (wait_que.top().req_time <= curr_time && !wait_que.empty())
    {
      exe_que.push(wait_que.top());
      wait_que.pop();
    }
  }

  return answer / jobs.size();
}

int main()
{
  vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};
  int a = solution(jobs);

  cout << a;
}