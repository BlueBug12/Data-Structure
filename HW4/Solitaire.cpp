#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//typedef struct node card;
struct card{
	char points;
	card* next;
};

void shuffle(char* cards,const int size,int level=20){
	srand(time(NULL));
	//randomly choose two elements to swap
	for(int i=0;i<level;++i){
		int p1 = rand()%size;
		int p2 = rand()%size;
		swap(cards[p1],cards[p2]);
	}
}

card* creat_list(card* header){
	char cards[13] ={'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
	shuffle(cards,13);

	header->points=cards[0];
	card* temp = header;

	for(int i=1;i<13;++i){
		card* c= new card;
		c->points=cards[i];
		c->next=NULL;
		temp->next=c;
		temp=c;
	}
	return temp;
}

void print(card* header){
	while(header!=NULL){
		if(header->points=='X')
			cout<<"10"<<' ';
		else
			cout<<header->points<<' ';
		header=header->next;
	}
	cout<<endl;
}

int main(){
	int sheets = 12;
	char reference[13] ={'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
	card* header = new card;
	card* tail = creat_list(header);
	print(header);

	while(header->next!=NULL){
		//find the target element,pop it out
		if(header->points==reference[sheets]){
			card* deleted_node = header;
			header=header->next;
			delete deleted_node;
			--sheets;
		}
		else{
			tail->next=header;
			header=header->next;
			tail=tail->next;
			tail->next=NULL;
		}

		print(header);
	}
	delete header;
	return 0;
}
