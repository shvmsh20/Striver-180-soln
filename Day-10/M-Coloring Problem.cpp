//T/C:O(n^m), S/C:O(n)+O(n)
bool isSafe(bool graph[101][101], int color[], int c, int v, int V){
    for(int i=0; i<V; i++){
        if(i!=v && graph[i][v]==true && color[i]==c) return false;
    }
    return true;
}
bool solve(bool graph[101][101], int color[], int m, int V, int v){
    if(v==V){
        return true;
    }
    for(int c=1; c<=m; c++){
        if(isSafe(graph, color, c, v, V)){
            color[v] = c;
            if(solve(graph, color, m, V, v+1)==true) return true;
            color[v]= 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V];
    for(int i=0; i<V; i++){
        color[i]=0;
    }
    if(solve(graph, color, m, V, 0)) return true;
    return false;
}