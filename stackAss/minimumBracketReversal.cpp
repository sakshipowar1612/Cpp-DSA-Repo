#include<iostream>
#include<stack>
using namespace std;

int countRev (string s)
{
        stack<char>box;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '{'){
                box.push(ch);
            }
            else if(ch == '}'){
                if(!box.empty() && box.top()=='{'){
                    box.pop();
                }
                else{
                    box.push(ch);
                }
            }
        }
       
        int noOfSwaps = 0;
         if(box.size()%2!=0){
            return -1;
        }
        while(!box.empty()){
            // if(box.top()=='{'){
            //     box.pop();
            //     if(!box.empty() && box.top()=='}'){
            //         noOfSwaps += 2;
            //         box.pop();
            //     }
            //     else if(!box.empty() && box.top()=='{'){
            //         noOfSwaps += 1;
            //         box.pop();
            //     }
            // }
            // else if(!box.empty() && box.top()=='}'){
            //     box.pop();
            //     if(!box.empty() && box.top() == '}'){
            //         noOfSwaps += 1;
            //         box.pop();
            //     }
            // }
            char first = box.top(), sec;
            box.pop();
            if(!box.empty()){
               sec = box.top(); 
               box.pop();
            }
            if(first==sec){
                noOfSwaps += 1;
            }
            else{
                noOfSwaps += 2;
            }
            
        }
        return noOfSwaps;
}

int main(){
    string s = "}}{}}}{}";
    cout << countRev(s) << endl;
}
