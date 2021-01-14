//
//  main.c
//  Hw4_ss
//
//  Created by Or Trabelsi on 05/01/2021.
//

#include <stdio.h>
#include "frequency.h"

int main(int argc, char const *argv[]) {
        
        
    if(argc<=1){
        frequencyp(0);
    }
    else if(*argv[1]=='r') {
        frequencyp(1);
    }
    
    
    
    
    return 0;
}
