#include "NumClass.h"

int power(int a, int b) {
    int ans = 1;
    for (int i = 1; i <= b; ++i) {
        ans = ans * a;
    }
    return ans;
}

int isPalindromeRecursive(int num, int temp);

int isPalindrome(int num) {
    return num == isPalindromeRecursive(num, 0);
}

int isPalindromeRecursive(int num, int temp) {
    if (num == 0) return temp;
    temp = (temp * 10) + (num % 10);
    num = num / 10;
    return isPalindromeRecursive(num, temp);
}

int digitAmount(int x) {
    int counter = 0;
    while (x > 0) {
        counter++;
        x /= 10;
    }
    return counter;
}

int isArmstrongRec(int a, int b) {
    return a == 0 ? 0 : power(a % 10, b) + isArmstrongRec(a / 10, b);
    }


    int isArmstrong(int num) {
        int digits = digitAmount(num);
            return (num == isArmstrongRec(num, digits));
    }
