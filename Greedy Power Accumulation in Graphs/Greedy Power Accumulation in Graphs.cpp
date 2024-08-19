//
//  main.cpp
//  secrethitler
//
//  Created by MacBook on 2/28/1402 AP.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <int> neighbour[1933];
bool flag[1933];
int power[1933];


int main()
{
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> power[i];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        neighbour[v].push_back(u);
        neighbour[u].push_back(v);
    }

    for (int v = 0; v < n; v++)
    {
        long long int curPower = power[v], powerUp = 0;

        for (int i = 0; i < n; i++)
            flag[i] = false;
        flag[v] = true;

        set <pair <int,int> > ns;
        for (int u : neighbour[v])
            if (!flag[u])
                ns.insert(make_pair(power[u], u));

        for (int i = 0; i < n - 1; i++)
        {
            int u = (*ns.begin()).second;
            ns.erase(ns.begin());

            flag[u] = true;
            for (int w : neighbour[u])
                if (!flag[w])
                    ns.insert(make_pair(power[w], w));

            if (power[u] < curPower + powerUp)
                curPower += power[u];
            else
            {
                powerUp += power[u] - (curPower + powerUp) + 1;
                curPower += power[u];
            }

        }

        cout << powerUp << " \n"[v == n - 1];
    }

    return 0;
}
