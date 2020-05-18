#include "objectModel.h"

static int countDimensions(const char *);
static void extractLengths(const char *, int, size_t []);
static void printBuffer(unsigned char *, size_t);
static size_t pack(void *, unsigned char *, struct class *);
static size_t unpack(unsigned char *, void *, struct class *);
static void printAll(void *class, struct class *);

void *(new)(struct new_args *args)
{
    size_t sizeToAlloc = args->getSize(NULL);

    int dimensions = countDimensions(args->strDimensionsAndLengths);
    size_t *lengths = NULL;
    if(dimensions > 0)
    {
        lengths = malloc(sizeof(size_t) * (unsigned long long) dimensions);
        extractLengths(args->strDimensionsAndLengths, dimensions, lengths);

        for(int i = 1; i <= dimensions; ++i)
        {
            assert(lengths[i - 1]);
            sizeToAlloc *= lengths[i - 1];
        }
    }
    struct object *object = malloc(sizeof(struct object) + sizeToAlloc);
    *object = (struct object)
            {
                    .destructor = args->destructor,
                    .name = args->objectName,
                    .instance = object + 1,
                    .dimensions = dimensions,
                    .lengths = lengths,
                    .totalSize = sizeToAlloc
            };
    args->constructor(object->instance, args->instance_args);
    return object->instance;
}

struct object *(find)(void *object)
{
    void **instance = (void **) object;

    if (*instance == NULL) return NULL;
    struct object *metadata = *instance - sizeof (struct object);
    assert(*instance == metadata->instance); // instance shall be a pointer returned by new

    return metadata;
}

void (delete)(void *object)
{
    void **instance = object;

    if (*instance == NULL) return;
    struct object *metadata = *instance - sizeof (struct object);
    assert(*instance == metadata->instance);
    metadata->destructor();

    if(metadata->dimensions > 0 && metadata->lengths != NULL)
        free(metadata->lengths);
    free(metadata);
}

void (reflex)(struct class *elementsToReflect)
{
    elementsToReflect->printBuffer = printBuffer;
    elementsToReflect->pack = pack;
    elementsToReflect->unpack = unpack;
    elementsToReflect->printAll = printAll;
}

static int countDimensions(const char *string)
{
    int count = 0;
    for(int i=0; string[i]; ++i) if(string[i] == '[') ++count;
    return count;
}

static void extractLengths(const char *string, int numberOfDimensions, size_t dimensions[numberOfDimensions])
{
    size_t number = 0;
    int j = 0;
    for(int i = 0; string[i] || j < numberOfDimensions; ++i)
    {
        switch(string[i])
        {
            case 48 ... 57 : // 1 to 9
                if(number == 0) number = ((size_t) (string[i] - 48));
                else number = number * 10 + ((size_t) (string[i] - 48));
                break;
            case 91 : // [
                number = 0;
                break;
            case 93 : // ]
                dimensions[j] = number;
                ++j;
                break;
            default:
                break;
        }
    }
}

static void printBuffer(unsigned char *buffer, size_t size)
{
    for (size_t j = 0; j < size; ++j)
        printf(" %02x", buffer[j]);
}

static size_t pack(void *class, unsigned char *buffer, struct class *elementsToReflect)
{
    size_t pos = 0, num_members = elementsToReflect->numAttributes + elementsToReflect->numMethods;
    for (size_t i = 0; i < num_members; ++i)
    {
        memcpy(buffer+pos, ((unsigned char*)class)+elementsToReflect->offsets[i], elementsToReflect->sizes[i]);
        pos += elementsToReflect->sizes[i];
    }
    return pos;
}

static size_t unpack(unsigned char *buffer, void *class, struct class *elementsToReflect)
{
    size_t pos = 0, num_members = elementsToReflect->numAttributes + elementsToReflect->numMethods;
    for (size_t i = 0; i < num_members; ++i)
    {
        memcpy(((unsigned char*)class)+elementsToReflect->offsets[i], buffer+pos, elementsToReflect->sizes[i]);
        pos += elementsToReflect->sizes[i];
    }
    return pos;
}

static void printAll(void *class, struct class *elementsToReflect)
{
    size_t num_members = elementsToReflect->numAttributes + elementsToReflect->numMethods;
    printf("%s:\n", elementsToReflect->name);
    for (size_t i = 0; i < num_members; ++i)
    {
        // %I64u for minGW using unsigned int of 64 bits
        // %zu or %llu for gcc in a real linux machine
        //printf("\t%s: %I64u %I64u =", elementsToReflect->memberNames[i], elementsToReflect->offsets[i], elementsToReflect->sizes[i]);
        printBuffer(((unsigned char *) class) + elementsToReflect->offsets[i], elementsToReflect->sizes[i]);
        puts("");
    }
}
