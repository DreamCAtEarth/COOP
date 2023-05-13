#define private_KPLGWrfu
#include MYSELF

#define namespace_kdzvSGAN
#include MYSPACE

CLASS_SETTER
(
    (),
    setClassName,
    getClassName,
    setPrivateAttribute,
    setAlternativePrivateAttribute,
    getPrivateAttribute,
    getAlternativePrivateAttribute,
    setProtectedAttribute,
    setAlternativeProtectedAttribute,
    getProtectedAttribute,
    getAlternativeProtectedAttribute,
    &operators[circonflex],
    MY_NAME
)

INTERNAL void constructor(Id *this, Overloader *args)
{
#ifdef REFLEXIVITY
    struct object *metadata = findMetadata_;
    metadata->getClass = getClass;
#endif
    Overloads((This *)this, args);
}

INTERNAL void destructor(bool freeParents)
{
    if(freeParents)
        free(self);
}

static void Overloads(This *this, Overloader *args)
{
    struct object *metadata = findMetadata_;
    size_t numberOfElements =
        (metadata->settings[isArray])
        ? metadata->array->size
        : args->numberOfSubInstancesConcerned+1;
    for(size_t i=0; i < numberOfElements; ++i)
    {
        switch(args->options)
        {
            case new_o1 :
                (this+i)->publicAttribute = args->_new_o1.arg1;
                (this+i)->packageAttribute = args->_new_o1.arg2;
                (this+i)->protectedAttribute = args->_new_o1.arg3;
                (this+i)->privateAttribute = args->_new_o1.arg4;
                break;
            case new_o2 :
                (this+i)->alternativePublicAttribute = args->_new_o2.arg1;
                (this+i)->alternativePackageAttribute = args->_new_o2.arg2;
                (this+i)->alternativeProtectedAttribute = args->_new_o2.arg3;
                (this+i)->alternativePrivateAttribute = args->_new_o2.arg4;
                break;
            case new_ :
                *(this+i) = (This)
                {
                    .publicAttribute = "default public",
                    .packageAttribute = "default package",
                    .protectedAttribute = "default protected",
                    .privateAttribute = "default private",
                    .alternativePublicAttribute = 2,
                    .alternativePackageAttribute = 2.4f,
                    .alternativeProtectedAttribute = 'c',
                    .alternativePrivateAttribute = 3.6
                };
                break;
        }
    }
}

#ifdef REFLEXIVITY
CLASS_GETTER

#ifdef HAS_OPERATORS
OPERATOR_GETTER

static union result *circonflexOperation(union result *result, struct object *operandToUse)
{
    This *this = operandToUse[0].instance;
    this->alternativeProtectedAttribute = result->char_ = 'x';
    return result;
}
#endif
#endif

static void setPrivateAttribute(This *this, char *string)
{
    this->privateAttribute = string;
}

static char *getPrivateAttribute(This *this)
{
    return this->privateAttribute;
}

static void setProtectedAttribute(This *this, char *string)
{
    this->protectedAttribute = string;
}

static char *getProtectedAttribute(This *this)
{
    return this->protectedAttribute;
}

static void setClassName(const char *string)
{
    self->className = string;
}

static const char *getClassName(void)
{
    return self->className;
}

static void setAlternativePrivateAttribute(This *this, double floatingNumber)
{
    this->alternativePrivateAttribute = floatingNumber;
}

static double getAlternativePrivateAttribute(This *this)
{
    return this->alternativePrivateAttribute;
}

static void setAlternativeProtectedAttribute(This *this, char character)
{
    this->alternativeProtectedAttribute = character;
}

static char getAlternativeProtectedAttribute(This *this)
{
    return this->alternativeProtectedAttribute;
}
