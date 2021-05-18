#include <stdio.h>
#include <stdlib.h>

int sumacc(int* arr, int n) {
    int acc = 0;

    while(n--) {
        acc = acc + *(arr++);
    }

    return acc;
}

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int richest_sum = 0;

    while (accountsSize--) {
        int cur_sum = sumacc(accounts[accountsSize], *accountsColSize);
        if (cur_sum > richest_sum) {
            richest_sum = cur_sum;
        }
    }

    return richest_sum;
}

int main(int argc, char const *argv[])
{
    int colSize = 3;
    int accSize = 3;
    int** teste3 = (int**) malloc(3 * sizeof(int*));
    
    for (int i = 0; i < 3; i++) {
        teste3[i] = (int*) malloc(3 * sizeof(int));
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            teste3[i][j] = rand() % 10;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        printf("%i: ", i);
        for (int j = 0; j < 3; j++) {
            printf("%i, ",teste3[i][j]);
        }
        printf("\n");
    }
    
    printf("%i", maximumWealth(teste3, accSize, &colSize));
    
    return 0;
}
