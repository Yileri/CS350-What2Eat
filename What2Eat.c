#include <stdio.h>
#include <string.h>

int main() {
    int people;
    int minPoint = 10;
    int finalCount = 0;
    int choices[5] = {0, 0, 0, 0, 0}; 
    char* itemList[5] = {"Kebab", "Hamburger", "Salad", "Lahmacun", "Pizza"};

    printf("Please enter the number of people: ");
    scanf("%d", &people);

    for (int i = 0; i < people; i++) {
        printf("\n");
        printf("Person %d, please rank these items from best to worst by typing their names.\n", i+1);
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

    printf("\n");
    printf("Finalist for the final round:\n");

    int index = 0;
    for (int i = 0; i < 5; i++) {
        if (choices[i] >= 10) {
            finalCount ++;
            printf("%d. ", index+1); 
            printf("%s ", itemList[i]);
            printf("%d Points\n", choices[i]);
            index++;
            
        }
    }
    
    // if none of the points of items are above 10
    if (finalCount == 0) {
        printf("No finalist, you are eating at home. Decide better next time.\n");
        return 0;
    }

    int* finalPoint[finalCount];
    char* finalList[finalCount];

    index = 0;
    for (int i = 0; i < 5; i++) {
        if (choices[i] >= 10) {
            finalList[index] = itemList[i];
            index ++;
        }
    }

    if (finalCount == 1) {
        printf("\n");
        printf("You are ordering %s!", finalList[0]);
        printf("\n");
        return 0;
    }

    printf("\n");

    // round 2
    for (int i = 0; i < people; i++) {
        printf("Person %d, please rank these items from best to worst by typing their names for final round.\n", i+1);
        for (int j = 0; j < finalCount; j++) {
            printf("%s\n", finalList[j]);
        }

        for (int j = 0; j < finalCount; j++) {
            char item[20];
            printf("Choice number %d: ", j+1);
            scanf("%s", item);

            for (int k = 0; k < finalCount; k++) {
                if (!strcmp(item, finalList[k])) {
                    finalPoint[k] += finalCount-j;
                } else {
                    printf("\n");
                    printf("Invalid item, please type an item from the list\n");
                    printf("\n");
                    j--;
                }
            }
        }
    }

    return 0;
}