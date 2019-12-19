#ifndef OBJECTMODEL_H
#define OBJECTMODEL_H

#include "exceptionManager.h"

#define STR_NOEXPAND(A) #A
#define STR(A) STR_NOEXPAND(A)
#define CAT_NOEXPAND(A, B) A ## B
#define CAT(A, B) CAT_NOEXPAND(A, B)
#define ENCAPSULATED const void * const

void main_coop(void);
void store_instance(void *);
void garbage_collector(void);

#endif //OBJECTMODEL_H

#ifdef CLASS
#if !defined(INSTANCE_DESCRIPTOR) || !defined(CLASS_DESCRIPTOR)
    #error "Did not define one of the two descriptors required for the definition of the class."
#endif

#define __CLASS_NAME__ STR(CLASS)
#define class_declaration_name CAT(CLASS,_)
#define instance_declaration_name CLASS

#define ATTRIBUTE(visibility, type, name) type name;
#define METHOD_CD(visibility, returnedType, name, ...) returnedType (*(name))(struct class_declaration_name *self, __VA_ARGS__);
#define METHOD_ID(visibility, returnedType, name, ...) returnedType (*(name))(struct instance_declaration_name *this, __VA_ARGS__);
#define ATTRIBUTE_R(visibility, inheritedClass, type, name) type CAT(name,inheritedClass);
#define METHOD_CD_R(visibility, inheritedClass, returnedType, name, ...) returnedType (*(CAT(name,inheritedClass)))(struct class_declaration_name *self, __VA_ARGS__);
#define METHOD_ID_R(visibility, inheritedClass, returnedType, name, ...) returnedType (*(CAT(name,inheritedClass)))(struct instance_declaration_name *this, __VA_ARGS__);

#ifdef CLASS_DEFINITION
#define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) returnedType (*(name))(struct class_declaration_name *self, __VA_ARGS__);
#define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) returnedType (*(name))(struct instance_declaration_name *this, __VA_ARGS__);
#define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) returnedType (*(CAT(name,inheritedClass)))(struct class_declaration_name *self, __VA_ARGS__);
#define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) returnedType (*(CAT(name,inheritedClass)))(struct instance_declaration_name *this, __VA_ARGS__);
#endif

struct instance_declaration_name
{
    struct class_declaration_name *class;
    INSTANCE_DESCRIPTOR
};

#ifdef CLASS_DEFINITION
static struct class_declaration_name
{
    CLASS_DESCRIPTOR
}*self = NULL;

#undef ATTRIBUTE
#undef METHOD_CD
#undef METHOD_ID
#undef PARENT_METHOD_CD
#undef PARENT_METHOD_ID
#undef MIMR_CD
#undef MIMR_ID

#define ATTRIBUTE(visibility, type, name)
#define METHOD_CD(visibility, returnedType, name, ...) static returnedType name(struct class_declaration_name *, __VA_ARGS__);
#define METHOD_ID(visibility, returnedType, name, ...) static returnedType name(struct instance_declaration_name *, __VA_ARGS__);
#define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...)
#define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...)
#define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...)
#define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...)

INSTANCE_DESCRIPTOR
CLASS_DESCRIPTOR

static void create(void);

#undef ATTRIBUTE
#undef METHOD_CD
#undef METHOD_ID
#undef PARENT_METHOD_CD
#undef PARENT_METHOD_ID
#undef MIMR_CD
#undef MIMR_ID

#define ATTRIBUTE(visibility, type, name)
#define METHOD_CD(visibility, returnedType, name, ...) self->name = name;
#define METHOD_ID(visibility, returnedType, name, ...) self->name = name;
#define PARENT_METHOD_CD(visibility, PackageAndClassPath, returnedType, name, ...) self->name = (returnedType (*) (struct class_declaration_name *, __VA_ARGS__)) PackageAndClassPath->name;
#define PARENT_METHOD_ID(visibility, PackageAndClassPath, returnedType, name, ...) self->name = (returnedType (*) (struct instance_declaration_name *, __VA_ARGS__)) PackageAndClassPath->name;
#define MIMR_CD(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) self->CAT(name,inheritedClass) = (returnedType (*) (struct class_declaration_name *, __VA_ARGS__)) PackageAndClassPath->name;
#define MIMR_ID(visibility, inheritedClass, PackageAndClassPath, returnedType, name, ...) self->CAT(name,inheritedClass) = (returnedType (*) (struct instance_declaration_name *, __VA_ARGS__)) PackageAndClassPath->name;

#ifdef DIRECT_SUPER_CLASS
#define super(...) CAT(DIRECT_SUPER_CLASS,_)(__VA_ARGS__)
#endif

#else
struct class_declaration_name
{
    CLASS_DESCRIPTOR
};

#undef class_declaration_name
#undef instance_declaration_name

#undef ATTRIBUTE
#undef METHOD_CD
#undef METHOD_ID
#undef ATTRIBUTE_R
#undef METHOD_CD_R
#undef METHOD_ID_R

#undef CLASS_DESCRIPTOR
#undef INSTANCE_DESCRIPTOR

#undef __CLASS_NAME__
#undef CLASS

#endif

#endif