#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> powerset(const vector<string>& all_set,vector<string>& ans,int index){
    int size=ans.size();
    for(int i=0;i<size;++i){
        if(ans.at(i).size()==0){
            ans.push_back(all_set.at(index));
        }
        else{
            ans.push_back(ans.at(i)+','+all_set.at(index));
        }
    }

    if(index==all_set.size()-1){return ans;}
    else{return powerset(all_set,ans,index+1);}
}

int main(){
    cout<<"Please type your input: ";
    while(!cin.eof()){
        string line;
        vector<string>all_set;
        vector<string>ans;
        getline(cin,line);
        all_set.push_back("");
        for(int i=0;i<line.size();++i){
            if(line.at(i)==' '){
                all_set.push_back("");
            }
            else{
                all_set.at(all_set.size()-1)+=line.at(i);
            }
        }

        ans.push_back("");//empty set
        powerset(all_set,ans,0);
        for(int i=0;i<ans.size();++i){
            cout<<'{'<<ans.at(i)<<"} ";
        }
        cout<<endl<<"Please type your input: ";
    }
    return 0;
}
