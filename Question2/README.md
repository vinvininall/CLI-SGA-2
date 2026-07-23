# Question 2 - Process Management Using fork()

## Objective

A C program was created to demonstrate process creation using `fork()`, monitor child execution, prevent zombie processes using `wait()`, and terminate an unresponsive child process using the `SIGTERM` signal.

---

## Commands Executed and Explanations

### 1. Create the C source file

Command:

```bash
nano process_manager.c
```

Explanation:

Created the C source file containing the process management program.

---

### 2. Compile the program

Command:

```bash
gcc process_manager.c -o process_manager
```

Explanation:

The `gcc` compiler converted the C source code into an executable program named `process_manager`.

---

### 3. Execute the program

Command:

```bash
./process_manager
```

Explanation:

Executed the compiled program to create a child process, monitor its execution, terminate it using a signal, and clean it up.

---

## Process Management Concepts

### fork()

`fork()` creates a new child process by duplicating the parent process. The parent and child execute independently after the fork.

### wait()

`wait()` allows the parent process to wait until the child process finishes execution. This prevents zombie processes by releasing the child's process resources.

### kill()

`kill(pid, SIGTERM)` sends the SIGTERM signal to terminate the child process gracefully when it becomes unresponsive.

### Signal Handling

Signals provide a way for one process to communicate with another. In this program, `SIGTERM` is used to stop the child process safely.

---

## How They Work Together

The parent process creates a child using `fork()`. It waits for a short period, checks the child, sends a termination signal using `kill()`, and finally calls `wait()` to collect the child's exit status. This prevents zombie processes while ensuring that unresponsive child processes are terminated.
