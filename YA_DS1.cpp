#include <stdio.h>

int main() {
    int a, b;

    printf("Enter rows: ");
    scanf("%d", &a);

    printf("Enter columns: ");
    scanf("%d", &b);

    int one[a][b], two[a][b], r[a][b];

    printf("Enter values for Array 1:\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d", &one[i][j]);  
        }
    }

    printf("Enter values for Array 2:\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d", &two[i][j]);  
        }
    }

    // Matrix addition
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            r[i][j] = one[i][j] + two[i][j];  
        }
    }

    // Print result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", r[i][j]); 
        }
        printf("\n");
    }

    return 0;
}