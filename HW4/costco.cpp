#include <iostream>
#include <string>
using namespace std;

struct customer{
    char name;
    int group;
};

class ArrayQueue{
public:
  ArrayQueue(){
    customers = new customer[27];
    front=0;
    rear=0;
  }
  ~ArrayQueue(){
    delete []customers;
  }
  bool is_empty(){
    if(front==rear) return 1;
    else return 0;
  }
  void push(char x,int group_number){

    int inserted_pos=traverse(group_number);
    //move back all elements behind inserted_pos
    for(int i=rear;i>=inserted_pos;--i){
      customers[i+1]=customers[i];
    }
    customers[inserted_pos].name=x;
    customers[inserted_pos].group=group_number;
    ++rear;
  }
  char pop(){
    if(is_empty()){throw "The queue is empty.";}
    else{
      ++front;
      return customers[front-1].name;
    }
  }
  int traverse(int group_number){//find the same group
    if(is_empty()){return 0;}
    if(group_number==0){return rear;}//no groups,push back
    int index = front;
    while(index<=rear){
      if(customers[index].group==group_number){return index;}
      ++index;
    }
    return rear;//didt't find any customer belonging to the same group
  }

  void print(){
    for(int i=front;i<rear;++i){
      cout<<customers[i].name;
    }
    cout<<endl;
  }
private:
  customer* customers;
  int front;
  int rear;
};

int find_group(const int* groups,char x){
  if(x<'A'||x>'Z') return -1;
  else return groups[x-'A'];
}

int main(){

  int* groups = new int[26];
  for(int i=0;i<26;++i){groups[i]=0;}
  int group_amount;
  cin>>group_amount;

  //read the groups information
  for(int i=0;i<group_amount;++i){
    int j;
    cin>>j;
    for(;j>0;--j){
      char name;
      cin>>name;
      groups[name-'A']=i+1;
    }
  }

  ArrayQueue q;
  string answer;
  while(!cin.eof()){
    string operation;
    cin>>operation;

    if(operation=="ENQUEUE"){
      char customer;
      cin>>customer;
      int group_number=find_group(groups,customer);
      q.push(customer,group_number);
    }
    else if(operation=="DEQUEUE"){
      if(q.is_empty())
        cout<<"The queue is empty!"<<endl;
      else
        answer.push_back(q.pop());
    }
    else{}
    //q.print();
  }

  //display the result
  for(int i=0;i<answer.size();++i){
    cout<<answer.at(i)<<endl;
  }
  delete []groups;
}
