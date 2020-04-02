#include<bits/stdc++.h>
#define mx 10001
using namespace std;
int flag;
string input[mx];
class Trie
{
public:
    //map<char,Trie*>children;
    Trie *children[12];
    bool endOfword;

    Trie(){
        this->endOfword=false;
        for(int i=0;i<12;i++){
            this->children[i]=nullptr;
        }
    }
    void del();
    void Insert(string word);
};

void Trie ::del()
{
		for(int i = 0; i < 10; i++)
			if(children[i] != NULL)
			{
				children[i]->del();
				delete children[i];
			}
}

void Trie ::Insert(string word)
{
    Trie *curr=this;
    int ln=word.size(),con=0;
    for(int i=0;i<ln;i++){
        char ch=word[i]-48;
        Trie *node=curr->children[ch];
        if(node==nullptr){
            node=new Trie();
            curr->children[ch]=node;
            con++; //cout<<"con..."<<endl;
        }
        curr=node;
        if(curr->endOfword)flag=1;
    }
    if(con==0)flag=1;
    curr->endOfword=true;
}

int main()
{
   //ios::sync_with_stdio(0);
   int t,n;
   //cin>>t;
   scanf("%d",&t);
   for(int i=1;i<=t;i++){
    flag=0;
    //cin>>n;
    scanf("%d",&n);
    getchar();
    for(int j=0;j<n;j++)cin>>input[j];
    Trie *root=new Trie();
    for(int j=0;j<n;j++){
        root->Insert(input[j]);
        if(flag==1){
            //cout<<"Case "<<i<<": NO"<<endl;
            break;
        }
    }
    //if(flag==0)cout<<"Case "<<i<<": YES"<<endl;
    printf("Case %d: %s\n", i, (!flag ? "YES" : "NO"));
    root->del();
    delete root;
   }
   return 0;
}
