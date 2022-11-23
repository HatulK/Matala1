#include "NumClass.h"

int isPrime(int num) {
    if (num == 2 || num == 1) return 1;
    for (int i = 2; i < num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int factorial1(int num){
    int ans=1;
    for(int i =1; i<= num; i++){
        ans*=i;
    }
    return ans;
}

int isStrong(int num){
    int original = num;
    int sum = 0;
    while(num!=0){
        int x = num%10;
        sum+= factorial1(x);
        num/=10;
    }
if (sum==original) return 1;
return 0;
}