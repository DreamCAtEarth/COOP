# COOP
C Object Oriented Project

COOP is a simple way or method to create C object oriented executables or libraries.
The pretension of COOP is certainly not to substitute other OOP languages like C++, Objective C, Java, or else.
It's only here to show it's possible to structure programs from an OO perspective and create some abstraction when it's needed from a non OO environment. At least it could be compared to other non OO languages of same level.
But if you are on a real app project, please, use a real OOP existing langage.
It's not a library or a framework by itself, because the code is only a set of examples to show the various ways to achieve some OOP concepts.

The commits can attest to these achievements if you take a look to them.

The compiler used is gcc from MinGW 8.1 posix w64 6.0.
The build manager is cmake 3.14 (see CMakeLists.txt).
The debugger is gdb from MinGW.

You can build directly the project with any cross platform oriented IDE like CLion from JetBrains.

No other configurations were tested but the code was designed to take advantages from some usefull gcc extensions, so it was not designed to be ported to another IDE.
However the code is still portable and should work when rebuilt on another OS :)

To start to understand a bit the code, just look at the entry point (the main), you'll see several tests outputs (displayed at cmd).

Each directory is a package thought to match to the package or namespace concept. Exceptions are used like a separate module and not like a class because it's not a part of the object model.
The object model describe the behavior of the whole class creation and it's encapsulation.

2 packages are tested with 1 class with the same name for each one. It's ensure that same class names are possibles in different packages.

5 classes are defined in the coop package with 4 in the Object hierarchy and 1 alone (Square).

The header files defines the class from non-private perspective and the overloading of methods (especially the constructor).
The c files defines the class from private perspective and its methods.

if you look at the names of the class and the package, the class are publickly defined with random strings of 8 chars.
It's used in order to avoid too long names (we are limited to 63 characters for an identifier in c) and conflicts due to redefinitions.
Of course in packages and hierarchies (for inheritence) the real names are used.
