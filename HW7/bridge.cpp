#include <iostream>
#include <vector>
using namespace std;
struct node{
  int n;
  node* next;
};
class graph{
public:
  graph(int n):size(n){
    g=new node*[size];
    dfn=new int[size];
    low=new int[size];
    for(int i=0;i<size;++i){
      node* head=new node;
      head->next=NULL;
      head->n=i;
      g[i]=head;
      dfn[i]=0;
      low[i]=0;
    }
  }

  ~graph(){
    for(int i=0;i<size;++i){
      node* temp=g[i];
      for(temp=g[i];temp->next!=NULL;){
        node* deleted_node=temp;
        temp=temp->next;
        delete deleted_node;
      }
      delete temp;
    }
    delete []g;
    delete []dfn;
    delete []low;
  }

  void new_edge(int i,int j){
    node* n1=new node;
    n1->n=i; n1->next=NULL;

    node* n2=new node;
    n2->n=j; n2->next=NULL;

    node* rear1;
    node* rear2;
    for(rear1=g[i];rear1->next!=NULL;rear1=rear1->next);
    for(rear2=g[j];rear2->next!=NULL;rear2=rear2->next);
    rear1->next=n2;
    rear2->next=n1;
  }
  void biconnected(){
    int* num;
    *num=1;
    biconnected(0,-1,num);
  }

  void biconnected(const int n,const int parent,int* num){
    node* temp=g[n];
    dfn[n]=*num;
    low[n]=*num;
    for(temp=g[n];temp;temp=temp->next){
      int w=temp->n;

      if(parent!=w&&dfn[w]<dfn[n]){
        if(!dfn[w]){
          ++(*num);
          biconnected(w,n,num);
          low[n]=min(low[n],low[w]);

          if(low[n]!=low[w]){
            pair<int,int>p;
            p.first=n;
            p.second=w;
            ans.push_back(p);
          }
        }
        else{
          //cross edge
          low[n]=min(dfn[n],dfn[w]);
        }
      }
    }
  }

  void result()const{
    for(int i=ans.size()-1;i>=0;--i){
      cout<<ans.at(i).first<<' '<<ans.at(i).second<<endl;
    }
  }

private:
  node** g;
  int* dfn;
  int* low;
  vector<pair<int,int>>ans;
  const int size;
};
int main(){
  int n,e;
  int n1,n2;
  cin>>n>>e;
  if(n<=1){return 0;}

  graph g(n);

  for(int i=0;i<e;++i){
    cin>>n1>>n2;
    g.new_edge(n1,n2);
  }
  cout<<endl;
  g.biconnected();
  g.result();
}
