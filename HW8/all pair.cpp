#include <iostream>
#include <climits>
#include <vector>

using namespace std;
int **record;

bool out_ans(int head,int end,vector<int>&ans){
  //cout<<head<<' '<<end<<endl;
  int a=record[head][end];

  if(a!=-1){
    out_ans(head,a,ans);
    //cout<<a<<endl;
    ans.push_back(a);
    //cout<<a<<endl;
    out_ans(a,end,ans);
  }
  else{return 1;}
}

int main(){
  int nodes,edges;

  vector<vector<int>>total_ans;
  while(cin>>nodes>>edges){

    record=new int*[nodes];
    for(int i=0;i<nodes;++i){
      int* temp=new int[nodes];
      for(int j=0;j<nodes;++j){
        temp[j]=-1;
      }
      record[i]=temp;
    }
    int**distance=new int*[nodes];
    //initialize a empty distance
    for(int i=0;i<nodes;++i){
      int* temp=new int[nodes];
      for(int j=0;j<nodes;++j){
        temp[j]=INT_MAX;//initiali distance is infinite
      }
      distance[i]=temp;
    }

    int v1,v2,w;
    for(int i=0;i<edges;++i){
      cin>>v1>>v2>>w;
      distance[v1][v2]=w;

    }

    for(int k=0;k<nodes;++k){
      for(int i=0;i<nodes;++i){
        for(int j=0;j<nodes;++j){
          if(i==j||(distance[i][k]==INT_MAX||distance[k][j]==INT_MAX)){continue;}
          if(distance[i][k]+distance[k][j]<distance[i][j]){
            distance[i][j]=distance[i][k]+distance[k][j];

            //cout<<"distance "<<i<<"->"<<j<<"=distance "<<i<<"->"<<k<<'+'<<k<<"->"<<j<<endl;
            record[i][j]=k;
          }
        }
      }
    }
    cout<<endl;
    for(int i=0;i<nodes;++i){
      for(int j=0;j<nodes;++j){
        if(i==j){continue;}
        int a=record[i][j];
        vector<int>ans;
        ans.push_back(i);
        out_ans(i,j,ans);
        ans.push_back(j);
        ans.push_back(distance[i][j]);
        total_ans.push_back(ans);
      }
    }

  }

  for(int i=0;i<total_ans.size();++i){
    if(total_ans.at(i).size()==0){cout<<endl;continue;}
    if(total_ans.at(i).at(total_ans.at(i).size()-1)==INT_MAX){cout<<"Impossible"<<endl;continue;}
    for(int j=0;j<total_ans.at(i).size();++j){
      cout<<total_ans.at(i).at(j);
      if(j==total_ans.at(i).size()-1){cout<<endl;}
      else if(j==total_ans.at(i).size()-2){cout<<' ';}
      else{cout<<',';}
    }
    //cout<<endl;
  }
}
