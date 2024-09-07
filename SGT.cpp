#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " ---> " << x << endl;
#define ll long long
#define pb push_back
const ll mod = 1e9 + 7; 


struct node{
    ll sum;
    node(){
        sum = INT_MAX;
    }
};
node t[8*100000+5];
vector<ll> v; 
node merge(node a , node b){
    node ans;
    ans.sum = min(a.sum  , b.sum);
    return ans;
}
 
void build(ll id,ll l,ll r){
    // Time complexity is O(n)
    if(l == r){
        t[id].sum = v[l];
        return;
    }

    ll mid = (l + r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);

    t[id] = merge(t[2*id],t[2*id+1]);
}

void update(ll id,ll l,ll r,ll pos, ll val){
    // Time complexity O(logn)
    if(pos < l ||  pos > r){
        return ;
    }
    if(l == r){
        v[pos] = val;
        t[id].sum = v[pos];
        return;
    }

    ll mid = (l + r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);

    t[id] = merge(t[2*id],t[2*id+1]);
}

node query(ll id,ll l ,ll r,ll lq,ll rq){ // Give some from lq to rq
     // Time complexity O(logn)
    if(lq > r || rq < l){
        return node();
    }

   // lq.......l.......r......rq
    if(lq <= l && r <= rq){
        return t[id];
    }
     ll mid = (l + r)/2;
    return  merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}



int main() {
     
      ll n,q; cin >> n >> q;
      v.resize(n);
      for(int i=0;i<n;i++){
         cin >> v[i];
      }
      build(1,0,n-1);

      while(q--){
        ll type ; cin >> type;
        if(type == 1){
           ll k,u; cin >> k >> u;
           k--;
           update(1,0,n-1,k,u);
        } else{ 
             ll lq,rq; cin >> lq >> rq;
             lq--;
             rq--;
             cout << query(1,0,n-1,lq,rq).sum << " ";
        }
          
      }
      cout << endl;
        
      
 
}
