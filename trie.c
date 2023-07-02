#include <stdlib.h>
#include <string.h>
#include <trie.h>

TrieNode *getNode(void) {
    TrieNode *pNode = (TrieNode *)malloc(sizeof(TrieNode)); pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL; return pNode;
}

Trie* trieCreate() { Trie *trie = (Trie *)malloc(sizeof(Trie)); trie->root = getNode(); return trie; }

void trieInsert(Trie* obj, char * word) { int length = strlen(word); int index; TrieNode *pCrawl = obj->root;
    for (int level = 0; level < length; level++) { index = word[level] - 'a'; if (!pCrawl->children[index])
    pCrawl->children[index] = getNode(); pCrawl = pCrawl->children[index]; } pCrawl->isEndOfWord = true; }

bool trieSearch(Trie* obj, char * word) { int length = strlen(word); int index; TrieNode *pCrawl = obj->root;
    for (int level = 0; level < length; level++) { index = word[level] - 'a'; if (!pCrawl->children[index])
    return false; pCrawl = pCrawl->children[index]; } return (pCrawl != NULL && pCrawl->isEndOfWord); }

bool trieStartsWith(Trie* obj, char * prefix){int length = strlen(prefix); int index; TrieNode *pCrawl = obj->root;
    for (int level = 0; level < length; level++) { index = prefix[level] - 'a'; if (!pCrawl->children[index])
    return false; pCrawl = pCrawl->children[index]; } return true; }

void freeNode(TrieNode *node) { for (int i = 0; i < ALPHABET_SIZE; i++) if (node->children[i])
    freeNode(node->children[i]); free(node); }

void trieFree(Trie* obj) { freeNode(obj->root); }
