#ifndef GLOBAL_PARAM
#define GLOBAL_PARAM 1

//DO NOT TOUCH!!! 
//Boleh Lapor Terlebih dahulu jika melihat kekurangan atau ingin memberi saran tambahan
//SEMUA TEMPAT UNTUK MENYIMPAN VARIABEL GLOBAL
struct Recipe {
	char *name;
	char *description;
	struct Instructions *instruct_head, *instruct_tail;
	struct Ingredient *ingredient_head, *ingredient_tail;
	
	struct Recipe *next, *prev;
};

struct Instructions {
	char *steps;
	
	struct Instructions *next, *prev;
};

struct Ingredient {
	char *name;
	
	struct Ingredient *next, *prev;
};

#endif
