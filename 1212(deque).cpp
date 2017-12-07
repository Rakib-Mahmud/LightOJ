#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,t,siz,input;
    char command[10];
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        siz=0;
        deque<int>deq;
        getchar();
        printf("Case %d:\n",i);
        for(int j=0;j<m;j++){
        scanf("%s",command);

        if(strcmp(command,"pushLeft")==0 || strcmp(command,"pushRight")==0){
            scanf("%d",&input);
            if(siz<n){
               if(strcmp(command,"pushLeft")==0){
                  deq.push_front(input);
                  siz++;
                  printf("Pushed in left: %d\n",input);
               }
               else{
                   deq.push_back(input);
                   siz++;
                   printf("Pushed in right: %d\n",input);
               }
            }

            else{
                printf("The queue is full\n");
              }

            }
            else{
                if(siz>0){
                    if(strcmp(command,"popLeft")==0){
                        input=deq.front();
                        deq.pop_front();
                        siz--;
                        printf("Popped from left: %d\n",input);
                    }
                    else{
                        input=deq.back();
                        deq.pop_back();
                        siz--;
                        printf("Popped from right: %d\n",input);
                    }
                }

                else{
                    printf("The queue is empty\n");
                }
            }
        }
    }
    return 0;
}
