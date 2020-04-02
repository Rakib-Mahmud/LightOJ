#include<bits/stdc++.h>
#define mx 50001
using namespace std;
long long res=-1;
string input[mx];
class Trie
{
public:
    //map<char,Trie*>children;
    Trie *children[4];
    bool endOfword;
    int prefix;
    Trie(){
        this->endOfword=false;
        this->prefix=0;
        for(int i=0;i<4;i++){
            this->children[i]=nullptr;
        }
    }
    void del();
    void Insert(string word);
};

void Trie ::del()
{
		for(int i = 0; i < 4; i++)
			if(children[i] != nullptr)
			{
				children[i]->del();
				delete children[i];
			}
}

void Trie ::Insert(string word)
{
    Trie *curr=this;
    int ln=word.size();
    for(int i=0;i<ln;i++){
        int ch;
        if(word[i]=='A')ch=0; if(word[i]=='C')ch=1; if(word[i]=='G')ch=2; if(word[i]=='T')ch=3;
        Trie *node=curr->children[ch];
        if(node==nullptr){
            node=new Trie();
            curr->children[ch]=node;
        }
        curr=node;
        (curr->prefix)++;
        if(res<(curr->prefix)*(i+1))res=(curr->prefix)*(i+1);
    }
    curr->endOfword=true;
}

int main()
{
   ios::sync_with_stdio(0);
   int t,n;
   cin>>t;
   for(int i=1;i<=t;i++){
    cin>>n;
    res=-1;
    for(int j=0;j<n;j++)cin>>input[j];
    Trie *root=new Trie();
    for(int j=0;j<n;j++){
        root->Insert(input[j]);
    }
    cout<<"Case "<<i<<": "<<res<<endl;
    root->del();
    delete root;
   }
   return 0;
}

