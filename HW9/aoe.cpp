#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <iomanip>
using namespace std;
struct node{
  int data;
  int number;
  node* next;
};

struct head{
  int ee;
  int le;
  int count;
  node* link;
  node* tail;
  vector<int>pre;//record the coming edges
  vector<int>edges_number;
};
void answer(head* graph,int n,int*ea,int*la,int a){
  cout<<left<<setw(8)<<"event"<<setw(8)<<"ee"<<"le"<<endl;
  for(int i=0;i<n;++i){
    cout<<left<<setw(8)<<i<<setw(8)<<graph[i].ee<<setw(8)<<graph[i].le<<endl;
  }
  cout<<endl;
  vector<int>critical;
  cout<<left<<setw(8)<<"act."<<setw(8)<<"e"<<left<<setw(8)<<"l"<<setw(8)<<"slack"<<setw(8)<<"critical"<<endl;
  for(int i=0;i<a;++i){
    cout<<left<<setw(8)<<i+1<<setw(8)<<ea[i]<<setw(8)<<la[i]<<setw(8)<<la[i]-ea[i]<<setw(8);
    if((la[i]-ea[i])==0){cout<<"Yes";critical.push_back(i+1);}
    else{cout<<"No";}
    cout<<endl;
  }
  cout<<endl;
  for(int i=0;i<critical.size();++i){
    cout<<critical.at(i)<<' ';
  }
  cout<<endl;
}
void forward_traverse(head* graph,int n,int* weight){
  int j,k,top;
  node* ptr;
  top=-1;
  for(int i=0;i<n;++i){
    if(!graph[i].count){
      //sort stack
      graph[i].count=top;
      top=i;
    }
  }
  for(int i=0;i<n;++i){
    if(top==-1){
      cout<<"Network has a cycle!"<<endl;
      exit(1);
    }
    else{
      j=top;
      top=graph[top].count;

      for(ptr=graph[j].link;ptr!=NULL;ptr=ptr->next){
        k=ptr->data;
        --graph[k].count;
        //update ee value
        if(graph[k].ee<graph[j].ee+weight[ptr->number]){graph[k].ee=graph[j].ee+weight[ptr->number];}
        if(!graph[k].count){
          graph[k].count=top;
          top=k;
        }
      }
    }
  }
}

void backward_traverse(head* graph,int n,int* ea,int* la,int* weight){
  graph[n-1].le=graph[n-1].ee;
  //traverse by BFS
  queue<int>q;
  int index,pre_vertex,pre_edge,temp_le;
  for(int i=0;i<graph[n-1].pre.size();++i){
    pre_vertex=graph[n-1].pre.at(i);
    pre_edge=graph[n-1].edges_number.at(i);
    q.push(pre_vertex);
    temp_le=graph[n-1].le-weight[pre_edge];
    //update le value
    if(graph[pre_vertex].le>temp_le){
      graph[pre_vertex].le=temp_le;
    }

    //update ea value
    ea[pre_edge]=graph[pre_vertex].ee;
    //update la value
    la[pre_edge]=temp_le;
  }


  while(!q.empty()){
     index=q.front();
     q.pop();
     for(int i=0;i<graph[index].pre.size();++i){
       pre_vertex=graph[index].pre.at(i);
       pre_edge=graph[index].edges_number.at(i);
       q.push(pre_vertex);

       temp_le=graph[index].le-weight[pre_edge];
       //update le value
       if(graph[pre_vertex].le>temp_le){
         graph[pre_vertex].le=temp_le;
       }
       //update ea value
       ea[pre_edge]=graph[pre_vertex].ee;
       //update la value
       la[pre_edge]=temp_le;
     }

  }
}
int main(){
  int activities;
  cin>>activities;
  //because we don't know the number of events, just choose the max possible amount
  head* graph=new head[activities+1];
  int* ea=new int[activities];
  int* la=new int[activities];
  int* weight=new int[activities];
  //initialize graph
  for(int i=0;i<activities+1;++i){
    graph[i].ee=0;
    graph[i].le=INT_MAX;
    graph[i].count=0;
    graph[i].link=NULL;
    graph[i].tail=NULL;
  }

  int edge_number,start,end,w;
  int n=0;
  for(int i=1;i<=activities;++i){
    cin>>edge_number>>start>>end>>w;

    ++graph[end].count;
    node* ptr=new node;
    ptr->data=end;
    ptr->next=NULL;
    ptr->number=edge_number-1;
    if(graph[start].tail!=NULL){
      graph[start].tail->next=ptr;
      graph[start].tail=ptr;
    }
    else{
      graph[start].link=ptr;
      graph[start].tail=ptr;
    }
    if(n<end+1){n=end+1;}
    graph[end].pre.push_back(start);
    graph[end].edges_number.push_back(edge_number-1);
    weight[edge_number-1]=w;
  }
  cout<<endl;
  forward_traverse(graph,n,weight);
  backward_traverse(graph,n,ea,la,weight);
  answer(graph,n,ea,la,activities);
}
