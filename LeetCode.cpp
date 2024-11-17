#include<iostream>
using namespace std;
main(){
int n;
cin>>n;


int prod=1;
int sum=0;
while(n>0){
  
    prod*=n%10;
    sum+=n%10;
    n/=10;
}
cout<<(prod-sum);

return 0;
}