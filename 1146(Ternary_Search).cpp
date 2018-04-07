#include<bits/stdc++.h>

using namespace std;

struct point{
    double x,y;
};

int main()
{
    int tst;
    point a,b,c,d,ma1,ma2,mb1,mb2,low1,low2,high1,high2;
    double dis1,dis2,dis_a,dis_b;

    scanf("%d",&tst);

    for(int i=1;i<=tst;i++){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        low1.x=a.x; low1.y=a.y;
        high1.x=b.x; high1.y=b.y;
        low2.x=c.x; low2.y=c.y;
        high2.x=d.x; high2.y=d.y;
        dis1=sqrt(pow((low1.x-low2.x),2)+pow((low1.y-low2.y),2));
        dis2=sqrt(pow((high1.x-high2.x),2)+pow((high1.y-high2.y),2));

        while(fabs(dis1-dis2)>0.0000001){
            ma1.x=((low1.x*2)+high1.x)/3; ma1.y=((low1.y*2)+high1.y)/3;
            ma2.x=(low1.x+(2*high1.x))/3; ma2.y=(low1.y+(2*high1.y))/3;
            mb1.x=((low2.x*2)+high2.x)/3; mb1.y=((low2.y*2)+high2.y)/3;
            mb2.x=(low2.x+(2*high2.x))/3; mb2.y=(low2.y+(2*high2.y))/3;

            dis_a=sqrt(pow((ma1.x-mb1.x),2)+pow((ma1.y-mb1.y),2));
            dis_b=sqrt(pow((ma2.x-mb2.x),2)+pow((ma2.y-mb2.y),2));

            if(dis_a<dis_b){
                dis2=dis_b;
                high1.x=ma2.x; high1.y=ma2.y;
                high2.x=mb2.x; high2.y=mb2.y;
            }

            if(dis_b<dis_a){
                dis1=dis_b;
                low1.x=ma1.x; low1.y=ma1.y;
                low2.x=mb1.x; low2.y=mb1.y;
            }


        }
        if(dis1>dis2){
            printf("Case %d: %lf\n",i,dis2);
        }
        else{
            printf("Case %d: %lf\n",i,dis1);
        }
    }
    return 0;
}
