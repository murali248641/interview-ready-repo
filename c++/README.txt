c++ Interview questions
=======================

1. What are the basic differences between C and C++?
    1) paradigm
        c is the procedural programming language(mainly focused on functions and procedure).
        c++ is multi-paradigm (supports procedural, object-oriented and generic programming)

    2) object-oriented programming
        c doesn't support class, object, ploymorphism, interitance, encapsulation, etc..
        c++ supports full oriented features like class, object, inheritance, polymorphism, encapsulation and etc.
    
    3) standard library
        c has a smaller standard library(mainly basic operation like input/output, string manipulation, etc).
        c++ offer richer standard library (eg. STL - standard template library for data structure and algorithms)        
    
    4) Memory Management
        c uses malloc() and free() for dynamic memory.
        c++ uses new and delete operators. and also allowing to override them.

    5) function overloading and defaults Arguments
        c does not support function overloading and defaults Arguments.
        c++ supports both.

    6) encapsulation and data hiding
        c uses struct without member function and access specifier.
        c++ uses class with member functions, private, public and protected access specifier.

    7) Name mangling
        c: no name mangling(function name remains as in symbol table)
        c++ supports name mangling to enable function overloading.
    
    8) input/output
        c uses printf and scanf, etc
        c++ uses streams like cin, cout (but also support c-style I/O)

    9) template and generic
        c doesn't support template
        c++ supports template for generic programming

    10) exception handling:
        c: no in-bulit exception handling
        c++: has try-catch exception handling

2) What is the difference between struct and class in C++?

    In c++ struct and class are mostly similar - both can have the member variables, member functions,
    access specifier, support inheritance, constructor, destructor, etc.

    however they are 2 difference,
    1) default access specifier for member variable, member functions, base class inheritance for struct is public.
       default access specifier for member variable, member functions, base class inheritance for class is private.
    2) usage convention
        struct is generally used plain data structure.  
        Typically just for storing the data without complex behaviour.

        class is typically used when implementing full object oriented features. 
        such us encapsulation, inheritance, ploymorphism, etc.
3) 