#include <iostream>
#include <string>

using namespace std;

int minChar = 0;
string commonPrefix;

struct node {
    char currentCharacter;      
    bool isWord;                
    int maxWeight;
    int numWords = 0;
    int contChar = 0;
    int countWords = 0;
    struct node *children[27];  
}*trie;



void init() {
    trie = new node();
    trie->isWord = false;
    trie->countWords = 0;
    trie->contChar++;
    minChar++;
}



bool searchWord(string word) {   
    node *currentNode =  trie;
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->isWord;
}

bool searchWordandDelete(string word) {   
    node *currentNode =  trie;
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    if (currentNode->isWord) {
        currentNode->isWord = false;
        return true;
    }
    return false;
}


int findWords(string prefix) {   
    node *currentNode =  trie;
    for (int i = 0; i< prefix.length(); i++) {
        int character = prefix[i] - 'a';      
        if(currentNode->children[character] == NULL ) {
           return 0;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->countWords;
}


void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}

int biggestWord(string prefix) {   
    node *currentNode =  trie;
    for (int i = 0; i< prefix.length(); i++) {
        int character = prefix[i] - 'a';       
        if(currentNode->children[character] == NULL ) {
           return 0;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->maxWeight;
}

void insertWord(string word, int w) {  
    node *currentNode =  trie;
    string auxPrefix = "";
    
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';     
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
            currentNode->children[character]->countWords = 0;
            minChar += 1;
            trie->contChar += 1;
            
        } else {
            if (commonPrefix.size() > auxPrefix.size()){
                auxPrefix.push_back(word[i]);
            }
            
        }
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
        currentNode->countWords++;
        currentNode->isWord = false; 
        currentNode->maxWeight = max(w,currentNode->maxWeight);
    }
    currentNode->isWord = true;
    trie->numWords++;
    
    /**
     Actualizamos el commonPrefix
     */
    commonPrefix = auxPrefix;
}


void deleteWord(string word){
    cout<<word<<" deleted: "<<searchWordandDelete(word);
}

int main() {
    init();
    insertWord("avia", 0);
    commonPrefix = "avia";
    insertWord("aviador", 0);
    insertWord("avon", 0);
    insertWord("avion", 0);
    insertWord("pato", 0);
    insertWord("pablo", 0);
    insertWord("a", 0);
    cout<<commonPrefix<<endl;
    cout<<"Word pato exists: "<<searchWord("pato")<<endl;
    deleteWord("pato");
    cout<<"Word pato exists: "<<searchWord("pato")<<endl;
   
}
