#include<bits/stdc++.h>
using namespace std;

//Detecting cycle in undirected graph using DFS.

bool detectCycle(int node, int parent, vector<int> adj[], vector<bool> &vis)
{
    vis[node]=true;

    for(auto neighbour: adj[node])
    {
        if(!vis[neighbour])
        {
            bool cycle = detectCycle(neighbour,node,adj,vis);
            if(cycle)
                return true;
        }
        else if(parent != neighbour)
            return true;
    }
    return false;
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

    for(int i=0;i<v;i++)    //for connected components
    {
        if(!vis[i])
        {
           bool cycle = detectCycle(i,-1,adj,vis);
           if(cycle)
           {
                cout<<"Cycle Present.";
                exit(0);
           }
        }   
    }
    cout<<"Cycle not present.";

    return 0;
}
