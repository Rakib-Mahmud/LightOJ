#include<bits/stdc++.h>
#define mx 100005
using namespace std;

int input[mx],tree[3*mx],flag=0,Value=0;

void make_tree(int node,int i,int j)
{
    if(i==j){
        tree[node]=input[i];
        return;
    }

    int left=2*node+1;
    int right=2*node+2;
    int mid=(i+j)/2;

    make_tree(left,i,mid);
    make_tree(right,mid+1,j);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j){
        return tree[node];
    }

    else if(b>j || e<i){
        return 0;
    }

    else {
        int left=2*node+1;
        int right=2*node+2;
        int mid=(b+e)/2;

        return query(left,b,mid,i,j)+query(right,mid+1,e,i,j);
    }

}

void update(int node,int b,int e,int i,int nwvalue)
{
    if(b>i || e<i){
        return;
    }

    else if(b>=i && e<=i){
        if(flag==1){ Value=tree[node]; tree[node]=0; flag=0; }
        else{ tree[node]=tree[node]+nwvalue; }
    }

    else {
        int left=2*node+1;
        int right=2*node+2;
        int mid=(b+e)/2;

        update(left,b,mid,i,nwvalue);
        update(right,mid+1,e,i,nwvalue);
        tree[node]=tree[left]+tree[right];
    }

}

int main()
{
    int n,q,t,a,b,c;
    scanf("%d",&t);
    for(int l=1;l<=t;l++){
       scanf("%d%d",&n,&q);

    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
    }

    make_tree(0,0,n-1);
    printf("Case %d:\n",l);
    for(int j=0;j<q;j++){
    scanf("%d",&a);
    if(a==1){
        scanf("%d",&b);
        flag=1;
        update(0,0,n-1,b,0);
    }

    else if(a==2){
        scanf("%d%d",&b,&c);
        update(0,0,n-1,b,c);
    }

    else{
        scanf("%d%d",&b,&c);
        Value=query(0,0,n-1,b,c);
    }
    if(a!=2){
    printf("%d\n",Value);
      }

    }
  }
    return 0;
}

