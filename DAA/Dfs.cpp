#include<bits/stdc++.h>
using namespace std;

//IMPLEMENTATION OF DFS(RECURSIVE)

void dfs(int node, vector<int> adj[],vector<bool> &vis)
{
    vis[node]=true;
    cout<<node<<" ";

    for(auto neighbour: adj[node])
    {
        if(!vis[neighbour])
            dfs(neighbour,adj,vis);
    }
}

int main()
{
    int v;
    cout<<"Enter no of vertices: ";
    cin>>v;

    int e;
    cout<<"Enter no of edges: ";
    cin>>e;

    vector<int> adj[v];
    for(int i=0;i<e;i++)
    {
        int u,ve;
        cin>>u>>ve;

        adj[u].push_back(ve);
        adj[ve].push_back(u);
    }

    vector<bool> vis(v);
    for(int i=0;i<vis.size();i++)
        cout<<" "<<vis[i];

    for(int i=0;i<v;i++)    //for connected components
    {
        if(!vis[i])
            dfs(i,adj,vis);
    }

    return 0;
}