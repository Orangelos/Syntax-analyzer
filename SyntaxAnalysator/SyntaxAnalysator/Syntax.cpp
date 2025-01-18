//
//  Syntax.cpp
//  SyntaxAnalysator
//
//  Created by Андрей Макаров on 14.12.2023.
//

#include "Syntax.hpp"
Syntax::Syntax(char* m){
    mas=m;
    r=int(strlen(mas));
    
    kol=0;
}
void Syntax::proverka(){
    
      
    

    skobka();
   skobkamain();
    skobkaif();
    skobkaarif();
    skobkafor();
    skobkawhile();
    skobkaswitch();
}

void Syntax::skobka(){
    for(int i=0;i<r;i++){
        
        if((mas[i]=='(')||(mas[i]==')')){
            int j=i,met=0;
            
            while(mas[j-1]!='\n'){
                if(mas[j-1]==' ');
            //       int k=i;
            //       if(mas[j-1]=='=')
            //           met=0;
            //       while(mas[k]!='\n')
            //       {
            //           if((mas[k]!=' ')||(mas[k]!=')'))
            //               met=1;
            //           else
            //               met=0;
            //       }
            //         if(met==0)
            //             break;
            //   }
                else{
                    met=1;
                    
                    break;
                   
                }
                j--;
                
            }
            
           if((mas[i-1]=='=')&&(mas[i+1]==')'))
               met=0;
            if(met==0)
            {   int p=0;
                while(mas[i+1]!='\n'){
                    if(mas[i]=='\x01')
                        p=1;
                    i++;
                }
                if(p==1)
                    goto m1;
                int k=0;
                char mass[]=" \x01 Expected expression or expression result unused \n";
                
             r=int(r+strlen(mass));
              //  mas=(char*)realloc(mas, r*sizeof(char));
                   
                
                
               while(k<strlen(mass)){
                   for(int j=r;j>i;j--){
                      // char h=mas[j+1];
                       mas[j+1]=mas[j];
                       //mas[j]=h;
                   }
                   k++;
            }
                
                int f=0;
                for(int j=i+1;j<=i+strlen(mass);j++){
                    mas[j]=mass[f];
                    f++;
                }
            }
            else
                continue;
          
        m1:;
            }
    
        
            
            
            }
            
            
}


void Syntax::skobkamain(){
    for(int i=0;i<r;i++){
        int met=0;
        if((mas[i]=='(')||(mas[i]==')')||(mas[-1]='n')||(mas[-2]='n')||(mas[-3]='n')||(mas[-4]='n'))
            if((mas[i-1]=='n')&&(mas[i-2]=='i')&&(mas[i-3]=='a')&&(mas[i-4]=='m')){
                
                if(mas[i]=='(')
                    for(int j=i;(j!='{');j++)
                        if(mas[j]==')')
                            met=1;
                        
                if((met==0)||(mas[i]==')')){
                    int k=0;
                    char mass[]=" \x01 Main cannot be declared as global variable          \n";
                    
                   r=int(r+strlen(mass));
                   // mas=(char*)realloc(mas, r*sizeof(char));
                    //r=int(r+strlen(mass));
                    
                   while(k<strlen(mass)){
                       for(int j=r;j>i;j--){
                           mas[j+1]=mas[j];
                      
                       }
                       k++;
                }
                    
                    int f=0;
                    for(int j=i+1;j<=i+strlen(mass);j++){
                        mas[j]=mass[f];
                        f++;
                    }
                    
                    
                }
                       
                
            }
        
    }
}

















void Syntax::skobkaif(){
    
    for(int i=0;i<r;i++){
        int met=1;
        if(((mas[i-1]==' ')||(mas[i-1]=='\n'))&&(mas[i]=='i')&&(mas[i+1]=='f')){
            int j=i+2;
            
            while(mas[j]!='\n'){
                if(mas[j]=='('){
                    met=1;
                    break;
                }
                else
                {
                    met=0;
                    
                }
                j++;
            }
            if(met==0){
                
                while(mas[i+1]!='\n')
                    i++;
                
                
                int k=0;
                char mass[]=" \x01 Expected '(' after 'if'         \n";
                
            r=int(r+strlen(mass));
                //mas=(char*)realloc(mas, r*sizeof(char));
                
                //r=int(r+strlen(mass));
                
                while(k<strlen(mass)){
                    for(int j=r;j>i;j--){
                        mas[j+1]=mas[j];
                        
                    }
                    k++;
                }
                
                int f=0;
                for(int j=i+1;j<=i+strlen(mass);j++){
                    mas[j]=mass[f];
                    f++;
                }
                
            }
            
        }
    }
}




void Syntax::skobkaarif(){
    for(int i=0;i<r;i++){
        if   ( (mas[i+2]!='{')&&(mas[i]=='(') && ((  (mas[i+1]==')')   ||  (mas[i+1]==' ')   ||(mas[i+1]=='+')   ||   (mas[i+1]=='-')  ||(mas[i+1]=='*')||(mas[i-1]==')'))))
        {
            
            
            
            if(((mas[i+1]==')')&&(mas[i-1]!=' ')&&(mas[i-1]!='+')   &&   (mas[i-1]!='-')  &&(mas[i-1]!='*')) ||((mas[i+1]==')')&&(mas[i+2]=='('))){
                
                
                while(mas[i+1]!='\n'){
                    if(mas[i+1]=='\x01')
                        break;
                    i++;
                }
                if(mas[i+1]=='\x01')
                    break;
                int k=0;
                char mass[]=" \x01 Called object type is not a function or function pointer  \n";
                
                r=int(r+strlen(mass));
                // mas=(char*)realloc(mas, r*sizeof(char));
                //r=int(r+strlen(mass));
                
                while(k<strlen(mass)){
                    for(int j=r;j>i;j--){
                        mas[j+1]=mas[j];
                        
                    }
                    k++;
                }
                
                int f=0;
                for(int j=i+1;j<=i+strlen(mass);j++){
                    mas[j]=mass[f];
                    f++;
                    
                    
                }
                
                
                break;
            }
            
            
            
            int h=i+1,l=i-1;
            
            while(mas[l]==' ')
                l--;
            
            
            while(mas[h]!=';')
            {  // printf("SRABOTALO -----%c-----%d----%d \n",mas[i],i,h);
                if(mas[h]==' ')
                    ; //printf("SRABOTALO -----%c-----%d----%d \n",mas[i],i,h)
                else
                    if(mas[h]==')')
                    {
                        
                        while(mas[i+1]!='\n'){
                            if(mas[i+1]=='\x01')
                                break;
                            i++;
                        }
                        if(mas[i+1]=='\x01')
                            break;
                        int k=0;
                        char mass[]=" \x01 Called object type is not a function or expected expression\n";
                        
                        r=int(r+strlen(mass));
                        // mas=(char*)realloc(mas, r*sizeof(char));
                        //r=int(r+strlen(mass));
                        
                        while(k<strlen(mass)){
                            for(int j=r;j>i;j--){
                                mas[j+1]=mas[j];
                                
                            }
                            k++;
                        }
                        
                        int f=0;
                        for(int j=i+1;j<=i+strlen(mass);j++){
                            mas[j]=mass[f];
                            f++;
                        }
                    }
                    else
                        break;
                
                h++;
            }
            
            
            if((mas[l]!='+')&&(mas[l]!='-')&&(mas[l]!='*')&&(mas[l]!='/')&&(mas[l]!='='))
            {
                //printf("SRABOTALO -----%c %c %c-----%d----%d \n",mas[l-5],mas[l],mas[l+3],i,l);
                while(mas[i+1]!='\n'){
                    if(mas[i+1]=='\x01')
                        goto m6;
                    i++;
                }
               
                int k=0;
                char mass[]=" \x01 Called object type is not a function or function pointer  \n";
                
                r=int(r+strlen(mass));
                // mas=(char*)realloc(mas, r*sizeof(char));
                //r=int(r+strlen(mass));
                
                while(k<strlen(mass)){
                    for(int j=r;j>i;j--){
                        mas[j+1]=mas[j];
                        
                    }
                    k++;
                }
                
                int f=0;
                for(int j=i+1;j<=i+strlen(mass);j++){
                    mas[j]=mass[f];
                    f++;
                    
                    
                    
                }
                
            }
        m6:
            ;
            
            
            
            
        }
            
        
        int j=i;
        int met=0;
        if((mas[i]=='(')&&(mas[i+1]!='\u0027')&&(mas[i-1]!='\u0027')&&(mas[i-1]!='(')){
            while((mas[j]!='\n')&&(mas[j]!=EOF)){
               // printf("%c\n",mas[j]);
                if(mas[j]=='(')
                    met++;
                if(mas[j]==')')
                    met--;
                j++;
                
            }
            j=i;
            while((mas[j]!='\n')&&(mas[j]!=EOF)){
                if(mas[j]=='\x01')
                    met=0;
                j++;
            }
            
        }
        if(met>0)
        {
            
            while(mas[i+1]!='\n')
                i++;
            
           
            int k=0;
            char mass[]=" \x01 Expected ')'       \n";
            
           r=int(r+strlen(mass));
           // mas=(char*)realloc(mas, r*sizeof(char));
            //r=int(r+strlen(mass));
            
            while(k<strlen(mass)){
                for(int j=r;j>i;j--){
                    mas[j+1]=mas[j];
                    
                }
                k++;
            }
            
            int f=0;
            for(int j=i+1;j<=i+strlen(mass);j++){
                mas[j]=mass[f];
                f++;
            }
            
            
            
        }
        
        
        if(met<0)
        {
            
            while((mas[j]!='\n')&&(mas[j]!=EOF))
                i++;
            
            //printf("met == %d",met);
            int k=0;
            char mass[]=" \x01 Extraneous '('       \n";
            
            
           // mas=(char*)realloc(mas, (r+strlen(mass))*sizeof(char));
            r=int(r+strlen(mass));
            
            
            while(k<strlen(mass)){
                for(int j=r;j>i;j--){
                    mas[j+1]=mas[j];
                    
                }
                k++;
            }
            
            int f=0;
            for(int j=i+1;j<=i+strlen(mass);j++){
                mas[j]=mass[f];
                f++;
            }
            
        
            
        }
        
        
      // if(mas[i]==')')
      // {
      //     int j=i,metka=1;
      //     while(mas[j]!='\n'){
      //         if(mas[j]=='(')
      //             metka=0;
      //         j++;
      //     }
      //     if(metka==0)
      //     {
      //
      //
      //         while(mas[i+1]!='\n'){
      //             if(mas[i+1]=='\x01')
      //                 goto m7;
      //             i++;
      //         }
      //
      //
      //         //printf("met == %d",met);
      //         int k=0;
      //         char mass[]=" \x01 Expected expression       \n";
      //
      //
      //        // mas=(char*)realloc(mas, (r+strlen(mass))*sizeof(char));
      //         r=int(r+strlen(mass));
      //
      //
      //         while(k<strlen(mass)){
      //             for(int j=r;j>i;j--){
      //                 mas[j+1]=mas[j];
      //
      //             }
      //             k++;
      //         }
      //
      //         int f=0;
      //         for(int j=i+1;j<=i+strlen(mass);j++){
      //             mas[j]=mass[f];
      //             f++;
      //         }
      //
      //     }
      //
      //
      // m7:;
      // }
           
    }
}



    void Syntax::skobkafor(){
        
        for(int i=0;i<r;i++){
            int met=1;
            if(((mas[i-1]==' ')||(mas[i-1]=='\n'))&&(mas[i]=='f')&&(mas[i+1]=='o')&&(mas[i+2]=='r')){
                int j=i+2;
                
                while(mas[j]!='\n'){
                    if(mas[j]=='('){
                        met=1;
                        break;
                    }
                    else
                    {
                        met=0;
                        
                    }
                    j++;
                }
                if(met==0){
                    
                    while(mas[i+1]!='\n')
                        i++;
                    
                    
                    int k=0;
                    char mass[]=" \x01 Expected '(' after 'for'         \n";
                    
                r=int(r+strlen(mass));
                    //mas=(char*)realloc(mas, r*sizeof(char));
                    
                    //r=int(r+strlen(mass));
                    
                    while(k<strlen(mass)){
                        for(int j=r;j>i;j--){
                            mas[j+1]=mas[j];
                            
                        }
                        k++;
                    }
                    
                    int f=0;
                    for(int j=i+1;j<=i+strlen(mass);j++){
                        mas[j]=mass[f];
                        f++;
                    }
                    
                }
                
            }
        }
    }
      //  for(int i=0;i<r;i++)
      //      if((mas[i]=='f')&&(mas[i+1]=='o')&&(mas[i+2]=='r')){
      //          if((mas[i-1]==' ')||(mas[i-1]=='\n'))
      //              if((mas[i+3]==' ')||(mas[i+3]=='('))
      //              {
      //                  int j=i+3;
      //                  while((mas[j]!='(')&&(mas[j]!='\n'))
      //                  {
      //                      if(mas[j]=='\x01')
      //                          break;
      //
      //                      if(mas[i]!=' ')
      //                      {
      //
      //
      //                          while(mas[i+1]!='\n'){
      //                              if(mas[i+1]=='\x01')
      //                                  break;
      //                              i++;
      //
      //                          }
      //
      //                          int k=0;
      //                          char mass[]=" \x01    Expected '(' after 'for'      \n";
      //
      //                          r=int(r+strlen(mass));
      //                          //mas=(char*)realloc(mas, r*sizeof(char));
      //
      //                          //r=int(r+strlen(mass));
      //
      //                          while(k<strlen(mass)){
      //                              for(int j=r;j>i;j--){
      //                                  mas[j+1]=mas[j];
      //
      //                              }
      //                              k++;
      //                          }
      //
      //                          int f=0;
      //                          for(int j=i+1;j<=i+strlen(mass);j++){
      //                              mas[j]=mass[f];
      //                              f++;
      //                          }
      //                      }
      //                      j++;
      //                  }}}
      //
      //
      //
      //
      //
        
        
    
void Syntax::skobkawhile(){
    for(int i=0;i<r;i++){
        int met=1;
        if((mas[i]=='w')&&(mas[i+1]=='h')&&(mas[i+2]=='i')&&(mas[i+3]=='l')&&(mas[i+4]=='e'))
            if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&((mas[i+5]==' ')||(mas[i+5]=='(')||(mas[i+5]=='\n'))){
           // printf("WHILE1");
            int j=i+2;
            
            while(mas[j]!='\n'){
                if(mas[j]=='('){
                    met=1;
                    break;
                }
                else
                {
                    met=0;
                    
                }
                j++;
            }
            if(met==0){
                
                while(mas[i+1]!='\n')
                    i++;
                
                
                int k=0;
                char mass[]=" \x01 Expected '(' after 'while'         \n";
                
            r=int(r+strlen(mass));
                //mas=(char*)realloc(mas, r*sizeof(char));
                
                //r=int(r+strlen(mass));
                
                while(k<strlen(mass)){
                    for(int j=r;j>i;j--){
                        mas[j+1]=mas[j];
                        
                    }
                    k++;
                }
                
                int f=0;
                for(int j=i+1;j<=i+strlen(mass);j++){
                    mas[j]=mass[f];
                    f++;
                }
                
            }
            
        }
    }
}


void Syntax::skobkaswitch(){
    for(int i=0;i<r;i++){
        int met=1;
        if((mas[i]=='s')&&(mas[i+1]=='w')&&(mas[i+2]=='i')&&(mas[i+3]=='t')&&(mas[i+4]=='c')&&(mas[i+5]=='h'))
            if(((mas[i-1]=='\n')||(mas[i-1]=='(')||(mas[i-1]==' '))&&((mas[i+6]==' ')||(mas[i+6]=='(')||(mas[i+6]=='\n'))){
           // printf("WHILE1");
            int j=i+2;
            
            while(mas[j]!='\n'){
                if(mas[j]=='('){
                    met=1;
                    break;
                }
                else
                {
                    met=0;
                    
                }
                j++;
            }
            if(met==0){
                
                while(mas[i+1]!='\n')
                    i++;
                
                
                int k=0;
                char mass[]=" \x01 Expected '(' after 'switch'         \n";
                
            r=int(r+strlen(mass));
                //mas=(char*)realloc(mas, r*sizeof(char));
                
                //r=int(r+strlen(mass));
                
                while(k<strlen(mass)){
                    for(int j=r;j>i;j--){
                        mas[j+1]=mas[j];
                        
                    }
                    k++;
                }
                
                int f=0;
                for(int j=i+1;j<=i+strlen(mass);j++){
                    mas[j]=mass[f];
                    f++;
                }
                
            }
            
        }
    }
}

