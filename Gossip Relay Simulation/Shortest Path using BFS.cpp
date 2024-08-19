#include<iostream>
#include<queue>



using namespace std;

const int maxN = 1e5 + 10, oo = 1e9;



void BFS(int n, int r, int distance[], queue<int> queue, vector<int> adj[])
{
    for (int i = 1; i <= n; i++)
        distance[i] = oo;
    distance[r] = 0;
    queue.push(r);
    while(queue.size())
    {
        int v = queue.front();
        queue.pop();
        for (auto u : adj[v])
            if(distance[u] > distance[v] + 1)
            {
                distance[u] = distance[v] + 1;
                queue.push(u);
                
            }
    }
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector <int> adj[n + 1];
        int distance[maxN];
        queue<int> q;
        int u, v;
        for (int i=0; i<m; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            
        }
        BFS(n, t, distance, q, adj);
        if(distance[s] == 1000000000)
            cout << -1 << endl;
        else
            cout << distance[s] << endl;
    
    }
    return 0;

}
