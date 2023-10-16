#include <stdio.h>

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[m"
#define COLOR_RED "\033[0;31m"
#define COLOR_DEFAULT "\033[0m"

int main() {
    int array_size, temp, counter1, counter2;
    printf("Input the desired amount of numbers: ");
    scanf("%d", &array_size);
    int array[array_size];

    //array populating
    for(counter1 = 0; counter1 < array_size; counter1++){
        printf(">> ");
        scanf("%d", &array[counter1]);
    }

    //print unsorted array
    printf(BOLD_ON COLOR_RED "Unsorted array:\n" BOLD_OFF COLOR_DEFAULT);
    for(counter1 = 0; counter1 < array_size; counter1++){
        printf(" %d ", array[counter1]);
    }

    //array sorting
    for(counter1 = 0; counter1 < array_size - 1; counter1++){
        for(counter2 = 0; counter2 < array_size - 1; counter2++){
            if(array[counter2] > array[counter2 + 1]) {
                temp = array[counter2];
                array[counter2] = array[counter2 + 1];
                array[counter2 + 1] = temp;
            }
        }
    }

    //print sorted array
    printf(BOLD_ON COLOR_RED "\nSorted array:\n" BOLD_OFF COLOR_DEFAULT);
    for(counter2 = 0; counter2 < array_size; counter2++){
        printf(" %d ", array[counter2]);
    }
    return 0;
}
