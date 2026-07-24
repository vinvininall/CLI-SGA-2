# Question 4 - Log File Monitoring

## Objective

This task demonstrates real-time monitoring of a log file using a Linux command pipeline. The pipeline extracts only ERROR messages, stores them in a separate report, and suppresses unnecessary error output.

---

## Commands Executed and Explanations

### 1. Create the log file

Command:

```bash
nano server.log
```

Explanation:

Created a sample server log containing INFO and ERROR messages.

---

### 2. Monitor the log

Command:

```bash
tail -f server.log | grep "ERROR" >> error_report.txt 2>/dev/null
```

Explanation:

Continuously monitored the log file, filtered only ERROR entries, appended them to a report file, and suppressed unnecessary error messages.

---

### 3. Add new log entries

Commands:

```bash
echo "INFO: New connection established" >> server.log
echo "ERROR: Authentication failed" >> server.log
echo "ERROR: Network timeout" >> server.log
```

Explanation:

Simulated new log entries to demonstrate real-time monitoring and filtering.

---

### 4. View the report

Command:

```bash
cat error_report.txt
```

Explanation:

Displayed the extracted ERROR messages collected during monitoring.

---

## Command Pipeline Explanation

- **tail -f** continuously monitors newly added lines in the log file.
- **grep** filters only lines containing the word ERROR.
- **| (pipe)** passes the output of one command directly to another.
- **>>** appends filtered messages to the report file.
- **2>/dev/null** suppresses unnecessary error messages by redirecting them to `/dev/null`.

---

## Summary

The command pipeline provides an efficient method for monitoring logs in real time while extracting only relevant ERROR messages and maintaining a separate report file.
