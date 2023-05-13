#ifndef OBJECT_MODEL_H
#define OBJECT_MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <math.h>

#if defined(__x86_64__) || defined(__amd64__) || defined(_WIN64)
#   define ARCH_ENV 64
#elif (defined(_M_IX86) && !defined(_M_I86)) || defined(_WIN32)
#   define ARCH_ENV 32
#elif defined(_M_I86) || defined(_WIN16)
#   define ARCH_ENV 16
#else
#   error "Not supported architecture."
#endif

#ifdef _WIN32
#   define mSize(pointer) _msize(pointer)
#elif defined(__APPLE__) && defined(__MACH__)
#   define mSize(pointer) malloc_size(pointer)
#elif defined(__linux__)
#   include <malloc.h>
#   define mSize(pointer) malloc_usable_size(pointer)
#endif

#if defined(__STDC__)
#   define STDC_1989
#   if defined(__STDC_VERSION__)
#       define STDC_1990
#       if (__STDC_VERSION__ >= 199409L)
#           define STDC_1994
#       endif
#       if (__STDC_VERSION__ >= 199901L)
#           define STDC_1999
#       endif
#       if (__STDC_VERSION__ >= 201112L)
#           define STDC_2011
#       endif
#       if (__STDC_VERSION__ >= 201710L)
#           define STDC_2018
#       endif
#   endif
#endif

#if (defined(STDC_2018) || defined(STDC_2011) || defined(STDC_1999)) && (defined(__MINGW32__))
#   define ZU_STR "%I64u"
#   define FUNCTION_NAME __func__
#elif (defined(STDC_2018) || defined(STDC_2011) || defined(STDC_1999)) && (defined(__GNUC__) || defined(__clang__))
#   define ZU_STR "%zu"
#   define FUNCTION_NAME __func__
#elif (!defined(STDC_2018) && !defined(STDC_2011) && !defined(STDC_1999))
#   define ZU_STR "%lu"
#   define FUNCTION_NAME __FUNCTION__
#endif

#define STR_(A) #A
#define STR(A) STR_(A)
#define DEF_(A,B) defined(A##B)
#define DEF(A,B) DEF_(A,B)
#define CAT_(A,B) A##B
#define CAT(A,B) CAT_(A,B)
#define CAT3_(A,B,C) A##B##C
#define CAT3(A,B,C) CAT3_(A,B,C)
#define STRIP(...) __VA_ARGS__
#define NO_ARG_OR_ARGS(...) NB_ARGS_(0, ##__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0)
#define ARG2_OR_ARGS2(...) NB_ARGS_(0, ##__VA_ARGS__, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0)
#define NB_ARGS(...) NB_ARGS_(0, ##__VA_ARGS__, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define NB_ARGS_(_0, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_, _34_, _35_, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, count, ...) count
#define V_STR_(...) #__VA_ARGS__
#define V_STR(...) V_STR_(__VA_ARGS__)
#define M_STR(A) (char_t []){L_STR(A)}
#define N_STR(A) (char_t []){P_STR(A)}
#define ZOF(A) sizeof A / sizeof *A
#define CTL_STR(A) ZOF(A) - 1
#define CTM_STR(A) {M_STR(A), CTL_STR(A)}
#define CTN_STR(A) {N_STR(A), CTL_STR(P_STR(A))}
#define RTM_STR(A) {A, strlen(A)}
#define RTN_STR(A,B) {A, B}
#define INTERNAL __attribute__((weak))
#define UNUSED __attribute__((unused))
#define ALIAS(function) __attribute__((weak, alias(STR(function))))
#define RAII __attribute__ ((cleanup(delete)))
#define INLINE __attribute__ ((always_inline)) inline
#define noDestroyDestructor(element) 0
#define Destructor(element) element##_
#define noRAIIRAII
#define WCHAR_USAGE 1

#if WCHAR_USAGE
#include <wchar.h>
#include <locale.h>

#define I_STR_ )
#define I_STR CAT(L, STR(
#define P_STR(A) CAT(L, STR(A))
#define L_STR(A) CAT(L, A)
#define W_STR_(...) L###__VA_ARGS__
#define W_STR(...) W_STR_(__VA_ARGS__)
#define S_STR "%S"
#define C_STR "%C"

#define token_operator_character(char) char == '!' || char == '#' || char == '%' || char == '&' || (char >= '*' && char <= '/') || (char >= ':' && char <= '@') || (char >= '[' && char <= '`') || char > 'z'

typedef wchar_t char_t;
typedef unsigned int uchar_t;
typedef signed int schar_t;

#define strcmp(string1, string2) _Generic(string1,                                                                                                  \
    char *: _Generic(string2, char *: (strcmp), wchar_t *: strcmp_str_wideStr, const char *: (strcmp), const wchar_t *: strcmp_str_wideStr),        \
    const char *: _Generic(string2, char *: (strcmp), wchar_t *: strcmp_str_wideStr, const char *: (strcmp), const wchar_t *: strcmp_str_wideStr),  \
    wchar_t *: _Generic(string2, char *: strcmp_wideStr_str, wchar_t *: wcscmp, const char *: strcmp_wideStr_str, const wchar_t *: wcscmp),         \
    const wchar_t *: _Generic(string2, char *: strcmp_wideStr_str, wchar_t *: wcscmp, const char *: strcmp_wideStr_str, const wchar_t *: wcscmp)    \
)(string1, string2)

#define strlen(string)          \
_Generic(string,                \
    char *: (strlen),           \
    const char *: (strlen),     \
    wchar_t *: wcslen,          \
    const wchar_t *: wcslen     \
)(string)

#define strrchr(string, Char) _Generic(string,                                          \
    char *: _Generic(Char, char : (strrchr), wchar_t : strrchr_str_wideChar),           \
    const char *: _Generic(Char, char : (strrchr), wchar_t : strrchr_str_wideChar),     \
    wchar_t *: _Generic(Char, char : strrchr_wideStr_char, wchar_t : wcsrchr),          \
    const wchar_t *: _Generic(Char, char : strrchr_wideStr_char, wchar_t : wcsrchr)     \
)(string, Char)

#define strcpy(string1, string2) _Generic(string1,                                  \
    char *: _Generic(string2, char *: (strcpy), wchar_t *: strcpy_str_wideStr),     \
    wchar_t *: _Generic(string2, char *: strcpy_wideStr_str, wchar_t *: wcscpy)     \
)(string1, string2)

#define strtol(string, ptrToEnd, base)  \
_Generic(string,                        \
    char *: (strtol),                   \
    wchar_t *: wcstol                   \
)(string, ptrToEnd, base)

#define strtok_r(string, delim, savePtr) _Generic(string,                           \
char *: _Generic(delim, char *: (strtok_r), wchar_t *: strtok_r_str_wideStr),       \
wchar_t *: _Generic(delim, char *: (strtok_r_wideStr_str), wchar_t *: wcstok)       \
)(string, delim, savePtr)

#define snprintf(string, length, formattedString, ...) _Generic(string,                         \
    char *: _Generic(formattedString, char *: (snprintf), wchar_t *: snprintf_str_wideStr),     \
    wchar_t *: _Generic(formattedString, char *: snprintf_wideStr_str, wchar_t *: swprintf)     \
)(string, length, formattedString, ##__VA_ARGS__)

#define fputs(string, stream)   \
_Generic(string,                \
    char *: (fputs),            \
    const char *: (fputs),      \
    wchar_t *: fputws,          \
    const wchar_t *: fputws     \
)(string, stream)

#define printf(formattedString, ...) wprintf(L_STR(formattedString), ##__VA_ARGS__)

INLINE int strcmp_str_wideStr(UNUSED const char *string, UNUSED const wchar_t *WideString)
{
    fputs(FUNCTION_NAME, stderr);
    return 0;
}

INLINE int strcmp_wideStr_str(UNUSED const wchar_t *WideString, UNUSED const char *string)
{
    fputs(FUNCTION_NAME, stderr);
    return 0;
}

INLINE char *strrchr_str_wideChar(UNUSED char const *string, UNUSED wchar_t WideChar)
{
    fputs(FUNCTION_NAME, stderr);
    return NULL;
}

INLINE wchar_t *strrchr_wideStr_char(UNUSED wchar_t const *wideString, UNUSED char Char)
{
    fputs(FUNCTION_NAME, stderr);
    return NULL;
}

INLINE char *strcpy_str_wideStr(UNUSED char const *string, UNUSED wchar_t const *WideString)
{
    fputs(FUNCTION_NAME, stderr);
    return NULL;
}

INLINE wchar_t *strcpy_wideStr_str(UNUSED wchar_t const *WideString, UNUSED char const *string)
{
    fputs(FUNCTION_NAME, stderr);
    return NULL;
}

INLINE char *strtok_r_str_wideStr(UNUSED char *wideString, UNUSED char *delimiter, UNUSED char *savePtr)
{
    fputs(FUNCTION_NAME, stderr);
    return NULL;
}
INLINE wchar_t *strtok_r_wideStr_str(UNUSED char *wideString, UNUSED char *delimiter, UNUSED char *savePtr)
{
    fputs(FUNCTION_NAME, stderr);
    return NULL;
}

INLINE int snprintf_str_wideStr(UNUSED const char *string, UNUSED size_t length, UNUSED const wchar_t *format, ...)
{
    fputs(FUNCTION_NAME, stderr);
    return 0;
}

INLINE int snprintf_wideStr_str(UNUSED const wchar_t *WideString, UNUSED size_t length, UNUSED const char *format, ...)
{
    fputs(FUNCTION_NAME, stderr);
    return 0;
}

#else
#define I_STR_
#define I_STR STR(
#define P_STR(A) STR(A)
#define L_STR(A) A
#define W_STR(...) V_STR_(__VA_ARGS__)
#define S_STR "%s"
#define C_STR "%c"

#define token_operator_character(char) char == '!' || char == '#' || char == '%' || char == '&' || (char >= '*' && char <= '/') || (char >= ':' && char <= '@') || (char >= '[' && char <= '`') || (char >= '{' && char < 127) || (char > -128 && char < 0)

typedef char char_t;
typedef unsigned char uchar_t;
typedef signed char schar_t;
#endif

#define first_identifier_character(char) char == '$' || char == '_' || (char >= 'A' && char <= 'Z') || (char >= 'a' && char <= 'z')
#define next_identifier_characters(char) (first_identifier_character(char)) || (char >= '0' && char <= '9')
#define space_character(char) char == ' '
#define first_literal_number_character(char) char >= '0' && char <= '9'
#define next_literal_number_characters(char) (first_literal_number_character(char)) || char == '.' || char == 'F' || char == 'f' || char == 'L' || char == 'l' || char == 'U' || char == 'u' || char == 'E' || char == 'e' || char == 'x' || char == 'b'
#define literal_string_character(char) char == '"'
#define end_string_character(char) char != '"'
#define open_array_character(currentChar, nextChar) currentChar == '[' && first_identifier_character(nextChar)
#define close_array_character(currentChar, nextChar) first_identifier_character(currentChar) && (nextChar) == ']'
#define call_function_character(currentChar, nextChar) currentChar == '(' && first_identifier_character(nextChar)
#define uncall_function_character(currentChar, nextChar) first_identifier_character(currentChar) && (nextChar) == ')'
#define use_object_character(previousChar, currentChar, nextChar) ((currentChar) == '.' && first_identifier_character(nextChar)) || ((previousChar) == '-' && (currentChar) == '>' && first_identifier_character(nextChar)) || ((currentChar) == '&' && first_identifier_character(nextChar)) || ((currentChar) == '*' && first_identifier_character(nextChar))

#include <containers/containers.h>

typedef const void * const encapsulated_t;
typedef const struct operator * operator_t;
typedef struct string string_t;

enum
{
    isMatchingCase,
    isWholeWord,
    isRegex,
    withOrder,
    numberOfResearchSettings,

    noDestroyDestructorSetting = 0,
    DestructorSetting,
    noRAIIwithRAII = 0,
    withRAII,

    hasDestructor = 0,
    isAutoFreed,
    isArray,
    hasScopeEnvironment,
    numberOfObjectSettings,

    hasOperator = 0,
    isOverloaded,
    isOverridden,
    hasEmptyClass,
    numberOfClassSettings,

    biByte = 2,
    kiBiByte = biByte * biByte * biByte * biByte * biByte * biByte * biByte * biByte * biByte * biByte,
    meBiByte = kiBiByte * kiBiByte,
    alignMax = _Alignof(max_align_t),
    staticMaxSize = meBiByte,
    archEnv = ARCH_ENV,
    headerBlock = (archEnv / 8) * 2,

    Offset1 = 1,

    minArity = 1,
    maxPriority = 17
};

struct staticMemory
{
    unsigned char available[staticMaxSize];
    size_t allocated;
    bool bigSingleAllocated;
};

#define free(memory) (free)(memory), (memory)=NULL
#define findMetadata_ find(&this, sizeof(struct object), (size_t) Offset1)
#define findMetadata(objectName) find(&(objectName), sizeof(struct object), Offset1)

enum ENV_States
{
    Operator,
    Symbol,
    Token,
    Operand,
    LiteralString,
    LiteralNumber,
    InterpretableString,
    InterpretableInteger,
    InterpretableFloat,
    InterpretableBoolean,
    InterpretablePointer,
    InterpretableCObjectOP,
    IdentifierCObjectOP,
    SupposedOperator,
    SupposedOperand,
    Nothing
};

struct string
{
    char_t *data;
    size_t length;
};

struct research
{
    bool settings[numberOfResearchSettings];
    string_t *toFind;
    string_t toParse;
    unsigned int numberOfSearches;
    unsigned int *numberOfOccurrences;
    unsigned int **orders;
    unsigned int *typesAliases;
    unsigned int totalOfOccurrences;
    bool *badString;
};

#define stringsSettingsCase_Word_Regex_Order_   true, true, true, true
#define stringsSettingsCase_Word_Regex_         true, true, true, false
#define stringsSettingsCase_Word_Order_         true, true, false, true
#define stringsSettingsCase_Regex_Order_        true, false, true, true
#define stringsSettingsWord_Regex_Order_        false, true, true, true
#define stringsSettingsCase_Word_               true, true, false, false
#define stringsSettingsCase_Regex_              true, false, true, false
#define stringsSettingsCase_Order_              true, false, false, true
#define stringsSettingsWord_Regex_              false, true, true, false
#define stringsSettingsWord_Order_              false, true, false, true
#define stringsSettingsRegex_Order_             false, false, true, true
#define stringsSettingsCase_                    true, false, false, false
#define stringsSettingsWord_                    false, true, false, false
#define stringsSettingsRegex_                   false, false, true, false
#define stringsSettingsOrder_                   false, false, false, true
#define stringsSettings_                        false, false, false, false
#define prodCode_0(code, otherCode) otherCode
#define prodCode_1(code, otherCode) code
#define createResearch(into, settings, ...) {           \
    {stringsSettings##settings##_},                     \
    (string_t []) {__VA_ARGS__},                        \
    into,                                               \
    NB_ARGS(__VA_ARGS__)/2,                             \
    (unsigned int [NB_ARGS(__VA_ARGS__)/2]) {0},        \
    (unsigned int *[NB_ARGS(__VA_ARGS__)/2]) {0},       \
    NULL,                                               \
    0,                                                  \
    (bool [NB_ARGS(__VA_ARGS__)/2]) {0}                 \
}
#define countStrings(into, settings, ...)               \
CAT(prodCode_, ARG2_OR_ARGS2(__VA_ARGS__))(*,)          \
countOccurrences(&(struct research)                     \
createResearch(STRIP(into), settings, __VA_ARGS__))

struct dimension
{
    unsigned int *max;
    unsigned int size;
};

union result
{
    char char_;
    signed char signed_char_;
    unsigned char unsigned_char_;
    short short_;
    short int short_int_;
    signed short signed_short_;
    signed short int signed_short_int_;
    unsigned short unsigned_short_;
    unsigned short int unsigned_short_int_;
    int int_;
    signed signed_;
    signed int signed_int_;
    unsigned unsigned_;
    unsigned int unsigned_int_;
    long long_;
    long int long_int_;
    signed long signed_long_;
    signed long int signed_long_int_;
    unsigned long unsigned_long_;
    unsigned long int unsigned_long_int_;
    long long long_long_;
    long long int long_long_int_;
    signed long long signed_long_long_;
    signed long long int signed_long_long_int_;
    unsigned long long unsigned_long_long_;
    unsigned long long int unsigned_long_long_int_;
    float float_;
    double double_;
    long double long_double_;
    _Bool bool_;
    char *string_;
    int *wide_string_;
    void (*void_)(void);
    struct object *object_;
};

#define VIRTUAL(...) if(metadata->class != self && metadata->getClass &&    \
metadata->getClass()->settings[isOverridden])                               \
{   struct class *reflexInfos = metadata->getClass();                       \
    return reflexInfos->virtual[reflexInfos->getVE              \
    (reflexInfos, FUNCTION_NAME)](this, ##__VA_ARGS__);                     \
}   else

#define TYPE_EQUALITY(a, b, msg) _Static_assert(__builtin_types_compatible_p(__typeof__(a), __typeof__(b)), msg)

struct type
{
    size_t size;
    char *name;
    unsigned int id;
    unsigned int length;
};

struct genericArray
{
    void *value;
    size_t memory;
    size_t size;
    struct dimension dimension;
    struct type type;
};

struct instantiation
{
    void (*constructor)(void *, ...);
    void (*destructor)(bool);
    size_t (*getSize)(void *, struct type *);
    struct genericArray *array;
    char_t *objectName;
    void *class;
    void *instanceArgs;
    bool settingsObject[numberOfObjectSettings];
};

struct object
{
    void (*destructor)(bool);
    struct class *(*getClass)(void);
    struct genericArray *array;
    char_t *name;
    void *class;
    void *instance;
    void *node;
    size_t size;
    bool settings[numberOfObjectSettings];
};

struct class
{
    char_t *name;
    unsigned int numObjects;
    unsigned int numAttributes;
    unsigned int numOperators;
    unsigned int numMethods;
    unsigned int numOverriddenMethods;
    size_t unpackedSize;
    size_t packedSize;
    size_t *offsets;
    size_t *sizes;
    const char **memberNames;
    unsigned int (*getVE)(struct class *, const char *);
    size_t (*pack)(void *, uchar_t *, struct class *);
    size_t (*unpack)(uchar_t *, void *, struct class *);
    void (*print)(void *, struct class *);
    operator_t (*getOperator)(char_t *, struct operator *, unsigned int);
    void *(**virtual)();
    bool settings[numberOfClassSettings];
};

struct operation
{
    char_t **supposedOperators;
    char_t **supposedOperands;
    enum ENV_States *script;
    union result *result;
    char_t *operationString;
};

struct operator
{
    unsigned int arity;
    char_t *symbolisation;
    char *name;
    unsigned int priority;
    enum ENV_States *associativity;
    union result *(*operation)(union result *, struct object *);
};

extern struct globalEnv
{
    char *path;
    char *programName;
    unsigned int programNArgs;
    char **programSArgs;
    union result currentResult;
} gEnv;

#include <exceptionHandler.h>

INLINE static void (nothing)(void){}

extern unsigned int findVirtualElement(struct class *elementToReflect, const char *virtualElementName);
extern size_t packClass(void *class, uchar_t *buffer, struct class *elementToReflect);
extern size_t unpackClass(uchar_t *buffer, void *class, struct class *elementToReflect);
extern void printClass(void *class, struct class *elementToReflect);
extern void *(new)(struct instantiation *args);
extern void *(alloc)(size_t size);
extern void *(allocStatic)(size_t sizeRequired);
extern void (freeStatic)(void *memoryAllocated);
extern void *(find)(void *member, size_t size, size_t offset);
extern void (delete)(void *object);
extern unsigned int (setTypeId)(const char *typeString);
extern void (showArrayInfos)(const struct genericArray *array);
extern void (garbageCollector)(void);
extern union result *(operate)(struct operation *operation);
extern unsigned int *(countOccurrences)(struct research *research);
extern char_t *(runtimeCat)(unsigned int numberOfStringsToCat, char_t *finalString, ...);
extern void ENV_(int argc, char **argv);

#define array(Type, name, arrayDescriptor, initialization, ...)                     \
struct genericArray name;                                                           \
{ __typeof__(Type) name##Array arrayDescriptor initialization;                      \
name = (struct genericArray)                                                        \
{                                                                                   \
    &name##Array,                                                                   \
    sizeof name##Array,                                                             \
    ZOF(name##Array),                                                               \
    (struct dimension)                                                              \
    {                                                                               \
        (__typeof__((struct genericArray){0}.dimension.size) [sizeof((unsigned      \
        int [NB_ARGS(__VA_ARGS__)+1]) {0}) / sizeof(unsigned int)])                 \
        { ZOF(name##Array), ##__VA_ARGS__ },                                        \
        NB_ARGS(__VA_ARGS__)+1                                                      \
    },                                                                              \
    (struct type)                                                                   \
    {                                                                               \
        sizeof(Type),                                                               \
        V_STR(Type),                                                                \
        setTypeId(V_STR(Type)),                                                     \
        CTL_STR(V_STR(Type))                                                        \
    }                                                                               \
}; } _Static_assert(CTL_STR(STR(arrayDescriptor)) > 0, "Array need at least one "   \
"dimension.")
#define vector(type, size, suffix) typedef __typeof__(type) v##size##suffix __attribute__ ((vector_size((size) * sizeof(type))))

#define newInit(element, destroyOrNot, Array, name, settings,                       \
overloadingOption, ...) (new)                                                       \
(                                                                                   \
    &(struct instantiation)                                                         \
    {                                                                               \
        (void (*)(void *, ...)) element,                                            \
        destroyOrNot##Destructor(element),                                          \
        (size_t (*)(void *, struct type *)) element##_getSize,                      \
        Array,                                                                      \
        P_STR(name),                                                                \
        0,                                                                          \
        CAT(prodCode_, NO_ARG_OR_ARGS(__VA_ARGS__))(STRIP(                          \
        &(struct element##_overloads)                                               \
        {                                                                           \
            .options = element##_new_##overloadingOption,                           \
            ._new_##overloadingOption = {__VA_ARGS__},                              \
            .numberOfSubInstancesConcerned = 0                                      \
        }), NULL),                                                                  \
        settings                                                                    \
    }                                                                               \
)
#define newNoEnvOv(RAIIorNot, destroyOrNot, element, name, option, ...)             \
RAIIorNot##RAII struct element *name =                                              \
newInit(element, destroyOrNot,                                                      \
    0, name,                                                                        \
    {STRIP(                                                                         \
        [hasDestructor] = destroyOrNot##DestructorSetting,                          \
        [isAutoFreed] = RAIIorNot##withRAII,                                        \
        [isArray] = false,                                                          \
        [hasScopeEnvironment] = false                                               \
    )},                                                                             \
    option,                                                                         \
    __VA_ARGS__)
#define newWithEnvOv(RAIIorNot, destroyOrNot, element, name, option, ...)           \
RAIIorNot##RAII struct element *name =                                              \
newInit(element, destroyOrNot,                                                      \
    0, name,                                                                        \
    {STRIP(                                                                         \
        [hasDestructor] = destroyOrNot##DestructorSetting,                          \
        [isAutoFreed] = RAIIorNot##withRAII,                                        \
        [isArray] = false,                                                          \
        [hasScopeEnvironment] = true                                                \
    )},                                                                             \
    option,                                                                         \
    __VA_ARGS__)
#define newWithArrayNoEnvOv(RAIIorNot, destroyOrNot, element, name,                 \
definitionArray, arrayDescriptor, dimensions, option, ...)                          \
array(struct element, definitionArray, arrayDescriptor, , STRIP dimensions);        \
RAIIorNot##RAII struct element (*name)arrayDescriptor = definitionArray.value =     \
newInit(element, destroyOrNot,                                                      \
    &definitionArray, name,                                                         \
    {STRIP(                                                                         \
        [hasDestructor] = destroyOrNot##DestructorSetting,                          \
        [isAutoFreed] = RAIIorNot##withRAII,                                        \
        [isArray] = true,                                                           \
        [hasScopeEnvironment] = false                                               \
    )},                                                                             \
    option,                                                                         \
    __VA_ARGS__)
#define newWithArrayWithEnvOv(RAIIorNot, destroyOrNot, element, name,               \
definitionArray, arrayDescriptor, dimensions, option, ...)                          \
array(struct element, definitionArray, arrayDescriptor, , STRIP dimensions);        \
RAIIorNot##RAII struct element (*name)arrayDescriptor = definitionArray.value =     \
newInit(element, destroyOrNot,                                                      \
    &definitionArray, name,                                                         \
    {STRIP(                                                                         \
        [hasDestructor] = destroyOrNot##DestructorSetting,                          \
        [isAutoFreed] = RAIIorNot##withRAII,                                        \
        [isArray] = true,                                                           \
        [hasScopeEnvironment] = true                                                \
    )},                                                                             \
    option,                                                                         \
    __VA_ARGS__)
#define newǁƎ(RAIIorNot, destroyOrNot, element, name, definitionArray, arrayDescriptor, dimensions, ...) newWithArrayWithEnvOv(RAIIorNot, destroyOrNot, element, name, definitionArray, arrayDescriptor, dimensions, __VA_ARGS__)
#define newǁNoƎ(RAIIorNot, destroyOrNot, element, name, definitionArray, arrayDescriptor, dimensions, ...) newWithArrayNoEnvOv(RAIIorNot, destroyOrNot, element, name, definitionArray, arrayDescriptor, dimensions, __VA_ARGS__)
#define newƎ(RAIIorNot, destroyOrNot, element, name, ...) newWithEnvOv(, , element, name, __VA_ARGS__)
#define newNoƎ(RAIIorNot, destroyOrNot, element, name, ...) newNoEnvOv(, , element, name, __VA_ARGS__)
#define newϽ(ArrayOrNot, EnvOrNot, RAIIorNot, destroyOrNot, element, name, ...) new##ArrayOrNot##EnvOrNot(RAIIorNot, destroyOrNot, element, name, __VA_ARGS__)
#define newǁ(element, name, definitionArray, arrayDescriptor, dimensions, ...) newǁNoƎ(, , element, name, definitionArray, arrayDescriptor, dimensions, __VA_ARGS__)
#define new(element, name, ...) newNoƎ(, , element, name, __VA_ARGS__)

#define Ͼ operate(&(struct operation) { 0, 0, 0, &gEnv.currentResult, I_STR
#define Ͽ I_STR_)})
#define Ξ Ͽ->
#define Ø void_()

#define private3Method(type, name, ...)     type (*name)(__VA_ARGS__)
#define private2Method(type, name, ...)     encapsulated_t name
#define private1Method(type, name, ...)     encapsulated_t name
#define private0Method(type, name, ...)     encapsulated_t name
#define protected3Method(type, name, ...)   type (*name)(__VA_ARGS__)
#define protected2Method(type, name, ...)   type (*name)(__VA_ARGS__)
#define protected1Method(type, name, ...)   encapsulated_t name
#define protected0Method(type, name, ...)   encapsulated_t name
#define namespace3Method(type, name, ...)   type (*name)(__VA_ARGS__)
#define namespace2Method(type, name, ...)   type (*name)(__VA_ARGS__)
#define namespace1Method(type, name, ...)   type (*name)(__VA_ARGS__)
#define namespace0Method(type, name, ...)   encapsulated_t name
#define public3Method(type, name, ...)      type (*name)(__VA_ARGS__)
#define public2Method(type, name, ...)      type (*name)(__VA_ARGS__)
#define public1Method(type, name, ...)      type (*name)(__VA_ARGS__)
#define public0Method(type, name, ...)      type (*name)(__VA_ARGS__)

#define private3Attribute(type, name)       type name
#define private2Attribute(type, name)       encapsulated_t name
#define private1Attribute(type, name)       encapsulated_t name
#define private0Attribute(type, name)       encapsulated_t name
#define protected3Attribute(type, name)     type name
#define protected2Attribute(type, name)     type name
#define protected1Attribute(type, name)     encapsulated_t name
#define protected0Attribute(type, name)     encapsulated_t name
#define namespace3Attribute(type, name)     type name
#define namespace2Attribute(type, name)     type name
#define namespace1Attribute(type, name)     type name
#define namespace0Attribute(type, name)     encapsulated_t name
#define public3Attribute(type, name)        type name
#define public2Attribute(type, name)        type name
#define public1Attribute(type, name)        type name
#define public0Attribute(type, name)        type name

#define private3Operator(name)              operator_t name
#define private2Operator(name)              encapsulated_t name
#define private1Operator(name)              encapsulated_t name
#define private0Operator(name)              encapsulated_t name
#define protected3Operator(name)            operator_t name
#define protected2Operator(name)            operator_t name
#define protected1Operator(name)            encapsulated_t name
#define protected0Operator(name)            encapsulated_t name
#define namespace3Operator(name)            operator_t name
#define namespace2Operator(name)            operator_t name
#define namespace1Operator(name)            operator_t name
#define namespace0Operator(name)            encapsulated_t name
#define public3Operator(name)               operator_t name
#define public2Operator(name)               operator_t name
#define public1Operator(name)               operator_t name
#define public0Operator(name)               operator_t name

#define PRIVATE 3
#define PROTECTED 2
#define PACKAGE 1
#define PUBLIC 0

#endif

#ifdef CLASS
#   define CLASS_NAME STR(CLASS)
#   if !defined(OBJECT_DESCRIPTOR) || !defined(CLASS_DESCRIPTOR)
#       error "The class :"
#       pragma message CLASS_NAME " is not well described : you have to describe both the Object and the Class definitions."
#   endif
#   define SELF CAT(CLASS,_)

#   ifdef INHERITANCE_DESCRIPTION
#       define extends(className, memberName) struct className memberName;
#       define override(classPath, name, originalThisType, returnedType, newThisType, ...)
#   endif
#   define attribute(visibility, type, name) visibility##0Attribute(type, name);
#   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) Visibility##0Operator(Name);
#   define this struct CLASS *
#   define that struct object *
#   define method(visibility, returnedType, name, ...) visibility##0Method(returnedType, name, __VA_ARGS__);

    struct CLASS
    {
#       ifdef INHERITANCE_DESCRIPTION
            INHERITANCE_DESCRIPTION
#       endif
        OBJECT_DESCRIPTOR
    };

#   ifdef extends
#       undef extends
#       define extends(className, memberName) struct className##_ *memberName;
#   endif

    struct SELF
    {
#       ifdef INHERITANCE_DESCRIPTION
            INHERITANCE_DESCRIPTION
#       endif
        CLASS_DESCRIPTOR
    };

#   ifdef INHERITANCE_DESCRIPTION
#       undef extends
#       undef override
#   endif
#   undef attribute
#   undef operator
#   undef this
#   undef that
#   undef method

#   ifdef OVERLOADING
        struct CAT(CLASS,_overloads)
        {
            enum CAT(CLASS, _options)
            {
#           define method(methodCallName, optionCallName, arguments) CAT3(CLASS, _##methodCallName##_, optionCallName),
#           define defaultMethod(methodCallName) CAT(CLASS, _##methodCallName##_),
                OVERLOADING
#           undef method
#           undef defaultMethod
            } options;
            union
            {
#           define method(methodCallName, optionCallName, arguments) struct CAT3(CLASS, _##methodCallName##_, optionCallName) { arguments; } CAT(_##methodCallName##_, optionCallName);
#           define defaultMethod(methodCallName)
                OVERLOADING
#           undef method
#           undef defaultMethod
            };
            unsigned int numberOfSubInstancesConcerned;
        };
        void CLASS(struct CLASS *, struct CAT(CLASS,_overloads) *);
#   else
        void CLASS(struct CLASS *);
#   endif

    size_t CAT(CLASS,_getSize)(struct SELF **, struct type *);
    void SELF(bool);

#   if DEF(private_, CLASS)
#       define ENCAPSULATION PRIVATE
#       define OBJECT ME
#       define this struct ME *
#   elif DEF(protected_, CLASS)
#       define ENCAPSULATION PROTECTED
#       define OBJECT CAT(protected_,CLASS)
#       define this struct OBJECT *
#   elif DEF(namespace_, CLASS)
#       define ENCAPSULATION PACKAGE
#       define OBJECT CAT(namespace_,CLASS)
#       define this struct OBJECT *
#   else
#       define ENCAPSULATION PUBLIC
#   endif

#   if ENCAPSULATION > PUBLIC
#       ifdef INHERITANCE_DESCRIPTION
#           define extends(className, memberName) struct memberName memberName;
#           define override(classPath, name, originalThisType, returnedType, newThisType, ...)
#       endif
#       define attribute(visibility, type, name) CAT3(visibility, ENCAPSULATION, Attribute)(type, name);
#       define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) CAT3(Visibility, ENCAPSULATION, Operator)(Name);
#       define that struct object *
#       define method(visibility, returnedType, name, ...) CAT3(visibility, ENCAPSULATION, Method)(returnedType, name, __VA_ARGS__);

        struct OBJECT
        {
#           ifdef INHERITANCE_DESCRIPTION
                INHERITANCE_DESCRIPTION
#           endif
            OBJECT_DESCRIPTOR
        };

#       ifdef extends
#           undef extends
#           define extends(className, memberName) struct memberName##_ *memberName;
#       endif

#       undef SELF
#       define SELF CAT(OBJECT,_)
        struct SELF
        {
#           ifdef INHERITANCE_DESCRIPTION
                INHERITANCE_DESCRIPTION
#           endif
            CLASS_DESCRIPTOR
        };

#       ifdef INHERITANCE_DESCRIPTION
#           undef extends
#           undef override
#       endif
#       undef attribute
#       undef operator
#       undef this
#       undef that
#       undef method
#   endif

#   if ENCAPSULATION == PRIVATE
        typedef struct ME This;
        typedef struct SELF Self;
        typedef struct CLASS Id;
        typedef struct CAT(CLASS,_) ID;
#       ifdef OVERLOADING
            typedef struct CAT(CLASS,_overloads) Overloader;
            static void Overloads(This *, Overloader *);
            ALIAS(constructor) void CLASS(Id *, Overloader *);
            INTERNAL void constructor(Id *, Overloader *);
            enum
            {
#           define method(methodCallName, optionCallName, arguments) methodCallName##_##optionCallName = CAT3(CLASS, _##methodCallName##_, optionCallName),
#           define defaultMethod(methodCallName) methodCallName##_ = CAT(CLASS, _##methodCallName##_),
                OVERLOADING
#           undef method
#           undef defaultMethod
            };
#       else
            ALIAS(constructor) void CLASS(Id *);
            INTERNAL void constructor(Id *);
#       endif

        ALIAS(classSetter) size_t CAT(CLASS,_getSize)(ID **, struct type *);
        INTERNAL size_t classSetter(ID **that, struct type *toCorrect);
        ALIAS(destructor) void CAT(CLASS,_)(bool);
#       ifdef INHERITANCE_DESCRIPTION
#           define extends(className, memberName) INTERNAL void CAT(destructorOf,memberName)(bool);
#           define override(classPath, name, originalThisType, returnedType, newThisType, ...)
            INHERITANCE_DESCRIPTION
#       endif
#       ifdef INHERITANCE_DESCRIPTION
#           undef extends
#           undef override
#       endif
        ALIAS(destructor) void CAT(destructorOf,ME)(bool);
        INTERNAL void destructor(bool);
        static Self *self = NULL;

#       ifdef INHERITANCE_DESCRIPTION
#           define extends(className, memberName)
#           define override(classPath, name, originalThisType, returnedType, newThisType, ...)                          \
            TYPE_EQUALITY(self->classPath->name, returnedType (*)(struct object *, originalThisType, ##__VA_ARGS__),    \
            "Conflict types during overriding of method " #name " in " STR(classPath));                                 \
            static returnedType name(newThisType, ##__VA_ARGS__);
#       endif
#       define attribute(visibility, type, name)
#       define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) static union result *CAT(Name, Operation)(union result *, struct object *);       \
        TYPE_EQUALITY(Arity, int, "Wrong arity data type.");                                                                                                        \
        _Static_assert(Arity > 0, "Too low arity, must be higher and positive.");                                                                                   \
        _Static_assert((Arity == 1 && CTL_STR(STR(Tokens)) > 0) || (Arity > 1 && CTL_STR(STR(Tokens)) > Arity-2), "Operator " STR(Name) " has too few tokens.");    \
        _Static_assert(CTL_STR(STR(Name)) > 2, "An Operator in " CLASS_NAME " class declaration has to have a longer name (3 minimum).");                           \
        _Static_assert((sizeof((enum ENV_States []){STRIP Associativity}) / sizeof(enum ENV_States) == (Arity * 2) && Arity == minArity) ||                         \
        (sizeof((enum ENV_States []){STRIP Associativity}) / sizeof(enum ENV_States) == (Arity * 2 - 1) && Arity > minArity),                                       \
        "Operator " STR(Name) " arity or associativity wrongly described : must at least be unary and have the right number of associations for each token.");      \
        TYPE_EQUALITY(Priority, int, "Wrong priority level data type.");                                                                                            \
        _Static_assert(Priority > 0, "Too low priority level, must be higher and positive.");                                                                       \
        _Static_assert(Priority < maxPriority, "Too high priority level, must be lower.");
#       define this This *
#       define that struct object *
#       define method(visibility, returnedType, name, ...) static returnedType name(__VA_ARGS__);
#       ifdef INHERITANCE_DESCRIPTION
            INHERITANCE_DESCRIPTION
#       endif
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR

#       ifdef INHERITANCE_DESCRIPTION
#           undef extends
#           undef override
#       endif
#       undef attribute
#       undef operator
#       undef this
#       undef that
#       undef method

#       ifdef INHERITANCE_DESCRIPTION
#           define extends(className, memberName)
#           define override(classPath, name, originalThisType, returnedType, newThisType, ...) + 1
#           define IS_OVERRIDDEN 0 INHERITANCE_DESCRIPTION
#       else
#           define IS_OVERRIDDEN 0
#       endif

#       if IS_OVERRIDDEN > 0
#           ifndef REFLEXIVITY
#               define REFLEXIVITY
#           endif
#       else
#           undef IS_OVERRIDDEN
#           ifdef REFLEXIVITY
#               undef REFLEXIVITY
#           endif
#       endif

#       ifdef INHERITANCE_DESCRIPTION
#           undef extends
#           undef override
#       endif

#       define attribute(visibility, type, name)
#       define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) + 1
#       define method(visibility, returnedType, name, ...)

#       define NUMBER_OF_OPERATORS 0 OBJECT_DESCRIPTOR CLASS_DESCRIPTOR
#       if NUMBER_OF_OPERATORS > 0
#           ifndef REFLEXIVITY
#               define REFLEXIVITY
#           endif
#           define HAS_OPERATORS

#       undef attribute
#       undef operator
#       undef method

        static operator_t getOperator(char_t *, struct operator *, unsigned int);
#       define OPERATOR_GETTER static operator_t getOperator(char_t *symbolisation,         \
        struct operator *operatorsFromSuperClasses, unsigned int start)                     \
        {                                                                                   \
            operator_t getOperator = NULL;                                                  \
            if(!symbolisation)                                                              \
                for(unsigned int i=start; i < start+reflectInfos.numOperators; ++i)         \
                    operatorsFromSuperClasses[start+i] = operators[i-start];                \
            else                                                                            \
                for(unsigned int i = 0, j = 0; i < reflectInfos.numOperators && !j; ++i)    \
                    if(!strcmp(symbolisation, operators[i].symbolisation))                  \
                        getOperator = &operators[i], j = 1;                                 \
            return getOperator;                                                             \
        }
        enum
        {

#       define attribute(visibility, type, name)
#       define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) Name,
#       define method(visibility, returnedType, name, ...)

            OBJECT_DESCRIPTOR
            CLASS_DESCRIPTOR

#       undef attribute
#       undef operator
#       undef method
            numberOfOperators
        };
        static const struct operator operators[] =
        {
#           define attribute(visibility, type, name)
#           define operator(Visibility, Arity, Associativity, Tokens, Name, Priority)       \
            {                                                                               \
                Arity,                                                                      \
                P_STR(Tokens),                                                              \
                STR(Name),                                                                  \
                Priority,                                                                   \
                (enum ENV_States []) { STRIP Associativity },                               \
                CAT(Name, Operation)                                                        \
            },
#           define method(visibility, returnedType, name, ...)
            OBJECT_DESCRIPTOR
            CLASS_DESCRIPTOR
        };
#       endif

#       undef NUMBER_OF_OPERATORS
#       undef attribute
#       undef operator
#       undef method

#       define attribute(visibility, type, name) 1 +
#       define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) 1 +
#       define method(visibility, returnedType, name, ...) 1 +

#       define IS_NOT_EMPTY_CLASS CLASS_DESCRIPTOR 0

#       if IS_NOT_EMPTY_CLASS == 0
#           define IS_EMPTY_CLASS
#       endif
#       undef IS_NOT_EMPTY_CLASS

#       undef attribute
#       undef operator
#       undef method

#       define INHERIT(super_public_id, super) CAT(super_public_id,_getSize)((struct CAT(super_public_id,_) **) &self->super, toCorrect)
#       ifdef REFLEXIVITY
#           define CLASS_GETTER static struct class *getClass(void) { return &reflectInfos; }
#           ifdef HAS_OPERATORS
#               define OPERATORS_SETTINGS getOperator
#           else
#               define OPERATORS_SETTINGS NULL
#           endif
        static struct class *getClass(void);
        static struct class reflectInfos =
            {
                .name = L_STR(MY_NAME),
                .numObjects = 0,
                .numAttributes =
                (
#                   define attribute(visibility, type, name) 1 +
#                   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority)
#                   define method(visibility, returnedType, name, ...)
                    OBJECT_DESCRIPTOR
                    CLASS_DESCRIPTOR
#                   undef attribute
#                   undef operator
#                   undef method
                0),
                .numOperators =
                (
#                   define attribute(visibility, type, name)
#                   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) 1 +
#                   define method(visibility, returnedType, name, ...)
                    OBJECT_DESCRIPTOR
                    CLASS_DESCRIPTOR
#                   undef attribute
#                   undef operator
#                   undef method
                0),
                .numMethods =
                (
#                   define attribute(visibility, type, name)
#                   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority)
#                   define method(visibility, returnedType, name, ...) 1 +
                    OBJECT_DESCRIPTOR
                    CLASS_DESCRIPTOR
#                   undef attribute
#                   undef operator
#                   undef method
                0),
                .numOverriddenMethods =
                (
#                   ifdef IS_OVERRIDDEN
#                       define extends(className, memberName)
#                       define override(classPath, name, originalThisType, returnedType, newThisType, ...) + 1
                        IS_OVERRIDDEN +
#                       undef extends
#                       undef override
#                   endif
                0),
                .unpackedSize = sizeof(Self) + sizeof(This),
                .packedSize =
                (
#                   ifdef INHERITANCE_DESCRIPTION
#                       define extends(className, memberName) sizeof(struct className) + sizeof(struct CAT(className,_)) +
#                       define override(classPath, name, originalThisType, returnedType, newThisType, ...)
#                   endif
#                   define attribute(visibility, type, name) sizeof(type) +
#                   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) sizeof(struct operator) +
#                   define method(visibility, returnedType, name, ...) sizeof(void *) +
#                   ifdef INHERITANCE_DESCRIPTION
                        INHERITANCE_DESCRIPTION
#                   endif
                    OBJECT_DESCRIPTOR
                    CLASS_DESCRIPTOR
#                   ifdef INHERITANCE_DESCRIPTION
#                       undef extends
#                       undef override
#                   endif
#                   undef attribute
#                   undef operator
#                   undef method
                0),
                .offsets = (size_t [])
                {
#                   ifdef INHERITANCE_DESCRIPTION
#                       define extends(className, memberName) offsetof(This, memberName),
#                       define override(classPath, name, originalThisType, returnedType, newThisType, ...)
#                   endif
#                   define attribute(visibility, type, name) offsetof(This, name),
#                   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) offsetof(This, Name),
#                   define method(visibility, returnedType, name, ...) offsetof(This, name),
#                   ifdef INHERITANCE_DESCRIPTION
                        INHERITANCE_DESCRIPTION
#                   endif
                    OBJECT_DESCRIPTOR
#                   ifdef INHERITANCE_DESCRIPTION
#                       undef extends
#                       undef override
#                   endif
#                   undef attribute
#                   undef operator
#                   undef method
#                   ifdef INHERITANCE_DESCRIPTION
#                       define extends(className, memberName) offsetof(Self, memberName),
#                       define override(classPath, name, originalThisType, returnedType, newThisType, ...)
#                   endif
#                   define attribute(visibility, type, name) offsetof(Self, name),
#                   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) offsetof(Self, Name),
#                   define method(visibility, returnedType, name, ...) offsetof(Self, name),
#                   ifdef INHERITANCE_DESCRIPTION
                        INHERITANCE_DESCRIPTION
#                   endif
                    CLASS_DESCRIPTOR
#                   ifdef INHERITANCE_DESCRIPTION
#                       undef extends
#                       undef override
#                   endif
#                   undef attribute
#                   undef operator
#                   undef method
                },
                .sizes = (size_t [])
                {
#                   ifdef INHERITANCE_DESCRIPTION
#                       define extends(className, memberName) sizeof(struct className) + sizeof(struct CAT(className,_)),
#                       define override(classPath, name, originalThisType, returnedType, newThisType, ...)
#                   endif
#                   define attribute(visibility, type, name) sizeof(type),
#                   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) sizeof(struct operator),
#                   define method(visibility, returnedType, name, ...) sizeof(void *),
#                   ifdef INHERITANCE_DESCRIPTION
                        INHERITANCE_DESCRIPTION
#                   endif
                    OBJECT_DESCRIPTOR
                    CLASS_DESCRIPTOR
#                   ifdef INHERITANCE_DESCRIPTION
#                       undef extends
#                       undef override
#                   endif
#                   undef attribute
#                   undef operator
#                   undef method
                },
                .memberNames = (const char *[])
                {
#                   ifdef INHERITANCE_DESCRIPTION
#                       define extends(className, memberName)
#                       define override(classPath, name, originalThisType, returnedType, newThisType, ...) #name,
#                   endif
#                   define attribute(visibility, type, name) #name,
#                   define operator(Visibility, Arity, Associativity, Tokens, Name, Priority) #Name,
#                   define method(visibility, returnedType, name, ...) #name,
#                   ifdef INHERITANCE_DESCRIPTION
                        INHERITANCE_DESCRIPTION
#                   endif
                    OBJECT_DESCRIPTOR
                    CLASS_DESCRIPTOR
#                   ifdef INHERITANCE_DESCRIPTION
#                       undef extends
#                       undef override
#                   endif
#                   undef attribute
#                   undef operator
#                   undef method
                },
                .getVE = findVirtualElement,
                .pack = packClass,
                .unpack = unpackClass,
                .print = printClass,
                .getOperator = OPERATORS_SETTINGS,
#               ifdef IS_OVERRIDDEN
#                   define extends(className, memberName)
#                   define override(classPath, name, originalThisType, returnedType, newThisType, ...) (void *(*)()) name,
#                   define OVERRIDING_SETTINGS (void *(*[])()) { INHERITANCE_DESCRIPTION }
#               else
#                   define OVERRIDING_SETTINGS NULL
#               endif
                .virtual = OVERRIDING_SETTINGS,
#               ifdef IS_OVERRIDDEN
#                   undef extends
#                   undef override
#               endif
#               ifdef IS_EMPTY_CLASS
#                   define EMPTY_CLASS_SETTINGS true
#               else
#                   define EMPTY_CLASS_SETTINGS false
#               endif
#               undef OVERLOADING_SETTINGS
#               ifdef OVERLOADING
#                   define OVERLOADING_SETTINGS true
#               else
#                   define OVERLOADING_SETTINGS false
#               endif
#               undef OVERRIDING_SETTINGS
#               ifdef IS_OVERRIDDEN
#                   define OVERRIDING_SETTINGS true
#               else
#                   define OVERRIDING_SETTINGS false
#               endif
#               undef OPERATORS_SETTINGS
#               ifdef HAS_OPERATORS
#                   define OPERATORS_SETTINGS true
#               else
#                   define OPERATORS_SETTINGS false
#               endif
                .settings =
                {
                    OPERATORS_SETTINGS,
                    OVERLOADING_SETTINGS,
                    OVERRIDING_SETTINGS,
                    EMPTY_CLASS_SETTINGS
                }
            };

#           define REFLEXIVITY_SETTINGS reflectInfos.numObjects++;
#       else
#           define REFLEXIVITY_SETTINGS
#       endif
#       define CLASS_SETTER(inheritances, ...)      \
        INTERNAL size_t classSetter                 \
        (ID **that, struct type *toCorrect)         \
        {                                           \
             if(!self)                              \
             {                                      \
                 self = NAMESPACE.ME =              \
                 (alloc)(sizeof(Self));             \
                 *self = (Self)                     \
                 {                                  \
                     __VA_ARGS__                    \
                 };                                 \
                 IMPORT_CALL                        \
                 REFLEXIVITY_SETTINGS               \
                 STRIP inheritances;                \
             }                                      \
             *toCorrect = (struct type)             \
             {                                      \
                 sizeof(This),                      \
                 MY_NAME,                           \
                 setTypeId(MY_NAME),                \
                 CTL_STR(MY_NAME)                   \
             };                                     \
             *that = (ID *) self;                   \
             return toCorrect->size;                \
        }
#   endif

#   undef ENCAPSULATION
#   ifdef INHERITANCE_DESCRIPTION
#       undef INHERITANCE_DESCRIPTION
#   endif
#   ifdef OVERLOADING
#       undef OVERLOADING
#   endif
#   undef OBJECT_DESCRIPTOR
#   undef CLASS_DESCRIPTOR
#   undef CLASS_NAME
#   undef SELF
#   ifdef OBJECT
#       undef OBJECT
#   endif
#   undef CLASS
#elif defined(NAMESPACE)
#   ifndef NAMESPACE_CONTENT
#       error "The namespace content of "
#       pragma message STR(NAMESPACE) " is not defined."
#   else
#       if DEF(namespace_, NAMESPACE)
#           define CLASS(typeElementName, memberName) struct CAT(memberName,_) *memberName;
#           define SUBNAMESPACE(typeElementName, memberName) struct typeElementName memberName;
#       else
#           define CLASS(typeElementName, memberName) struct CAT(typeElementName,_) *memberName;
#           define SUBNAMESPACE(typeElementName, memberName) struct typeElementName memberName;
#       endif
        extern struct NAMESPACE
        {
            NAMESPACE_CONTENT
        } NAMESPACE;
#       undef CLASS
#       undef SUBNAMESPACE
#       define CLASS(typeElementName, memberName)
#       define SUBNAMESPACE(typeElementName, memberName) 1 +
#       define IMPORT_NAMESPACE NAMESPACE_CONTENT 0
#       if DEF(namespace_, NAMESPACE)
#           if IMPORT_NAMESPACE > 0
#               define IMPORT CAT(NAMESPACE,_import)
                void IMPORT(void);
#               define IMPORT_CALL CAT(NAMESPACE,_import)();
#           else
#               define IMPORT_CALL
#           endif
#       else
#           undef NAMESPACE
#       endif
#       undef CLASS
#       undef SUBNAMESPACE
#       undef IMPORT_NAMESPACE
#       undef NAMESPACE_CONTENT
#   endif
#endif
