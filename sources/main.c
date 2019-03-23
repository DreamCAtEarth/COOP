#include <stdio.h>

#include "DerivedObject.h"

#include "objectModel.h"

int main(void)
{
    start();

    DerivedObject *derivedObject1 = newDerivedObject("yeah","marche !");
    printf("%s\n", derivedObject->getProtectedAttribute(derivedObject1));
    printf("%s\n", derivedObject->getPrivateAttribute(derivedObject1));
    printf("%s\n", derivedObject->getClassName(derivedObject));

    end();

    return 0;
}