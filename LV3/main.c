#include <stdio.h>
#include <time.h>
#include "stack.h"
#include "stack_linked_list.h"

int povrh_recursion(int n, int m){
    if(n == m || n == 1 || m == 0)
        return 1;
    else
        return povrh_recursion(n - 1, m - 1) + povrh_recursion(n - 1, m);
}

int main() {
    int n;
    clock_t start, end;

    printf("Input n >> ");
    scanf("%d", &n);

// Calculating povrh using recursion
    start = clock();
    printf("%d povrh %d (recursion) >> %d", n, n/2, povrh_recursion(n, n / 2));
    end = clock();
    printf("\nRecursion time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

// Calculating povrh using stack
    start = clock();
    printf("%d povrh %d (stack) >> %d", n, n/2, povrh_stack(n, n / 2));
    end = clock();
    printf("\nStack time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

// Calculating povrh using stack linked list
    start = clock();
    printf("%d povrh %d (stack linked list) >> %d", n, n/2, povrh_stack_list(n, n / 2));
    end = clock();
    printf("\nStack linked list time %lf ms\n", ((double)(end - start))/CLOCKS_PER_SEC*1000);

    return 0;
}
