#include <stdio.h>


#define MAX 10

void addition(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int i, j;

    printf("\nMatrix Addition:\n");

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[MAX][MAX], int r, int c) {
    int i, j;

    printf("\nTranspose of Matrix:\n");

    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}

void multiplication(int a[MAX][MAX], int b[MAX][MAX],
                    int r1, int c1, int c2) {
    int result[MAX][MAX] = {0};
    int i, j, k;

    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            for(k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication:\n");

    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;
    int i, j;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < r2; i++)
        for(j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    if(r1 == r2 && c1 == c2)
        addition(a, b, r1, c1);
    else
        printf("\nAddition not possible.\n");

    transpose(a, r1, c1);

    if(c1 == r2)
        multiplication(a, b, r1, c1, c2);
    else
        printf("\nMultiplication not possible.\n");

    return 0;
}
