@echo off
title F1C Move Analyzed Files
cd /d "%~dp0"
echo Moving files from not_analyzed/ to analyzed/ based on current docs state...
"%USERPROFILE%\AppData\Local\Programs\Python\Python312\python.exe" merge_to_docs.py --move-only
pause
