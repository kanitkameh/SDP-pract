#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[64];
bool used[64] = { 0 };

void create() {
  int m;
  cin >> m;

  for(int i = 0; i < m; i++) {
    int a ,b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  cout << "=========" << endl;
}

void dfs(int s) {
  used[s] = 1;
  cout << s << " ";
  for(int i=0; i < graph[s].size(); i++) {
    if(!used[graph[s][i]]) {
      dfs(graph[s][i]);
    }
  }
}

void bfs(int s) {
  queue<int> q;
  q.push(s);
  used[s] = 1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << " ";
    for(int i = 0; i < graph[curr].size(); i++) {
      if(!used[graph[curr][i]]) {
        used[graph[curr][i]] = 1;
        q.push(graph[curr][i]);
      }
    }
  }
}

int main() {
  create();
  // dfs(1);
  bfs(1);

  return 0;
}

/*
7
1 2
0 1
1 3
3 4
4 0
3 2
4 5
*/