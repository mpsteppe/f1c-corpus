@echo off
title F1C Merge to Docs
cd /d "%~dp0"
set PYTHON=%USERPROFILE%\AppData\Local\Python\bin\python3.exe

echo === Merging standard worker output ===
"%PYTHON%" merge_to_docs.py

echo.
echo === Merging IDA Gaps output (if any) ===
if exist "output\ida_gaps\worker_A.md" (
    "%PYTHON%" merge_to_docs.py --subdir ida_gaps --archive
) else (
    echo   No ida_gaps output found, skipping.
)

echo.
echo === Rebuilding knowledge graph ===
"%PYTHON%" "..\tools\knowledge_graph\rebuild.py"

pause
