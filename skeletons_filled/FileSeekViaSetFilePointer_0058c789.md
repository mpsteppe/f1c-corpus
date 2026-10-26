## FileSeekViaSetFilePointer_0058c789 — _lseek: file seek via SetFilePointer

**Summary:** CRT `_lseek` implementation that positions a file handle using SetFilePointer. Validates handle index, clears the EOF tracking flag on success, and maps OS errors to CRT errno via ErrorIDLookupTable.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58C724 (0058c724), sub_58CA19 (0058ca19), sub_58E290 (0058e290), sub_595AF9 (00595af9), sub_59797B (0059797b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e168 | SetFilePointer | R | Win32 SetFilePointer function pointer |
| 0059e188 | GetLastError | R | Win32 GetLastError function pointer |
| 008d4920 | dword_8D4920 | R | Critical section array; clears EOF bit (bit 1) on successful seek |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058af5c | ErrorIDLookupTable | Map OS GetLastError to CRT errno on seek failure |
| 0058afcf | TLSOffsetGetter | Get TLS errno slot; writes 9 (EBADF) on invalid handle |
| 00595a1f | sub_595A1F | Retrieve OS handle value by CRT handle index |

**Guard conditions:** If sub_595A1F returns -1 (invalid handle), sets errno=9 and returns -1. If SetFilePointer returns -1 (0xFFFFFFFF) and GetLastError is nonzero, maps error and returns -1. On success, clears EOF flag (bit 1) in handle's critical section tracking byte.
