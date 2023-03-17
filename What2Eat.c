#include <stdio.h>
#include <string.h>

int main() {
    int people;
    int minPoint = 10;
    int finalCount = 0;
    int* choices[] = {0, 0, 0, 0, 0}; 

    printf("Please enter the number of people: ");
    scanf("%d", &people);

    for (int i = 0; i < people; i++) {
        printf("\n");
        printf("Person %d, please type the name of items to be the most wanted one in the beginning and least wanted at the end\n", i+1);
        printf("1. Kebab\n");
        printf("2. Hamburger\n");
        printf("3. Salad\n");
        printf("4. Lahmacun\n");
        printf("5. Pizza\n");
        printf("\n");

        for (int j = 0; j < 5; j++) {
            char item[20];
            printf("Choice number %d: ", j+1);
            scanf("%s", item);

            if (!strcmp(item, "Kebab")) {
                choices[0] += 5-j;
            } else if (!strcmp(item, "Hamburger")) {
                choices[1] += 5-j;
            } else if (!strcmp(item, "Salad")) {
                choices[2] += 5-j;
            } else if (!strcmp(item, "Lahmacun")) {
                choices[3] += 5-j;
            } else if (!strcmp(item, "Pizza")) {
                choices[4] += 5-j;
            } else {
                printf("\n");
                printf("Invalid item, please type an item from the list\n");
                printf("\n");
                j--;
            }
        }

    }

    for (int i = 0; i < sizeof(choices); i++) {
        if (choices[i] >= 10) {
            finalCount ++;
        }
    }
    
    // if none of the points of items are above 10
    if (finalCount == 0) {
        printf("You are eating at home, decide better next time.");
        return 0;
    }

    int* finalList[finalCount];

    int index = 0;
    for (int i = 0; i < sizeof(choices); i++) {
        if (choices[i] >= 10) {
            finalList[index] = choices[i];
            index++;
        }
    }

    return 0;
}