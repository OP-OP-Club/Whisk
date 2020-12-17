#include<stdio.h>
#include"../hDirectory/globalService.h"
#include"../hDirectory/recommendationAlgo.cpp"
#include<stdlib.h>
#include"../hDirectory/Tugas-2.h"

int  main(){
	
	// Initialize Local Recipe Head
	// Bakal dipakai ke function function sebagai PASSING-BY REFERENCE
	struct Recipe *recipe_head, *recipe_tail;
	recipe_head = recipe_tail = NULL;
	
//	struct Recipe *cree = CreateRecipeNode((char *) "nama 1", (char *) "deskripsi kosong");
//	RecipePushBack(&recipe_head, &recipe_tail, cree);
//	
//	cree = CreateRecipeNode((char *) "nama 2", (char *) "deskripsi kosong");
//	RecipePushBack(&recipe_head, &recipe_tail, cree);
//	
//	cree = CreateRecipeNode((char *) "nama 3", (char *) "deskripsi kosong");
//	RecipePushBack(&recipe_head, &recipe_tail, cree);
//	
//	cree = CreateRecipeNode((char *) "nama 4", (char *) "deskripsi kosong");
//	RecipePushBack(&recipe_head, &recipe_tail, cree);
//	
//	printf("%s\n", recipeRecommendation(&recipe_head, (char *)"am"));
	
	getchar();
	return 0;
}
