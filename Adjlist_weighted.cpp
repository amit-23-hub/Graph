#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int ver , ed   ;
  cin>>ver>>ed  ;
    vector<pair<int , int> >adjList[ver] ; 

    int u , v , w ; 

    for(int i = 0 ; i < ed ; i++){

        cin>> u >> v >> w ; 

        adjList[u].push_back(make_pair(v , w)) ; 
        adjList[v].push_back(make_pair(u , w)) ;
    }

    //  printing 

    for(int  i = 0 ; i<ver ; i++ ){
        cout<<i<<"->" ;

        for(int j = 0 ; j<adjList[i].size() ; j++){
            cout<<adjList[i][j].first<<"," << adjList[i][j].second << " ";
        }
        cout<<endl ;
    }
    return 0;
}