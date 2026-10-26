## WideCharMultiByteStringConversionWithAllocLoop_00597fac — WideStrListToMultiByteConvert

**Summary:** Iterates through a linked list of wide-character strings, converts each to multibyte via WideCharToMultiByte, allocates a buffer for each, calls sub_598323 to store the converted string. Returns 0 on success (full list processed), -1 on conversion or allocation failure. Part of CRT startup command-line/locale string processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_596D81 (00596d81), sub_598323 (00598323)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e228 | WideCharToMultiByte | R | import: kernel32 WideCharToMultiByte function pointer |
| 008d3e98 | dword_8D3E98 | R | WideStrLinkedList [DERIVED] (also: linked list of wide strings (command-line args / locale strings) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | allocate memory for converted multibyte string |
| 00598323 | sub_598323 | store converted multibyte string into internal structure |

**Guard conditions:** Checks if *(DWORD*)dword_8D3E98 is NULL → return 0 immediately (empty list). Loop continues until v1 (next wide string pointer) is NULL. Returns -1 if WideCharToMultiByte fails (returns 0) or if MallocWrapperForNhMalloc returns NULL or conversion fails.
