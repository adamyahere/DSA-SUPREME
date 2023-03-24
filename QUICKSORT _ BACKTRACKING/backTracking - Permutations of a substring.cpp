#include <iostream>
using namespace std;

void permute(string &str, int i ){
    //base case
    if(i >= str.length()){
        cout<<str<<" ";
        return  ;
    }
    //swapping
    for(int j = i ; j< str.length(); j++){
        //swap 
        swap(str[i],str[j]);
        //rec call
        permute(str,i+1);
        //backstracking - why?-> jab bhi mai wapis jaunga original string ko wapis create kr dunga!
        // or to recreate the original input 
        swap(str[i],str[j]);
    }
    
}

int main() {
    string str = "abc";
    int i = 0;
    
    permute(str,i);
    
    return 0;
}
