#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "globalService.h"

void pantryMenu(struct Recipe **recipe_head, struct Recipe **recipe_tail) {
    system("CLS");

    int cFlag = 0;
    char choice[10];
    do {
        cFlag = 1;
        printf("===================\n");
        printf("|   Pantry Menu   |\n");
        printf("===================\n");
        puts("");
        printf("1. Insert Ingredient\n");
        printf("2. Delete Ingredient\n");
        printf("3. Insert Recipe\n");
        printf("4. Exit\n")
        printf(">> ");
        scanf("%s", choice);
        if (strlen(choice) > 1) {
            cFlag = 0;
        } else if (choice[0] < '1' || choice[0] > '4') {
            cFlag = 0;
        }
    } while (cFlag == 0);

    if (choice[0] == '1') {
        
    } else if (choice[0] == '2') {

    } else if (choice[0] == '3') {
        char name[105], desc[105];
        printf("Dish's Name: ");
        getchar();
        scanf("%[^\n]", name); 
        getchar();
        printf("Dish's Description: ");
        scanf("%[^\n]", desc);

        struct Recipe *recipe = CreateRecipeNode(name, desc);
        RecipePushBack(recipe_head, recipe_tail, recipe);
        printf("Recipe Successfully Added!\n");
        printf("Press enter to continue...");
        getchar();
        system("CLS");
    } else {
        return;
    }
}