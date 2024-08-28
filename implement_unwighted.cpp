#include<bits/stdc++.h>
using namespace std  ; 

int main (){
    int ver , ed ; 
    cin>> ver >> ed ; 
   
   vector<int>adjList[ver] ; 
       int v  ,  u  ; 

    for (int i = 0 ;  i<ed ;  i++){
            cin>> u , v ; 
            adjList[u].push_back(v) ;
            adjList[v].push_back(u) ;
    }


    //  for printing 

    for(int  i = 0  ;  i <ver ; i++) {
        cout << i << " ->" ;
        for(int  j = 0 ; j<adjList[i].size() ; j++ ){

            cout<< adjList[i][j] << " "; 
        }
        cout << endl ;
    }
}







