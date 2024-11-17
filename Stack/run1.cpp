#include <bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

void nseRight(vector<int> arr,vector<int> &next)
{
  stack <int> store;
  for(int i=arr.size()-1;i>=0;i--)  
  { // true when current element is smaller then top element
    while(!store.empty()&&arr[store.top()]>=arr[i])
    {
        store.pop();
    }

    int temp=store.empty()? -1:store.top();
    store.push(i);
    next[i]=temp;
  }
}

void nseLeft(vector<int> arr,vector<int> &prev)
{
  stack <int> store;
 for(int i=0;i<arr.size();i++)  
  { // true when current element is smaller then top element
    while(!store.empty()&&arr[store.top()]>=arr[i])
    {
        store.pop();
    }

    int temp=store.empty()? -1:store.top();
    store.push(i);
    prev[i]=temp;
  }
}
int  maxAreaHistogram(vector<int> arr)
{
   int size=arr.size();
   vector<int> prev(size);
   vector<int> next(size);
    nseRight(arr,next);
    nseLeft(arr,prev);
    int area=-1;
    for(int i=0;i<size;i++)
    {
      int length=arr[i];
      if(next[i]==-1)
      next[i]=size;
      int breath=next[i]-prev[i]-1;
      int newArea=length*breath;
      area=max(area,newArea);
    }
    return area;
} 
int main() {
	// your code goes here
	int testcase;
	cin>>testcase;
	int n;
	while(testcase--)
	{
	    cin>>n;
	    vector<int>arr(n);
	     for(int i=0;i<arr.size();i++)
         {
            cin>>arr[i];
         }
        
	    cout<<maxAreaHistogram(arr)<<endl;
	}
	
	return 0;

}
