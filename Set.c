#include <assert.h>
#include "Set.h"
#include "New.h"
#include "Object.h"

#if !defined MANY || MANY < 1
#define MANY 10
#endif

static int heap[MANY];

void *new(const void *type, ...) {
    int *pointer; // &heap[1..]
    for (pointer = heap + 1; pointer < heap + MANY; ++pointer) {
        if (!*pointer) {
            break;
        }
    }
    assert(pointer < heap + MANY);
    *pointer = MANY;
    return pointer;
}

void delete(void *_item) {
    int *item = _item;
    if (item) {
        assert(item > heap && item < heap + MANY);
        *item = 0;
    }
}

void *addElement(void *_set, const void *_element) {
    int *set = _set;
    const int *element = _element;
    assert(set > heap && set < heap + MANY);
    assert(*set == MANY);
    assert(element > heap && element < heap + MANY);
    if (*element == MANY) {
        *(int *) element = set - heap;
    } else {
        assert(*element == set - heap);
    }
    return (void *) element;
}

void *findElement(const void *_set, const void *_element) {
    const int *set = _set;
    const int *element = _element;
    assert(set > heap && set < heap + MANY);
    assert(*set == MANY);
    assert(element > heap && element < heap + MANY);
    assert(*element);
    return *element == set - heap ? (void *) element : 0;
}

bool containsElement(const void *_set, const void *_element) {
    return findElement(_set, _element) != 0;
}

void *removeElement(void *_set, const void *_element) {
    int *element = findElement(_set, _element);
    if (element) {
        *element = MANY;
    }
    return element;
}

bool differs(const void *a, const void *b) {
    return a != b;
}