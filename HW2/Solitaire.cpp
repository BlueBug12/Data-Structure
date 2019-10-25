#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void shuffle(char* cards,const int size,int level=20){
	srand(time(NULL));
	//randomly choose two elements to swap
	for(int i=0;i<level;++i){
		int p1 = rand()%size;
		int p2 = rand()%size;
		swap(cards[p1],cards[p2]);
	}
}

void print(const char* cards,int head,int tail,int size){
	while(head!=tail){
		if(cards[head]=='X'){cout<<"10";}
		else{cout<<cards[head];}
		cout<<' ';
		head=(head+1)%size;
	}
	cout<<endl;
}

int main(){
	int sheets = 13;
	int circular_size = sheets+1;
	int head = 0;
	int tail = 13;//point to empty element in circular queue
	char cards[circular_size] ={'A','2','3','4','5','6','7','8','9','X','J','Q','K',' '};
	char reference[sheets] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};

	shuffle(cards,sheets);
	print(cards,head,tail,circular_size);
	while(sheets>=1){
		//found the target element,pop it out
		if(cards[head]==reference[sheets-1]){
			head=(head+1)%circular_size;
			--sheets;
		}

		//pop out the first element and push it back
		else{
			cards[tail]=cards[head];
			tail=(tail+1)%circular_size;
			head=(head+1)%circular_size;
		}
		print(cards,head,tail,circular_size);
	}
	return 0;
}
