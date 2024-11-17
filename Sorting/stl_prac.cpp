#include<iostream>
#include <array>
#include<vector>
#include<deque> 

using namespace std;
main(){

array<int,4> a={1,2,3,4};
vector<int> v(6,1);
cout<<"capacity"<<v.capacity()<<endl;
v.push_back(2);
v.pop_back();

cout<<"capacity"<<v.capacity()<<endl;
cout<<"size"<<v.size()<<endl;
cout<<"elem"<<v.at(0)<<endl;
cout<<a.front()<<endl;
cout<<a.back();

v.push_back(23);
v.clear();

return 0;
}