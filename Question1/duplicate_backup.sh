#!/bin/bash

SOURCE="./submissions"
BACKUP="./backup"

REPORT="duplicate_report.txt"
ERRORS="errors.log"

processed=0
duplicates=0
backedup=0

> "$REPORT"
> "$ERRORS"

declare -A file_hashes

while read file
do
    ((processed++))

    hash=$(md5sum "$file" 2>>"$ERRORS" | awk '{print $1}')

    if [[ ${file_hashes[$hash]} ]]
    then
        echo "Duplicate file: $file" >> "$REPORT"
        ((duplicates++))
    else
        file_hashes[$hash]=1
        cp "$file" "$BACKUP/" 2>>"$ERRORS"
        ((backedup++))
    fi

done < <(find "$SOURCE" -type f | sort)

echo "Files processed: $processed" >> "$REPORT"
echo "Duplicate files: $duplicates" >> "$REPORT"
echo "Files backed up: $backedup" >> "$REPORT"
