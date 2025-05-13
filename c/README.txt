C interview questions:
=====================

1. Intro to c?
        c is developed by deDennis Ritchie at bell labortory(1972). 
        Dennis Ritchie  is founder of c.
        c is mid-level language. (support for writing code of application as well as driver.
                                  its used for hardware/application interaction purpose so that called
                                  mid level language )
        c is procedure oriented language / structure oriented programming language.
                        (everything function based so that called procedure oriented lang)
    
2. Lifecycle of c program?

        source-code  
           |
       preprocessor (header files, defines are expanded)
           |  -> .i  is the output
        compiler 
           |  -> .s (assembly code)
       assembler
           |  -> .o (object code)
         linker
              -> .exe (executable files) (machine code)

    cmd for compiling the c program,
        gcc hello.c -o hello.o   -> compiles the hello.c and generated the hello.o object/machine code.
        gcc -E hello.c -o hello.i -> preprocessed file output stored in hello.i
        gcc -S hello.c -o hello.s -> assembly output of c code
        gcc -c hello.c -o hello.o -> object code 
    
        multiple object code output to final exe
            gcc hello.o hello1.o -o hello.exe


        gcc -Wall -g hello.c -o hello
            -Wall -> enables all common warnings
            -g    -> includes debug information (useful with gdb)
            -w    -> ignore all warnings
            -Wno-<warning-name> -> to disable a specific warning
                Implicit function declarations	-Wno-implicit-function-declaration
                Unused variables	            -Wno-unused-variable
                Unused function              	-Wno-unused-function
                Implicit int (older C)       	-Wno-implicit-int
                Format (e.g., printf) mismatch	-Wno-format

3. object vs machine code in c?

    Object code: Compiled but not yet linked (intermediate .o)
    Machine code: Final executable (ready to run on CPU)

4. what is tool-chain? 
    A toolchain is a set of software tools that work together to build, 
    compile, link, and sometimes debug your program — typically from source code to executable.

    🧰 In C/C++ Programming, a Toolchain Usually Includes:
        Tool	            Purpose	                                           Example Tool
        Compiler    	Translates source code (.c) to object code (.o)   	    gcc, clang
        Assembler	    Converts assembly (.s) to machine code	Built into      gcc
        Linker	        Links multiple object files into an executable	        ld
        Debugger	    Helps track down bugs in compiled code	                gdb
        Build System    Automates compiling/linking steps                   	make, cmake

5. Difference between char *a & char a[] in c ?

    char *a -> The string literal "Hello" is stored in read-only memory.
               we cannot change the value of a.

    char a[] -> is stored in stack memory. we change the value of a.

    | Feature                | `char *a = "Hello";`    | `char a[] = "Hello";`             |
    | ---------------------- | ----------------------- | --------------------------------- |
    | Where data is stored   | Read-only section       | Stack (or local variable space)   |
    | Can modify contents?   | No (undefined behavior) | Yes                               |
    | Can reassign variable? | Yes                     | No (array name is not assignable) |
    | Type                   | Pointer to char         | Array of char                     |

6. memory map of the c program?

    memory layout of c program is refer to how the program's data stored in memory during program execution.
    understanding this layout helps developer manage memory efficiently. Avoid issue like segmenation falue or memory leaks.

    | Segment     | Contains                                | Init Value   |
    | ---------   | --------------------------------------- | ------------ |
    | **Text**    | Program code (instructions)             | N/A          |
    | **Data**    | Initialized global/static variables     | Given values |
    | **BSS**     | Uninitialized global/static variables   | Zero         |
    | **.rodata** | **String literals**, constant variables |
    | **Heap**    | Dynamically allocated memory (`malloc`) | Undefined    |
    | **Stack**   | Function call frames, local variables   | Undefined    |

    Why Use a Separate Segment?
        The BSS segment doesn't take up space in the executable file — just metadata (size).
        At runtime, the operating system initializes this memory to zero.
        This saves space in the compiled binary and speeds up loading.

    cmd for memory map generation:
        gcc -o example example.c -Wl,-Map=output.map

7. 
