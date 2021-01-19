//
//  main.c
//  Hw4_ss
//
//  Created by Or Trabelsi on 05/01/2021.
//

#include <stdio.h>
#include "frequency.h"

int main(int argc, char const *argv[]) {
        
  // if enterd frequency only send to frequencyp with 0 else if enterd frequency r send to frequencyp with 1.(this arg make the metod print revers)
    if(argc<=1){
        frequencyp(0);
    }
    else if(*argv[1]=='r') {
        frequencyp(1);
    }
    
    
    
    
    return 0;
}
