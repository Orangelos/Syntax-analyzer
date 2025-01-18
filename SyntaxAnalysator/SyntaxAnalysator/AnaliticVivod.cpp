//
//  AnaliticVivod.cpp
//  SyntaxAnalysator
//
//  Created by Андрей Макаров on 10.12.2023.
//
#include<stdio.h>
#include "AnaliticVivod.hpp"

AnaliticVivod::AnaliticVivod(char* m){
    mas=m;
    r=int(strlen(mas));
}






void AnaliticVivod::vivod(){
    int i=0,met=0;
    while (i<r-1) {
        if((mas[i]=='c')&&(mas[i+1]=='h')&&(mas[i+2]=='a')&&(mas[i+3]=='r')){
            i = char0(i);
        }
        if((mas[i]=='l')&&(mas[i+1]=='o')&&(mas[i+2]=='n')&&(mas[i+3]=='g')){
            i = long0(i);
        }
        if((mas[i]=='s')&&(mas[i+1]=='h')&&(mas[i+2]=='o')&&(mas[i+3]=='r')&&(mas[i+4]=='t')){
            i = short0(i);
        }
        
        if((mas[i]=='s')&&(mas[i+1]=='i')&&(mas[i+2]=='g')&&(mas[i+3]=='n')){
            i = sign0(i);
        }
        
        if((mas[i]=='b')&&(mas[i+1]=='r')&&(mas[i+2]=='e')&&(mas[i+3]=='a')&&(mas[i+4]=='k')){
            i = break0(i);
        }
        
        
        
        if((mas[i]=='u')&&(mas[i+1]=='n')&&(mas[i+2]=='s')&&(mas[i+3]=='i')&&(mas[i+4]=='g')&&(mas[i+5]=='n')&&(mas[i+6]=='e')&&(mas[i+7]=='d')){
            i = unsigned0(i);
        }
        
        if((mas[i]=='i')&&(mas[i+1]=='f')){
            i = if0(i);
        }

        if(mas[i]=='\u0027')
            i=odinar(i);
        
        
        
        
        if((mas[i]=='d')&&(mas[i+1]=='o')){
            i = do0(i);
        }
        
        if((mas[i]=='e')&&(mas[i+1]=='l')&&(mas[i+2]=='s')&&(mas[i+3]=='e')){
            i = else0(i);
        }
        
        if((mas[i]=='g')&&(mas[i+1]=='o')&&(mas[i+2]=='t')&&(mas[i+3]=='o')){
            i = goto0(i);
        }
        
        
        
        if((mas[i]=='c')&&(mas[i+1]=='a')&&(mas[i+2]=='s')&&(mas[i+3]=='e')){
            i = case0(i);
        }
        
        
        
        if((mas[i]=='f')&&(mas[i+1]=='o')&&(mas[i+2]=='r')){
            i = for0(i);
        }
        
        if((mas[i]=='v')&&(mas[i+1]=='o')&&(mas[i+2]=='i')&&(mas[i+3]=='d')){
            i = void0(i);
        }
        
        
        if((mas[i]=='w')&&(mas[i+1]=='h')&&(mas[i+2]=='i')&&(mas[i+3]=='l')&&(mas[i+4]=='e')){
            i = while0(i);
        }
        if((mas[i]=='s')&&(mas[i+1]=='w')&&(mas[i+2]=='i')&&(mas[i+3]=='t')&&(mas[i+4]=='c')&&(mas[i+5]=='h')){
            i = switch0(i);
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        if((mas[i]=='f')&&(mas[i+1]=='l')&&(mas[i+2]=='o')&&(mas[i+3]=='a')&&(mas[i+4]=='t')){
            i = float0(i);
        }
        if (mas[i]=='\x01'){
            i=oshibka(i);
        }
        if(mas[i]=='#'){
           i = include(i);
        }
        if((mas[i]=='p')&&((mas[i-1]==' ')||(mas[i-1]=='\n'))&&(mas[i+5]=='f')&&(mas[i+1]=='r'))
            i=pf(i);
        if((mas[i]=='s')&&((mas[i-1]==' ')||(mas[i-1]=='\n'))&&(mas[i+4]=='f')&&(mas[i+1]=='c'))
            i=scanf0(i);
        if((mas[i]=='i')&&(mas[i+1]=='n')&&(mas[i+2]=='t')){
            i = int0(i);
        }
        mnogoscobok=0;
        if(mas[i]=='(')
            i=scobka(i);
        
        if(mas[i]=='"')
            i=kovicki(i);
        //if(mas[i]=='{')
       //     i=vivodin(i);
        if(mas[i]=='{'){
            met++;
            printf("\033[1;30m%c",mas[i]);
            i++;
            continue;
        }
        if(mas[i]=='}'){
            met--;
            printf("\033[1;30m%c",mas[i]);
            i++;
            continue;
        }
        if(met==0)
            printf("\033[0;34m%c",mas[i]);
        else
            printf("\033[0;30m%c",mas[i]);
        i++;
        
            
    }
}



int AnaliticVivod::include(int i){
    printf("\033[0;33m");
    while (i<r-1) {
        
        if(mas[i]=='\n')
            break;
        if((mas[i]=='<')||(mas[i]=='"')){
            printf("\033[0;31m%c",mas[i]);
            i++;
            continue;
        }
        
    printf("%c",mas[i]);
        i++;
    }
    printf("\033[0m");
    return i;
}

int AnaliticVivod::int0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+3]==' '))
        while (i<j+3) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::scobka(int i){
    while ((mas[i-1]!=')')&&(mas[i]!='\n')){
        if(mas[i]=='\x01'){
            i=oshibka(i);
            break;
        }
        if((mas[i]=='(')&&((mas[i+1]==')')||(mas[i+1]=='{')))
            goto m3;
        if(mas[i]=='"')
            i=kovicki(i);
        if(mas[i]=='\u0027')
            i=odinar(i);
        if((mas[i]=='i')||(mas[i+1]=='n')||(mas[i+1]=='t')){
            i = int0(i);
        }
        
        
        
        
        
        
        
        
        
        
        
        
        if((mas[i]=='c')&&(mas[i+1]=='h')&&(mas[i+2]=='a')&&(mas[i+3]=='r')){
            i = char0(i);
        }
        if((mas[i]=='l')&&(mas[i+1]=='o')&&(mas[i+2]=='n')&&(mas[i+3]=='g')){
            i = long0(i);
        }
        if((mas[i]=='s')&&(mas[i+1]=='h')&&(mas[i+2]=='o')&&(mas[i+3]=='r')&&(mas[i+4]=='t')){
            i = short0(i);
        }
        
        if((mas[i]=='s')&&(mas[i+1]=='i')&&(mas[i+2]=='g')&&(mas[i+3]=='n')){
            i = sign0(i);
        }
        
        
        if((mas[i]=='u')&&(mas[i+1]=='n')&&(mas[i+2]=='s')&&(mas[i+3]=='i')&&(mas[i+4]=='g')&&(mas[i+5]=='n')&&(mas[i+6]=='e')&&(mas[i+7]=='d')){
            i = unsigned0(i);
        }
        
        if((mas[i]=='i')&&(mas[i+1]=='f')){
            i = if0(i);
        }

        if(mas[i]=='\u0027')
            i=odinar(i);
        
        
        
        
        if((mas[i]=='d')&&(mas[i+1]=='o')){
            i = do0(i);
        }
        
        if((mas[i]=='e')&&(mas[i+1]=='l')&&(mas[i+2]=='s')&&(mas[i+3]=='e')){
            i = else0(i);
        }
        
        if((mas[i]=='g')&&(mas[i+1]=='o')&&(mas[i+2]=='t')&&(mas[i+3]=='o')){
            i = goto0(i);
        }
        
        
        
        if((mas[i]=='c')&&(mas[i+1]=='a')&&(mas[i+2]=='s')&&(mas[i+3]=='e')){
            i = case0(i);
        }
        
        
        
        if((mas[i]=='f')&&(mas[i+1]=='o')&&(mas[i+2]=='r')){
            i = for0(i);
        }
        
        if((mas[i]=='v')&&(mas[i+1]=='o')&&(mas[i+2]=='i')&&(mas[i+3]=='d')){
            i = void0(i);
        }
        
        
        if((mas[i]=='w')&&(mas[i+1]=='h')&&(mas[i+2]=='i')&&(mas[i+3]=='l')&&(mas[i+4]=='e')){
            i = while0(i);
        }
        if((mas[i]=='s')&&(mas[i+1]=='w')&&(mas[i+2]=='i')&&(mas[i+3]=='t')&&(mas[i+4]=='c')&&(mas[i+5]=='h')){
            i = switch0(i);
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        if((mas[i]=='f')&&(mas[i+1]=='l')&&(mas[i+2]=='o')&&(mas[i+3]=='a')&&(mas[i+4]=='t')){
            i = float0(i);
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
       
        if((mas[i+1]=='(')&&(mnogoscobok==0)){
            mnogoscobok=1;
            i=scobka(i);
        }
            
        m3:
        printf("\033[1;30m%c\033[0m",mas[i]);
        i++;
    }
    
    return i;
}
 
int AnaliticVivod::kovicki(int i){
    printf("\033[0;31m%c",mas[i]);
    i+=1;
    while(mas[i]!='"'){
        printf("\033[0;31m%c",mas[i]);
        i++;
    }
    if(mas[i]=='"'){
        printf("\033[0;31m%c",mas[i]);
        i+=1;
    }
    return i;
}

int AnaliticVivod::pf(int i){
    while ((mas[i]!='(')&&(mas[i]!='"')){
        printf("\033[1;36m%c",mas[i]);
        i+=1;
    }
    return i;
}











int AnaliticVivod::oshibka(int i){
    printf("\033[1;107m                                                                          ");
    while (mas[i]!='\n'){
        printf("\033[1;107m%c\033[0m",mas[i]);
        i++;
    }
    
    return i;
}


int AnaliticVivod::float0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+5]==' '))
        while (i<j+5) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::char0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+4]==' '))
        while (i<j+4) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::long0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+4]==' '))
        while (i<j+4) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::short0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+5]==' '))
        while (i<j+5) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}

int AnaliticVivod::break0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&((mas[i+5]==' ')||(mas[i+5]==';')))
        while (i<j+5) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::sign0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+4]==' '))
        while (i<j+4) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}

int AnaliticVivod::unsigned0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+8]==' '))
        while (i<j+8) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}

int AnaliticVivod::if0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+2]==' '))
        while (i<j+2) {
            printf("\033[1;32m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::else0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&((mas[i+4]==' ')||(mas[i+4]=='\n')))
        while (i<j+4) {
            printf("\033[1;32m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}

int AnaliticVivod::for0(int i){ 
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&((mas[i+3]==' ')||(mas[i+3]=='(')||(mas[i+3]=='\n')))
        while (i<j+3) {
            printf("\033[1;32m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::while0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&((mas[i+5]==' ')||(mas[i+5]=='(')||(mas[i+5]=='\n')))
        while (i<j+5) {
            printf("\033[1;32m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::switch0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&((mas[i+6]==' ')||(mas[i+6]=='(')||(mas[i+6]=='\n')))
        while (i<j+6) {
            printf("\033[1;32m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}



int AnaliticVivod::do0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+2]==' '))
        while (i<j+2) {
            printf("\033[1;32m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}



int AnaliticVivod::goto0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+4]==' '))
        while (i<j+4) {
            printf("\033[1;32m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::case0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&(mas[i+4]==' '))
        while (i<j+4) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}


int AnaliticVivod::scanf0(int i){
    while ((mas[i]!='(')&&(mas[i]!='"')){
        printf("\033[1;36m%c",mas[i]);
        i+=1;
    }
    return i;
}


int AnaliticVivod::odinar(int i){
    printf("\033[1;34m%c",mas[i]);
    i+=1;
    while(mas[i]!='\u0027'){
        printf("\033[1;34m%c",mas[i]);
        i++;
    }
    if(mas[i]=='\u0027'){
        printf("\033[1;34m%c",mas[i]);
        i+=1;
    }
    return i;
}


int AnaliticVivod::void0(int i){
    int j=i;
    if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&((mas[i+4]==' ')||(mas[i+4]==')')))
        while (i<j+4) {
            printf("\033[1;35m%c\033[0m",mas[i]);
            i++;
        }
    
    return i;
}

