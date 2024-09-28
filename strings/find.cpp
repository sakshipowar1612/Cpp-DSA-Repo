#include<iostream>
#include<string>
using namespace std;


int find(string source, string part){
    int n1 = source.length();
    int n2 = part.length();
    int position=-1;
    for(int i=0; i<=(n1-n2); i++){
        int found = -1;
        for (int j = i; j < n2; j++)
        {
            found = i;
            if(source[j]!=part[j-i]){
                found = -1;
                break;
            }   
        }
        if(found!=-1){
            position = found;
            break;
        }
        
    }
    return position;
}

int main(){
    string str1;
    getline(cin, str1);
    string str2;
    getline(cin, str2);
    cout << find(str1, str2) << endl;
}