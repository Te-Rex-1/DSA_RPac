#include<stdio.h>
#include<conio.h>
// int main(){
//    int n,sum=0;
//    printf("Enter no");
//    scanf("%d",&n);
//    while(n!=0){
//     sum+=n%10;
//     n/=10;
//    }
//    printf("Sum is %d",sum);
//    getch();
//    return 0;
// }


// int main() {
//     int num;
//     int factorial = 1;

//     // Asking for user input
//     printf("Enter a number: ");
//     scanf("%d", &num);

//     // Handling negative input
//     if(num < 0) {
//         printf("Factorial is not defined for negative numbers.\n");
//     } else {
//         // Calculating factorial iteratively
//         for(int i = 1; i <= num; ++i) {
//             factorial *= i;
//         }
//         // Printing the result
//         printf("Factorial of %d is %d\n", num, factorial);
//     }

//     return 0;
// }


// int main(){
//     for(int i=1,j=20;i<=j;i++,j--)
//     printf("\n i=%d j=%d",i,j);
// }

void hcf(int num1,int num2){
    int min,i,hcf;
    min=(num1<num2)?num1:num2;
    i=1;
    while(i<=min){
        if (num1%i==0&&num2%i==0)
        {
            /* code */
            hcf=i;
        }
        i++;
        
    }
    printf("The hcf %d",hcf);
}
int main()
{
hcf(14,18);
printf("\n");




    int rows = 4; // Number of rows for the pyramid

    for (int i = 1; i <= rows; i++) {
        // Loop to print the stars for each row
        for (int j = 1; j <= i; j++) {
            printf("%d",j);
        }
        // Move to the next line after printing each row
        printf("\n");
    }

    return 0;
 return 0;
}