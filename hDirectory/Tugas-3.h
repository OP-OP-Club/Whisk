#ifndef TUGAS_TIGA_PARAM
#define TUGAS_TIGA_PARAM 1

#include<stdio.h>
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

void KitchenMain(Recipe *recipe_head, Recipe *recipe_tail){

    KitchenListRecipes(&recipe_head, &recipe_tail);
}

#endif

