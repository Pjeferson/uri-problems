#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int MAX_INT = 500*1000;
int memo[21];
int graph[502][502];
int v;

int dijkstra(int start, int end) {
    int path[v+1];
    int openset[v+1];
    memset(path,MAX_INT,sizeof path);
    memset(openset,0,sizeof openset);
    path[start] = 0;
    openset[start] = 1;

    
    for(int i = 1; i < v; i++) { //max possibilities
        if(openset[end]==-1) break; // reaching the end
        int minv = -1;
        int minw = MAX_INT;
        for(int j = 1; j <= v; j++) {//finding the vertex less heavy
            if(openset[j] == 1 && path[j]<= minw){
                minw = path[j];
                minv = j;
            }
        }
        if(minv == -1) break; //openset is empty
        openset[minv] = -1;
        for(int j = 1; j <= v; j++) {
            if(openset[j] != -1 && graph[minv][j] < MAX_INT){//finding neighbors
                int tempPath = path[minv]+graph[minv][j];
                if(openset[j] == 1){
                    if (tempPath < path[j]) {
                        path[j] = tempPath;
                    } 
                } else {
                    path[j] = tempPath;
                    openset[j] = 1;
                }
            }
        }
    }
    return path[end];
}

int main(int argc, char const *argv[]) {
    int e,v1,v2,w;
    while(cin >> v >> e, v+e){
        memset(graph,MAX_INT,sizeof graph);
        
        while(e--){
            cin >> v1>>v2>>w;
            graph[v1][v2] = w;
            if(graph[v2][v1] < MAX_INT) {
                graph[v1][v2] = 0;
                graph[v2][v1] = 0;
            }
        }
        cin>>e; // Reusing 'e' to store Queries count
        while(e--){
            cin >> v1>>v2;
            w =dijkstra(v1,v2); // Reusing 'w' to store the function result
            if(w < MAX_INT) cout << w;
            else cout << "Nao e possivel entregar a carta";
            cout<<endl;
        }

        cout <<endl;
    }
    return 0;
}