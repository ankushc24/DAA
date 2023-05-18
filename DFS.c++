#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void DFS(int **edges, int v, int sv, int ev, bool *visited, unordered_map<int, int> hash, bool flag) {
  if (flag == 1) {
    return;
  }
  visited[sv] = true;
  

  for (int i = 0; i < v; i++) {
    if (edges[sv][i] == 1 && visited[i] == false) {
      if (flag == 1) {
        return;
      }

      hash[i] = sv;
      if (i == ev) {
        flag = 1;
        break;
      }
      DFS(edges, v, i, ev, visited, hash, flag);
    }
  }
}
int main() {
  // Write your code here
  int v, e;
  cin >> v >> e;
  int **edges = new int *[v];
  for (int i = 0; i < v; i++) {
    edges[i] = new int[v];
  }
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      edges[i][j] = 0;
    }
  }
  bool *visited = new bool[v];
  for (int i = 0; i < v; i++) {
    visited[i] = false;
  }
  unordered_map<int, int> hash;
  bool flag = 0;
  for (int j = 0; j < e; j++) {
    int a, b;
    cin >> a >> b;
    edges[a][b] = 1;
    edges[b][a] = 1;
  }
  int v1, v2;
  cin >> v1 >> v2;
  DFS(edges, v, v1, v2, visited, hash, flag);

  vector<int> ans;
  ans.push_back(v2);
  int current = v2;
  while (current != v1) {
    ans.push_back(current);
    current = hash[current];
  }
  int s = ans.size();
  for (int j = 0; j < s; j++) {
    cout << ans[j] << " ";
  }
  cout << "\n";
}