# Question 5 - Recovery Mechanisms in vi Editor

## Objective

This task evaluates the recovery mechanisms available in the vi editor and explains how they help recover work after an unexpected system crash.

---

## Commands Executed and Explanations

### 1. Create a configuration file

Command:

```bash
nano config.conf
```

Explanation:

Created a sample configuration file for demonstrating editing and recovery.

---

### 2. Edit the file using vi

Command:

```bash
vi config.conf
```

Explanation:

Opened the configuration file in the vi editor and modified its contents to simulate editing.

---

### 3. Exit without saving

Command:

```text
:q!
```

Explanation:

Exited the editor without saving changes to simulate an interrupted editing session.

---

### 4. Attempt recovery

Command:

```bash
vi -r config.conf
```

Explanation:

Used vi's recovery mode to check for recoverable changes from a swap file.

---

## Recovery Mechanisms in vi

### Swap Files

Swap files store temporary editing information and allow recovery after an unexpected crash.

### Undo History

Undo history enables recently made changes to be reversed during an editing session using the `u` command.

### Registers

Registers temporarily store deleted, copied, and pasted text for later reuse.

### Backup Files

Backup files preserve the previous version of a file before changes are saved, providing an additional recovery option.

### Auto-Recovery

The `vi -r` command attempts to recover unsaved work using the available swap file.

---

## Most Reliable Recovery Strategy

The most reliable recovery strategy is using swap files together with `vi -r` because swap files automatically preserve editing progress during a session. If the system crashes unexpectedly, the swap file allows the latest unsaved changes to be recovered, minimizing data loss.
