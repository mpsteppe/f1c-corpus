@echo off
cd /d "%USERPROFILE%\Desktop\F1C_ghidra_project"

git add docs/ roles/ scripts/ work/CHANGELOG.md work/QUEUE.md README.md CLAUDE.md commit.bat .gitignore

echo.
echo Files staged:
git status --short

echo.
set /p MSG="Commit message (or press Enter for auto): "

if "%MSG%"=="" (
    for /f "tokens=*" %%i in ('git diff --cached --stat --no-color') do set STAT=%%i
    set MSG=docs: session checkpoint
)

git commit -m "%MSG%"

echo.
echo Done. Log:
git log --oneline -5
echo.
pause
