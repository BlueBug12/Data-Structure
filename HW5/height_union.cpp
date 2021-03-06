#include <iostream>
#include <string>
#include <vector>
using namespace std;
class set{
public:
  set(){
    s=new int[100];//max size=100
    }

  ~set(){
    delete [] s;
  }

  void push(const int node,const int parent){
    s[node]=parent;
  }

  int collapsingFind(const int i,int*record){
    int root;
    if(s[i]<0){
      return i;
    }
    else{
      ++(*record);//traverse previous edge
      root=collapsingFind(s[i],record);
    }
    if(s[i]!=root){
      s[i]=root;
      ++(*record);//link reset
    }
    return root;
  }

  void heightUnion(const int i,const int j){

    if(s[i]<s[j]){//j has less height
      s[j]=i;
    }
    else if(s[i]>s[j]){//i has less height
      s[i]=j;
    }
    else{//equal height
      s[j]=i;
      --s[i];
    }
  }

private:
  int* s;
};

int main(){
  int n,size,height,parent,node;
  set s;
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>size;
    for(int j=0;j<size;++j){
      cin>>node>>parent;
      s.push(node,parent);
    }
  }
  string command;
  vector<int>answer;
  while(cin>>command){
    if(command=="UNION"){
      int x,y;
      cin>>x>>y;
      s.heightUnion(x,y);
    }
    else if(command=="FIND"){
      int x;
      cin>>x;
      int* record;
      *record=0;
      s.collapsingFind(x,record);
      answer.push_back(*record);
    }
    else if(command=="STOP"){
      break;
    }
    else{
      cout<<"Wrong command!"<<endl;
    }
  }

  //print the answer
  cout<<endl;
  for(int i : answer){
    cout<<i<<endl;
  }
  return 0;
}
