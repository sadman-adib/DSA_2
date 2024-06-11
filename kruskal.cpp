#include<bits/stdc++.h>

using namespace std;
int ne, nv;

int p[100];
int r[100];

   void MakeSet( ){
      for (int i=0; i<nv; i++){

       p[i]=i;
       r[i]=0;
  }
}

int findset(int x){
 if(x!= p[x]){

   p[x]=findset(p[x]);
 }
    return p[x];

}

   int Union (int a, int b){
       int x=findset(a);
       int y= findset(b);

       if(r[x]>r[y]){
           p[y]=x;
       }
       else{
            p[y]=x;
       }

    if(r[x]==r[y]){
        r[y]++;
    }
}

int main()
{
   vector<pair<int, pair<int, int> > > graph;
   int i, u, v, w;

   printf("enter number of vertices: \n");
   cin>> nv;
   printf("enter number of edges: \n");
   cin>> ne;

   printf("enter the graph: \n");

   for( i=0; i<ne; i++){

    cin >>u>>v>>w;
    graph.push_back(make_pair(w, make_pair(u,v)));

   }
   sort( graph.begin(), graph.end() );

   printf("sorted graph: \n");
   for(int i=0; i<ne; i++){
    cout<<"<"<< graph[i].second.first<<","<< graph[i].second.second<<">--->"<< graph[i].first<< '\n';
   }
   cout<<'\n';

   MakeSet( );

   printf("min spanning tree: \n");

   for(i=0; i<ne; i++){

    u= graph[i].second.first;
    v= graph[i].second.second;
    if( Union (u,v) != 0 )
        //cout<< "<" << u<< ","   << v<< ">--->" << << '\n';
        printf("<%d,%d>----->%d\n", u, v, graph[i].first);


   }

   return 0;
}
