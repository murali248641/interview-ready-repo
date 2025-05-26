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

11. What does the static keyword mean in C?
     The static keyword can be used in different contexts,
        -> inside the functions
            value retained multiple function calls
        -> static global variable
            make variable visiable to current file only.
        -> static function
            make function is visiable to current file only.

12. Can a static variable be declared in a header file?
        Yes, but it causes each source file including the header to have its own separate copy
        of the static variable (because of internal linkage).
        This is usually discouraged.

13. why  static const int a;  declaring in header file is valid?
        Because static gives it internal linkage and const makes it read-only,
        each including .c file gets its own private copy of a, 
        and there is no linker conflict and no logical issue.
        so its safe for using in header file.

14. what is translation unit in c?
        A translation unit is the result of a source file (.c) after the preprocessor has:
            included all headers
            expanded all macros
            removed comments
        
        example:
            One .c file + everything it includes (via #include) = One translation unit

15. what is mean by internal, external and no linkage in c?

        | Linkage Type         | Description                                                                |
        | -------------------- | -------------------------------------------------------------------------- |
        | **Internal Linkage** | Identifier is **visible only within the same translation unit**            |
        | **External Linkage** | Identifier is **visible across multiple translation units**                |
        | **No Linkage**       | Identifier is **local to a block** (i.e., no visibility outside the block) |

16. storage class explain in c?

    In C, a storage class defines four key properties of a variable or function:

        Scope – Where it can be accessed (e.g., inside a block, file-wide, or across files)
        Lifetime – How long it exists in memory
        Linkage – Whether it's accessible from other files
        Storage location – Typically RAM or CPU registers

    | Storage Class | Keyword    | Scope                 | Lifetime         | Linkage          |
    | ------------- | ---------- | --------------------- | ---------------- | ---------------- |
    | **Automatic** | `auto`     | Local (block)         | Until block ends | No linkage       |
    | **Register**  | `register` | Local (block)         | Until block ends | No linkage       |
    | **Static**    | `static`   | Depends on context    | Entire program   | Internal or none |
    | **External**  | `extern`   | Global (across files) | Entire program   | External         |

17. Why is declaring static variables in headers dangerous?

    | Issue                     | Explanation                                                                                              |
    | ------------------------- | -------------------------------------------------------------------------------------------------------- |
    | **Memory bloat**          | Every `.c` file including the header gets a separate copy of the variable.                               |
    | **Inconsistent behavior** | You might think you're updating a shared global value, but you're actually working with isolated copies. |
    | **Hard to debug**         | Changes to the variable in one file **don’t affect** the value in another — leading to confusing bugs.   |
    | **Hidden coupling**       | It hides logic inside a header that silently alters the program’s memory model.                          |

18. Explain the lifetime, scope, and linkage of a static variable inside a function?
        | Property     | Value                            |
        | ------------ | -------------------------------- |
        | **Lifetime** | Whole program duration           |
        | **Scope**    | Inside the function only         |
        | **Linkage**  | No linkage (not visible outside) |

19. What is linkage in C? How does it relate to storage classes?

    Linkage in C determines whether an identifier (variable/function) defined in one file can be accessed in another file.

    | Linkage Type         | Meaning                                                            |
    | -------------------- | ------------------------------------------------------------------ |
    | **External Linkage** | Identifier is accessible from **other files**                      |
    | **Internal Linkage** | Identifier is **only accessible within the same translation unit** |
    | **No Linkage**       | Identifier is **local to its block/function**                      |

20. what is diffference between global int and static int in declaration?
        | Feature                     | Global `int` (`int a;`)                                                     | Static `int` (`static int a;`)                              |
        | --------------------------- | --------------------------------------------------------------------------- | ----------------------------------------------------------- |
        | **Scope (Visibility)**      | Visible **across all files** (external linkage)                             | Visible **only within the current file** (internal linkage) |
        | **Linkage**                 | **External linkage**: shared between files                                  | **Internal linkage**: private to the file                   |
        | **Storage Area**            | Stored in **.data** (if initialized) or **.bss** (if uninitialized) segment | Stored in **.data** or **.bss** as well                     |
        | **Initialization Default**  | Zero (if not explicitly initialized)                                        | Zero (if not explicitly initialized)                        |
        | **Access from other files** | Yes, via `extern` declaration                                               | No, cannot be accessed outside the file                     |
        | **Use Case**                | Variables meant to be **shared globally**                                   | Variables meant to be **private to the file**               |

21. Build your own strlen program in c?

22. Build your own strrev program in c?

23. Build your own strcpy program in c?

24. Build your own strcat program in c?

25. Build your own strcmp program in c?

26. Build your own strcmp without casesensitive program in c?

27. Build nibble swap program in c?

28. count setbits in a variable in c?

29. setbit, clearbit, togglebit and odd-even using bitwise operator program in c?

30. check the number is power of 2 in c?

31. swap 2 number without temp variable?

32. find single non-repeating element in a array?

33. find all non-repeating element in a array?

34. Reverse the array in c?

35. find the maximum and minimum element in a array?

36. check array is sorted?

37. sort the array of integer using c?

38. Find all pairs with a given sum?

39. Merge two sorted arrays?

40. Find union and intersection of two arrays?

41. Remove duplicates from a sorted/unsorted array?

42. Find missing number in 1 to n (using sum or XOR)?
        sum formula -> sum1..n = n(n+1)/2
      
43. Find the frequency of all elements using hashing?

44. how do you allocate and free the memory for 2d array?

45. call by value and call by reference fully understand in c?
        understand in deep.
        when need to pass ** in function parameter
        try multiple mcq

46. volatile in c?
    The volatile keyword in C is a type qualifier that tells the compiler not to optimize 
    accesses to a variable — because the value of the variable can change unexpectedly, 
    outside the program’s control.

        volatile keyword tells 
        1. prevent compiler optimize on variable access.
        2. always read and write from memory
        3. variable changed externally.

47. Can a constant variable be volatile?
        yes 

48. union vs structure in c?
    | Feature           | `struct`                                 | `union`                                        |
    | ----------------- | ---------------------------------------- | ---------------------------------------------- |
    | Memory allocation | Each member gets its **own memory**      | All members **share the same memory**          |
    | Total size        | Sum of sizes (plus padding)              | Size of the **largest** member                 |
    | Member access     | All members can be accessed **at once**  | Only **one member** is valid at a time         |
    | Use case          | Group related data (e.g., employee info) | Store **one of many types** in the same memory |
    | Overlap           | No                                       | Yes — all members overlap                      |

49. return the structure from function to caller function?

50. Write custom memcpy() or memmove() function?

51. Sort array using pointer arithmetic?

52. const variable,  const pointer related example?

53. Bitfields + unions, Bitfields + struct?

54. function pointers examples?
    callback registration mechanism in c? communication between two modules?
    pointer-to-array-of-function-pointers?

55. lvalue vs rvalue related errors with examples?

56. What do the keywords volatile, restrict, and inline mean in C? 

57. 1) What does *++𝗽𝘁𝗿 do?
    2) What does ++*𝗽𝘁𝗿 do?
    3) What does *𝗽𝘁𝗿++ do?

58. write function ptr for malloc api?

59. char *p = "Hello";
    *p = 'M';    /* works */
    p = "Bye";   /* works */

    const char *p = "Hello";
    *p = 'M';    /* error */
    p = "Bye";   /* works */

    char const *p = "Hello";
    *p = 'M';    /* error */
    p = "Bye";   /* works */

    char  * const p = "Hello";
    *p = 'M';    /* works */
    p = "Bye";   /* error */

    const char  * const p = "Hello";
    *p = 'M';    /* error */
    p = "Bye";   /* error */

60 .



Linkedlist related questions:
1. Print the Middle of a given linked list
2. Reverse a Linked List
3. Nth node from end of linked list
4. Detect Loop in linked list
5. Remove loop in Linked List
6. Add two numbers represented by Linked lists
7. Reverse a linked list in groups of given size
8. Intersection point of two Linked Lists
9. delete the node in linked list?
10. delete middle of linked list?
11. remove nth node from end of list?



Implement Queue using Linked List
Implement a stack using singly linked list
Merge two sorted linked lists
Intersection point in Y shaped Linked lists
Intersection of two Sorted Linked Lists
Delete last occurrence of an item from linked list
Delete middle of linked list
Remove duplicate elements from sorted linked list

Print the Middle of a given linked list
Reverse a Linked List
   sort list
   

1. Reverse Linked List: https://lnkd.in/g6etVg3C
2. Palindrome Linked List: https://lnkd.in/gk883n7E
3. Middle of the Linked List: https://lnkd.in/dk_EuXBV
4. Intersection of Two Linked Lists: https://lnkd.in/guiNJzCn
5. Design Linked List: https://lnkd.in/ggb76-kP
6. Remove Duplicates from Sorted List II: https://lnkd.in/g2rfvkHX
7. Swap Nodes in Pairs: https://lnkd.in/giDUfZpE
8. Copy List with Random Pointer: https://lnkd.in/gMTwRYgM
9. Rotate List: https://lnkd.in/gtg4hjUz
10. Add Two Numbers: https://lnkd.in/dZ2hfGGf
11. Linked List Cycle II: https://lnkd.in/guyrrkjf
12. Reverse Linked List II: https://lnkd.in/g-Tc7TpU
13. Partition List: https://lnkd.in/gc9BMiWv
14. Flatten a Multilevel Doubly Linked List: https://lnkd.in/gGjHPKjR
15. Reverse Nodes in k-Group: https://lnkd.in/gwZBd4Kx


String-Based Questions
1. Reverse a string — without using built-ins.
2. Is it a palindrome? Let's find out.
3. Remove duplicates from a string — efficiently.
4. First non-repeating character — who stands alone?
5. Count how many times each character appears.
6. Flip the words in a sentence, not the letters.
7. Are two strings anagrams? Prove it.
8. Longest substring without repeats — sliding window style.
9. Build your own atoi — string to integer.
10. Compress strings with run-length encoding.
11. Most frequent character — who dominates?
12. List all possible substrings of a string.
13. Is one string a rotation of another?
14. Strip all white spaces from a string.
15. Is this a valid shuffle of two strings?
16. Convert text to Title Case — properly.
17. Find the longest common prefix among words.
18. Break a string into a char array — without confusion.
19. Replace spaces with %20 — classic URL trick.
20. Turn full sentences into acronyms.
21. Check if the string is all digits — no alphabets allowed.
22. Count how many words are in the string.
23. Remove a specific character — cleanly.
24. Find the shortest word in a sentence.
25. Longest palindromic substring — two-pointer style.

Array-Based Questions
26. Reverse an array in-place.
27. Find the largest and smallest element.
28. Check for duplicates in an array.
29. Remove duplicates — return only unique values.
30. Find the missing number from 1 to N.
31. Move all zeros to the end — keep order.
32. Rotate the array left/right by K positions.
33. Find the Kth largest/smallest element.
34. Merge two sorted arrays — without using extra space.
35. Find the intersection of two arrays.
36. Sort 0s, 1s, and 2s without using sort().
37. Find subarrays with a given sum.
38. Detect if a subarray sums to 0.
39. Find the longest increasing subsequence.
40. Kadane’s Algorithm — maximum subarray sum.
41. Check if array is sorted and rotated.
42. Rearrange array in max-min order alternately.
43. Find leaders in an array (no greater element to the right).
44. Calculate frequency of all elements in O(n).
45. Product of all elements except self.