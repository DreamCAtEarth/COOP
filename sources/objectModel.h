#ifndef OBJECT_MODEL_H
#define OBJECT_MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "exceptionManager.h"
#include "collections/simplyLinkedList.h"

#define STR_(A) #A
#define STR(A) STR_(A)
#define CAT_(A, B) A ## B
#define CAT(A, B) CAT_(A, B)
#define CAT3_(A, B, C) A ## B ## C
#define CAT3(A, B, C) CAT3_(A, B, C)
#define ENCAPSULATED const void * const

struct new_args
{
    void (*constructor)(void *, void *);
    void (*destructor)(void);
    size_t (*getSize)(void *);
    char *strDimensionsAndLengths;
    char *objectName;
    void *class;
    void *instance_args;
};

struct object
{
    void (*destructor)(void);
    char *name;
    void *class;
    void *instance;
    int dimensions;
    size_t *lengths;
    size_t totalSize;
};

struct class
{
    char const *name;
    size_t numObjects;
    size_t numAttributes;
    size_t numMethods;
    size_t unpackedSize;
    size_t packedSize;
    size_t *offsets;
    size_t *sizes;
    char const **memberNames;
    size_t (*pack)(void *, unsigned char *, struct class *);
    size_t (*unpack)(unsigned char *, void *, struct class *);
    void (*print)(void *, struct class *);
};

void *(new)(struct new_args *args);
struct object *(find)(void *object);
void (delete)(void *object);
void (reflex)(struct class *elementsToReflect);
size_t (getLength)(void *object);
void (garbageCollector)(void);

#define NEW(element, name, declarationArray, option, ...)                   \
__attribute__((cleanup(delete))) struct element (*name)declarationArray =   \
(new)                                                                       \
(                                                                           \
    &(struct new_args)                                                      \
    {                                                                       \
        (void (*)(void *, void *)) element,                                 \
        (void (*)(void)) CAT(element,_),                                    \
        (size_t (*)(void *)) CAT(element,_getSize),                         \
        STR(declarationArray),                                              \
        STR(name),                                                          \
        NULL,                                                               \
        &(struct CAT(element,_overloads))                                   \
        {                                                                   \
            .options = CAT3(element,_new_,option),                          \
            .CAT(new_,option)= {__VA_ARGS__}                                \
        }                                                                   \
    }                                                                       \
)

#define NEW_(element, name, declarationArray, ...) NEW(element, name, declarationArray, __VA_ARGS__)
#define new(element, name, ...) NEW_(element, name, __VA_ARGS__)

#endif //OBJECT_MODEL_H

#ifdef CLASS
#if !defined(OBJECT_DESCRIPTOR) || !defined(CLASS_DESCRIPTOR)
    #error "The class :"
    #pragma message STR(CLASS) " is not well described."
#endif

#define __CLASS_NAME__ STR(CLASS)
#define class_declaration_name CAT(CLASS,_)
#define object_declaration_name CLASS

#define EXTENDS_OD(className, memberName) struct className memberName;
#define EXTENDS_CD(className, memberName) struct CAT(className,_) *memberName;
#define ATTRIBUTE(visibility, type, name) type name;
#define METHOD_CD(visibility, returnedType, name, ...) returnedType (*name)(struct class_declaration_name *, ##__VA_ARGS__);
#define METHOD_OD(visibility, returnedType, name, ...) returnedType (*name)(struct object_declaration_name *, ##__VA_ARGS__);
#define METHOD_SA(visibility, returnedType, name, ...) returnedType (*name)(__VA_ARGS__);
#define METHOD_IM(visibility, returnedType, interface, name, ...) returnedType (*(CAT3(interface, _, name)))(void *, ##__VA_ARGS__);

struct object_declaration_name
{
    OBJECT_DESCRIPTOR
};

#ifdef CLASS_PUBLIC_ID
static struct class_declaration_name
{
    CLASS_DESCRIPTOR
}*self = NULL;

#undef EXTENDS_OD
#undef EXTENDS_CD
#undef ATTRIBUTE
#undef METHOD_CD
#undef METHOD_OD
#undef METHOD_SA
#undef METHOD_IM

#ifdef REFLEXIVITY
    static struct class reflectInfos =
    {
        .name = __CLASS_NAME__,
        .numObjects = (0),
        .numAttributes =
                (
        #define EXTENDS_OD(className, memberName)
        #define EXTENDS_CD(className, memberName)
        #define ATTRIBUTE(visibility, type, name) 1 +
        #define METHOD_CD(visibility, returnedType, name, ...)
        #define METHOD_OD(visibility, returnedType, name, ...)
        #define METHOD_SA(visibility, returnedType, name, ...)
        #define METHOD_IM(visibility, returnedType, interface, name, ...)
            OBJECT_DESCRIPTOR
            CLASS_DESCRIPTOR
        #undef EXTENDS_OD
        #undef EXTENDS_CD
        #undef ATTRIBUTE
        #undef METHOD_CD
        #undef METHOD_OD
        #undef METHOD_SA
        #undef METHOD_IM
                0),
        .numMethods =
                (
        #define EXTENDS_OD(className, memberName)
        #define EXTENDS_CD(className, memberName)
        #define ATTRIBUTE(visibility, type, name)
        #define METHOD_CD(visibility, returnedType, name, ...) 1 +
        #define METHOD_OD(visibility, returnedType, name, ...) 1 +
        #define METHOD_SA(visibility, returnedType, name, ...) 1 +
        #define METHOD_IM(visibility, returnedType, interface, name, ...) 1 +
            OBJECT_DESCRIPTOR
            CLASS_DESCRIPTOR
        #undef EXTENDS_OD
        #undef EXTENDS_CD
        #undef ATTRIBUTE
        #undef METHOD_CD
        #undef METHOD_OD
        #undef METHOD_SA
        #undef METHOD_IM
                0),
        .unpackedSize = sizeof(struct class_declaration_name) + sizeof(struct object_declaration_name),
        .packedSize =
                (
        #define EXTENDS_OD(className, memberName)
        #define EXTENDS_CD(className, memberName)
        #define ATTRIBUTE(visibility, type, name) sizeof(type) +
        #define METHOD_CD(visibility, returnedType, name, ...) sizeof(void *) +
        #define METHOD_OD(visibility, returnedType, name, ...) sizeof(void *) +
        #define METHOD_SA(visibility, returnedType, name, ...) sizeof(void *) +
        #define METHOD_IM(visibility, returnedType, interface, name, ...) sizeof(void *) +
            OBJECT_DESCRIPTOR
            CLASS_DESCRIPTOR
        #undef EXTENDS_OD
        #undef EXTENDS_CD
        #undef ATTRIBUTE
        #undef METHOD_CD
        #undef METHOD_OD
        #undef METHOD_SA
        #undef METHOD_IM
                0),
        .offsets = (size_t [])
                {
        #define EXTENDS_OD(className, memberName)
        #define ATTRIBUTE(visibility, type, name) offsetof(struct object_declaration_name, name),
            OBJECT_DESCRIPTOR
        #undef EXTENDS_OD
        #undef ATTRIBUTE
        #define EXTENDS_CD(className, memberName)
        #define ATTRIBUTE(visibility, type, name) offsetof(struct class_declaration_name, name),
        #define METHOD_CD(visibility, returnedType, name, ...) offsetof(struct class_declaration_name, name),
        #define METHOD_OD(visibility, returnedType, name, ...) offsetof(struct class_declaration_name, name),
        #define METHOD_SA(visibility, returnedType, name, ...) offsetof(struct class_declaration_name, name),
        #define METHOD_IM(visibility, returnedType, interface, name, ...) offsetof(struct class_declaration_name, CAT3(interface, _, name)),
            CLASS_DESCRIPTOR
        #undef EXTENDS_CD
        #undef ATTRIBUTE
        #undef METHOD_CD
        #undef METHOD_OD
        #undef METHOD_SA
        #undef METHOD_IM
                },
        .sizes = (size_t [])
                {
        #define EXTENDS_OD(className, memberName)
        #define EXTENDS_CD(className, memberName)
        #define ATTRIBUTE(visibility, type, name) sizeof(type),
        #define METHOD_CD(visibility, returnedType, name, ...) sizeof(void *),
        #define METHOD_OD(visibility, returnedType, name, ...) sizeof(void *),
        #define METHOD_SA(visibility, returnedType, name, ...) sizeof(void *),
        #define METHOD_IM(visibility, returnedType, interface, name, ...) sizeof(void *),
            OBJECT_DESCRIPTOR
            CLASS_DESCRIPTOR
        #undef EXTENDS_OD
        #undef EXTENDS_CD
        #undef ATTRIBUTE
        #undef METHOD_CD
        #undef METHOD_OD
        #undef METHOD_SA
        #undef METHOD_IM
                },
        .memberNames = (char const *[])
                {
        #define EXTENDS_OD(className, memberName)
        #define EXTENDS_CD(className, memberName)
        #define ATTRIBUTE(visibility, type, name) #type " : " #name ,
        #define METHOD_CD(visibility, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
        #define METHOD_OD(visibility, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
        #define METHOD_SA(visibility, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
        #define METHOD_IM(visibility, returnedType, interface, name, ...) #returnedType " : " STR(CAT3(interface, _, name)) " (" #__VA_ARGS__ ") ",
            OBJECT_DESCRIPTOR
            CLASS_DESCRIPTOR
        #undef EXTENDS_OD
        #undef EXTENDS_CD
        #undef ATTRIBUTE
        #undef METHOD_CD
        #undef METHOD_OD
        #undef METHOD_SA
        #undef METHOD_IM
                },
        .pack = NULL,
        .unpack = NULL,
        .print = NULL
    };
#endif

static struct exception exception;

#define EXTENDS_OD(className, memberName)
#define EXTENDS_CD(className, memberName)
#define ATTRIBUTE(visibility, type, name)
#define METHOD_CD(visibility, returnedType, name, ...) static returnedType name(struct class_declaration_name *, ##__VA_ARGS__);
#define METHOD_OD(visibility, returnedType, name, ...) static returnedType name(struct object_declaration_name *, ##__VA_ARGS__);
#define METHOD_SA(visibility, returnedType, name, ...) static returnedType name(__VA_ARGS__);
#define METHOD_IM(visibility, returnedType, interface, name, ...)

OBJECT_DESCRIPTOR
CLASS_DESCRIPTOR

#undef EXTENDS_OD
#undef EXTENDS_CD
#undef ATTRIBUTE
#undef METHOD_CD
#undef METHOD_OD
#undef METHOD_SA
#undef METHOD_IM

#undef class_declaration_name
#undef object_declaration_name

#undef CLASS_DESCRIPTOR
#undef OBJECT_DESCRIPTOR

#else
struct class_declaration_name
{
    CLASS_DESCRIPTOR
};

#undef EXTENDS_OD
#undef EXTENDS_CD
#undef ATTRIBUTE
#undef METHOD_CD
#undef METHOD_OD
#undef METHOD_SA
#undef METHOD_IM

#undef class_declaration_name
#undef object_declaration_name

#undef CLASS_DESCRIPTOR
#undef OBJECT_DESCRIPTOR

#undef __CLASS_NAME__
#undef CLASS

#endif
#elif defined(INTERFACE)
#ifndef IMPLEMENTS
    #error "The interface :"
    #pragma message STR(INTERFACE) " is not implemented."
#else

#define METHOD(returnedType, inheritedInterface, name, ...) static returnedType CAT3(inheritedInterface,_,name)(void *, ##__VA_ARGS__);

INTERFACE_DESCRIPTOR

#undef IMPLEMENTS
#undef METHOD

#endif

#undef INTERFACE_DESCRIPTOR
#undef INTERFACE
#elif defined(PACKAGE)
#ifndef PACKAGE_CONTENT
    #warning "The package :"
    #pragma message STR(PACKAGE) " is empty."
#else

#define CLASS(typeElementName, memberName) struct typeElementName *memberName;
#define SUBPACKAGE(typeElementName, memberName) struct typeElementName memberName;

extern struct PACKAGE
{
    PACKAGE_CONTENT
}PACKAGE;

#undef CLASS
#undef SUBPACKAGE
#undef PACKAGE_CONTENT
#endif

#undef PACKAGE
#endif //CLASS OR INTERFACE OR PACKAGE
