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

7. what is compliler, intetpreter and assembler? 

    Compiler: 
            A compiler is a program that translates the entire source code
            (written in a high-level language like C, C++, or Java) into machine code (binary)
             before execution.

        ex: c, c++

    Interpreter:
        An interpreter translates and runs code line by line, at runtime. 
        It doesn't produce a separate executable.

        ex: python

        javascript ->  Interpreted + JIT Compiled
    
    Assembler: 
            An assembler converts assembly language (low-level human-readable instructions) 
            into machine code.

    ☕ What About Java? Is it Compiled or Interpreted?
        Java is a hybrid language — it uses both a compiler and an interpreter (actually, a Just-In-Time compiler too).

    🔄 Java Compilation and Execution Flow

        Java Compiler (javac):
        Converts your .java source file (high-level) into bytecode, stored in a .class file.
        Bytecode is not machine code, but a platform-independent intermediate representation.

        Java Virtual Machine (JVM):
        Reads the bytecode (.class files).
        Interprets or compiles it Just-In-Time (JIT) into machine code for the host CPU.

    | Tool            | Input Language      | Output            | Works How?                    |
    | --------------- | ------------------- | ----------------- | ----------------------------- |
    | **Compiler**    | High-level (C, C++) | Machine code      | Translates all at once        |
    | **Interpreter** | High-level (Python) | Executes directly | Translates line by line       |
    | **Assembler**   | Assembly            | Machine code      | Translates assembly to binary |


    | Language         | Tool/Environment                             | Type of Tool                    | Notes                                           |
    | ---------------- | -------------------------------------------- | ------------------------------- | ----------------------------------------------- |
    | **C**            | `gcc`, `clang`                               | Compiler                        | Compiles to machine code                        |
    | **C++**          | `g++`, `clang++`                             | Compiler                        | Supports OOP, more complex than C               |
    | **Java**         | `javac` + `java` (JVM)                       | Compiler + Interpreter/JIT      | Compiles to bytecode, runs on JVM               |
    | **Python**       | `python`, `python3`                          | Interpreter (with optional JIT) | Line-by-line execution; PyPy adds JIT           |
    | **JavaScript**   | V8 (Chrome), SpiderMonkey (Firefox), Node.js | Interpreter + JIT               | Runs in browsers or Node.js                     |
    | **C#**           | `csc` (C# compiler), .NET CLR                | Compiler + VM                   | Compiles to IL code; runs on .NET runtime       |
    | **Ruby**         | `ruby`                                       | Interpreter                     | Dynamic, high-level scripting language          |
    | **Go**           | `go build`, `go run`                         | Compiler                        | Compiles to a single binary                     |
    | **Rust**         | `rustc`, `cargo`                             | Compiler                        | Safe systems language; compiles to machine code |
    | **Kotlin**       | `kotlinc`, JVM                               | Compiler                        | Can compile to JVM bytecode or JavaScript       |
    | **Swift**        | `swiftc`, Xcode                              | Compiler                        | Used for iOS/macOS development                  |
    | **PHP**          | `php`                                        | Interpreter                     | Server-side scripting language                  |
    | **TypeScript**   | `tsc`                                        | Compiler (to JS)                | Superset of JavaScript, compiled to plain JS    |
    | **Perl**         | `perl`                                       | Interpreter                     | Text processing and scripting                   |
    | **Scala**        | `scalac`, JVM                                | Compiler                        | Runs on JVM, functional + OOP                   |
    | **Haskell**      | `ghc`                                        | Compiler                        | Purely functional language                      |
    | **R**            | `R`                                          | Interpreter                     | Used in statistics and data analysis            |
    | **Shell (Bash)** | `bash`                                       | Interpreter (Shell)             | Unix shell language                             |
    | **Assembly**     | `nasm`, `gas`, `as`                          | Assembler                       | Translates assembly to machine code             |
    | **MATLAB**       | MATLAB environment                           | Interpreter + JIT               | Numeric computing and simulations               |

8. Endianness in c program? 
   little endian vs big endian?
   write a program to find the endian?

    Endianness is refer to the byte order used by computer or microcontroller.
    or 
    machine to read or write single "machine word" in memory.

    32-bit or 64-bit machine word.

    endian will decide how to store multiple bytes in memory.
    It’s all about the order of the bytes of a word (multi-byte variable) in memory.

    little endian:
        LSB (Least significant byte) is stored first or to a lower memory address.

        Thus, the little-endian byte order means, when the computer writes a word (Multi Byte) into memory,
        it begins by writing the Lowest byte to the lowest memory address and continues until it has written the highest byte to the highest memory address. 
        It does this by writing subsequent and ascending memory addresses, no matter the endianness.

    Big Endian: (MSB (Most significant byte))
        In Big Endian, MSB (Most significant byte) is stored first or to a lower memory address.
        The big-endian byte order means, when the computer writes a word (Multi Byte) into memory, 
        it begins by writing the highest byte to the lowest memory address and continues until it has written the lowest byte to the highest memory address.

    example:
        0x11223344
	
    Big Endian			
        Memory Address	100	   101	    102	   103
             Content	0x11	0x22	0x33	0x44

    little endian:
        Memory Address	100	    101 	102 	103
            Content 	0x44	0x33	0x22	0x11

9. where endianess is matter for developers for developing a program?

    | Area                         | Why It Matters                                            |
    | ---------------------------- | --------------------------------------------------------- |
    | Network programming          | Different systems → standardize to network byte order     |
    | Binary file formats          | Files shared between machines → use consistent byte order |
    | Embedded systems             | CPU architectures vary → must handle explicitly           |
    | Multimedia/network protocols | File or protocol specs define byte order                  |
    | Cross-platform development   | System compatibility requires consistent interpretation   |

10. program endian conversion in c program?
