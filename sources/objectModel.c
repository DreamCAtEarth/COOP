#include "objectModel.h"

static struct exception exception;
static struct simplyLinkedList list = {.first = NULL, .size = 0};

static size_t pack(void *, unsigned char *, struct class *);
static size_t unpack(unsigned char *, void *, struct class *);
static void print(void *class, struct class *);

void *(new)(struct new_args *args)
{
    void extractLengths(const char *string, int numberOfDimensions, size_t dimensions[numberOfDimensions])
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
    int countDimensions(const char *string)
    {
        int count = 0;
        for(int i=0; string[i]; ++i) if(string[i] == '[') ++count;
        return count;
    }
    struct object *object = NULL;
    size_t sizeToAlloc = args->getSize(&args->class);
    int dimensions = countDimensions(args->strDimensionsAndLengths);
    size_t *lengths = NULL;

    if(dimensions > 0)
    {
        try {
            lengths = malloc(sizeof(size_t) * (unsigned long long) dimensions);
            allocationWellDone(&exception, lengths);
        }
        catch(badAllocationException)
        {
            printf("%s\n", exception.message);
            garbageCollector();
            exit(0);
        } endTry
        extractLengths(args->strDimensionsAndLengths, dimensions, lengths);
        for(int i = 1; i <= dimensions; ++i) sizeToAlloc *= lengths[i - 1];
    }

    try {
        object = malloc(sizeof(struct object) + sizeToAlloc);
        allocationWellDone(&exception, object);
    }
    catch(badAllocationException)
    {
        printf("%s\n", exception.message);
        garbageCollector();
        exit(0);
    } endTry
    *object = (struct object)
    {
        .destructor = args->destructor,
        .name = args->objectName,
        .class = args->class,
        .instance = object + 1,
        .dimensions = dimensions,
        .lengths = lengths,
        .totalSize = sizeToAlloc
    };
    addOnHead(&list, object);
    args->constructor(object->instance, args->instance_args);
    return object->instance;
}

struct object *(find)(void *object)
{
    struct object *metadata = NULL;
    void **instance = (void **) object;
    try {
        metadata = *instance - sizeof (struct object);
        objectWellFound(&exception, *instance, metadata->instance);
    }
    catch(objectMetadataNotFoundException)
    {
        printf("%s\n", exception.message);
        garbageCollector();
        exit(0);
    } endTry

    return metadata;
}

void (delete)(void *object)
{
    struct simplyLinkedListNode *node = list.first;
    node->object = find(object);
    node->object->destructor();
    if(node->object->dimensions > 0 && node->object->lengths != NULL) free(node->object->lengths);
    free(node->object);
    deleteOnHead(&list, node);
}

void (reflex)(struct class *elementsToReflect)
{
    elementsToReflect->pack = pack;
    elementsToReflect->unpack = unpack;
    elementsToReflect->print = print;
}

size_t (getLength)(void *object)
{
    size_t length = 1;
    struct object *metadata = find(&object);

    if(metadata->dimensions > 0)
        for(int i = 1; i <= metadata->dimensions; ++i) length *= metadata->lengths[i - 1];

    return length;
}

void (garbageCollector)(void)
{
    while(list.first != NULL) delete(list.first->object);
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

static void print(void *class, struct class *elementsToReflect)
{
    void printBuffer(unsigned char *buffer, size_t size)
    {
        for (size_t j = 0; j < size; ++j) printf(" %02x", buffer[j]);
    }
    size_t num_members = elementsToReflect->numAttributes + elementsToReflect->numMethods;
    printf("%s:\n", elementsToReflect->name);
    for (size_t i = 0; i < num_members; ++i)
    {
        // %I64u for minGW using unsigned int of 64 bits
        // %zu or %llu for gcc in a real linux machine
        printf("\t%s: %I64u %I64u =", elementsToReflect->memberNames[i], elementsToReflect->offsets[i], elementsToReflect->sizes[i]);
        printBuffer(((unsigned char *) class) + elementsToReflect->offsets[i], elementsToReflect->sizes[i]);
        puts("");
    }
}
