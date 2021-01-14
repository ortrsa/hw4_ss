//
//  frequency.c
//  Hw4_ss
//
//  Created by Or Trabelsi on 05/01/2021.
//

#include "frequency.h"
#include <stdlib.h>





void frequencyp(int r){
    
    Node *root=new_Node('\0');
    Node *temp=root;
    int max = -1;
    int count =0;
    char word = '\0';
    int flag =1;
    while (flag==1) {
        if(scanf("%c", &word)== EOF){
            flag =0;
        }
        if(flag==1){
        if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')){
        if ((word >= 'A' && word <= 'Z')){
            word = word - 'A' +'a';
        }
           temp =  Put_in_Tree(word , temp);
            count ++;
        }
        }
        if ((word)== '\t'|| (word) == '\n' || (word) == ' ' || flag ==0 ) {
            if(count>max && count!=0){
                max = count;
            }
            if(count!=0){
            count =0;
            temp -> count ++;
            temp -> bol = 1;
            temp = root;
            }
            
        }
    
    }
    
    

    char s[max + 5];
    if(r==0){
    print(root, s, 0);
    }
    else if (r==1){
        printr(root, s, 0);
        
    }
    
    
    free_nodes(root);
    
}


void free_nodes(Node* n)
{
    if (n == (void*)0)
        return;

    for (int i = 0; i < NUM_LETTERS; ++i)
    {
        free_nodes(n->children[i]);
    }

    free(n);
}

Node* Put_in_Tree(char word ,Node* root){
    if (root->children[word-'a']==(void *)0){
        Node *temp = new_Node(word);
        root->children[word-'a'] = temp;
        return temp;
        
    }
    else{
        return root->children[word-'a'];
    }
    
    

}

void print(Node* root, char *s , int i){
    if(isempty(root)){
        
        s[i] = '\0';
        printf("%s \t %lu \n", s ,root ->count);
        return;
    }
    else if(root ->bol == 1){
        s[i] = '\0';
        printf("%s \t %lu\n", s ,root ->count);
    
    }
    
    for (int j =0 ; j< NUM_LETTERS; j++) {
        if(root -> children[j] != (void *)0){
            s[i] = root -> children[j] -> Letter;
            print(root -> children[j], s, i+1);
        }
    }
    
    
}
void printr(Node* root , char* s , int i){
    if(isempty(root)){
        
        s[i] = '\0';
        printf("%s \t %lu \n", s ,root ->count);
        return;
    }
    else if(root ->bol == 1){
        s[i] = '\0';
        printf("%s \t %lu\n", s ,root ->count);
    
    }
    
    for (int j =NUM_LETTERS-1; j>=0 ; j--) {
        if(root -> children[j] != (void *)0){
            s[i] = root -> children[j] -> Letter;
            printr(root -> children[j], s, i+1);
        }
    }
    
    
}


int isempty(Node* node){
    for (int i =0; i<NUM_LETTERS ; i++) {
        if(node ->children[i]) return 0;
    }
    return 1;
    
    
    
}


Node* new_Node(char a){
    Node *n = (Node*)malloc(sizeof(Node));
    n->Letter = a;
    n->count = 0;
    n->bol = 0;
    
    for (int i =0; i<NUM_LETTERS; i++) {
        n ->children[i] = (void *)0;
        
    }
    return n;
}
