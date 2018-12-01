# Adjacent list iteration

```
// Printing all neighbors

vector< vector< pair<int,int> > > graph(SIZE);

for (int i = 0; i < graph.size(); ++i) {
    cout << "Vertex"<<i;
    
    vector< pair<int, int> >::iterator itr = graph[i].begin();
    
    while (itr != graph[i].end()) {
        cout <<" -> Vertex"<<(*itr).first;
        ++itr;
    }
    cout << endl;
}
```

# Adjacent matrix iteration

```
// Printing all neighbors

for(int i = 0; i < SIZE; i++) { //use all vertices
    if(graph[v][i]){
        cout << v << "-"<<i<<endl;
    }
}
```

# DFS in adjacent matrix
```
void dfs(int v) {
    memo[v] = 1;
            
    for(int i = 0; i < 21; i++) {
        if(graph[v][i]){
            int neighbor = i;
            if(memo[neighbor] == 0){ // non-visited
                cout << v<<"-"<<neighbor<<endl;
                dfs(neighbor);
            } else { //visited
                
            }
        }
    }
}
```

# Dijkstra in adjacent matrix
```
int dijkstra(int start, int end) {
    int path[v+1], openset[v+1];
    memset(path,MAX_INT,sizeof path);
    memset(openset,0,sizeof openset);
    path[start] = 0; openset[start] = 1;

    for(int i = 1; i < v; i++) {//max possibilities
        if(openset[end]==-1) break; // reaching the end
        int minv = -1;
        int minw = MAX_INT;
        for(int j = 1; j <= v; j++) { //finding the vertex less heavy
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
```