#include <bits/stdc++.h>
#include<queue>

using namespace std;
class Sol{
    
    public:
     int store;
    void move1(queue<int> &que){
        while(que.size()>1){
            store=que.front();
            que.pop();
            que.push(store);
        }
    }
    void move2(queue<int> &que){
        while(que.size()>1)
        {
            que.pop();
        }
    }
    void playerAman(queue<int> &que)
    {
        move1(que);
        move2(que);
    }
    void playerAkshat(queue<int> &que)
    {
        move1(que);
        move1(que);
        move2(que);
    }
};
int main() {
	// your code goes here
	class Sol find;
	int testCase;
	int n;
	int input;
	cin>>testCase;
	while(testCase--)
	
	{   // input for pile
	    cin>>n;
	    queue<int> pile;
	    for (int i = 0; i < n; i++) {
	        /* code */
	        cin>>input;
	        pile.push(input);
	        
	    }
	    bool isAmanTurn=true;
	    int lastPlayer=1;
	    while(pile.size()>1){
	        
	    if(isAmanTurn){
	   find.playerAman(pile);
	    lastPlayer=1;
	    }
	    else{
	   find.playerAkshat(pile);
	   lastPlayer=0;
	    }
	    isAmanTurn=!isAmanTurn;
	    }
	    
	    cout<<lastPlayer<<" "<<pile.front()<<endl;
	    
	    
	}

}
