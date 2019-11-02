#include <iostream>
#include <string>
using namespace std;

typedef struct node* listPointer;
struct node{
    char name;
    int group;
    listPointer link;
};

class LinkedQueue{
public:
  LinkedQueue(){
    //initialize a head node
    listPointer head = new node;
    head->name='#';
    head->group=-1;
    head->link=NULL;
    front=head;
    rear=head;
  }
  ~LinkedQueue(){
    listPointer temp;
    while(front!=rear){
      temp=front;
      front=front->link;
      //cout<<"delete "<<temp->name<<endl;
      delete temp;
    }
    delete rear;
  }
  bool is_empty(){
    if(front==rear) return 1;
    else return 0;
  }
  void push(char x,int group_number){
    listPointer new_node = new node;
    new_node->name=x;
    new_node->group=group_number;

    listPointer inserted_node=traverse(group_number);
    if(inserted_node==rear){rear=new_node;}
    new_node->link=inserted_node->link;
    inserted_node->link=new_node;
  }
  char pop(){
    if(is_empty()){throw "The queue is empty.";}
    else{
      if(front->link==rear){rear=front;}//pop last element
      listPointer del_node=front->link;
      char name=del_node->name;
      front->link=del_node->link;
      delete del_node;
      return name;
    }
  }
  listPointer traverse(int group_number){//find the same group, and return the previous node
    listPointer temp = front;
    while(temp->link!=NULL){
      if(temp->link->group==group_number){return temp;}
      temp=temp->link;
    }
    return rear;//dont't find any customer belonging to the same group
  }
  void print(){
    listPointer temp=front->link;
    while(temp){
      cout<<temp->name;
      temp=temp->link;
    }
    cout<<endl;
  }
private:
  listPointer front;
  listPointer rear;
};

int find_group(const int* groups,char x){
  if(x<'A'||x>'Z') return -1;
  else return groups[x-'A'];
}

int main(){

  int* groups = new int[26];
  for(int i=0;i<26;++i){groups[i]==0;}
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

  LinkedQueue q;
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
