#define LRU_H

LRUCache* lRUCacheCreate(int capacity);

void moveToHead(LRUCache *cache, Node *node);

int lRUCacheGet(LRUCache* obj, int key);

void lRUCachePut(LRUCache* obj, int key, int value);

void lRUCacheFree(LRUCache* obj);

typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct LRUCache {
    int capacity;
    int size;
    Node *head;
    Node *tail;
    Node **table;
} LRUCache;

