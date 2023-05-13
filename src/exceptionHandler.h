#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

#include <backtrace.h>

#define SUCCESS_RED_COLOR               24
#define SUCCESS_GREEN_COLOR             134
#define SUCCESS_BLUE_COLOR              45
#define INTERRUPTION_RED_COLOR          149
#define INTERRUPTION_GREEN_COLOR        85
#define INTERRUPTION_BLUE_COLOR         0
#define ERROR_RED_COLOR                 216
#define ERROR_GREEN_COLOR               31
#define ERROR_BLUE_COLOR                42
#define WARNING_RED_COLOR               255
#define WARNING_GREEN_COLOR             223
#define WARNING_BLUE_COLOR              0
#define NOTICE_RED_COLOR                196
#define NOTICE_GREEN_COLOR              202
#define NOTICE_BLUE_COLOR               206

#define CONSOLE_RGB(Red, Green, Blue)   STR_(Red;Green;Blue)
#define CONSOLE_HEADER_STYLE            "\033[1m\033[38;2;"
#define CONSOLE_FOOTER_STYLE            "\033[0m"
#define CONSOLE_MINIMAL_STYLE           CONSOLE_HEADER_STYLE CONSOLE_RGB(0,0,0)"m"CONSOLE_FOOTER_STYLE
#define CONSOLE_SUCCESS_STYLE           CONSOLE_HEADER_STYLE CONSOLE_RGB(SUCCESS_RED_COLOR,SUCCESS_GREEN_COLOR,SUCCESS_BLUE_COLOR)"m"
#define CONSOLE_INTERRUPTION_STYLE      CONSOLE_HEADER_STYLE CONSOLE_RGB(INTERRUPTION_RED_COLOR,INTERRUPTION_GREEN_COLOR,INTERRUPTION_BLUE_COLOR)"m"
#define CONSOLE_ERROR_STYLE             CONSOLE_HEADER_STYLE CONSOLE_RGB(ERROR_RED_COLOR,ERROR_GREEN_COLOR,ERROR_BLUE_COLOR)"m"
#define CONSOLE_WARNING_STYLE           CONSOLE_HEADER_STYLE CONSOLE_RGB(WARNING_RED_COLOR,WARNING_GREEN_COLOR,WARNING_BLUE_COLOR)"m"
#define CONSOLE_NOTICE_STYLE            CONSOLE_HEADER_STYLE CONSOLE_RGB(NOTICE_RED_COLOR,NOTICE_GREEN_COLOR,NOTICE_BLUE_COLOR)"m"

#define ST_STR(style, string)           CONSOLE_##style##_STYLE L_STR(string) CONSOLE_FOOTER_STYLE
#define getDNF1B(base) ((base) == 16) ? 3 : ((base) == 10) ? 4 : ((base) == 8) ? 4 : ((base) == 2) ? 9 : -1

#if WCHAR_USAGE
#define SF_STR "@{S}"
#define CF_STR "@{C}"
#else
#define SF_STR "@{s}"
#define CF_STR "@{c}"
#endif

enum
{
    success,
    interruption,
    error,
    warning,
    notice,
    numberOfStacks,
    successRedColor = SUCCESS_RED_COLOR,
    successGreenColor = SUCCESS_GREEN_COLOR,
    successBlueColor = SUCCESS_BLUE_COLOR,
    interruptionRedColor = INTERRUPTION_RED_COLOR,
    interruptionGreenColor = INTERRUPTION_GREEN_COLOR,
    interruptionBlueColor = INTERRUPTION_BLUE_COLOR,
    errorRedColor = ERROR_RED_COLOR,
    errorGreenColor = ERROR_GREEN_COLOR,
    errorBlueColor = ERROR_BLUE_COLOR,
    warningRedColor = WARNING_RED_COLOR,
    warningGreenColor = WARNING_GREEN_COLOR,
    warningBlueColor = WARNING_BLUE_COLOR,
    noticeRedColor = NOTICE_RED_COLOR,
    noticeGreenColor = NOTICE_GREEN_COLOR,
    noticeBlueColor = NOTICE_BLUE_COLOR
};

enum exceptionType
{
    allocateMemoryUID = -INT_MAX,
    allocateStaticMemoryUID,
    freeStaticMemoryUID,
    doingCustomOperationUID,

    undefinedSituation = -3,
    readyToTry,
    goingWell,
    successfulNominalScenario,

    emptySize_,
    badAllocation_, allocateMemory = badAllocation_,

    wrongSize_ = 1,
    bigSingleAllocation_, allocateStaticMemory = bigSingleAllocation_,

    bigSingleDesallocation_ = 1,
    invalidDataArgument_,
    exception3_, freeStaticMemory = exception3_,

    stringOperationNotEnoughLong_ = 1,
    stringOperationContainsNotAllowedCharacters_,
    noSymbolNorSupposedOperandsFounds_,
    operandHasNotOperatorsNorReflexivity_,
    operatorNotFound_,
    realOperandNotFound_, doingCustomOperation = realOperandNotFound_
};

union exceptionArgs
{
    struct emptySize { size_t size; } emptySize;
    struct badAllocation { void *instance; size_t sizeRequested; size_t sizeObtained; } badAllocation;
    struct wrongSize { size_t size; size_t sizeAligned; struct staticMemory *staticMemory; } wrongSize;
    struct bigSingleAllocation { size_t size; } bigSingleAllocation;
    struct bigSingleDesallocation { struct staticMemory *memory; } bigSingleDesallocation;
    struct invalidDataArgument { void *pointer; } invalidDataArgument;
    struct stringOperationNotEnoughLong { size_t stringOperationLength; } stringOperationNotEnoughLong;
    struct stringOperationContainsNotAllowedCharacters { char_t *stringOperation; size_t stringOperationLength; } stringOperationContainsNotAllowedCharacters;
    struct noSymbolNorSupposedOperandsFounds { unsigned int numberOfSymbols; unsigned int numberOfOperands; } noSymbolNorSupposedOperandsFounds;
    struct operandHasNotOperatorsNorReflexivity { struct class *(*reflexivity)(void); char_t *operandString; } operandHasNotOperatorsNorReflexivity;
    struct realOperandNotFound { bool found; char_t *string; } realOperandNotFound;
    struct operatorNotFound { bool found; char_t *string; } operatorNotFound;
};

struct localEnv
{
    uintptr_t counter;
    const char *file;
    int line;
    const char *function;
    string_t stackTrace;
};

struct exception
{
    int type;
    int numberOfCases;
    void (**throw)(int *, union exceptionArgs *);
};

extern struct stream
{
    int stack[numberOfStacks];
    char_t *message;
    struct backtrace_state *backTrace;
    struct localEnv lEnv;
    bool allocated;
} currentStream;

extern void Exception(struct exception *, int scenario);
extern void streamF(char_t *string, ...);

#define try(criticalOperation) try_(criticalOperation, )
#define try_(criticalOperation, suffix) {                                           \
struct exception CAT3(criticalOperation, Exception, suffix) =                       \
    { .type = undefinedSituation,                                                   \
    .numberOfCases = (criticalOperation),                                           \
    .throw = (void (*[criticalOperation])(int *, union exceptionArgs *)){0} };      \
Exception(&CAT3(criticalOperation, Exception, suffix), criticalOperation##UID);     \
CAT3(criticalOperation, Exception, CAT(suffix,start)):                              \
switch(CAT3(criticalOperation, Exception, suffix).type)                             \
{ case readyToTry : while(1) {
#define throws(Case, exceptionName, ...) exceptionName.throw[Case##_-1]             \
(&exceptionName.type, &(union exceptionArgs){.Case=(struct Case){__VA_ARGS__}});    \
if(exceptionName.type > successfulNominalScenario) goto exceptionName##start
#define catch(exceptionType) break; case exceptionType##_ :
#define finally break; } default: {
#define stop break; } } }

#endif
