#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <random>
#include <ctime>
//#include <time.h>
using namespace std;
void quickSort(int* n,const int left,const int right){
  if(left<right){
    int i=left;
    int j=right+1;
    int pivot=n[left];
    /*median of three
    int m=(right+left)/2;
    int pivot;
    if(n[left]<n[right]){
      if(n[left]>n[m]){pivot=n[left];}
      else{pivot=n[m];m=n[left];}
    }
    else{
      if(n[right]>n[m]){pivot=n[right];n[right]=n[left];}
      else{pivot=n[m];n[m]=n[left];}
    }
    n[left]=pivot;*/

    do{
      do i++;while(n[i]<pivot);
      do j--;while(n[j]>pivot);
      if(i<j)swap(n[i],n[j]);
    }while(i<j);

    swap(n[left],n[j]);
    quickSort(n,left,j-1);
    quickSort(n,j+1,right);
    /*longer first/shorter first
    if(right-j-1<j-1-left){
      quickSort(n,j+1,right);
      quickSort(n,left,j-1);
    }
    else{
      quickSort(n,left,j-1);
      quickSort(n,j+1,right);
    }*/

  }
}
int main(){
  srand(time(NULL));
  fstream file;
  file.open("test data.txt",ios::in);
  int* data=new int[150001];

  int i=1;
  clock_t start,end;
  double cpu_time_used;
  int x;

  while(file>>x){
    data[i]=x;
    ++i;
  }

  start = clock();
  quickSort(data,1,150000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  //cout<<"use median of three and longer first execution time = "<<cpu_time_used<<endl;
  cout<<"use median of three and shorter first execution time = "<<cpu_time_used<<endl;
  delete [] data;
}
