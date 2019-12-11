#include <iostream>

using namespace std;

class max_heap{
public:
  max_heap(int size){
    heap = new int [size+1];
    heap[0]=0;//number of nodes
  }
  ~max_heap(){
    delete [] heap;
  }
  bool is_enpty(){
    if(heap[0]==0) return 1;
    else return 0;
  }
  void push(int n){
    int index=heap[0]+1;
    heap[index]=n;
    while(index!=1&&heap[index/2]<n){
      heap[index]=heap[index/2];
      index/=2;
    }
    heap[index]=n;
    ++heap[0];
  }
  int pop(){
    if(is_enpty()){
      cout<<"the max heap is empty!"<<endl;
      return -1;
    }
    int max=heap[1];
    int temp=heap[heap[0]];//last element in the heap
    int parent=1;
    int child=2;
    while(child<=heap[0]){
      if(child<heap[0]&&heap[child]<heap[child+1]){
        ++child;
      }
      if(temp>heap[child]){
        break;
      }
      heap[parent]=heap[child];
      parent=child;
      child*=2;
    }
    heap[parent]=temp;
    --heap[0];
    return max;
  }
private:
  int* heap;
};

int main(){
  int n;
  int rows;
  int fans;
  int* answer;
  cin>>n;
  answer=new int [n];
  for(int i=0;i<n;++i){
    cin>>rows>>fans;
    int seats;
    max_heap mh(rows);
    for(int j=0;j<rows;++j){
      cin>>seats;
      mh.push(seats);
    }

    int pounds=0;
    for(int j=0;j<fans;++j){
      int max = mh.pop();
      pounds+=max;
      if(max-1>0)
        mh.push(max-1);
    }
    answer[i]=pounds;
  }
  //print the answer
  for(int i=0;i<n;++i){
    cout<<answer[i]<<endl;
  }
  delete []answer;
  return 0;
}
