# Learn C

## **C Tutorial Introduction**

- C is a general-purpose programming language designed for system and application programming.
- It is widely used for developing firmware and portable applications.
- Understanding C lays a strong foundation for learning other programming languages like C++, Java, and Python.

## **Downloading VS Code IDE**

1. Visit the official [Visual Studio Code](https://code.visualstudio.com/) website.
2. Download the installer for your operating system (Windows, macOS, or Linux).
3. Run the installer and follow the setup wizard instructions.

## **Creating a New Project in VS Code**

1. Open VS Code.
2. Create a new folder for your project.
3. Go to **File > Open Folder** and select your project folder.
4. Use the **Explorer** tab to manage files and create new ones.

## **Installing Compiler**

- C requires a compiler to translate the code into machine language.
- Install GCC (GNU Compiler Collection):
  - **Windows**: Install MinGW or TDM-GCC.
  - **macOS**: Use `xcode-select --install` to install GCC.
  - **Linux**: Use `sudo apt install gcc`.

## **Extensions in VS Code**

- Install useful extensions:
  - **C/C++ by Microsoft**: Provides IntelliSense, debugging, and code browsing.
  - **Code Runner**: Enables running code snippets directly in the editor.

## **Creating the First C Program**

1. In the project folder, create a new file: `hello.c`.
2. Write your first C program:

   ```c
   #include <stdio.h>
   int main() {
       printf("Hello, World!\n");
       return 0;
   }
   ```

## **Configuring VS Code Settings**

- Configure the compiler and terminal:
  1. Go to **File > Preferences > Settings**.
  2. Set the path for the GCC compiler in the environment variable or tasks.json.

## **Running Your First Program**

1. Open the terminal in VS Code.
2. Compile the program:

   ```
   gcc hello.c -o hello
   ```

3. Run the executable:
   ```
   ./hello
   ```

## **Understanding Our First C Program**

- `#include <stdio.h>`: Includes the standard I/O library for functions like `printf`.
- `int main()`: Entry point of the program.
- `printf("Hello, World!\n");`: Prints text to the console.
- `return 0;`: Indicates successful execution.

## **Creating Another C Program**

- Create a file: `sum.c`.
- Write a program to add two numbers:

  ```c
  #include <stdio.h>
  int main() {
      int a = 5, b = 10;
      printf("Sum: %d\n", a + b);
      return 0;
  }
  ```

## **Comments**

- **Single-line**: `// This is a comment`
- **Multi-line**:

  ```c
  /* This is 
     a multi-line comment */
  ```

## **Data Types**

- **Basic**: `int`, `float`, `char`, `double`.
- **Derived**: `array`, `pointer`, `structure`.
- **Enumeration**: `enum`.

## **Variables**

- Containers for storing data values.
- Example:

  ```c
  int age = 25;
  float pi = 3.14;
  ```

## **sizeof() Function**

- Returns the memory size of a data type or variable.
- Example:

  ```c
  printf("Size of int: %lu\n", sizeof(int));
  ```

## **Rules for Defining Variables**

1. Names must begin with a letter or underscore.
2. Case-sensitive.
3. Cannot use reserved keywords.

## **const Keyword**

- Declares variables as read-only.
- Example:

  ```c
  const float pi = 3.14159;
  ```

## **Operators**

- **Arithmetic**: `+`, `-`, `*`, `/`, `%`.
- **Relational**: `>`, `<`, `==`.
- **Logical**: `&&`, `||`, `!`.

## **Taking User Input**

- Example using `scanf`:

  ```c
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  ```

## **Typecasting**

- Converts one data type to another.
- Example:

  ```c
  float x = 5.7;
  int y = (int)x;
  ```

## **Decision-Making (Conditional Statements)**

- **if**, **else**, **else if**:

  ```c
  if (age > 18) {
      printf("Adult");
  } else {
      printf("Minor");
  }
  ```

## **Switch Case Statements**

- Example:

  ```c
  int day = 3;
  switch (day) {
      case 1: printf("Monday"); break;
      case 2: printf("Tuesday"); break;
      default: printf("Other day");
  }
  ```

## **Loops (Iterative Statements)**

1. **for loop**:
   
   ```c
   for (int i = 0; i < 10; i++) {
       printf("%d\n", i);
   }
   ```
   
2. **while loop**:
   
   ```c
   int i = 0;
   while (i < 10) {
       printf("%d\n", i);
       i++;
   }
   ```
   
3. **do-while loop**:
   
   ```c
   int i = 0;
   do {
       printf("%d\n", i);
       i++;
   } while (i < 10);
   ```

## **Functions**

- Breaks the program into reusable parts.
- Example:

  ```c
  int add(int a, int b) {
      return a + b;
  }
  ```

## **Arrays**

- Stores multiple values of the same type.
- Example:

  ```c
  int arr[5] = {1, 2, 3, 4, 5};
  ```

## **Pointers**

- Variables that store the memory address of another variable.
- Example:

  ```c
  int a = 10;
  int *ptr = &a;
  ```

## **Strings**

- Array of characters ending with a null terminator (`\0`).
- Example:

  ```c
  char name[] = "John";
  printf("Name: %s", name);
  ```

## **Structure**

- User-defined data type to group variables.
- Example:

  ```c
  struct Person {
      char name[50];
      int age;
  };
  ```
  
