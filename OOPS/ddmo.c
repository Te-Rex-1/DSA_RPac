#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack, int N) {
    return stack->top == N - 1;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    return stack->array[stack->top];
}

long max(long a, long b) {
    return (a > b) ? a : b;
}


int* nseLeft(int heights[],int n)
{
    int* left=(int*)malloc(n*sizeof(int));
    struct Stack* stk=NULL;
    for (int i = 0; i < n; i++) {
        /* code */
        while(isEmpty(stk)==0&&heights[peek(stk)]>=heights[i])
        {
            pop(stk);
        }
        int st=isEmpty(stk);
        if(st==1)
        left[i]=-1;
        else
        left[i]=peek(stk);
        
    }
    return left;
}
int* nseRight(int heights[],int n)
{
    int* right=(int*)malloc(n*sizeof(int));
    struct Stack* stk=NULL;
    for(int i=n-1;i>=0;i--)
    {
        while(isEmpty(stk)==0&&heights[peek(stk)]>=heights[i])
        {
            pop(stk);
        }
        int st=isEmpty(stk);
        if(st==1)
        right[i]=-1;
        else
        right[i]=peek(stk);
      
    }
    return right;
}
int largeArea(int heights[],int n)
{
    int * left=nseLeft(heights,n);
    int * right=nseRight(heights,n);
    int maxArea=0;
    for(int i=0;i<n;i++)
    {
        int width=right[i]-left[i]-1;
        int area=heights[i]*width;
        if(area>maxArea)
        maxArea=area;
    }
    return maxArea;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--){
        //Write your code here
        int n;
        scanf("%d",n);
        int arr[n];
        printf("%d",largeArea(arr,n));
        
    }
    return 0;
}
