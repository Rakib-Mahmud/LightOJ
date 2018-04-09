#include<bits/stdc++.h>

using namespace std;

struct point{
    double x,y,z;
};

int main()
{
    //ifstream in; ofstream out;
    //in.open("input.txt");
    //out.open("out.txt");
    int tst;
    point A,B,P,m1,m2;
    double dis1,dis2,_dis1,_dis2;

    scanf("%d",&tst);
    //in>>tst;

    for(int i=1;i<=tst;i++){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&A.z,&B.x,&B.y,&B.z,&P.x,&P.y,&P.z);
        //in>>A.x>>A.y>>A.z>>B.x>>B.y>>B.z>>P.x>>P.y>>P.z;

        dis1=sqrt(pow((A.x-P.x),2)+pow((A.y-P.y),2)+pow((A.z-P.z),2));
        dis2=sqrt(pow((B.x-P.x),2)+pow((B.y-P.y),2)+pow((B.z-P.z),2));
        int c=100;
        while(c--){
            m1.x=((A.x*2)+B.x)/3;
            m1.y=((A.y*2)+B.y)/3;
            m1.z=((A.z*2)+B.z)/3;

            m2.x=(A.x+(B.x*2))/3;
            m2.y=(A.y+(B.y*2))/3;
            m2.z=(A.z+(B.z*2))/3;

            _dis1=sqrt(pow((m1.x-P.x),2)+pow((m1.y-P.y),2)+pow((m1.z-P.z),2));
            _dis2=sqrt(pow((m2.x-P.x),2)+pow((m2.y-P.y),2)+pow((m2.z-P.z),2));

            if(_dis1<_dis2){
                dis2=_dis2;
                B.x=m2.x; B.y=m2.y; B.z=m2.z;
            }

            else{
                dis1=_dis1;
                A.x=m1.x; A.y=m1.y; A.z=m1.z;
            }
        }
            printf("Case %d: %lf\n",i,(dis1+dis2)/2);

    }
    //in.close(); out.close();
    return 0;
}
