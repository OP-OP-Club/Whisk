#ifndef TUGAS_TIGA_MODEL_PARAM
#define TUGAS_TIGA_MODEL_PARAM 1

#include<stdlib.h>

struct KitchenCook {
    struct Recipe *recipe;
    int step_done;

    struct KitchenCook *next, *prev;
};


//KITCHEN COOK

//Init Empty Node
struct KitchenCook* InitializeKitchenCookNode() {
	return (struct KitchenCook*) malloc(sizeof(struct KitchenCook));
}

//Create Node
struct KitchenCook* CreateKitchenCookNode(struct Recipe *new_recipe) {
	struct KitchenCook *new_node = InitializeKitchenCookNode();
	
	new_node->recipe = new_recipe;
	new_node->next = new_node->prev = NULL;

	return new_node;
}

//Push Back Node
void KitchenCookPushBack(struct KitchenCook **head, struct KitchenCook **tail, struct KitchenCook *inserted){
	if((*head) == NULL){
		(*head) = (*tail) = inserted;
	}
	else{
		(*tail)->next = inserted;
		inserted->prev = (*tail);
		(*tail) = inserted;
	}
}

//Push Front Node
void KitchenCookPushFront(struct KitchenCook **head, struct KitchenCook **tail, struct KitchenCook *inserted){
	if((*head) == NULL){
		(*head) = (*tail) = inserted;
	}
	else{
		(*head)->prev = inserted;
		inserted->next = (*head);
		(*head) = inserted;
	}
}

void KitchenCookPopBack(struct KitchenCook **head, struct KitchenCook **tail){
	if((*head) == NULL){
		return;
	}
	if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
		free((*head));
	}
	else{
		struct KitchenCook *curr = (*tail)->prev;
		curr->next = NULL;
		
		(*tail) = NULL;
		free((*tail));
		
		(*tail) = curr;	
	}
}

void KitchenCookPopFront(struct KitchenCook **head, struct KitchenCook **tail){
	if((*head) == NULL){
		return;
	}
	if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
		free((*head));
	}
	else{
		struct KitchenCook *curr = (*head)->next;
		curr->prev = NULL;
		
		(*head) = NULL;
		free((*head));
		
		(*head) = curr;	
	}
}


#endif