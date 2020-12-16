#include<stdio.h>
#include"../hDirectory/globalService.h"
#include<stdlib.h>
#include"../hDirectory/Tugas-2.h"

int  main(){
	
	// Initialize Local Recipe Head
	// Bakal dipakai ke function function sebagai PASSING-BY REFERENCE
	struct Recipe *recipe_head, *recipe_tail;
	recipe_head = recipe_tail = NULL;
	
	insertNewRecipe(&recipe_head, &recipe_tail);
	insertNewRecipe(&recipe_head, &recipe_tail);
	insertNewRecipe(&recipe_head, &recipe_tail);
	cookbook(&recipe_head, &recipe_tail);
	
	
	getchar();
	return 0;
}
