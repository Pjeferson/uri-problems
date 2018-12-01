#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int memo[21];
int graph[21][21];

int dfs(int v, string space) {
    int hasLine = 0;
    if(memo[v]) return 0;
    memo[v] = -1;
            
    for(int i = 0; i < 21; i++) {
        if(graph[v][i]){
            int neighbor = i;
            if(memo[neighbor] == 0){
                hasLine++;
                cout << space << v<<"-"<<neighbor<<" pathR(G,"<<neighbor<<")"<<endl;
                dfs(neighbor,space+"  ");
            } else {
                cout << space << v<<"-"<<neighbor<<endl;
            }
        }
    }
    return hasLine;
}

int main(int argc, char const *argv[]) {
    int n,v,e,v1,v2,w;
    cin >> n;
    for(int z = 1; z <= n; z++) {
        memset(memo, 0,sizeof memo);
        memset(graph, 0,sizeof graph);
        cin >> v >> e;
        for(int i = 0; i < e; i++) {
            cin >> v1 >> v2;
            graph[v1][v2] = 1;
        }
        cout << "Caso "<<z<<":" << endl;
        
        for (int i = 0; i <v; ++i) {
            if(dfs(i, "  ")) cout << endl;
        }
    }
    return 0;
}