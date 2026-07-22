# Question 1 - Duplicate Submission Detection and Backup

## Objective

A shell script was created to identify duplicate student submissions, back up unique submissions, generate a processing report, and store errors separately.

## Commands Executed and Explanations

### 1. Create required folders

Command:echo "Linux assignment submission from Vinayak" > vinayak.txt
echo "Linux assignment submission from Aryan" > aryan.txt
echo "Linux assignment submission from Vinayak" > vinayakcopy.txt

```bash
mkdir submissions backup
