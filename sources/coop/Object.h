#if defined(private_coop_object_start) && !defined(private_coop_object_stop)

struct coop_Object
{
    char *publicAttribute;
};

struct coop_Object_
{
    void(* setPrivateAttribute)(char *,struct coop_Object *);
    char *(* getPrivateAttribute)(struct coop_Object *);
    void(* setProtectedAttribute)(char *,struct coop_Object *);
    char *(* getProtectedAttribute)(struct coop_Object *);
    void(* setClassName)(char *);
    char *(* getClassName)();
};

struct Object
{
    /*public */struct coop_Object *Object;
    /*package */struct Object_ *class;
    /*package */char *packageAttribute;
    /*protected */char *protectedAttribute;
    /*private */char *privateAttribute;
};

struct Object_
{
    /*public */struct coop_Object_ *Object;
    /*private static */char *className;
};

void coop_Object(void);

#define private_coop_object_stop
#elif defined(protected_coop_object_start) && !defined(protected_coop_object_stop)

#define protected_coop_object_stop
#elif defined(package_coop_object_start) && !defined(package_coop_object_stop)

void coop_Object(void);

#define package_coop_object_stop
#elif !defined(public_coop_object) && !defined(package_coop_object_start) && !defined(protected_coop_object_start) && !defined(private_coop_object_start)

struct coop_Object
{
    char *publicAttribute;
};

struct coop_Object_
{
    void(* setPrivateAttribute)(char *, struct coop_Object *);
    char *(* getPrivateAttribute)(struct coop_Object *);
    void(* setProtectedAttribute)(char *, struct coop_Object *);
    char *(* getProtectedAttribute)(struct coop_Object *);
    void(* setClassName)(char *);
    char *(* getClassName)();
};

#define public_coop_object
#endif
