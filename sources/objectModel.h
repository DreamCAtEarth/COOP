#ifndef OBJECT_MODEL_H
#define OBJECT_MODEL_H

#include "exceptionManager.h"

#define STR_NOEXPAND(A) #A
#define STR(A) STR_NOEXPAND(A)
#define CAT_NOEXPAND(A, B) A ## B
#define CAT(A, B) CAT_NOEXPAND(A, B)
#define ENCAPSULATED const void * const

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
};

void main_coop(void);
void *(new)(size_t);
void *(new_)(size_t);
void integrate_reflexivity(struct class *elementsToReflect);
void garbage_collector(void);

struct entity
{
    void *instance;
    struct class reflexivity;
    struct entity *next;
    void (*print_buffer)(unsigned char *, size_t);
    size_t (*pack)(void *, unsigned char *);
    size_t (*unpack)(unsigned char *, void *);
    void (*print_all)(void *);
};

#define new(entity) new(sizeof(struct entity))
#define new_(primitive) new_(sizeof(primitive))

#endif //OBJECT_MODEL_H

#ifdef CLASS
#if !defined(OBJECT_DESCRIPTOR) || !defined(CLASS_DESCRIPTOR)
    #error "Did not define one of the two descriptors required for the definition of the class."
#endif

#define __CLASS_NAME__ STR(CLASS)
#define class_declaration_name CAT(CLASS,_)
#define object_declaration_name CLASS

#define ATTRIBUTE(visibility, type, name) type name;
#define METHOD_CD(visibility, returnedType, name, ...) returnedType (*(name))(struct class_declaration_name *self, __VA_ARGS__);
#define METHOD_ID(visibility, returnedType, name, ...) returnedType (*(name))(struct object_declaration_name *this, __VA_ARGS__);
#define ATTRIBUTE_R(visibility, inheritedClass, type, name) type CAT(name,inheritedClass);
#define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) returnedType (*(CAT(name,inheritedClass)))(struct class_declaration_name *self, __VA_ARGS__);
#define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) returnedType (*(CAT(name,inheritedClass)))(struct object_declaration_name *this, __VA_ARGS__);

#ifdef CLASS_DEFINITION
#define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) returnedType (*(name))(struct class_declaration_name *self, __VA_ARGS__);
#define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) returnedType (*(name))(struct object_declaration_name *this, __VA_ARGS__);
#define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) returnedType (*(CAT(name,inheritedClass)))(struct class_declaration_name *self, __VA_ARGS__);
#define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) returnedType (*(CAT(name,inheritedClass)))(struct object_declaration_name *this, __VA_ARGS__);
#endif

struct object_declaration_name
{
    struct class_declaration_name *class;
    OBJECT_DESCRIPTOR
};

#ifdef CLASS_DEFINITION
static struct class_declaration_name
{
    CLASS_DESCRIPTOR
}*self = NULL;

#undef ATTRIBUTE
#undef ATTRIBUTE_R
#undef METHOD_CD
#undef METHOD_ID
#undef METHOD_CD_R
#undef METHOD_ID_R
#undef PARENT_METHOD_CD
#undef PARENT_METHOD_ID
#undef MIMR_CD
#undef MIMR_ID

#ifdef REFLEXIVITY
#include <stddef.h>

static struct class reflectInfos =
{
    .name = __CLASS_NAME__,
    .num_objects = (0),
    .num_attributes =
            (
    #define ATTRIBUTE(visibility, type, name) 1 +
    #define ATTRIBUTE_R(visibility, inheritedClass, type, name) 1 +
    #define METHOD_CD(visibility, returnedType, name, ...)
    #define METHOD_ID(visibility, returnedType, name, ...)
    #define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...)
    #define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...)
    #define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...)
    #define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...)
    #define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...)
    #define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...)
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef ATTRIBUTE
    #undef ATTRIBUTE_R
    #undef METHOD_CD
    #undef METHOD_ID
    #undef METHOD_CD_R
    #undef METHOD_ID_R
    #undef PARENT_METHOD_CD
    #undef PARENT_METHOD_ID
    #undef MIMR_CD
    #undef MIMR_ID
            0),
    .num_methods =
            (
    #define ATTRIBUTE(visibility, type, name)
    #define ATTRIBUTE_R(visibility, inheritedClass, type, name)
    #define METHOD_CD(visibility, returnedType, name, ...) 1 +
    #define METHOD_ID(visibility, returnedType, name, ...) 1 +
    #define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) 1 +
    #define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) 1 +
    #define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) 1 +
    #define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) 1 +
    #define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) 1 +
    #define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) 1 +
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef ATTRIBUTE
    #undef ATTRIBUTE_R
    #undef METHOD_CD
    #undef METHOD_ID
    #undef METHOD_CD_R
    #undef METHOD_ID_R
    #undef PARENT_METHOD_CD
    #undef PARENT_METHOD_ID
    #undef MIMR_CD
    #undef MIMR_ID
            0),
    .unpacked_size = sizeof(struct class_declaration_name) + sizeof(struct object_declaration_name),
    .packed_size =
            (
    #define ATTRIBUTE(visibility, type, name) sizeof(type) +
    #define ATTRIBUTE_R(visibility, inheritedClass, type, name) sizeof(type) +
    #define METHOD_CD(visibility, returnedType, name, ...) sizeof(void *) +
    #define METHOD_ID(visibility, returnedType, name, ...) sizeof(void *) +
    #define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) sizeof(void *) +
    #define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) sizeof(void *) +
    #define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) sizeof(void *) +
    #define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) sizeof(void *) +
    #define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) sizeof(void *) +
    #define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) sizeof(void *) +
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef ATTRIBUTE
    #undef ATTRIBUTE_R
    #undef METHOD_CD
    #undef METHOD_ID
    #undef METHOD_CD_R
    #undef METHOD_ID_R
    #undef PARENT_METHOD_CD
    #undef PARENT_METHOD_ID
    #undef MIMR_CD
    #undef MIMR_ID
            0),
    .offsets = (size_t [])
            {
    #define ATTRIBUTE(visibility, type, name) offsetof(struct object_declaration_name, name),
    #define ATTRIBUTE_R(visibility, inheritedClass, type, name) offsetof(struct object_declaration_name, name),
        OBJECT_DESCRIPTOR
    #undef ATTRIBUTE
    #undef ATTRIBUTE_R
    #define ATTRIBUTE(visibility, type, name) offsetof(struct class_declaration_name, name),
    #define ATTRIBUTE_R(visibility, inheritedClass, type, name) offsetof(struct class_declaration_name, name),
    #define METHOD_CD(visibility, returnedType, name, ...) offsetof(struct class_declaration_name, name),
    #define METHOD_ID(visibility, returnedType, name, ...) offsetof(struct class_declaration_name, name),
    #define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) offsetof(struct class_declaration_name, name),
    #define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) offsetof(struct class_declaration_name, name),
    #define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) offsetof(struct class_declaration_name, name),
    #define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) offsetof(struct class_declaration_name, name),
    #define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) offsetof(struct class_declaration_name, name),
    #define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) offsetof(struct class_declaration_name, name),
        CLASS_DESCRIPTOR
    #undef ATTRIBUTE
    #undef ATTRIBUTE_R
    #undef METHOD_CD
    #undef METHOD_ID
    #undef METHOD_CD_R
    #undef METHOD_ID_R
    #undef PARENT_METHOD_CD
    #undef PARENT_METHOD_ID
    #undef MIMR_CD
    #undef MIMR_ID
            },
    .sizes = (size_t [])
            {
    #define ATTRIBUTE(visibility, type, name) sizeof(type),
    #define ATTRIBUTE_R(visibility, inheritedClass, type, name) sizeof(type),
    #define METHOD_CD(visibility, returnedType, name, ...) sizeof(void *),
    #define METHOD_ID(visibility, returnedType, name, ...) sizeof(void *),
    #define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) sizeof(void *),
    #define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) sizeof(void *),
    #define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) sizeof(void *),
    #define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) sizeof(void *),
    #define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) sizeof(void *),
    #define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) sizeof(void *),
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef ATTRIBUTE
    #undef ATTRIBUTE_R
    #undef METHOD_CD
    #undef METHOD_ID
    #undef METHOD_CD_R
    #undef METHOD_ID_R
    #undef PARENT_METHOD_CD
    #undef PARENT_METHOD_ID
    #undef MIMR_CD
    #undef MIMR_ID
            },
    .names = (char const *[])
            {
    #define ATTRIBUTE(visibility, type, name) #type " : " #name ,
    #define ATTRIBUTE_R(visibility, inheritedClass, type, name) #type " : " #name ,
    #define METHOD_CD(visibility, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
    #define METHOD_ID(visibility, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
    #define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
    #define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
    #define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
    #define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
    #define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
    #define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) #returnedType " : " #name " (" #__VA_ARGS__ ") ",
        OBJECT_DESCRIPTOR
        CLASS_DESCRIPTOR
    #undef ATTRIBUTE
    #undef ATTRIBUTE_R
    #undef METHOD_CD
    #undef METHOD_ID
    #undef METHOD_CD_R
    #undef METHOD_ID_R
    #undef PARENT_METHOD_CD
    #undef PARENT_METHOD_ID
    #undef MIMR_CD
    #undef MIMR_ID
            }
};

#endif

#define ATTRIBUTE(visibility, type, name)
#define ATTRIBUTE_R(visibility, inheritedClass, type, name)
#define METHOD_CD(visibility, returnedType, name, ...) static returnedType name(struct class_declaration_name *, __VA_ARGS__);
#define METHOD_ID(visibility, returnedType, name, ...) static returnedType name(struct object_declaration_name *, __VA_ARGS__);
#define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) static returnedType CAT(name,inheritedClass)(struct class_declaration_name *, __VA_ARGS__);
#define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) static returnedType CAT(name,inheritedClass)(struct object_declaration_name *, __VA_ARGS__);
#define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...)
#define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...)
#define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...)
#define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...)

OBJECT_DESCRIPTOR
CLASS_DESCRIPTOR

static void create(void);

#undef ATTRIBUTE
#undef ATTRIBUTE_R
#undef METHOD_CD
#undef METHOD_ID
#undef METHOD_CD_R
#undef METHOD_ID_R
#undef PARENT_METHOD_CD
#undef PARENT_METHOD_ID
#undef MIMR_CD
#undef MIMR_ID

#define ATTRIBUTE(visibility, type, name)
#define ATTRIBUTE_R(visibility, type, name)
#define METHOD_CD(visibility, returnedType, name, ...) self->name = name;
#define METHOD_ID(visibility, returnedType, name, ...) self->name = name;
#define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) self->name = CAT(name,inheritedClass);
#define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) self->name = CAT(name,inheritedClass);
#define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) self->name = (returnedType (*) (struct class_declaration_name *, __VA_ARGS__)) PackageAndClassPath->name;
#define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) self->name = (returnedType (*) (struct object_declaration_name *, __VA_ARGS__)) PackageAndClassPath->name;
#define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) self->CAT(name,inheritedClass) = (returnedType (*) (struct class_declaration_name *, __VA_ARGS__)) PackageAndClassPath->name;
#define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) self->CAT(name,inheritedClass) = (returnedType (*) (struct object_declaration_name *, __VA_ARGS__)) PackageAndClassPath->name;

#else
struct class_declaration_name
{
    CLASS_DESCRIPTOR
};

#undef class_declaration_name
#undef object_declaration_name

#undef ATTRIBUTE
#undef ATTRIBUTE_R
#undef METHOD_CD
#undef METHOD_ID
#undef METHOD_CD_R
#undef METHOD_ID_R

#undef CLASS_DESCRIPTOR
#undef OBJECT_DESCRIPTOR

#undef __CLASS_NAME__
#undef CLASS

#endif

#endif
