#include <stdio.h>
#include "New.h"
#include "Object.h"
#include "Set.h"

int main(void) {
    const void *Set;
    const void *Object;

    void *set = new(Set);
    void *elementA = addElement(set, new(Object));
    void *elementB = addElement(set, new(Object));
    void *elementC = new(Object);

    if (containsElement(set, elementA) && containsElement(set, elementB)) {
        puts("ok");
    }
    if (containsElement(set, elementC)) {
        puts("contains?");
    }
    if (differs(elementA, addElement(set, elementA))) {
        puts("differs?");
    }
    if (containsElement(set, removeElement(set, elementA))) {
        puts("remove?");
    }
    delete(removeElement(set, elementB));
    delete(removeElement(set, elementC));
    return 0;
}
