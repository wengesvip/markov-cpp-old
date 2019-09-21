#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <windows.h>
using namespace std;

mt19937_64 twister(time(NULL));
uniform_int_distribution<int> randomnum(0,2147483647);
#define rand() randomnum(twister)

//MARKOV
//wenge is juruo

const int LENGTH=1000;
string _PT;

vector<string> text;

unordered_multimap<string,string> text_map;

string retrieve_word(string _key){
    auto range=text_map.equal_range(_key);
    auto l=range.first;
    auto r=range.second;
    int n=text_map.count(_key);
    //cout<<n<<endl;
    int index=rand()%n;
    for(auto i=l;i!=r;i++){
        if(index<=0){
            auto j=*i;
            string s=j.second;
            return s;
        }
        index--;
    }
}

int main(int argc,char* argv[]){
	if(argc!=2){
		cout<<"Usage: mcpp filename\n";
		return 0;
	}
	
    ifstream in;
    in.open(argv[1]);

    if(in.is_open()){
        string s;
        while(in>>s){
            text.push_back(s);
        }

        for(int i=0;i<text.size()-1;i++){
            text_map.insert(make_pair(text[i],text[i+1]));
        }

        _PT="is";
        ofstream out("res.txt");
        for(int i=0;i<LENGTH;i++){
            string s=retrieve_word(_PT);
            out<<s<<" ";
            _PT=s;
        }

            cout<<"OK\n";
        //Sleep(1000);
    }
    else{
    	cout<<"failed to open file "<<argv[1]<<"\n";
	}
    return 0;
}
