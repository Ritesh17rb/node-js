#include <bits/stdc++.h>
#define ll long long
using namespace std;

class DisjoinSet
{
    vector<int> rank, parent, size;

public:
    // Constructor to create an empty set of disjoint sets.
    DisjoinSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUlParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUlParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{

    DisjoinSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    // ds.unionByRank(3, 7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    ds.unionBySize(3, 7);

    if (ds.findUlParent(3) == ds.findUlParent(7))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}