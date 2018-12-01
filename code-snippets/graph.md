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