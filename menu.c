#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int get_stringlength(char* string){
    int i = 0;
    while(string[i] != '\0') i++;
    return i;
}

void append_string(char* source_str, char* appended_str){
    int i;
    int length_source_str = get_stringlength(source_str);
    int length_appended_str = get_stringlength(appended_str);
    for(i = length_source_str;i < (length_source_str+length_appended_str);i++) source_str[i] = appended_str[i-length_source_str];
    source_str[length_source_str+length_appended_str] = '\0';
}

void set_string(char* source_str, char* new_str){
    int length_new_str = get_stringlength(new_str);
    int i;
    for(i = 0;i < length_new_str;i++) source_str[i] = new_str[i];
    source_str[length_new_str] = '\0';
}


void draw_menu(int index, char menu_strings[][100], int num_of_options){
    int i;
    for(i = 0; i < num_of_options;i++){
        menu_strings[i][0] = ' ';
        if(i == index-1) menu_strings[i][0] = '>';
        printf("%s\n", menu_strings[i]);
    }
}

int menu(char* menu_strings[], int num_of_options){
    char menu_strings_res[20][100];
    char input, index = 1;
    int i;
    for(i = 0;i < num_of_options;i++) set_string(menu_strings_res[i], " ");
    for(i = 0;i < num_of_options;i++) append_string(menu_strings_res[i], menu_strings[i]);
    do{
        system("cls");
        draw_menu(index, menu_strings_res, num_of_options);
        input = getch();
        switch(input){
            case 0x77:
            case 0x57: if(index>1)index--;break;
            case 0x73:
            case 0x53: if(index<=num_of_options-1)index++;break;
            default: continue;
        }
    }while(input != 0xd);
    return index;
}
