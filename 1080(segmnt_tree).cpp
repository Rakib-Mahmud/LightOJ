#include<bits/stdc++.h>
#define mx 100005
using namespace std;

int tree[mx*3];

char input[mx];

void make_tree(int node,int i,int j)
{
    if(i==j){
        tree[node]=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(i+j)/2;
    make_tree(left,i,mid);
    make_tree(right,mid+1,j);

    tree[node]=tree[left]+tree[right];
    return;
}

void update(int node,int b,int e,int i,int j)
{
    if(b>j || e<i){
        return;
    }

    if(b>=i && e<=j){
        tree[node]+=1;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    return;
}

int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(b>j || e<i){
        return 0;
    }

    if(b>=i && e<=j){
        return (tree[node]+carry);
    }

    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int ob1=query(left,b,mid,i,j,tree[node]+carry);
    int ob2=query(right,mid+1,e,i,j,tree[node]+carry);
    return ob1+ob2;
}

int main()
{
    int n,q,u,a,b,res,t;
    char ch;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%s",input);
        printf("Case %d:\n",i);
        n=strlen(input);
        make_tree(1,1,n);
        scanf("%d",&q);

        for(int j=0;j<q;j++){
            getchar();
            scanf("%c",&ch);
            if(ch=='I'){
                scanf("%d%d",&a,&b);
                update(1,1,n,a,b);
            }
            else{
                scanf("%d",&a);
                res=query(1,1,n,a,a);
                if(res%2==0){
                    printf("%d\n",(input[a-1]=='0' ? 0 : 1));
                }
                else{
                    printf("%d\n",(input[a-1]=='0' ? 1 : 0));
                }
            }
        }
   }
    return 0;
}
