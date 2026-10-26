## HandleCloseWithErrorReporting_0058c38e — CloseHandle with cleanup and error mapping

**Summary:** Closes an OS handle by CRT index, with special handling for shared stdout/stderr handles. Clears the handle's open-state byte in the critical section array and maps any CloseHandle failure to CRT errno via ErrorIDLookupTable.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58C331 (0058c331)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e188 | GetLastError | R | Win32 GetLastError function pointer |
| 0059e1a8 | CloseHandle | R | Win32 CloseHandle function pointer |
| 008d4920 | dword_8D4920 | R | Critical section array; clears open-state byte on close |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058af5c | ErrorIDLookupTable | Map OS GetLastError to CRT errno on failure |
| 005959a0 | sub_5959A0 | Cleanup handle entry metadata after close |
| 00595a1f | sub_595A1F | Retrieve OS handle value by CRT handle index |

**Guard conditions:** If sub_595A1F handle retrieval returns -1, CloseHandle is skipped. If handle is 1 or 2 (stdout/stderr) and both map to the same OS handle, CloseHandle is skipped to avoid closing shared console output. On CloseHandle failure, captures GetLastError and maps via ErrorIDLookupTable, returning -1.
