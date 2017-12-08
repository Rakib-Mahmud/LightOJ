#include<bits/stdc++.h>
#define pi 3.141592653589793238462643383279
using namespace std;

int main()
{
    int t;
    double r1,r2,h,p,r3,volume;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);

        r3=r2+(r1-r2)*(p/h);
        volume=(p/3)*pi*(r3*r3+r3*r2+r2*r2);

        printf("Case %d: %.9lf\n",i,volume);
    }
    return 0;
}
