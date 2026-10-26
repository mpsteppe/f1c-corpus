## FileOpWithGlobalBuffer_00588821 — FormattedOutputWithCriticalSection

**Summary:** Writes formatted output into global buffer `unk_5E6768` under critical section protection. Saves buffer state before format, restores after, returns format result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WindowsAdminCheck (00423250), MediaFileDecodeHeader (0052dc90), MPEGBuffer (0052e350)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e6768 | unk_5E6768 | R | Global buffer/context used for formatted output operations |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058c1e0 | CriticalSectionEnter | Lock critical section on global buffer before operation |
| 0058c232 | CriticalSectionLeave_c232 | Unlock critical section on global buffer after operation |
| 0058d04d | sub_58D04D | Perform formatted output: format string + va_list into global buffer |
| 0058e41b | sub_58E41B | Save current buffer state before formatted output |
| 0058e4a8 | ClearStructFieldsIfFlagSet | Restore/clear buffer state using saved flag after format |

**Guard conditions:** None — function contains no conditional branches; always executes full sequence (enter CS, save state, format, restore, leave CS).
