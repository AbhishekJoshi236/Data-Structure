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

void  addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
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
        addEdge(adj,u,ve);
    }

    //Topological Sorting
    vector<bool> vis(v+1,false);
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
            topologicalSort(i,adj,vis,st);
    }

    //Printing stack
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}