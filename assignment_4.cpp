#include <iostream>
using namespace std;

int main() {
  int n = 4;
  int cost[10][10], dist[10][10], hop[10][10];

  cout << "Enter the cost matrix (use -1 for infinity/no direct link):\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cost[i][j];
      dist[i][j] = (cost[i][j] == -1 && i != j) ? 999 : cost[i][j];
      hop[i][j] = (cost[i][j] != -1) ? j : -1;
    }
  }

  // Distance Vector Update
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          hop[i][j] = hop[i][k];
        }

  cout << "\n--- Final Distance Table ---\n";
  for (int i = 0; i < n; i++, cout << "\n")
    for (int j = 0; j < n; j++)
      cout << dist[i][j] << "\t";

  cout << "\n--- Final Next-Hop Table ---\n";
  for (int i = 0; i < n; i++, cout << "\n")
    for (int j = 0; j < n; j++)
      cout << hop[i][j] << "\t";

  cout << "\n--- Routing Paths Between All Routers ---\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "Path from " << i << " to " << j << " (Cost: " << dist[i][j]
           << "): ";
      if (dist[i][j] >= 999) {
        cout << "No path\n";
      } else {
        cout << i;
        for (int curr = i; curr != j; curr = hop[curr][j])
          cout << " -> " << hop[curr][j];
        cout << "\n";
      }
    }
  }

  return 0;
}