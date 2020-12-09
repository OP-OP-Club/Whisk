#ifndef GLOBAL_SERVICE_PARAM
#define GLOBAL_SERVICE_PARAM 1

//STD Library
#include<stdlib.h>

//External Library
#include "global.h"

//Recipe Service
struct Recipe* InitializeRecipeNode();
struct Recipe* CreateRecipeNode(char *name, char *description);
void RecipePushBack(struct Recipe **head, struct Recipe **tail, struct Recipe *inserted);
void RecipePushFront(struct Recipe **head, struct Recipe **tail, struct Recipe *inserted);
void RecipePopBack(struct Recipe **head, struct Recipe **tail);
void RecipePopFront(struct Recipe **head, struct Recipe **tail);

//Instructions Service
struct Instructions* InitializeInstructionsNode();
struct Instructions* CreateInstructionsNode(char *steps);
void InstructionsPushBack(struct Instructions **head, struct Instructions **tail, struct Instructions *inserted);
void InstructionsPushFront(struct Instructions **head, struct Instructions **tail, struct Instructions *inserted);
void InstructionsPopBack(struct Instructions **head, struct Instructions **tail);
void InstructionsPopFront(struct Instructions **head, struct Instructions **tail);

//Ingredient Service
struct Ingredient* InitializeIngredientNode();
struct Ingredient* CreateIngredientNode(char *name);
void IngredientPushBack(struct Ingredient **head, struct Ingredient **tail, struct Ingredient *inserted);
void IngredientPushFront(struct Ingredient **head, struct Ingredient **tail, struct Ingredient *inserted);
void IngredientPopBack(struct Ingredient **head, struct Ingredient **tail);
void IngredientPopFront(struct Ingredient **head, struct Ingredient **tail);

//RECIPE

//Init Empty Node
struct Recipe* InitializeRecipeNode() {
	return (struct Recipe*) malloc(sizeof(struct Recipe));
}

//Create Node
struct Recipe* CreateRecipeNode(char *name, char *description) {
	struct Recipe *new_node = InitializeRecipeNode();
	
	new_node->name = name;
	new_node->description = description;
	new_node->ingredient_head = new_node->ingredient_tail = NULL;
	new_node->instruct_head = new_node->instruct_tail = NULL;
	new_node->next = new_node->prev = NULL;

	return new_node;
}

//Push Back Node
void RecipePushBack(struct Recipe **head, struct Recipe **tail, struct Recipe *inserted){
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
void RecipePushFront(struct Recipe **head, struct Recipe **tail, struct Recipe *inserted){
	if((*head) == NULL){
		(*head) = (*tail) = inserted;
	}
	else{
		(*head)->prev = inserted;
		inserted->next = (*head);
		(*head) = inserted;
	}
}

void RecipePopBack(struct Recipe **head, struct Recipe **tail){
	if((*head) == NULL){
		return;
	}
	if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
		free((*head));
	}
	else{
		struct Recipe *curr = (*tail)->prev;
		curr->next = NULL;
		
		(*tail) = NULL;
		free((*tail));
		
		(*tail) = curr;	
	}
}

void RecipePopFront(struct Recipe **head, struct Recipe **tail){
	if((*head) == NULL){
		return;
	}
	if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
		free((*head));
	}
	else{
		struct Recipe *curr = (*head)->next;
		curr->prev = NULL;
		
		(*head) = NULL;
		free((*head));
		
		(*head) = curr;	
	}
}

//INSTRUCTIONS

//Init Empty Node
struct Instructions* InitializeInstructionsNode() {
	return (struct Instructions*) malloc(sizeof(struct Instructions));
}

//Create Node
struct Instructions* CreateInstructionsNode(char *steps) {
	struct Instructions *new_node = InitializeInstructionsNode();
	
	new_node->steps = steps;
	new_node->next = new_node->prev = NULL;
	
	return new_node;
}

//Push Back Node
void InstructionsPushBack(struct Instructions **head, struct Instructions **tail, struct Instructions *inserted){
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
void InstructionsPushFront(struct Instructions **head, struct Instructions **tail, struct Instructions *inserted){
	if((*head) == NULL){
		(*head) = (*tail) = inserted;
	}
	else{
		(*head)->prev = inserted;
		inserted->next = (*head);
		(*head) = inserted;
	}
}

void InstructionsPopBack(struct Instructions **head, struct Instructions **tail){
	if((*head) == NULL){
		return;
	}
	if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
		free((*head));
	}
	else{
		struct Instructions *curr = (*tail)->prev;
		curr->next = NULL;
		
		(*tail) = NULL;
		free((*tail));
		
		(*tail) = curr;	
	}
}

void InstructionsPopFront(struct Instructions **head, struct Instructions **tail){
	if((*head) == NULL){
		return;
	}
	if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
		free((*head));
	}
	else{
		struct Instructions *curr = (*head)->next;
		curr->prev = NULL;
		
		(*head) = NULL;
		free((*head));
		
		(*head) = curr;	
	}
}

int InstructionsSize(struct Instructions **head, struct Instructions **tail){
	int count = 0;

	struct Instructions *curr = (*head);

	while(curr != NULL){
		count++;
	}

	return count;
}

//INGREDIENTS

//Init Empty Node
struct Ingredient* InitializeIngredientNode() {
	return (struct Ingredient*) malloc(sizeof(struct Ingredient));
}

//Create Node
struct Ingredient* CreateIngredientNode(char *name) {
	struct Ingredient *new_node = InitializeIngredientNode();
	
	new_node->name = name;
	new_node->next = new_node->prev = NULL;
	
	return new_node;
}

//Push Back Node
void IngredientPushBack(struct Ingredient **head, struct Ingredient **tail, struct Ingredient *inserted){
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
void IngredientPushFront(struct Ingredient **head, struct Ingredient **tail, struct Ingredient *inserted){
	if((*head) == NULL){
		(*head) = (*tail) = inserted;
	}
	else{
		(*head)->prev = inserted;
		inserted->next = (*head);
		(*head) = inserted;
	}
}

void IngredientPopBack(struct Ingredient **head, struct Ingredient **tail){
	if((*head) == NULL){
		return;
	}
	if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
		free((*head));
	}
	else{
		struct Ingredient *curr = (*tail)->prev;
		curr->next = NULL;
		
		(*tail) = NULL;
		free((*tail));
		
		(*tail) = curr;	
	}
}

void IngredientPopFront(struct Ingredient **head, struct Ingredient **tail){
	if((*head) == NULL){
		return;
	}
	if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
		free((*head));
	}
	else{
		struct Ingredient *curr = (*head)->next;
		curr->prev = NULL;
		
		(*head) = NULL;
		free((*head));
		
		(*head) = curr;	
	}
}


#endif
