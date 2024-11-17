#include<iostream>
using namespace std;
bool unique(int arrr[],int size)
{       int ans;
    for(int i=0;i<size;i++){
        ans=ans^arrr[i];
    }
    if (ans==0)
    {
        return true;
    }
    else
    return false;
    
}

int findDup(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];

    }
    for (int  i = 1; i < size; i++)

    {
        /* code */
        ans=ans^i;
    }
    return ans;
    
}
void merge(int arr1,int arr2) {
        for (int  i = 0; i < arr1.size(); i++)
    
        {
            for (int  j = 0; j < arr2.size(); j++)
            {
                /* code */
            }
            
        }
        
    }
int main(){
int arr[7]={1,2,3,4,5,2,3};
int arr1[]={-3,0,1,-3,1,1,1,-3,10,0};
// cout<<unique(arr1,sizeof(arr1)/sizeof(int))<<endl;
// cout<<unique(arr,5)<<endl;
cout<<findDup(arr,7);
return 0;
}