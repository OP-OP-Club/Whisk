#include "globalService.h"
#include <stdio.h>
#include <string.h>

int SAVED_RECIPES = 0;

void cookbookEn(struct Recipe **recipe_head, struct Recipe **recipe_tail){
    system("cls||clear");
    char recipe_name[255], recipe_desc[255];
    do{
        printf("Enter recipe name [1 - 50 characters]: ");
        scanf("%[^\n]", recipe_name);
        getchar();
    }while(strlen(recipe_name) < 1 || strlen(recipe_name) > 50);
    do{
        printf("Enter recipe description [5 - 100 characters]: ");
        scanf("%[^\n]", recipe_desc);
        getchar();
    }while(strlen(recipe_desc) < 5 || strlen(recipe_desc) > 100);
    struct Recipe *temp = CreateRecipeNode(recipe_name, recipe_desc);
    RecipePushBack(recipe_head, recipe_tail, temp);
    int ingredient_number;
    do{
        printf("Enter number of ingredients [more than 1]: ");
        scanf("%d", &ingredient_number);
        getchar();
    }while(ingredient_number < 1);
    for(int i = 1; i <= ingredient_number; i++){
        char ingredient_name[255];
        do{
            printf("Ingredient %d [1 - 20 characters]: ", i);
            scanf("%[^\n]", ingredient_name);
            getchar();
        }while(strlen(ingredient_name) < 1 || strlen(ingredient_name) > 20);
        IngredientPushBack(&temp->ingredient_head, &temp->ingredient_tail, CreateIngredientNode(ingredient_name));
    }
    int instruction_number;
    do{
        printf("Enter number of steps [more than 1]: ");
        scanf("%d", &instruction_number);
        getchar();
    }while(instruction_number < 1);
    for(int i = 1; i <= instruction_number; i++){
        char instruction_name[255];
        do{
            printf("Step %d [5 - 50 characters]: ", i);
            scanf("%[^\n]", instruction_name);
            getchar();
        }while(strlen(instruction_name) < 5 || strlen(instruction_name) > 50);
        InstructionsPushBack(&temp->instruct_head, &temp->instruct_tail, CreateInstructionsNode(instruction_name));
    }
    SAVED_RECIPES++;
    printf("Recipe added successfully!\n");
    printf("Press enter to continue");
    getchar();
}