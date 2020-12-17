#ifndef TUGAS_TIGA_PARAM
#define TUGAS_TIGA_PARAM 1

#include <stdio.h>
#include <string.h>
#include "globalService.h"
#include "../model/Tugas-3Things.h"

void KitchenListRecipes(struct Recipe **head, struct Recipe **tail){   
    int flag = 1;
    struct Recipe *curr = (*head);
    int numbering = 1;
    while(curr != NULL){
        printf("%d. %s\n", numbering, curr->name);
        flag = 0;
        numbering++;
        curr = curr->next;
    }
    if(flag){
        printf("Tidak ada resep\n");
    }
}

void KitchenListInstruction(struct Recipe *recipe){
    int numbering = 1;
    Ingredient *curr = recipe->ingredient_head;
    while(curr != NULL){
        printf("%d. %s\n", numbering, curr->name);
        curr = curr->next;
        numbering++;
    }
}

void KitchenCookSelected(struct KitchenCook **curr) {
    printf("Status: %d/%d Completed\n", (*curr)->step_done, KitchenCookCount(curr));
}

void KitchenSelectRecipe();
void KitchenListKitchenCook();
void KitchenViewRecipe(KitchenCook *select);

void KitchenMain(){
    char choice;
    while(true){
        system("cls||clear");
        printf("Kitchen\n\n");
        printf("1. Select Recipe (Create Kitchen Cook)\n");
        printf("2. List Kitchen Cook\n");
        printf("3. Main Menu\n");
        printf(">> ");
        scanf("%c", &choice); getchar();
        if(choice == '1'){
            KitchenSelectRecipe();
        }
        else if(choice == '2'){
            KitchenListKitchenCook();
        }
        else if(choice == '3'){
            return;
        }
        
    }
    
}

void KitchenListKitchenCook(struct KitchenCook **kitchen_head, struct KithcenCook **kitchen_tail) {
    struct KitchenCook *curr = (*kitchen_head);

    int flag = 0;
    while(curr != NULL){
        printf("%d. %s\n", flag + 1, curr->recipe->name);
        flag++;
        curr = curr->next;
    }

    if(flag == 0){
        printf("Empty\n");
        printf("Press Enter To Continue\n");
        getchar();
        return;
    }

    printf("\n");
    printf(">> ");
    int choices;
    scanf("%d", &choices);
    getchar();

    while(1){
        if(choices == 0){
            return;
        }
        if(choices > flag || choices < 0){
            printf("Not Valid!!\nPress Enter To Continue\n");
            getchar();
        }
        else{
            choices--;
            curr = (*kitchen_head);
            while(choices--){
                curr = curr->next;
            }

            KitchenViewRecipe(curr);
            return;
        }
    }

}

void KitchenSelectRecipe(struct Recipe **recipe_head, struct Recipe **recipe_tail, struct KitchenCook **kitchen_head, struct KitchenCook **kitchen_tail){
    struct Recipe *curr = (*recipe_head);

    if(curr == NULL){
        printf("Tidak ada resep\n");
        printf("Press Enter to return");
        getchar();
        return;
    }
    else{
        char choice;
        while(true){
            system("cls||clear");
            printf("Select Recipe to Add (0 to return):\n");
            KitchenListRecipes(recipe_head, recipe_tail);
            printf(">> ");
            scanf("%c", &choice);getchar();
            if(choice == '0'){
                return;
            }
            int flag = 0;
            struct Recipe *curr = (*recipe_head);
            int idx = choice - '0';
            for(int i=1;i<idx;i++){
                curr = curr->next;
                if(curr == NULL){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                printf("Please enter a valid number\n");
                printf("Press Enter to return");
                getchar();
            }
            else{
                struct KitchenCook *newKitchenCook = CreateKitchenCookNode(curr);
                KitchenCookPushBack(kitchen_head, kitchen_tail, newKitchenCook);
                printf("Recipe %s has been added!\n", curr->name);
                printf("Press Enter to return");
                getchar();

                break;
            }
        }
    }
}

void KitchenListKitchenCook(struct KitchenCook **kitchen_head, struct KitchenCook **kitchen_tail){
    if((*kitchen_head) == NULL){
        printf("You have not added any recipes yet\n");
        printf("Press Enter to return");
        getchar();
        return;
    }
    else{
        char choice;
        while(true){
            system("cls||clear");
            struct KitchenCook *curr = (*kitchen_head);
            int numbering = 1;
            while(curr != NULL){
                printf("%d. %s\n", numbering, curr->recipe->name);
                numbering++;
                curr = curr->next;
            }
            curr = (*kitchen_head);
            printf("Select Recipe (0 to return):\n");
            scanf("%c", &choice); getchar();
            if(choice == '0'){
                return;
            }
            int flag = 0;
            int idx = choice - '0';
            for(int i=1;i<idx;i++){
                curr = curr->next;
                if(curr == NULL){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                printf("Please enter a valid number\n");
                printf("Press Enter to return");
                getchar();
            }
            else{
                KitchenViewRecipe(curr);
            }
            getchar();
        }
    }
}

void KitchenViewRecipeIngredient(struct KitchenCook *select) {
    system("cls||clear");

    struct Ingredient *curr = select->recipe->ingredient_head;

    while(curr != NULL){
        printf("%s\n", curr->name);
        curr = curr->next;
    }
    getchar();
}

void KitchenViewRecipe(struct KitchenCook *select){
    char choice;
    while(true){
        system("cls||clear");
        printf("Recipe: %s\n", select->recipe->name);
        KitchenCookSelected(&select);
        printf("1. List Ingredient\n");
        printf("2. Start Cooking\n");
        printf("3. Stop Cooking\n");
        printf("0. Return\n");
        printf(">> ");
        scanf("%c", &choice);
        getchar();
    }
}

#endif

