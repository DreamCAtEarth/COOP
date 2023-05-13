#include <objectModel.h>

struct globalEnv gEnv;

static _Alignas(max_align_t) struct staticMemory staticMemory;

typedef struct linkedList gContainer_t;
typedef struct linkedListNode gElement_t;
static gContainer_t list = {.size = -1};

static size_t align(size_t element);
static bool objectsAreAllAutoFreed(void *class);
static char_t *doNothing(char_t *string);
static char_t *toUpperCase(char_t *string);
static void printBuffer(uchar_t *buffer, size_t size);

void *(new)(struct instantiation *args)
{
    struct type type = {0, "", 0, 0};
    size_t sizeToAlloc = args->getSize(&args->class, &type);

    if(args->settingsObject[isArray])
    {
        args->array->memory = sizeToAlloc * args->array->size;
        args->array->type = (__typeof__(type))
        {
            type.size,
            type.name,
            type.id,
            type.length
        };
        sizeToAlloc = args->array->memory;
    }

    struct object *object = (alloc)(sizeof *object + sizeToAlloc + sizeof(gElement_t));
    *object = (__typeof__(*object))
    {
        args->destructor,
        NULL,
        args->array,
        args->objectName,
        args->class,
        object + Offset1,
        object + Offset1,
        sizeToAlloc,
        {
            args->settingsObject[hasDestructor],
            args->settingsObject[isAutoFreed],
            args->settingsObject[isArray],
            args->settingsObject[hasScopeEnvironment]
        }
    };
    initContainer(list)(&list);
    list.addOnHead(&list, object->node, object);
    args->constructor(object->instance, args->instanceArgs);
    return object->instance;
}

void *(alloc)(size_t size)
{
    void *memory = 0;
    try(allocateMemory)
        throws(emptySize, allocateMemoryException, size);
        memory = malloc(size);
        throws(badAllocation, allocateMemoryException, memory, size, mSize(memory));
    catch(emptySize)
        goto sameStep;
    catch(badAllocation)
        sameStep:printf(S_STR, currentStream.message);
        garbageCollector();
        exit(EXIT_FAILURE);
    stop
    return memory;
}

static size_t align(const size_t element)
{
    return (element % alignMax == 0) ? element : element + alignMax - element % alignMax;
}

void *(allocStatic)(size_t dataBlock)
{
    const size_t memoryRequired = align(headerBlock + dataBlock);
    try(allocateStaticMemory)
        throws(wrongSize, allocateStaticMemoryException, dataBlock, memoryRequired, &staticMemory);
    catch(bigSingleAllocation)
        return &staticMemory.available[0];
    catch(wrongSize)
        printf(S_STR, currentStream.message);
        return (alloc)(dataBlock);
    stop

    staticMemory.allocated += memoryRequired;
    size_t indexMemory = staticMemory.allocated - memoryRequired + headerBlock;
    for(size_t i = 0, j = headerBlock / 2, k = headerBlock / 2; i < headerBlock; ++i)
    {
        size_t headerIndex = staticMemory.allocated - memoryRequired + i;
        if(j)
        {
            --j;
            if(indexMemory >= (size_t) pow(pow((double) biByte, (double) CHAR_BIT), (double) j))
                staticMemory.available[headerIndex] = (unsigned char) (indexMemory >> CHAR_BIT * j & ((size_t) pow((double) biByte, (double) CHAR_BIT) - 1));
        }
        else if(k)
        {
            --k;
            if(dataBlock >= (size_t) pow(pow((double) biByte, (double) CHAR_BIT), (double) k))
                staticMemory.available[headerIndex] = (unsigned char) (dataBlock >> CHAR_BIT * k & ((size_t) pow((double) biByte, (double) CHAR_BIT) - 1));
        }
    }
    return &staticMemory.available[indexMemory];
}

void (freeStatic)(void *memoryAllocated)
{
    try(freeStaticMemory)
        throws(bigSingleDesallocation, freeStaticMemoryException, &staticMemory);
        __typeof__(*staticMemory.available) header[headerBlock] = {0};
        throws(invalidDataArgument, freeStaticMemoryException, memoryAllocated);
        size_t memoryToFree = 0;
        size_t indexMemoryToFree = 0;
        for(size_t i = 0, j = 0; i < headerBlock; ++i)
        {
            header[i] = *((__typeof__(*staticMemory.available) *) memoryAllocated - (i+1));
            if(i >= headerBlock / 2)
            {
                indexMemoryToFree += header[i] * (size_t) pow(pow((double) biByte, (double) CHAR_BIT), (double) j);
                ++j;
            }
            else
                memoryToFree += header[i] * (size_t) pow(pow((double) biByte, (double) CHAR_BIT), (double) i);
        }
        memoryToFree += headerBlock;
        indexMemoryToFree -= headerBlock;

        if(memoryToFree <= headerBlock)
            return;

        staticMemory.bigSingleAllocated = false;
        for(size_t i = indexMemoryToFree; i < memoryToFree; ++i)
            if(staticMemory.available[i])
                staticMemory.available[i] = 0;
        staticMemory.allocated -= memoryToFree;
    catch(bigSingleDesallocation)
        printf(S_STR, currentStream.message);
    catch(invalidDataArgument)
        printf(S_STR, currentStream.message);
    catch(exception3)
    stop
}

void *(find)(void *member, size_t size, size_t offset)
{
    unsigned char **pointerToMember = member;
    unsigned char *pointerToContainerToFind = *pointerToMember - size * offset;
    void *pointerFound = pointerToContainerToFind;
    return pointerFound;
}

void (delete)(void *instance)
{
    gElement_t *node = (instance) ? list.getNodeFromObject(&list, find(instance, sizeof(struct object), (size_t) Offset1)) : list.first;
    if(node->object->getClass)
    {
        node->object->getClass()->numObjects--;
        if(!node->object->getClass()->numObjects && node->object->settings[hasDestructor])
            node->object->destructor(true);
        else if(!node->object->getClass()->numObjects && !node->object->settings[hasDestructor])
            free(node->object->class);
    }
    else
        if(objectsAreAllAutoFreed(node->object->class))
            (node->object->settings[hasDestructor]) ? node->object->destructor(true) : free(node->object->class);
    (!instance) ? list.delOnHead(&list) : list.delOnNode(&list, node);
    struct object *object = node->object;
    free(object);
}

unsigned int (setTypeId)(const char *typeString)
{
    unsigned int id = 0;
    for(int i=0; typeString[i]; ++i)
        id += (unsigned int) typeString[i];
    return id;
}

void (showArrayInfos)(const struct genericArray *array)
{
    printf("calculated sizes : "ZU_STR" element(s) occupying "ZU_STR" bytes\n", array->size, array->memory);
    array->dimension.size ? printf("Values of dimensions : ") : printf("Values of dimensions : 0");
    for(unsigned int i=0; i < array->dimension.size; ++i)
        printf("%u ", array->dimension.max[i]);
    printf("\nNumber of dimensions : %u\n", array->dimension.size);

    unsigned int restOfSize;
    switch(array->dimension.size)
    {
        case 0 :
            fputs(L_STR("Can't display an array with 0 dimension.\n"), stderr);
            return;
        case 1 :
            for(unsigned int i = 0, n = 1; i < array->dimension.max[0]; printf("%d ", n), ++i, ++n);
            break;
        case 2 :
            for(unsigned int i = 0, n = 1; i < array->dimension.max[0]; ++i, printf("\n"))
                for(unsigned int j = 0; j < array->dimension.max[1]; printf("%d ", n), ++j, ++n);
            break;
        case 3 :
            for(unsigned int i = 0, n = 1; i < array->dimension.max[0]; ++i, printf("\n"))
                for(unsigned int j = 0; j < array->dimension.max[1]; ++j, printf("\n"))
                    for(unsigned int k = 0; k < array->dimension.max[2]; printf("%d ", n), ++k, ++n);
            break;
        case 4 :
            for(unsigned int i = 0, n = 1; i < array->dimension.max[0]; ++i, printf("\n"))
                for(unsigned int j = 0; j < array->dimension.max[1]; ++j, printf("\n"))
                    for(unsigned int k = 0; k < array->dimension.max[2]; ++k, printf("\t"))
                        for(unsigned int l = 0; l < array->dimension.max[3]; printf("%d ", n), ++l, ++n);
            break;
        default:
            if((array->dimension.max[1] * array->dimension.max[2] * array->dimension.max[3]) == 0)
                restOfSize = (unsigned int) array->size;
            else
                restOfSize = (unsigned int) array->size / (array->dimension.max[1] * array->dimension.max[2] * array->dimension.max[3]);
            for(unsigned int i = 0, n = 1; i < restOfSize; ++i, printf("\n"))
                for(unsigned int j = 0; j < array->dimension.max[1]; ++j, printf("\n"))
                    for(unsigned int k = 0; k < array->dimension.max[2]; ++k, printf("\t"))
                        for(unsigned int l = 0; l < array->dimension.max[3]; printf("%d ", n), ++l, ++n);
            break;
    }
}

static char_t *doNothing(char_t *string)
{
    #if !WCHAR_USAGE
    for(int i=0; string[i];++i)
        if(string[i] > 126 || string[i] < 0 || (128 & string[i])!=0)
        {
            printf(CONSOLE_ERROR_STYLE"character ("C_STR" or %d) not supported."CONSOLE_RESET_STYLE"\n", string[i], string[i]);
        }
    #endif
    return string;
}

static char_t *toUpperCase(char_t *string)
{
    for(int i=0; string[i];++i)
    #if !WCHAR_USAGE
    {
        if(string[i] > 126 || string[i] < 0 || (128 & string[i])!=0)
        {
            printf(CONSOLE_ERROR_STYLE"character ("C_STR" or %d) not supported."CONSOLE_RESET_STYLE"\n", string[i], string[i]);
        }
    #endif
        if(string[i] > 96 && string[i] < 123)
            string[i]-=32;
    #if !WCHAR_USAGE
    }
    #endif
    return string;
}

unsigned int *countOccurrences(struct research *research)
{
    typedef char_t *(*researchCaseHandler)(char_t *string);
    researchCaseHandler rch = !research->settings[isMatchingCase] ? toUpperCase : doNothing;
    rch(research->toParse.data);
    for(unsigned int i=0; i < research->numberOfSearches; ++i)
        research->orders[i] = NULL, research->badString[i] = false;
    bool parseTwice = false;
    unsigned int *m = NULL;

    for(unsigned int i=0; i < research->numberOfSearches; ++i)
    {
        rch(research->toFind[i].data);
        if(research->toFind[i].length > research->toParse.length)
        {
            research->badString[i] = true;
            if(i == research->numberOfSearches-1)
            {
                for(unsigned int j=i; j > 0; --j)
                    if(!research->badString[j]) goto parsing;
                goto end;
            }
        }
        else if(research->toFind[i].length == research->toParse.length && !strcmp(research->toFind[i].data, research->toParse.data))
        {
            research->numberOfOccurrences[i] = research->totalOfOccurrences = 1;
            research->typesAliases = allocStatic(sizeof *research->typesAliases);
            research->orders[i] = allocStatic(sizeof **research->orders);
            research->orders[i][0] = 1;
            research->typesAliases[0] = i;
            goto end;
        }
    }
    parsing:if(parseTwice)
    {
        m = alloca(sizeof *m * research->numberOfSearches);
        for(unsigned int i=0; i < research->numberOfSearches; ++i)
            m[i] = 0;
    }
    for(unsigned int i=0, j=0, k=0, l=0; research->toParse.data[i];)
    {
        if(research->toParse.data[i] == research->toFind[j].data[k] && !research->badString[j])
            ++k, ++i;
        else ++j;
        if(j == research->numberOfSearches)
            j=0, k=0, ++i;
        if(research->numberOfSearches > 1 && k > research->toFind[j].length+1)
            j = (j+1 == research->numberOfSearches) ? 0 : j+1;
        else if(!research->toFind[j].data[k])
        {
            if(!parseTwice)
            {
                ++research->numberOfOccurrences[j];
                ++research->totalOfOccurrences;
            }
            else
            {
                research->orders[j][m[j]] = l+1;
                research->typesAliases[l] = j;
                ++l;
                ++m[j];
            }
            j=0, k=0;
        }
    }
    if(!parseTwice && research->settings[withOrder])
    {
        research->typesAliases = allocStatic(sizeof *research->typesAliases * research->totalOfOccurrences);
        for(unsigned int i = 0; i < research->numberOfSearches; ++i)
            research->orders[i] = (research->numberOfOccurrences[i]) ? allocStatic(sizeof **research->orders * research->numberOfOccurrences[i]) : NULL;
        if(research->numberOfSearches == 1)
            for(unsigned int i = 0; i < research->numberOfOccurrences[0]; ++i)
                research->orders[0][i] = i+1, research->typesAliases[i] = 0;
        else
        {
            parseTwice = true;
            goto parsing;
        }
    }
    end:return research->numberOfOccurrences;
}

char_t *(runtimeCat)(const unsigned int numberOfStringsToCat, char_t *finalString, ...)
{
    size_t bufferSize = 0;
    va_list args;
    va_start(args, finalString);
    char_t **strings = alloca(sizeof *strings * numberOfStringsToCat);
    size_t *stringsLength = alloca(sizeof *stringsLength * numberOfStringsToCat);
    for(unsigned int i=0; i < numberOfStringsToCat; ++i)
    {
        strings[i] = va_arg(args, __typeof__(*strings));
        stringsLength[i] = strlen(strings[i]);
        bufferSize += stringsLength[i];
    }
    int k=0;
    for(unsigned i=0; i < numberOfStringsToCat; ++i)
        for(size_t j=0; j < stringsLength[i]; ++j, ++k)
            finalString[k] = strings[i][j];
    finalString[bufferSize] = 0;
    va_end(args);
    return finalString;
}

void (garbageCollector)(void)
{
    while(list.first)
        delete(NULL);
}

union result *(operate)(struct operation *operation)
{
    try(doingCustomOperation)
        enum ENV_States currentState = Nothing;
        size_t operationLength = strlen(operation->operationString);
        throws(stringOperationNotEnoughLong, doingCustomOperationException, operationLength);
        int *lengths = alloca(sizeof *lengths * operationLength);
        char_t *operationString = operation->operationString;
        throws(stringOperationContainsNotAllowedCharacters, doingCustomOperationException, operationString, operationLength);
        unsigned int numberOfOperands = 0, numberOfSymbols = 0;
        for(int i = 0; operationString[i];)
        {
            if(currentState != Nothing && space_character(operationString[i]))
            {
                currentState = Nothing;
                while(space_character(operationString[i]))
                    lengths[i] = 0, ++i;
            }
            else if(currentState != SupposedOperand && (first_identifier_character(operationString[i]) || (first_literal_number_character(operationString[i])) || literal_string_character(operationString[i])))
            {
                currentState = SupposedOperand;
                int j = i;
                if(first_identifier_character(operationString[j]))
                {
                    do lengths[j] = 0, ++j;
                    while(next_identifier_characters(operationString[j]));
                }
                else if(first_literal_number_character(operationString[j]))
                {
                    do lengths[j] = 0, ++j;
                    while(next_literal_number_characters(operationString[j]));
                }
                else if(literal_string_character(operationString[j]))
                {
                    do lengths[j] = 0, ++j;
                    while(end_string_character(operationString[j]));
                }
                lengths[i] = j - i + 1;
                i = j;
                numberOfOperands++;
            }
            else if(currentState != SupposedOperator && (token_operator_character(operationString[i])))
            {
                currentState = SupposedOperator;
                int j = i;
                while(token_operator_character(operationString[j]))
                    lengths[j] = 0, ++j;
                lengths[i] = -(j - i + 1);
                i = j;
                numberOfSymbols++;
            }
        }
        throws(noSymbolNorSupposedOperandsFounds, doingCustomOperationException, numberOfSymbols, numberOfOperands);

        operation->supposedOperators = alloca(sizeof *operation->supposedOperators * numberOfSymbols);
        operation->supposedOperands = alloca(sizeof *operation->supposedOperands * numberOfOperands);
        operation->script = alloca(sizeof *operation->script * (numberOfOperands+numberOfSymbols));
        for(unsigned int i = 0, l = 0, m = 0; i < operationLength; ++i)
        {
            if(!lengths[i]) continue;
            else if(lengths[i] > 0)
            {
                operation->script[m+l] = Operand;
                size_t length = (size_t) lengths[i];
                char_t *stringOperand = alloca(sizeof *stringOperand * length);
                unsigned int j = i;
                for(size_t k = 0; k < length - 1; ++k, ++j)
                    stringOperand[k] = operationString[j];
                stringOperand[length - 1] = 0;
                operation->supposedOperands[m] = alloca(sizeof **operation->supposedOperands * length);
                strcpy(operation->supposedOperands[m], stringOperand);
                m++;
            }
            else
            {
                operation->script[m+l] = Operator;
                int length = -(lengths[i]);
                char_t *stringSymbol = alloca(sizeof *stringSymbol * (size_t) length);
                unsigned int j = i;
                for(int k = 0; k < length - 1; ++k, ++j)
                    stringSymbol[k] = operationString[j];
                stringSymbol[length - 1] = 0;
                operation->supposedOperators[l] = alloca(sizeof **operation->supposedOperators * (size_t) length);
                strcpy(operation->supposedOperators[l], stringSymbol);
                l++;
            }
        }

        struct object *operands = alloca(sizeof *operands * numberOfOperands);
        for(unsigned int i = 0; i < numberOfOperands; ++i)
        {
            gElement_t *nodeToSearch = list.first;
            bool operandFound = false;
            while(nodeToSearch && !operandFound)
            {
                if(!strcmp(nodeToSearch->object->name, operation->supposedOperands[i]))
                {
                    operandFound = true;
                    throws(operandHasNotOperatorsNorReflexivity, doingCustomOperationException, nodeToSearch->object->getClass, nodeToSearch->object->name);
                    operands[i] = *nodeToSearch->object;
                    unsigned int numberOfOperators = operands[i].getClass()->numOperators;
                    struct operator *operators = alloca(sizeof *operators * numberOfOperators);
                    operands[i].getClass()->getOperator(NULL, operators, 0);
                    bool operatorFound = false;
                    for(unsigned int j = 0; j < numberOfOperators; ++j)
                    {
                        for(unsigned int k = 0; k < numberOfSymbols; ++k)
                        {
                            if(!strcmp(operators[j].symbolisation, operation->supposedOperators[k]))
                            {
                                operatorFound = true;
                                struct object *operandsDoingTheOperation = alloca(sizeof *operandsDoingTheOperation * operators[j].arity);
                                for(unsigned int o = 0; o < operators[j].arity; ++o)
                                    operandsDoingTheOperation[o] = operands[i + o];
                                operators[j].operation(operation->result, operandsDoingTheOperation);
                            }
                        }
                    }
                    throws(operatorNotFound, doingCustomOperationException, operatorFound, L"");
                }
                else
                    nextOperand: nodeToSearch = nodeToSearch->next;
            }
            throws(realOperandNotFound, doingCustomOperationException, operandFound, L"");
            nextOperands:;
        }
    catch(stringOperationNotEnoughLong)
        printf(S_STR, currentStream.message);
    catch(stringOperationContainsNotAllowedCharacters)
        printf(S_STR, currentStream.message);
    catch(noSymbolNorSupposedOperandsFounds)
        printf(S_STR, currentStream.message);
    catch(operandHasNotOperatorsNorReflexivity)
        printf(S_STR, currentStream.message);
        goto nextOperand;
    catch(operatorNotFound)
        printf(S_STR, currentStream.message);
        goto nextOperand;
    catch(realOperandNotFound)
        printf(S_STR, currentStream.message);
        goto nextOperands;
    stop
    return operation->result;
}

static bool objectsAreAllAutoFreed(void *class)
{
    bool areAllAutoFreed = false;
    for(gElement_t *node = list.first; node; node = node->next)
    {
        if(class == node->object->class)
        {
            if(node->object->settings[isAutoFreed] && !areAllAutoFreed)
                areAllAutoFreed = true;
            else if(!node->object->settings[isAutoFreed])
            {
                areAllAutoFreed = false;
                break;
            }
        }
    }
    return areAllAutoFreed;
}

void ENV_(int argc, char **argv)
{
    char *savePtr = NULL;
    gEnv = (struct globalEnv)
    {
        argv[0],
        strtok_r(strrchr(argv[0], '/'), "/", &savePtr),
        (unsigned int) argc-1,
        argv,
        {.void_ = nothing}
    };
    for(unsigned int i = 0, j = 1; i < gEnv.programNArgs && j <= gEnv.programNArgs; ++i, ++j)
        gEnv.programSArgs[i] = argv[j];
    gEnv.programSArgs[gEnv.programNArgs] = NULL;
    currentStream.backTrace = backtrace_create_state(gEnv.path, 0, NULL, NULL);
}

unsigned int findVirtualElement(struct class *elementToReflect, const char *virtualElementName)
{
    unsigned int id = 0;
    unsigned int num_members = elementToReflect->numAttributes + elementToReflect->numMethods + elementToReflect->numOperators + elementToReflect->numOverriddenMethods;
    for(unsigned int i = 0; i < num_members; ++i)
        if(!strcmp(virtualElementName, elementToReflect->memberNames[i]))
            id = i;
    return id;
}

size_t packClass(void *class, uchar_t *buffer, struct class *elementToReflect)
{
    size_t pos = 0;
    unsigned int num_members = elementToReflect->numAttributes + elementToReflect->numMethods + elementToReflect->numOperators + elementToReflect->numOverriddenMethods;
    for(size_t i = 0; i < num_members; ++i)
    {
        memcpy(buffer+pos, ((unsigned char *) class) + elementToReflect->offsets[i], elementToReflect->sizes[i]);
        pos += elementToReflect->sizes[i];
    }
    return pos;
}

size_t unpackClass(uchar_t *buffer, void *class, struct class *elementToReflect)
{
    size_t pos = 0;
    unsigned int num_members = elementToReflect->numAttributes + elementToReflect->numMethods + elementToReflect->numOperators + elementToReflect->numOverriddenMethods;
    for(size_t i = 0; i < num_members; ++i)
    {
        memcpy(((unsigned char *) class) + elementToReflect->offsets[i], buffer + pos, elementToReflect->sizes[i]);
        pos += elementToReflect->sizes[i];
    }
    return pos;
}

static void printBuffer(uchar_t *buffer, size_t size)
{
    for(size_t j = 0; j < size; ++j)
        printf(" %02x", buffer[j]);
}

void printClass(void *class, struct class *elementToReflect)
{
    unsigned int num_members = elementToReflect->numAttributes + elementToReflect->numMethods + elementToReflect->numOperators + elementToReflect->numOverriddenMethods;
    printf(S_STR":\n", elementToReflect->name);
    for(size_t i = 0; i < num_members; ++i)
    {
        printf("\t"S_STR": "ZU_STR" "ZU_STR" =", elementToReflect->memberNames[i], elementToReflect->offsets[i], elementToReflect->sizes[i]);
        printBuffer(((uchar_t *) class) + elementToReflect->offsets[i], elementToReflect->sizes[i]);
        printf("\n");
    }
}
