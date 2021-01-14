//
//  frequency.h
//  Hw4_ss
//
//  Created by Or Trabelsi on 05/01/2021.
//

#ifndef frequency_h
#define frequency_h

#include <stdio.h>

#define NUM_LETTERS 26

typedef struct Node{
    char Letter;
    long unsigned int count;
    struct Node* children[NUM_LETTERS];
    int bol;
} Node;


Node* Put_in_Tree(char word ,Node* node);
void free_nodes(Node* n);
void frequencyp(int r);
void print(Node* root, char *s , int i);
void printr(Node* root, char* s , int i);
Node* new_Node(char a);
int isempty(Node* node);

#endif /* frequency_h */
