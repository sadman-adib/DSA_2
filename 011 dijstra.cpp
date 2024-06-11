#include <bits/stdc++.h>

using namespace std;

struct compare{
      bool operator()(pair<int,pair<int, int> > const &a,   pair<int, pair<int, int> > const b)
      {
          return a.first > b.first;
      }
};

int main()
{
    int graph [100][100];
    int nv, ne, i, j, u, v, w;
    printf("enter vertex and edges: \n");
    cin >> nv >>ne;
    for( i=0; i<=nv; i++){
        for(j=0; j<=nv; j++)
            graph[i][j]=0;
    }
    printf("enter node1, node2, weight: \n");
    for(i=0; i<ne; i++){
        cin>> u >> v >> w;
        graph[u][v]= w;
        //graph[v][u]= w;
    }
    for(i=1; i<=nv; i++){
        for(j=1; j<=nv; j++)
            cout << graph[i][j]<< ' ';
        cout <<'\n';
    }

    int visited[nv+10];
    int parent[nv+10];
    int dis[nv+10];
    int source;

    //prims start
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, compare> queue_edges;
    for(j=0; j<=nv; j++){
        visited[j]=0;
        parent[j]= -1;
        dis[j]=99999999999999999999;
    }
    cout<< "enter source: \n";
    cin >> source;
    parent[source]=0;
    dis[source]=0;
    visited[source]=1;

    for(i=1; i<=nv; i++){
        if(graph[source][i]!=0)
            queue_edges.push(make_pair(graph[source][i], make_pair(source, i)));
    }

    while(!queue_edges.empty()){
        w=queue_edges.top().first;
        u=queue_edges.top().second.first;
        v=queue_edges.top().second.second;
        queue_edges.pop();
        if((visited[v]==0)&& (dis[v]> dis[u]+graph[u][v])){
            parent[v]=u;
            dis[v]= dis[u]+graph[u][v];

            for(i=1; i<=nv; i++){
                if(graph[v][i]!=0)
                    queue_edges.push(make_pair(graph[v][i], make_pair(v, i)));
            }
            visited[v]=1;
        }
    }

    for(int i=0; i<=nv; i++){
        if(parent[i]!=-1) cout<< i <<" " <<parent[i]<<endl;
    }

    cout<<"enter destination: \n"<< endl;
    int des;
    cin >> des;
    vector<int> path;
    while(des!= source){
        path.push_back(des);
        des= parent[des];
    }
     path.push_back(des);


     for(int i= path.size()-1; i>0; i--)
     cout<< path[i]<< "---->";
     cout<< path[0] << endl;

    return 0;
}
