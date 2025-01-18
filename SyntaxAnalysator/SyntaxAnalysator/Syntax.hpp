//
//  Syntax.hpp
//  SyntaxAnalysator
//
//  Created by Андрей Макаров on 14.12.2023.
//

#ifndef Syntax_hpp
#define Syntax_hpp
#include<istream>
#include <stdio.h>
class Syntax{
        char *mas;
        int r,kol;
    void skobka();
    void skobkamain();
    void skobkaif();
    void skobkaarif();
    void skobkafor();
    void skobkawhile();
    void skobkaswitch();
public:
    Syntax(char*);
    void proverka(void);
};
#endif /* Syntax_hpp */
