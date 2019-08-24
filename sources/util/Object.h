#if defined(private_util_object_start) && !defined(private_util_object_stop)

struct util_Object
{
    char *publicAttribute;
};

struct util_Object_
{
    void(* setPrivateAttribute)(char *,struct util_Object *);
    char *(* getPrivateAttribute)(struct util_Object *);
    void(* setProtectedAttribute)(char *,struct util_Object *);
    char *(* getProtectedAttribute)(struct util_Object *);
    void(* setClassName)(char *);
    char *(* getClassName)();
};

struct Object
{
    /*public */struct util_Object *Object;
    /*package */struct Object_ *class;
    /*package */char *packageAttribute;
    /*protected */char *protectedAttribute;
    /*private */char *privateAttribute;
};

struct Object_
{
    /*public */struct util_Object_ *Object;
    /*private static */char *className;
};

void util_Object(void);

#define private_util_object_stop
#elif defined(protected_util_object_start) && !defined(protected_util_object_stop)

#define protected_util_object_stop
#elif defined(package_util_object_start) && !defined(package_util_object_stop)

void util_Object(void);

#define package_util_object_stop
#elif !defined(public_util_object) && !defined(package_util_object_start) && !defined(protected_util_object_start) && !defined(private_util_object_start)

struct util_Object
{
    char *publicAttribute;
};

struct util_Object_
{
    void(* setPrivateAttribute)(char *, struct util_Object *);
    char *(* getPrivateAttribute)(struct util_Object *);
    void(* setProtectedAttribute)(char *, struct util_Object *);
    char *(* getProtectedAttribute)(struct util_Object *);
    void(* setClassName)(char *);
    char *(* getClassName)();
};

#define public_util_object
#endif
