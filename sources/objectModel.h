#ifndef OBJECT_MODEL_H
#define OBJECT_MODEL_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "exceptionManager.h"

#define STR_(A) #A
#define STR(A) STR_(A)
#define CAT_(A, B) A ## B
#define CAT(A, B) CAT_(A, B)
#define ENCAPSULATED const void * const
#define NOTNULL (void *) ~(unsigned long long) NULL
#define FC_WITH_OV(ov_arg) &(struct CAT(ov_arg,_overloads)){.options = CAT(ov_arg,_new_)}
#define PC_WITH_OV NULL
#define FC_WITHOUT_OV true
#define PC_WITHOUT_OV false
#define $YES true
#define $NO false

struct class
{
    char const *name;
    size_t num_objects;
    size_t num_attributes;
    size_t num_methods;
    size_t unpacked_size;
    size_t packed_size;
    size_t *offsets;
    size_t *sizes;
    char const **names;
    void (*print_buffer)(unsigned char *, size_t);
    size_t (*pack)(void *, unsigned char *, struct class *);
    size_t (*unpack)(unsigned char *, void *, struct class *);
    void (*print_all)(void *, struct class *);
};

struct entity
{
    void *instance;
    struct entity *next;
};

struct list
{
    struct entity *first;
    int size;
};

void main_coop(void);
void *(new)(size_t);
void *(new_)(size_t);
void integrate_reflexivity(struct class *);
void garbage_collector(void);

#define new(entity) new(sizeof(struct entity))
#define new_(primitive) new_(sizeof(primitive))

#endif //OBJECT_MODEL_H

#ifdef CLASS
#if !defined(OBJECT_DESCRIPTOR) || !defined(CLASS_DESCRIPTOR)
    #error "The class :"
    #pragma message STR(CLASS) " is not well described."
#endif

#define __CLASS_NAME__ STR(CLASS)
#define class_declaration_name CAT(CLASS,_)
#define object_declaration_name CLASS

#define EXTENDS_OD(className, memberName) struct className *memberName;
#define EXTENDS_CD(className, memberName) struct CAT(className,_) *memberName;
#define ATTRIBUTE(visibility, type, name) type name;
#define METHOD_CD(visibility, returnedType, name, ...) returnedType (*(name))(struct class_declaration_name *self, __VA_ARGS__);
#define METHOD_OD(visibility, returnedType, name, ...) returnedType (*(name))(struct object_declaration_name *this, __VA_ARGS__);

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

#ifdef REFLEXIVITY

static struct class reflectInfos =
{
    .name = __CLASS_NAME__,
    .num_objects = (0),
    .num_attributes =
            (
    #define EXTENDS_OD(className, memberName)
    #define EXTENDS_CD(className, memberName)
    #define ATTRIBUTE(visibility, type, name) 1 +
    #define METHOD_CD(visibility, returnedType, name, ...)
    #define METHOD_OD(visibility, returnedType, name, ...)
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef EXTENDS_OD
    #undef EXTENDS_CD
    #undef ATTRIBUTE
    #undef METHOD_CD
    #undef METHOD_OD
            0),
    .num_methods =
            (
    #define EXTENDS_OD(className, memberName)
    #define EXTENDS_CD(className, memberName)
    #define ATTRIBUTE(visibility, type, name)
    #define METHOD_CD(visibility, returnedType, name, ...) 1 +
    #define METHOD_OD(visibility, returnedType, name, ...) 1 +
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef EXTENDS_OD
    #undef EXTENDS_CD
    #undef ATTRIBUTE
    #undef METHOD_CD
    #undef METHOD_OD
            0),
    .unpacked_size = sizeof(struct class_declaration_name) + sizeof(struct object_declaration_name),
    .packed_size =
            (
    #define EXTENDS_OD(className, memberName)
    #define EXTENDS_CD(className, memberName)
    #define ATTRIBUTE(visibility, type, name) sizeof(type) +
    #define METHOD_CD(visibility, returnedType, name, ...) sizeof(void *) +
    #define METHOD_OD(visibility, returnedType, name, ...) sizeof(void *) +
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef EXTENDS_OD
    #undef EXTENDS_CD
    #undef ATTRIBUTE
    #undef METHOD_CD
    #undef METHOD_OD
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
        CLASS_DESCRIPTOR
    #undef EXTENDS_CD
    #undef ATTRIBUTE
    #undef METHOD_CD
    #undef METHOD_OD
            },
    .sizes = (size_t [])
            {
    #define EXTENDS_OD(className, memberName)
    #define EXTENDS_CD(className, memberName)
    #define ATTRIBUTE(visibility, type, name) sizeof(type),
    #define METHOD_CD(visibility, returnedType, name, ...) sizeof(void *),
    #define METHOD_OD(visibility, returnedType, name, ...) sizeof(void *),
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef EXTENDS_OD
    #undef EXTENDS_CD
    #undef ATTRIBUTE
    #undef METHOD_CD
    #undef METHOD_OD
            },
    .names = (char const *[])
            {
    #define EXTENDS_OD(className, memberName)
    #define EXTENDS_CD(className, memberName)
    #define ATTRIBUTE(visibility, type, name) #type " : " #name ,
    #define METHOD_CD(visibility, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
    #define METHOD_OD(visibility, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef EXTENDS_OD
    #undef EXTENDS_CD
    #undef ATTRIBUTE
    #undef METHOD_CD
    #undef METHOD_OD
            },
    .print_buffer = NULL,
    .pack = NULL,
    .unpack = NULL,
    .print_all = NULL
};

#endif

#define EXTENDS_OD(className, memberName)
#define EXTENDS_CD(className, memberName)
#define ATTRIBUTE(visibility, type, name)
#define METHOD_CD(visibility, returnedType, name, ...) static returnedType name(struct class_declaration_name *, __VA_ARGS__);
#define METHOD_OD(visibility, returnedType, name, ...) static returnedType name(struct object_declaration_name *, __VA_ARGS__);

OBJECT_DESCRIPTOR
CLASS_DESCRIPTOR
static void create(struct class_declaration_name *);

#undef EXTENDS_OD
#undef EXTENDS_CD
#undef ATTRIBUTE
#undef METHOD_CD
#undef METHOD_OD

#define EXTENDS_OD(className, memberName)
#define EXTENDS_CD(className, memberName)
#define ATTRIBUTE(visibility, type, name)
#define METHOD_CD(visibility, returnedType, name, ...) self->name = name;
#define METHOD_OD(visibility, returnedType, name, ...) self->name = name;

#else
struct class_declaration_name
{
    CLASS_DESCRIPTOR
};

#undef class_declaration_name
#undef object_declaration_name

#undef EXTENDS_OD
#undef EXTENDS_CD
#undef ATTRIBUTE
#undef METHOD_CD
#undef METHOD_OD

#undef CLASS_DESCRIPTOR
#undef OBJECT_DESCRIPTOR

#undef __CLASS_NAME__
#undef CLASS

#endif
#elif defined(INTERFACE)

#ifndef IMPLEMENTS
    #warning "The interface :"
    #pragma message STR(NAME) " is not implemented."
#else
#define METHOD_R(returnedType, inheritedClass, name, ...) returnedType (*(CAT(name,inheritedClass)))(__VA_ARGS__);

struct IMPLEMENTS
{
    INTERFACE
};

#undef METHOD_R

#define METHOD_R(returnedType, inheritedClass, name, ...) static returnedType CAT(name,inheritedClass)(__VA_ARGS__);

INTERFACE

#undef IMPLEMENTS
#undef METHOD_R

#endif

#undef NAME
#undef INTERFACE
#endif //CLASS OR INTERFACE
