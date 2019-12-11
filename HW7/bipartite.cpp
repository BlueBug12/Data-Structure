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
    for(int i=0;i<size;++i){
      node* head=new node;
      head->next=NULL;
      head->n=i;
      g[i]=head;
    }
    visited=new int[size];
    for(int i=0;i<size;++i){
      visited[i]=0;
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
    delete []visited;
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

  bool bipartite(){
    dfn(0,1);
    bool flag=0;
    for(int i=0;i<size;++i){
      if(!visited[i]){
        flag=1;
        dfn(i,2);//unvisted node,second dfn
        break;
      }
    }
    if(!flag){return 0;}
    for(int i=0;i<size;++i){
      if(!visited[i]) return 0;
    }
    return 1;
  }

  void dfn(const int v,const int round){
    visited[v]=round;
    node* temp=g[v];
    while(temp->next!=NULL){
      if(!visited[temp->next->n]){
        dfn(temp->next->n,round);
      }
      temp=temp->next;
    }
  }

  void answer()const{
    vector<int>g1;
    vector<int>g2;
    for(int i=0;i<size;++i){
      if(visited[i]==1){g1.push_back(i);}
      else{g2.push_back(i);}
    }

    for(int i : g1){cout<<i<<' ';}
    cout<<endl;

    for(int i : g2){cout<<i<<' ';}
    cout<<endl;
  }

private:
  node** g;
  int* visited;
  const int size;
};
int main(){
  int n,e;
  int n1,n2;
  cin>>n>>e;
  graph g(n);

  for(int i=0;i<e;++i){
    cin>>n1>>n2;
    g.new_edge(n1,n2);
  }
  cout<<endl;
  if(g.bipartite()){
    cout<<"true"<<endl;
    g.answer();
  }
  else{
    cout<<"false"<<endl;
  }
  return 0;
}
