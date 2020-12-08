#ifndef RECOMMEND_ALGO_PARAM
#define RECOMMEND_ALGO_PARAM 1

#include<iostream>
#include<vector>
#include <regex>
#include "global.h"
using namespace std;

//DO NOT TOUCH!!!
//REGEX MASIH DALAM PENGEMBANGAN
const char* recipeRecommendation(struct Recipe **head, char* searched){
	
	
	string word (searched);
	
	vector<string> listWord;
	
	struct Recipe *curr = (*head);
	while(curr != NULL){
		string conver(curr->name);
		listWord.push_back(conver);
		curr = curr->next;
	}

	vector<string> filtered;
	regex e1 (("(.*)(" + word + ")(.*)"), regex_constants::icase);
		
	for(auto it :listWord) {
		
		if(regex_match(it, e1)){
			filtered.push_back(it);
		}
	}
	
	string joined = "";
	for(auto it: filtered){
//		cout << it << '\n';
		joined += it + '\n';
	}	
	
	return joined.c_str();
}

void aaa(char *pass[]){
	for(int i = 0; pass[i] != NULL; i++){
		printf("%s\n", pass[i]);
	}
}

//int main(){
//	
//	char *arr[] = {
//		"your name",
//		"abcdefg",
//		"hijklmno",
//		"hijklmno",
//	};;
//	
//	aaa(arr);
//	
//	return 0;
//}




#endif
