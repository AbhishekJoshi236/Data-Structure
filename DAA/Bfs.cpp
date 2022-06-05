#include<bits/stdc++.h>
using namespace std;

//BFS MPLMENTATION FOR BOTH (DIRECTED AND UNDIRECTED)

void bfs (int node,vector<int> adj[],vector<bool> &vis, queue<int> &q)
{
    vis[node] =true;
    q.push(node);

    while(!q.empty())
    {
        int front = q.front();
        cout<<front<<" ";
        q.pop();
        for(auto neighbour: adj[front] )
        {
            if(!vis[neighbour])
            {
                vis[neighbour]= true;
                q.push(neighbour);
            }
        }
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

    vector<int> adj[v+1];
    for(int i=0;i<e;i++)
    {
        int u,ve;
        cin>>u>>ve;

        adj[u].push_back(ve);
        adj[ve].push_back(u);
    }

    vector<bool> vis(v+1);
    queue<int> q;
    for(int i=0;i<v;i++)
    {
         if(!vis[i])
            bfs(1,adj,vis,q);
    }
    return 0;
}
