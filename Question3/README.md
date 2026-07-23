# Question 3 - File Processing Using Linux System Calls

## Objective

This program demonstrates file processing using Linux system calls instead of standard library file functions. It creates a file, stores employee records, updates a specific record, retrieves records efficiently using random access, and closes the file.

---

## Commands Executed and Explanations

### 1. Create the C source file

Command:

```bash
nano file_system_calls.c
```

Explanation:

Created the C source file containing the program that performs file operations using Linux system calls.

---

### 2. Compile the program

Command:

```bash
gcc file_system_calls.c -o file_system_calls
```

Explanation:

Compiled the C source code into an executable program named `file_system_calls`.

---

### 3. Execute the program

Command:

```bash
./file_system_calls
```

Explanation:

Executed the program to create the employee file, write records, update a specific record, retrieve the updated record, and close the file.

---

## Code Explanation

The program creates a binary file called `employees.dat` using `open()`. Three employee records are written into the file using `write()`. The `lseek()` system call moves the file pointer directly to the second employee record, allowing only that record to be updated without rewriting the entire file. The same function is used again before `read()` to retrieve the updated record efficiently. Finally, `close()` releases the file descriptor after all operations are complete.

---

## Linux System Calls Used

### open()

Creates and opens the employee data file for reading and writing.

### write()

Stores employee records into the file.

### lseek()

Moves the file pointer directly to a specific employee record, enabling efficient updates and retrieval.

### read()

Reads a selected employee record from the file.

### close()

Closes the file and releases system resources.

---

## Justification

Using Linux system calls provides low-level control over file operations. The use of `lseek()` allows direct access to specific records, making updates more efficient because the entire file does not need to be rewritten.
