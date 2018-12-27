#pragma once

/* Comportement des exceptions :
info : c'est bon, mais c'est pas une bonne façon de faire, ce n'est pas obligé d'être corrigé

warning : ça présente des risques de ne pas être bon et ça doit être corrigé

error : c'est pas bon mais le programme peut continuer

interruption : tout doit s'arrêter avant de faire autre chose
 * */

typedef struct Info Info;
typedef struct Warning Warning;
typedef struct Error Error;
typedef struct Interruption Interruption;

struct Interruption
{
    int id;
    char *name;
    char *description;
};

void throwExceptionNotAllocatedClass(void);
void throwExceptionNotAllocatedInstance(void);