#define private_ddUKsuMN
#include MYSELF

#define namespace_vlDzoKUd
#include MYSPACE

CLASS_SETTER
(
    (INHERIT(kGAzHwmx, Object)),
    .absCustom = absCustom,
    .useCustom = useCustom
)

INTERNAL void constructor(Id *this, Overloader *args)
{
#ifdef REFLEXIVITY
    struct object *metadata = findMetadata_;
    metadata->getClass = getClass;
#endif
    Overloads((This *) this, args);
}

INTERNAL void destructor(bool freeParents)
{
    destructorOfObject(freeParents);
    if(freeParents)
        free(self);
}

static void Overloads(This *this, Overloader *args)
{
    struct object *metadata = findMetadata_;
    size_t numberOfElements = (metadata->settings[isArray])
        ? metadata->array->size
        : args->numberOfSubInstancesConcerned+1;
    for(size_t i=0; i < numberOfElements; ++i)
    {
        switch(args->options)
        {
            case new_o1 :
                (this+i)->Object.publicAttribute = args->_new_o1.arg1;
                (this+i)->Object.packageAttribute = args->_new_o1.arg2;
                (this+i)->Object.protectedAttribute = args->_new_o1.arg3;
                break;
            case new_o2 :
                (this+i)->Object.alternativePublicAttribute = args->_new_o2.arg1;
                (this+i)->Object.alternativePackageAttribute = args->_new_o2.arg2;
                (this+i)->Object.alternativeProtectedAttribute = args->_new_o2.arg3;
                break;
            case new_ :
                (this+i)->Object.publicAttribute = "default public";
                (this+i)->Object.packageAttribute = "default package";
                (this+i)->Object.protectedAttribute = "default protected";
                (this+i)->Object.alternativePublicAttribute = 4;
                (this+i)->Object.alternativePackageAttribute = 6.99f;
                (this+i)->Object.alternativeProtectedAttribute = 'u';
                break;
        }
    }
}

static void absCustom(void)
{

}

static void useCustom(void)
{

}

#ifdef REFLEXIVITY
CLASS_GETTER

#endif

#ifdef IS_OVERRIDDEN
static char *getProtectedAttribute(This * this)
{
    this->Object.protectedAttribute = "overridden protected attribute !";
    return this->Object.protectedAttribute;
}
#endif
