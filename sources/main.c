#include "coop/coop.h"
#include "util/util.h"

int main()
{
    new(kGAzHwmx, object1, [4][5], o1, "salut 1", "salut 2", "salut 3", "salut 4");
    new(KPLGWrfu, object2, [6], o2, 3, 4.4f, 'p', 5.7);

    vlDzoKUd.Object->setProtectedAttribute(&(*object1)[1][1], "salut la compagnie 3 !");
    for(int i = 0; i < 4; ++i)
    {
        for(int j=0; j < 5; ++j)
        printf("attribut protégé : %s\n", vlDzoKUd.Object->getProtectedAttribute(&(*object1)[i][j]));
    }
    printf("Nom de la classe : %s\n", vlDzoKUd.Object->getClassName(vlDzoKUd.Object));

    kdzvSGAN.Object->setAlternativePrivateAttribute(&(*object2)[4] ,8.8);
    for(int i = 0; i < 6; ++i)
    {
        printf("attribut privé alternatif : %f\n", kdzvSGAN.Object->getAlternativePrivateAttribute(&(*object2)[i]));
    }

    return 0;
}
