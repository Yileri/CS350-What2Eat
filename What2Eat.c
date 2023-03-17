#include <stdio.h>

int main() {
    int people;
    char* choices[] = {"Kebab", "Hamburger", "Salad", "Lahmacun", "Pizza"}; 

    printf("Please enter the number of people: ");
    scanf("%d", &people);

    for (int i = 0; i < people; i++) {
        printf("Person %d, please type the name of items to be the most wanted one in the beginning and least wanted at the end", i+1);

    }
    return 0;
}