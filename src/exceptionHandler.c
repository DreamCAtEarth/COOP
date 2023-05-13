#include <objectModel.h>

struct stream currentStream;

static int backTrace(UNUSED void *data, uintptr_t programCounter, const char *fileName, int lineNumber, const char *functionName);
static void initScenario(struct exception *newException, ...);

static void emptySize(int *thrown, union exceptionArgs *args);
static void badAllocation(int *thrown, union exceptionArgs *args);

static void wrongSize(int *thrown, union exceptionArgs *args);

static void bigSingleDesallocation(int *thrown, union exceptionArgs *args);
static void invalidDataArgument(int *thrown, union exceptionArgs *args);

static void stringOperationNotEnoughLong(int *thrown, union exceptionArgs *args);
static void stringOperationContainsNotAllowedCharacters(int *thrown, union exceptionArgs *args);
static void noSymbolNorSupposedOperandsFounds(int *thrown, union exceptionArgs *args);
static void operandHasNotOperatorsNorReflexivity(int *thrown, union exceptionArgs *args);
static void realOperandNotFound(int *thrown, union exceptionArgs *args);
static void operatorNotFound(int *thrown, union exceptionArgs *args);

void Exception(struct exception *newException, int scenario)
{
    switch(scenario)
    {
        case allocateMemoryUID :
            initScenario(newException,
                         emptySize,
                         badAllocation);
            break;
        case allocateStaticMemoryUID :
            initScenario(newException,
                         wrongSize);
            break;
        case freeStaticMemoryUID :
            initScenario(newException,
                         bigSingleDesallocation,
                         invalidDataArgument);
            break;
        case doingCustomOperationUID :
            initScenario(newException,
                         stringOperationNotEnoughLong,
                         stringOperationContainsNotAllowedCharacters,
                         noSymbolNorSupposedOperandsFounds,
                         operandHasNotOperatorsNorReflexivity,
                         operatorNotFound,
                         realOperandNotFound);
            break;
        default :
            fputs(L_STR("Try can't start, wrong scenario id.\n"), stderr);
            return;
    }
    newException->type = readyToTry;
}

static void initScenario(struct exception *newException, ...)
{
    va_list args;
    va_start(args, newException);
    for(int i = 0; i < newException->numberOfCases; ++i)
        newException->throw[i] = va_arg(args, __typeof__(*newException->throw));
    va_end(args);
}

static int backTrace(UNUSED void *data, uintptr_t programCounter, const char *fileName, int lineNumber, const char *functionName)
{
    if(!fileName || !lineNumber || !functionName)
        return 1;
    char *savePtr = NULL;
    currentStream.lEnv = (struct localEnv)
    {
        programCounter,
        strtok_r(strrchr(fileName, '/'), "/", &savePtr),
        lineNumber,
        functionName,
        {NULL, CTL_STR(" -> 0x: :::")+strlen(gEnv.programName)+strlen("currentStream.lEnv.counter")+strlen(currentStream.lEnv.file)+strlen("currentStream.lEnv.line")+strlen(currentStream.lEnv.function)}
    };
    if(!strcmp("main", currentStream.lEnv.function))
        return 2;
    return 0;
}

void streamF(char_t *string, ...)
{
    va_list args;
    va_start(args, string);
    enum { c_var, s_var, d_var, numberOfVarTypes };
    struct research research = createResearch(RTM_STR(string), Case_Order, CTM_STR(CF_STR), CTM_STR(SF_STR), CTM_STR("@{d}"));
    countOccurrences(&research);
    size_t hasVars = 0;
    for(unsigned int i = 0; i < numberOfVarTypes; ++i)
        if(research.numberOfOccurrences[i])
            hasVars += research.numberOfOccurrences[i] * research.toFind[i].length;
    if(!hasVars || research.toParse.length < CTL_STR(CONSOLE_MINIMAL_STYLE) || !countStrings(RTN_STR(string, research.toParse.length), Case, CTM_STR(CONSOLE_HEADER_STYLE)))
        goto end;

    enum { red, green, blue, numberOfColors, digitsBase = 10 };
    struct colorToFind
    {
        long int value[numberOfColors];
        bool found[numberOfColors];
        char_t string[numberOfColors][getDNF1B(digitsBase)];
    } color = {0};
    bool notFound = true;
    for(unsigned long i=0; i < research.toParse.length && notFound; ++i)
    {
        if(i >= CTL_STR(CONSOLE_HEADER_STYLE))
        {
            unsigned long int j = i;
            for(int k=0, l=0; notFound; ++j, ++l)
            {
                if(string[j] == ';' || string[j] == 'm')
                {
                    char_t *endPtr = NULL;
                    color.value[k] = strtol(color.string[k], &endPtr, digitsBase);
                    color.found[k] = true;
                    notFound = !color.found[red] || !color.found[green] || !color.found[blue];
                    ++k;
                    l=-1;
                }
                else
                    color.string[k][l] = string[j];
            }
            i = j;
        }
    }
    if(color.value[red] == successRedColor && color.value[green] == successGreenColor && color.value[blue] == successBlueColor)
        ++currentStream.stack[success];
    else if(color.value[red] == interruptionRedColor && color.value[green] == interruptionGreenColor && color.value[blue] == interruptionBlueColor)
        ++currentStream.stack[interruption];
    else if(color.value[red] == errorRedColor && color.value[green] == errorGreenColor && color.value[blue] == errorBlueColor)
        ++currentStream.stack[error];
    else if(color.value[red] == warningRedColor && color.value[green] == warningGreenColor && color.value[blue] == warningBlueColor)
        ++currentStream.stack[warning];
    else if(color.value[red] == noticeRedColor && color.value[green] == noticeGreenColor && color.value[blue] == noticeBlueColor)
        ++currentStream.stack[notice];
    else goto end;

    char_t **stringsToReplace[numberOfVarTypes];
    for(unsigned int i = 0; i < numberOfVarTypes; ++i)
        stringsToReplace[i] = alloca(sizeof *stringsToReplace * research.numberOfOccurrences[i]);
    size_t numberOfStringsToReplace[numberOfVarTypes] = {0};
    size_t lengthStringsToReplace = 0;
    for(struct {unsigned int i; unsigned int j[numberOfVarTypes];} r = {0, {0}}; r.i < research.totalOfOccurrences; ++r.i)
    {
        char_t *toReplace = NULL;
        switch(research.typesAliases[r.i])
        {
            case c_var :
                toReplace = alloca(sizeof *toReplace * 2);
                toReplace[0] = va_arg(args, char_t);
                toReplace[1] = '\0';
                ++lengthStringsToReplace;
                break;
            case s_var :
                toReplace = va_arg(args, char_t *);
                lengthStringsToReplace += strlen(toReplace);
                break;
            case d_var :
                {
                    int intToConvert = va_arg(args, int);
                    size_t length = (size_t)(snprintf)(0, 0L,"%d", intToConvert) + 1;
                    char_t *intString = alloca(sizeof *intString * length);
                    snprintf(intString, length, L_STR("%d"), intToConvert);
                    toReplace = intString;
                    lengthStringsToReplace += strlen(toReplace);
                }
                break;
            default :
                goto end;
        }
        stringsToReplace[research.typesAliases[r.i]][r.j[research.typesAliases[r.i]]] = toReplace;
        ++r.j[research.typesAliases[r.i]];
    }
    for(unsigned int i = 0; i < research.numberOfSearches; ++i)
        if(research.orders[i])
            freeStatic(research.orders[i]);
    freeStatic(research.typesAliases);

    size_t newStringLength = research.toParse.length - hasVars + lengthStringsToReplace + 1;
    char_t *newString = calloc( newStringLength, sizeof *newString);
    newString[newStringLength-1] = '\0';
    for(unsigned int i=0, j=0; i < research.toParse.length && j < newStringLength;)
    {
        if(string[i] == '@' && string[i+1] && string[i+1] == '{')
        {
            size_t stringTypeLength = 0;
            for(unsigned int k=i; string[k] != '}'; ++k, ++stringTypeLength);
            char_t *stringType = alloca(sizeof *stringType * (stringTypeLength + 2));
            for(unsigned int k=i, l=0; string[k] != '}'; ++k, ++l)
                stringType[l] = string[k];
            stringType[stringTypeLength] = '}';
            stringType[stringTypeLength+1] = '\0';
            unsigned int k = c_var;
            for(; k < numberOfVarTypes && strcmp(stringType, research.toFind[k].data) != 0; ++k);
            if(k == numberOfVarTypes) goto end;
            unsigned int l = 0;
            for(; stringsToReplace[k][numberOfStringsToReplace[k]][l]; ++l)
                newString[j + l] = stringsToReplace[k][numberOfStringsToReplace[k]][l];
            j += l;
            i += (unsigned int) stringTypeLength+1;
            ++numberOfStringsToReplace[k];
        }
        else
        {
            newString[j] = string[i];
            ++i;
            ++j;
        }
    }
    if(currentStream.allocated)
    {
        char_t *oldString = alloca(sizeof *oldString * (strlen(currentStream.message)+1));
        strcpy(oldString, currentStream.message);
        currentStream.message = realloc(currentStream.message,sizeof *currentStream.message * (strlen(oldString) + newStringLength));
        backtrace_full(currentStream.backTrace, 2, backTrace, NULL, NULL);
        runtimeCat(2, currentStream.message, oldString, newString);
        free(newString);
    }
    else
    {
        currentStream.allocated = true;
        currentStream.message = newString;
    }
    end:va_end(args);
}

static void emptySize(int *thrown, union exceptionArgs *args)
{
    size_t size = args->emptySize.size;
    if(!size)
    {
        streamF(ST_STR(INTERRUPTION, "An allocation requested a too high or a null/empty size."));
        *thrown = emptySize_;
        return;
    }
    streamF(ST_STR(SUCCESS, "Right size allocation requested."));
    *thrown = goingWell;
}

static void badAllocation(int *thrown, union exceptionArgs *args)
{
    struct badAllocation badAllocation = {args->badAllocation.instance, args->badAllocation.sizeRequested, args->badAllocation.sizeObtained };
    if(!badAllocation.instance || badAllocation.sizeRequested > badAllocation.sizeObtained)
    {
        streamF(ST_STR(INTERRUPTION, "An allocation failed in the heap segment : nullptr returned or abnormally low size pointed by the returned pointer."));
        *thrown = badAllocation_;
        return;
    }
    streamF(ST_STR(SUCCESS, "An allocation succeeded in the heap segment."));
    *thrown = successfulNominalScenario;
}

static void wrongSize(int *thrown, union exceptionArgs *args)
{
    struct wrongSize wrongSize = {args->wrongSize.size, args->wrongSize.sizeAligned, args->wrongSize.staticMemory};
    if(!wrongSize.size || wrongSize.size > staticMaxSize || wrongSize.staticMemory->allocated + wrongSize.size > staticMaxSize || wrongSize.staticMemory->allocated + wrongSize.sizeAligned > staticMaxSize)
    {
        *thrown = wrongSize_;
        return;
    }
    else if(wrongSize.size > staticMaxSize - headerBlock)
    {
        wrongSize.staticMemory->bigSingleAllocated = true;
        wrongSize.staticMemory->allocated += wrongSize.size;
        *thrown = bigSingleAllocation_;
        return;
    }
    *thrown = successfulNominalScenario;
}

static void bigSingleDesallocation(int *thrown, union exceptionArgs *args)
{
    struct staticMemory memory = *args->bigSingleDesallocation.memory;
    if(memory.bigSingleAllocated)
    {
        memory.bigSingleAllocated = false;
        memory.allocated = 0;
        for(size_t i = 0; i < staticMaxSize; ++i)
            if(memory.available[i])
                memory.available[i] = 0;
        streamF(ST_STR(SUCCESS, "Big allocation freed on the data segment."));
        *thrown = bigSingleDesallocation_;
        return;
    }
    streamF(ST_STR(SUCCESS, "There isn't any big allocation on the data segment, free process can proceed in normal way."));
    *thrown = goingWell;
}

static void invalidDataArgument(int *thrown, union exceptionArgs *args)
{
    void *pointer = args->invalidDataArgument.pointer;
    if(!pointer)
    {
        streamF(ST_STR(ERROR, "Data segment argument is not a valid pointer, is already freed or points to an empty size."));
        *thrown = invalidDataArgument_;
        return;
    }
    streamF(ST_STR(SUCCESS, "Data segment argument is a valid pointer."));
    *thrown = goingWell;

}

static void stringOperationNotEnoughLong(int *thrown, union exceptionArgs *args)
{
    size_t stringLength = args->stringOperationNotEnoughLong.stringOperationLength;
    if(stringLength <= 2)
    {
        streamF(ST_STR(ERROR, "The operation "SF_STR" isn't long enough."), L_STR("My Operation"));
        *thrown = stringOperationNotEnoughLong_;
        return;
    }
    streamF(ST_STR(SUCCESS, "The operation "SF_STR" is long enough."), L_STR("My Operation"));
    *thrown = goingWell;
}

static void stringOperationContainsNotAllowedCharacters(int *thrown, union exceptionArgs *args)
{
    string_t string = {args->stringOperationContainsNotAllowedCharacters.stringOperation, args->stringOperationContainsNotAllowedCharacters.stringOperationLength};
    for(unsigned int i = 0; i < string.length; ++i)
    {
        if((string.data[i] > 0 && string.data[i] < 32) || string.data[i] == 127 || string.data[i] == -127)
        {
            streamF(ST_STR(ERROR, "The character "CF_STR" is not allowed.\n"), string.data[i]);
            if(*thrown != stringOperationContainsNotAllowedCharacters_)
                *thrown = stringOperationContainsNotAllowedCharacters_;
        }
    }
    if(*thrown==stringOperationContainsNotAllowedCharacters_)
    {
        streamF(ST_STR(ERROR, "The operation "SF_STR" contains not allowed characters that cannot be used for parsing."), string.data);
        return;
    }
    streamF(ST_STR(SUCCESS, "The operation "SF_STR" is well written and can be parsed."), string.data);
    *thrown = goingWell;
}

static void noSymbolNorSupposedOperandsFounds(int *thrown, union exceptionArgs *args)
{
    struct noSymbolNorSupposedOperandsFounds numberOf = { args->noSymbolNorSupposedOperandsFounds.numberOfSymbols, args->noSymbolNorSupposedOperandsFounds.numberOfOperands };
    if(numberOf.numberOfSymbols == 0 || numberOf.numberOfOperands == 0)
    {
        streamF(ST_STR(ERROR, "There is no supposed operand nor supposed operator to find further."));
        *thrown = noSymbolNorSupposedOperandsFounds_;
        return;
    }
    streamF(ST_STR(SUCCESS, "There is at least one supposed operand and one supposed operator to find at parsing further."));
    *thrown = goingWell;
}

static void operandHasNotOperatorsNorReflexivity(int *thrown, union exceptionArgs *args)
{
    __typeof__(args->operandHasNotOperatorsNorReflexivity) reflex = args->operandHasNotOperatorsNorReflexivity;
    if(!reflex.reflexivity || !reflex.reflexivity()->settings[hasOperator])
    {
        streamF(ST_STR(ERROR, "The operand "SF_STR" found haven't reflexivity feature or any operator : no operation can be performed."), reflex.operandString);
        *thrown = operandHasNotOperatorsNorReflexivity_;
        return;
    }
    streamF(ST_STR(SUCCESS, "The operand "SF_STR" found have at least reflexivity with one operator."), reflex.operandString);
    *thrown = goingWell;
}

static void realOperandNotFound(int *thrown, union exceptionArgs *args)
{
    bool found = args->realOperandNotFound.found;
    char_t *string = args->realOperandNotFound.string;
    if(!found)
    {
        streamF(ST_STR(ERROR, "The supposed operand "SF_STR" wasn't associate to any object nor literal operand."), string);
        *thrown = realOperandNotFound_;
        return;
    }
    streamF(ST_STR(SUCCESS, "The supposed operand "SF_STR" is associated to something that can operate."), string);
    *thrown = goingWell;
}

static void operatorNotFound(int *thrown, union exceptionArgs *args)
{
    bool found = args->operatorNotFound.found;
    char_t *string = args->operatorNotFound.string;
    if(!found)
    {
        streamF(ST_STR(ERROR, "The supposed symbol "SF_STR" wasn't associated to any known operator."), string);
        *thrown = operatorNotFound_;
        return;
    }
    streamF(ST_STR(SUCCESS, "The supposed symbol "SF_STR" is associated to an operator."), string);
    *thrown = successfulNominalScenario;
}
