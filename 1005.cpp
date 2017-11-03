#include<bits/stdc++.h>
using namespace std;

unsigned long long int fact(int n)
{
    return ((n==1 || n==0) ? 1 : fact(n-1)*n);
}

int main()
{
    int n,k,t;
    long long int ans;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&k);
        ans=1;
        if(k==1){
            printf("Case %d: %d\n",i,(n*n));
            continue;
        }

        if(k>n){
            printf("Case %d: %d\n",i,0);
            continue;
        }

        for(int l=n;l>n-k;l--){
            ans=ans*l;
        }
        ans=ans/fact(k);

        for(int j=n;j>(n-k);j--){
                ans=ans*j;
        }

        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
