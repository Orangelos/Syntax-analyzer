//
//  AnaliticVivod.hpp
//  SyntaxAnalysator
//
//  Created by Андрей Макаров on 10.12.2023.
//

#ifndef AnaliticVivod_hpp
#define AnaliticVivod_hpp
#include <stdio.h>
#include<iostream>
class AnaliticVivod{
    char *mas;
    int r;
    int t=0;
    int mnogoscobok=0;
    int include(int);
    int int0(int);
    int scobka(int);
    int kovicki(int);
    int pf(int);
    int oshibka(int);
    int float0(int);
    int char0(int);
    int long0(int);
    int short0(int);
    int sign0(int);
    int unsigned0(int);
    int if0(int);
    int void0(int);
    int break0(int);
    
    
    int else0(int);
    int for0(int);
    int while0(int);
    int switch0(int);
    int do0(int);
    int goto0(int);
    int case0(int);
    
    int scanf0(int);
    int odinar(int);
public:
    AnaliticVivod(char*);
    void vivod();
};




#endif /* AnaliticVivod_hpp */
