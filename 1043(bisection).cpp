#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    double x,AE,DE,AB,AC,BC,EC,DB,k,h,rto,rto1,s,tri,trap,high,low;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%lf%lf%lf%lf",&AB,&AC,&BC,&rto);

        x=AB;
        high=AB; low=0.0;

        while((high-low)>0.0000001){
            x=(high+low)/2;
            AE=(AC*x)/AB;
            DE=(BC*x)/AB;
            EC=AC-AE;
            DB=AB-x;
            k=BC-DE;
            s=(DB+EC+k)/2;
            h=(2*sqrt(s*(s-DB)*(s-EC)*(s-k)))/k;
            s=(x+AE+DE)/2;
            tri=sqrt(s*(s-x)*(s-AE)*(s-DE));
            trap=((DE+BC)*h)/2;
            rto1=tri/trap;

            if(rto1>rto){
                high=x;
            }
            else{
                low=x;
            }
        }
       printf("Case %d: %.6lf\n",i,x);
    }
    return 0;
}
