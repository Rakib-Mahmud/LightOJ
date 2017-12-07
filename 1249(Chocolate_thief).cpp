#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,volume,length,width,height;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        string nam[n+1];
        char name[n+1][22];
        map<int,string>mp;
        vector<int>vec;

        for(int j=0;j<n;j++){
            getchar();
            scanf("%s%d%d%d",name[j],&length,&width,&height);
            nam[j]=name[j];
            volume=length*width*height;
            mp[volume]=nam[j];
            vec.push_back(volume);
        }
        sort(vec.begin(),vec.end());
        if(vec[0]<vec[n-1]){
            cout<<"Case "<<i<<": "<<mp[vec[n-1]]<<" took chocolate from "<<mp[vec[0]]<<"\n";
        }
        else{
            printf("Case %d: no thief\n",i);
        }
    }
    return 0;
}
