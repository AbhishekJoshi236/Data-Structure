#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int node,vector<int> adj[],vector<bool> &vis,stack<int> &st)
{
    vis[node]=true;

    for(auto neighbour: adj[node])
    {
        if(!vis[neighbour])
            topologicalSort(neighbour,adj,vis,st);
    }
    st.push(node);
}

void dfs(int node,vector<int> trans[],vector<bool> &vis)
{
    cout<<node<<" ";
    vis[node]=true;

    for(auto neighbour: trans[node])
    {
        if(!vis[neighbour])
            dfs(neighbour,trans,vis);
    }
}
int main()
{
    int v;
    cout<<"Enter no of vertices: ";
    cin>>v;
    int e;
    cout<<"Enter no of edges: ";
    cin>> e;
    
    //adding edges
    vector<int> adj[v];
    cout<<"Enter edges: \n";
    for(int i=0;i<e;i++)
    {
        int u,ve;
        cin>>u>>ve;
        adj[u].push_back(ve);
    }

    //Topological Sorting
    vector<bool> vis(v+1,false);
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
            topologicalSort(i,adj,vis,st);
    }

    
    //transposing edges
    vector<int> trans[v];
    for(int i=0;i<v;i++)
    {
        vis[i]=false;
        for(auto x: adj[i])
            trans[x].push_back(i);
    }


    //calling dfs on stack
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(!vis[node])
        {
            dfs(node,trans,vis);
            cout<<endl;
        }

    }

    return 0;
}