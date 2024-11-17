#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    // int a,b;
    // cout<<"Enter no"<<endl;
    // cin>>a;
    // cin>>b;
    // if(a>b){
    //     cout<<"A is greater than b";

    // }
    // else
    // {
    //     cout<<"B is greater than a ";
    // }
    // char ch='A';
    // for (int i = 0; i <1000; i++)
    // {    
    //     /* code */
    //     for (int j = 0; j<=i; j++)
    //     {
     
    //         /* code */
    //         cout<<ch<<" ";
    //               ch=ch+1;
    //     }
    //     cout<<endl;
    // 0,1,1,2,3,5,8    
    // }
    // int a=4;
    // int b=6;
    // cout<<" a&b"<<(a&b)<<endl;
    // cout<<" a|b"<<(a|b)<<endl;
    // cout<<" ~a"<<(~a)<<endl;
    // cout<<" a^b"<<(a^b)<<endl;
        //  cout<<(17>>1)<<endl;
        //  cout<<(17>>2)<<endl;
        //  cout<<(19<<1)<<endl;
        //  cout<<(21<<2)<<endl;
        //     int a=0;
        //     int b=1;
        //     int next;
        //     cout<<a<<","<<b;
        // for (int i = 0; i < 10; i++)
        // {   next=a+b;
        //     cout<<(next)<<",";
        //     a=b;
        //     b=next;
        // }

        // 3 march 2024

        int n;
        int bin=0;
        int i=0;
        cin>>n;
        while(n!=0){

            bin=((n&1)*pow(10,i))+(bin);
            n=n>>1;
          //  cout<<n<<"testing "<<endl;
            i++;
        }
        cout<<bin;

        return 0;

        
    
}