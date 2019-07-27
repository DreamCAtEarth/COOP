#include <stdio.h>

#include "coop/DerivedObject.h"

#include "objectModel.h"

int main(void)
{
    start();

    coop_DerivedObject *derivedObject1 = coopDerivedObject("yeah","marche !","Gilets jaunes");
    printf("%s\n", coopDerivedObject->getProtectedAttribute(derivedObject1));
    printf("%s\n", coopDerivedObject->getPrivateAttribute(derivedObject1));
    printf("%s\n", coopDerivedObject->getClassName(coopDerivedObject));

    end();

    return 0;
}