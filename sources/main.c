#include <stdio.h>

#include "DerivedObject.h"

int main(void)
{
    ObjectInstance *object1 = NewObject();
    ObjectInstance *object2 = NewObject();
    ObjectInstance *object3 = NewObject();
    ObjectInstance *object4 = NewObject();
    DerivedObjectInstance *derivedObject1 = NewDerivedObject();

    Object->setPrivateAttribute("raconte moi une histoire", object1);
    Object->setPrivateAttribute("j'adore l'argent", object2);
    Object->setPrivateAttribute("nain porte quoi", object3);
    Object->setPrivateAttribute("MDR !!", object4);
    DerivedObject->setPrivateAttribute("LOL !!", derivedObject1);

    printf("%s\n", Object->getPrivateAttribute(object1));
    printf("%s\n", Object->getPrivateAttribute(object2));
    printf("%s\n", Object->getPrivateAttribute(object3));
    printf("%s\n", Object->getPrivateAttribute(object4));
    printf("%s\n", DerivedObject->getPrivateAttribute(derivedObject1));

    Object->delete(object1);
    Object->delete(object2);
    Object->delete(object3);
    Object->delete(object4);
    DerivedObject->delete(derivedObject1);

    return 0;
}