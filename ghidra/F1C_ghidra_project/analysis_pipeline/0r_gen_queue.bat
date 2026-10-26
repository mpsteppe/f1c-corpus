@echo off
title F1C Generate Review Queue
cd /d "%~dp0"
echo Generating full-entry review queue from triage index...
"%USERPROFILE%\AppData\Local\Programs\Python\Python312\python.exe" generate_review_queue.py
pause
