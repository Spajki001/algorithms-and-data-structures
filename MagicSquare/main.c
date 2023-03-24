#include <stdio.h>

#define N 7

int main(){
    int i, j, num = 1;
    int r, c;
    int matrix[N][N];
    for(i = N / 2; i < N + N / 2; i++){
        for(j = 0; j < N; j++){
            r = (i - j + 3 * N) % N;
            c = (i + j + 1 + 3 * N) % N;
            matrix[r][c] = num;
            printf("%d %d - %d;", r, c, num);
            num++;
        }
        printf("\n");
    }
    printf("\n\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf(" %2d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 1;
}