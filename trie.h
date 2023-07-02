#define TRIE.H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode { struct TrieNode *children[ALPHABET_SIZE]; bool isEndOfWord; } TrieNode;

typedef struct { TrieNode *root; } Trie;

Trie* trieCreate();

void trieInsert(Trie* obj, char * word);

bool trieSearch(Trie* obj, char * word);

bool trieStartsWith(Trie* obj, char * prefix);

void trieFree(Trie* obj);
 
