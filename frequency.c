//
//  frequency.c
//  Hw4_ss
//
//  Created by Or Trabelsi on 05/01/2021.
//

#include "frequency.h"
#include <stdlib.h>




//reads from the file while the is more to read and fills the tree bt PutInTree function.
// then checks if we need to print it reversed or normall and print it how it should be.
// we also check if the letters are lowered case and if not we lower case them.
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

//frees the memory 
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
//gets a char and a node if the char is exist already at the node array we return the node that we need
// else we create a new node we that char and put it in the node array and return the new node.
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
//prints the words that are in the tree in a dicionary order from a to z and every word we print with the number of times
// the word was at the text.
//going from the root to his childrens array from 0 to NUM_LETTERS and if its not null we send it
// in a recursion to the function ro and by that we get the right order.
void print(Node* root, char *s , int i){
    if(isempty(root)){
        
        s[i] = '\0';
        printf("%s %lu\n", s ,root ->count);
        return;
    }
    else if(root ->bol == 1){
        s[i] = '\0';
        printf("%s %lu\n", s ,root ->count);
    
    }
    
    for (int j =0 ; j< NUM_LETTERS; j++) {
        if(root -> children[j] != (void *)0){
            s[i] = root -> children[j] -> Letter;
            print(root -> children[j], s, i+1);
        }
    }
    
    
}
//workd just like the function above but we are going from the last letter to the first.
void printr(Node* root , char* s , int i){
    if(isempty(root)){
        
        s[i] = '\0';
        printf("%s %lu\n", s ,root ->count);
        return;
    }
    else if(root ->bol == 1){
        s[i] = '\0';
        printf("%s %lu\n", s ,root ->count);
    
    }
    
    for (int j =NUM_LETTERS-1; j>=0 ; j--) {
        if(root -> children[j] != (void *)0){
            s[i] = root -> children[j] -> Letter;
            printr(root -> children[j], s, i+1);
        }
    }
    
    
}

//returns 1 if there arent nodes at the given node array and 0 otherwise.
int isempty(Node* node){
    for (int i =0; i<NUM_LETTERS ; i++) {
        if(node ->children[i]) return 0;
    }
    return 1;
    
    
    
}

// creates a new node with the given char.
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
