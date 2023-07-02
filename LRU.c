#include <stdio.h>
#include <stdlib.h>

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    cache->table = calloc(capacity, sizeof(Node*));
    return cache;
}

void moveToHead(LRUCache *cache, Node *node) {
    if (node == cache->head) return;

    if (node == cache->tail) {
        cache->tail = node->prev;
        cache->tail->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    node->prev = NULL;
    node->next = cache->head;
    cache->head->prev = node;
    cache->head = node;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node *node = obj->table[key];
    if (node == NULL) return -1;

    moveToHead(obj, node);
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node *node = obj->table[key];
    if (node != NULL) {
        node->value = value;
        moveToHead(obj, node);
        return;
    }

    if (obj->size == obj->capacity) {
        obj->table[obj->tail->key] = NULL;

        if (obj->capacity == 1) {
            free(obj->tail);
            obj->head = NULL;
            obj->tail = NULL;            
        } else {
                        Node *newTail = obj->tail->prev;
            newTail->next = NULL;

            free(obj->tail);
            obj->tail = newTail;            
        }

        obj->size--;
    }

    node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;

    node->prev = NULL;
    node->next = obj->head;

    if (obj->head != NULL) {
        obj->head->prev = node;
    }

    obj->head = node;

    if (obj->tail == NULL) {
        obj->tail = node;
    }

    obj->table[key] = node;
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    Node *node = obj->head;
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }
    free(obj->table);
    free(obj);
}

