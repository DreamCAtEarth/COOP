#define private_BwXbIZdw
#include MYSELF

#define namespace_nnVYoBNR
#include MYSPACE

CLASS_SETTER
(
    (),
    getValue,
    setValue
)

INTERNAL void constructor(UNUSED Id *this)
{

}

INTERNAL void destructor(bool freeParents)
{
    if(freeParents)
        free(self);
}

static bool getValue(This *this)
{
    return this->value;
}

static void setValue(This *this, bool newValue)
{
    this->value = newValue;
}
