#ifndef TUGAS_TIGA_PARAM
#define TUGAS_TIGA_PARAM 1

#include<stdio.h>
#include "globalService.h"

void KitchenListRecipes(struct Recipe **head, struct Recipe **tail){   
    int flag = 1;
    struct Recipe *curr = (*head);
    int numbering = 1;
    while(curr != NULL){
        printf("%d. %s\n", numbering, curr->name);
        flag = 0;
        numbering++;
    }
    if(flag){
        printf("Tidak ada resep\n");
    }
}

void KitchenListInstruction(struct Recipe *curr){
    int numbering = 1;
    while(curr != NULL){
        printf("%d. %s\n", numbering, curr->instruct_head);
        curr = curr->next;
        numbering++;
    }
}

#endif

