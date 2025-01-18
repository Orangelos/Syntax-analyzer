//
//  main.cpp
//  SyntaxAnalysator
//
//  Created by Андрей Макаров on 15.11.2023.
//
#include<stdio.h>
#include "AnaliticVivod.hpp"
#include "Syntax.hpp"
int main(){
    
          FILE* run;
          //run = fopen("/Users/orangelos/Desktop/vivod.txt", "r");
          run=fopen("/Users/orangelos/Desktop/vivod+.txt", "r");
          int i=0,n=100000;
          char *mas;

          mas=(char*)calloc(n,sizeof(char));
          while(mas[i-1]!=EOF){
              if (i<n)
              mas[i]=fgetc(run);
              else{
                  n=n+5;
                  mas=(char*)realloc(mas, 100000*sizeof(char));
                  mas[i]=fgetc(run);
              }
              i=i+1;
          }
    if(mas[0]==EOF)
        printf("Файл пуст");
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    Syntax pr=mas;
    pr.proverka();
    
    AnaliticVivod vivod=mas;
    vivod.vivod();
    
    
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    
//    for(int i=0;i<strlen(mas);i++)
//        printf("%c",mas[i]);
//    
//        free(mas);
          
}



