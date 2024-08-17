#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int edge  ,  vertex  ;
    cin >> edge >> vertex;
    vector<vector<bool> >adjMat(vertex, vector<bool>(vertex , 0))  ;

    // initialing edge coordinate 
    int u ,  v  ;
    for(int i = 0 ; i<vertex ; i++){
        cin>> u>>v ; 
        adjMat[u][v] = 1 ;   //  in the case of undirected we can go u->v and v->u 
        adjMat[v][u] = 1 ;
    }

    // printing 
    for(int i = 0 ; i<vertex ; i++){
        for(int j = 0 ; j<vertex ; j++){
            cout<<adjMat[i][j]<<" ";
           
        }
         cout<<endl ; 
    }
    return 0;
}