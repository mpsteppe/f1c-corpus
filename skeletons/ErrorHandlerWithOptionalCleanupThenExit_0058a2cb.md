## ErrorHandlerWithOptionalCleanupThenExit_0058a2cb — FatalErrorExit

**Summary:** Fatal error handler. Optionally displays an error message via sub_5932BA if flag is set, then runs cleanup via sub_5932F3 and terminates process with exit code 0xFF.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_58A19E (0058a19e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1d4 | ExitProcess | R | Terminate process with error exit code 0xFF |
| 008d3ebc | dword_8D3EBC | R | Error display flag; if == 1, shows error message before cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005932ba | sub_5932BA | Display error message to user |
| 005932f3 | sub_5932F3 | Perform cleanup operations before exit |

**Guard conditions:** Checks dword_8D3EBC: if == 1, calls error display sub_5932BA before cleanup; otherwise skips display. Always runs cleanup and ExitProcess.
