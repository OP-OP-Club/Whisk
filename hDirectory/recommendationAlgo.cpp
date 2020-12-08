#ifndef RECOMMEND_ALGO_PARAM
#define RECOMMEND_ALGO_PARAM 1

#include<iostream>
#include<vector>
#include <regex>
using namespace std;


//DO NOT TOUCH!!!
//REGEX MASIH DALAM PENGEMBANGAN
void recommendation(){
	string word = "a";
	vector<string> listWord;
	
	listWord.push_back("David");
	listWord.push_back("Charles");
	listWord.push_back("Matthew");
	listWord.push_back("Nich");
	listWord.push_back("Jevon");
	listWord.push_back("Michael");
	listWord.push_back("Priscilla");
	listWord.push_back("UwU");
	listWord.push_back("NaCl");
	
	vector<string> filtered;
	regex e1 (("(.*)(" + word + ")(.*)"), regex_constants::icase);
		
	for(auto it :listWord) {
		
		if(regex_match(it, e1)){
			filtered.push_back(it);
		}
	}
	
	for(auto it: filtered){
		cout << it << '\n';
	}	
}


#endif
