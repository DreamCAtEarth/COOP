#include "coop/coop.h"
#include "util/util.h"

int main(void)
{
    new(YPnOLrQT, object1, [2][5]);
    new(KPLGWrfu, object2, , o2, 3, 4.4f, 'p', 5.7);

    vlDzoKUd.Object->setProtectedAttribute(&(*object1)[1][1].Derived.Object, "salut la compagnie 3 !");
    for(int i = 0; i < 2; ++i)
    {
        for(int j=0; j < 5; ++j)
        printf("attribut protégé : %s\n", vlDzoKUd.Object->getProtectedAttribute(&(*object1)[i][j].Derived.Object));
    }
    printf("Nom de la classe : %s\n", vlDzoKUd.Object->getClassName(vlDzoKUd.Object));

    kdzvSGAN.Object->setAlternativePrivateAttribute(object2, 8.8);
    printf("attribut privé alternatif : %f\n", kdzvSGAN.Object->getAlternativePrivateAttribute(object2));

    return 0;
}
