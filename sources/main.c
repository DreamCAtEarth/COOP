#include <stdio.h>

#include "Object.h"

#include "objectModel.h"

#include "overriding.h"

int main(void)
{
    start();

    Object *object1 = newObject();
    Object *object2 = newObject("petit Objet", "petit Objet 2", "petit Objet 3");
    Object *object3 = newObject("petit Objet 4", "petit Objet 5");
    Object *object4 = newObject("petit Objet 6");

    printf("%s\n",object->getPrivateAttribute(object1));
    printf("%s\n",object->getPrivateAttribute(object2));
    printf("%s\n",object->getProtectedAttribute(object2));
    printf("%s\n",object2->publicAttribute);
    printf("%s\n",object->getPrivateAttribute(object3));
    printf("%s\n",object->getPrivateAttribute(object4));

    end();

    return 0;
}