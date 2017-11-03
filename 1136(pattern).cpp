#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,a,b;
    int c=0;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&a,&b);
        c=0;

        c=((b*2)/3)-((a*2)/3);
        c++;
        if((b%3)==2){
            c++;
        }
        if((a%3)==2){
            c--;
        }
        if(a%3==1){
            c--;
        }
        printf("Case %d: %d\n",i,c);
    }
    return 0;
}
