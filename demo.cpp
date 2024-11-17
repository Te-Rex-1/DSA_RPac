#include<iostream>
using namespace std;
bool isPowerOfTwo(int n) {
        
        bool flag = false;
        
        while (n != 0) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n == 1) {

                flag = true;
                n = 0;
            } else {
                flag = false;
                n = 0;
            }
        }
        return flag;
    }

    int check(int n){
        n*=10;
        //cout<<n<< "value in function";
        return n;
    }
    int main(){
        int n;
        cin>>n;
        cout<<check(n);
        cout<<n;
        return 0;
    }