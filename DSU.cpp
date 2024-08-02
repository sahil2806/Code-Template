#include<bits/stdc++.h>
using namespace std;

class DSU {
    private:
    static const int N = 1e5 + 7;
    int parent[N];
    int size[N];

    public:
    DSU() {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    // This function help in to make node
    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    // This function the find the parent of the node
    int find(int v) {
        if (v == parent[v]) return v;
        // Path Compression 
        return parent[v] = find(parent[v]);
    }
    // This function combined the two things
    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            // Union By Size
            if (size[u] < size[v]) std::swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
    // Time Complexity = O(alpha(n))  amortised time complexity 
};

int main(){
    
     DSU obj;
     int n,k; cin >> n >> k;
      
     while(k--){
        int u,v; cin >> u >> v;
        obj.Union(u,v);
     }
     int component = 0;

    // we are finding no of connected components
     for(int i=1;i<=n;i++){
        if(obj.find(i) == i){
            component++;
        }
     }
     cout << component << endl;
     
}