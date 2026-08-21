#include <bits/stdc++.h>
using namespace std;

void printPath(int u, int v, const vector<vector<int>>& nexthop, const vector<vector<int>>& dist) {
    if (dist[u][v] == -1) {
        cout << "No path";
        return;
    }
    
    cout << u;
    int curr = u;
    while (curr != v) {
        curr = nexthop[curr][v];
        cout << " -> " << curr;
    }
}

void solve(){
    int n = 4;
    vector<vector<int>> cost(n, vector<int>(n, 0));
    vector<vector<int>> dist(n, vector<int>(n, 0));
    vector<vector<int>> nexthop(n, vector<int>(n, 0));

    cout << "Enter the cost matrix (use -1 for infinity/no direct link):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }

    cout << "\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = cost[i][j];
            if(i == j){
                nexthop[i][j] = i;
            }
            else if(cost[i][j] != -1){
                nexthop[i][j] = j;
            }
            else{
                nexthop[i][j] = -1;
            }
        }
    }

    int updated = 1;
    while(updated != 0){
        updated = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(dist[i][k] != -1 && dist[k][j] != -1){
                        if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]){
                            dist[i][j] = dist[i][k] + dist[k][j];
                            nexthop[i][j] = nexthop[i][k];
                            updated = 1;
                        }
                    }
                }
            }
        }
    }

    cout << "--- Final Distance Table ---\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";

    cout << "--- Final Next-Hop Table ---\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << nexthop[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";

    cout << "--- Routing Paths Between All Routers ---\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "Path from " << i << " to " << j << " (Cost: " << dist[i][j] << "): ";
            printPath(i, j, nexthop, dist);
            cout << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}