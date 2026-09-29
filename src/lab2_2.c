#include <stdio.h>
 
/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).
 
    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/
 
long long factorial(int n) {
    long long result = 1;
 
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
 
    return result;
}
 
int main(void) {
    int n;
 
    printf("Enter a non-negative integer n: ");
    if (scanf("%d", &n) != 1) {
        printf("Error: input is not an integer.\n");
        return 1;
    }
 
    if (n < 0) {
        printf("Error: factorial is not defined for negative numbers.\n");
        return 1;
    }
 
    /* 20! is the largest factorial that fits in long long */
    if (n > 20) {
        printf("Error: n is too large, max n is 20.\n");
        return 1;
    }
 
    printf("%d! = %lld\n", n, factorial(n));
 
    return 0;
}