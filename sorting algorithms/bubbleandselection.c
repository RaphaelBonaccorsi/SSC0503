#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(int v[], int n);
void selection(int v[], int n);

int main() {
    char opt[8];
    scanf("%8[^\n]", opt);
    int n;
    scanf("%i", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%i", &nums[i]);
    }
    if (strcmp(opt,"selecao") == 0) {
        selection(nums, n);
    } else if (strcmp(opt,"bolha") == 0) {
        bubble(nums, n);
    } else {
        return 1;
    }


    return 0;
}

void bubble(int v[], int n) {
    int qtd = n - 1, swapped;
    while (qtd >= 1) {
        swapped = -1;
        for (int i = 0; i < qtd; i++) {
            printf("C %i %i\n", i, i + 1);
            if (v[i] > v[i + 1]) {
                printf("T %i %i\n", i, i + 1);
                int temp = v[i + 1];
                v[i + 1] = v[i];
                v[i] = temp;
                swapped = i; 
            }
        }
        
        qtd = swapped;

        if (swapped == -1) {
            break;
        }

    }

    for (int i = 0; i < n; i++) {
        printf("%i ", v[i]);
    }
}


void selection(int v[], int n) {
    int lower;
    for (int i = 0; i < n - 1; i++) {
        lower = i;
        for (int j = i + 1; j < n; j++) {
            printf("C %i %i\n", lower, j);
            if (v[j] < v[lower]) {
                lower = j;
            }
        }

        if (lower != i) {
            printf("T %i %i\n", i, lower);
            int aux = v[i];
            v[i] = v[lower];
            v[lower] = aux;
        }
    }

    for (int i = 0; i < n; i++){
        printf("%i ", v[i]);
    }
}
