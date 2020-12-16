#ifndef TUGAS_LIMA_PARAM
#define TUGAS_LIMA_PARAM_1 

#include"global.h"
#include<stdio.h>
#include<string.h>
#include"globalService.h"

char NAME[255];
char LANGUAGE[255];
int SAVED_RECIPES= 0;

void updateLanguage(){
    char lang;
    int updateFlag = 1;
    do{
        updateFlag = 1;
        if(strcmp(LANGUAGE, "English")==0){
            printf("Select Language:\n");
            printf("1. English\n");
            printf("2. Indonesian\n");
        }
        else{
            printf("Pilih Bahasa:\n");
            printf("1. Bahasa Inggris\n");
            printf("2. Bahasa Indonesia\n");
        }
        printf(">> ");
        lang = getchar();
        getchar();
        if(lang-'0'<1 || lang-'0'>2){
            updateFlag = 0;
        }
    }while(updateFlag==0);
    switch(lang-'0'){
        case 1:
            strcpy(LANGUAGE, "English");
            break;
        case 2:
            strcpy(LANGUAGE, "Indonesian");
    }
    if(strcmp(LANGUAGE,"English")==0)printf("Press enter to continue..");
    else printf("Tekan tombol 'Enter' untuk kembali..");
    getchar();
    return;
}

void updateName(){
    char name[255];
    int updateFlag  = 1;
    do{
        updateFlag = 1;
        if(strcmp(LANGUAGE,"English")==0)printf("Enter your name [4 - 20 characters ]: ");
        else printf("Masukkan nama [4 - 20 karakter]: ");
        scanf("%[^\n]", name);
        getchar();
        int tempLen = strlen(name);
        if(tempLen<4 || tempLen>20){
            updateFlag = 0;
            if(strcmp(LANGUAGE,"English")==0)printf("Name must be between 4 - 20 characters!\n");
            else printf("Nama harus tersusun atas 4 - 20 karakter!\n");
        }
    }while(updateFlag==0);
    strcpy(NAME, name);
    if(strcmp(LANGUAGE,"English")==0)printf("Press enter to continue..");
    else printf("Tekan tombol 'Enter' untuk kembali..");
    getchar();
    return;
}

void profileHandling(){
    char profileChoice;
    do{
        do{
            system("cls");
            if(strcmp(LANGUAGE,"English")==0){
                printf("Name: %s\n", NAME);
                printf("Number of Saved Recipes: %d\n", SAVED_RECIPES);
                printf("Preferred Language: %s\n", LANGUAGE);
                printf("1. Change Name\n");
                printf("2. Change Language\n");
                printf("3. Back to Main Menu\n");
            }
            else{
                printf("Nama: %s\n", NAME);
                printf("Jumlah Resep yang telah disimpan: %d\n", SAVED_RECIPES);
                printf("Bahasa: %s\n", LANGUAGE);
                printf("1. Ganti Nama\n");
                printf("2. Ganti Bahasa\n");
                printf("3. Kembali ke Menu Utama\n");
            }
            printf(">> ");
            profileChoice = getchar();
            getchar();
        }while(profileChoice-'0'<1 || profileChoice-'0'>3);
        switch(profileChoice-'0'){
            case 1:
                updateName();
                break;
            case 2:
                updateLanguage();
                break;
        }
    }while(profileChoice!='3');
}

void Register(){
    char tempName[255];
    int registerFlag  = 1;
    do{
        registerFlag = 1;
        printf("Enter your name [4 - 20 characters ]: ");
        scanf("%[^\n]", tempName);
        getchar();
        int tempLen = strlen(tempName);
        if(tempLen<4 || tempLen>20){
            registerFlag = 0;
            printf("Name must be between 4 - 20 characters!\n");
        }
    }while(registerFlag==0);
    strcpy(NAME, tempName);
    char lang;
    do{
        registerFlag = 1;
        printf("Select Language:\n");
        printf("1. English\n");
        printf("2. Indonesian\n");
        printf(">> ");
        lang = getchar();
        getchar();
        if(lang-'0'<1 || lang-'0'>2){
            registerFlag = 0;
        }
    }while(registerFlag==0);
    switch(lang-'0'){
        case 1:
            strcpy(LANGUAGE, "English");
            break;
        case 2:
            strcpy(LANGUAGE, "Indonesian");
    }
    if(strcmp(LANGUAGE,"English")==0)printf("Press enter to continue..");
    else printf("Tekan tombol 'Enter' untuk kembali..");
    getchar();
    return;
}
#endif