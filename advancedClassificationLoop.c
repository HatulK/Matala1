#include "NumClass.h"
int power (int a , int b);

int isArmstrong(int num){
    int original = num;
    int counter = 0;
    int temp = 0;
    while(num!=0){
        counter++;
        num/=10;
    }
    num = original;
    while(num!=0){
        temp += power((num%10),counter);
        num=num/10;
    }
    return original == temp;
}

int power (int a , int b){
    int ans = 1 ;
    for (int i = 0; i <=b ; ++i) {
        ans= ans* a;
    }
    return ans;
}

int isPalindrome(int num){
int reverse =0 ;
int left = 0;
int original = num;
while(num!=0) {
    left = num % 10;
    reverse = reverse * 10 + left;
    num/=10;
}
return (original == reverse);
}
