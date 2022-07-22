#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define ll long long
 
struct segment_tree {
 
    vector<ll>tree;
    ll m = 1;
 
    segment_tree(ll n){
        
        while(m < n)m *= 2;
        tree.resize(2*m-1);
    }
    
    void update(ll i,ll val,ll v,ll lx,ll rx){
        
        if(rx - lx  == 1){
            tree[v] += val;
            return;
        }
        
        ll mid = (lx+rx)/2;
        
        if(i < mid)update(i,val,v*2+1,lx,mid);
        else update(i,val,v*2+2,mid,rx);
        
        tree[v] = (tree[v*2+1]+tree[v*2+2]);                  // операция
        
    }
    
    void update(ll i,ll val){
        update(i,val,0,0,m);
    }
    
    
    ll op(ll l,ll r,ll v,ll lx,ll rx){
        
        if(l >= rx || lx >= r)return 0;                      // нейтральный эл.
        if(lx >= l && rx <= r)return tree[v];
        
        ll mid = (lx+rx)/2;
        
        return ( op(l,r,v*2+1,lx,mid)+op(l,r,v*2+2,mid,rx) );      // операция 
        
    }
    
    ll op(ll l,ll r){
        return op(l,r,0,0,m);
    }
    
    
    
};
 
int main() 
{
    ll n,x;
    cin >> n;
    
    vector<ll>v(n),t;
 
    for(ll i = 0;i<n;++i)cin >> v[i];
    
    t = v;
    
    sort(t.begin(),t.end());
    
    for(ll i = 0;i<n;++i)v[i] = lower_bound(t.begin(),t.end(),v[i])-t.begin();
    
    segment_tree tr(n);
    
    ll sum = 0;
    
    for(ll i = 0;i<n;++i){
    
        sum += tr.op(v[i]+1,n);
        
        tr.update(v[i],1);
        
    }
    
    cout << sum << "\n";
    
    
    
    return 0;
}
