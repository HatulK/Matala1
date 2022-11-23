#include "NumClass.h"

int isPalindromeRecursive(int num ,int temp);

int isPalindrome(int num){
    return num==isPalindromeRecursive(num,0);
}
int isPalindromeRecursive(int num ,int temp) {
if(num==0) return temp;
temp = (temp*10)+(num%10);
return isPalindromeRecursive(num/10,temp);
}


int isArmstrong (int num){
    if (num<10) return num*num*num;
    return (num%10)*(num%10)*(num%10)+ isArmstrong(num/10);
}