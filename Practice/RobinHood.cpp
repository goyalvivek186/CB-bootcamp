#include"bits/stdc++.h"
#define ll long long
#define ms(x,a) memset(x,a,sizeof(x))
#define inf 0x3f3f3f3f
#define db double
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn],n,k;

bool ck1(int x){
    ll sm = 0;
    for(int i = 1;i <= n; ++i){
        if(a[i] >= x)break;
        sm += x - a[i]; 
    }
    if(sm > k)return false;
    return true; 
}

bool ck2(int x){
    ll sm = 0;
    for(int i = n;i >= 1; --i){
        if(a[i] <= x)break;
        sm += a[i] - x; 
    }
    if(sm > k)return false;
    return true; 
}

int main() {
    scanf("%d%d",&n,&k);
    ll sm = 0;
    for(int i = 1;i <= n; ++i){
        scanf("%d",&a[i]);
        sm += a[i];
    }
    sort(a + 1,a + 1 + n); 
    int L,R;
    if(sm % n){
        L = sm / n;
        R = sm / n + 1;
    }
    else {
        L = R = sm / n;
    }
    int l,r,amn,amx;
    l = a[1],r = L;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(ck1(mid)){
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    amn = l;
    l = R,r = a[n];
    while(l < r){
        int mid = (l + r) >> 1;
        if(ck2(mid)){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    amx = l;
//  cout<<amn<<" "<<amx<<endl;
    printf("%d\n",amx - amn);
    return 0;
}



                                                        