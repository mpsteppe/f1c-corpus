## PEImageBaseAddressDetection_005930e8 — ReadPEHeaderLinkerVersion

**Summary:** Retrieves the PE optional header linker major/minor version from the current process image's NT headers. Stores MajorLinkerVersion at field offset 0, MinorLinkerVersion at field offset 1, returns MinorLinkerVersion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_593115 (00593115)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | MajorLinkerVersion from PE optional header |
| this | 0x1 | RW | — | MinorLinkerVersion from PE optional header |

**Written-by note (persistence):**
- this 0x0: written once conditionally (only if MZ signature valid and e_lfanew non-zero)
- this 0x1: written once conditionally (only if MZ signature valid and e_lfanew non-zero)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e21c | GetModuleHandleA | R | Get base address of current process image for PE header parsing |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns 0 without writing fields if `GetModuleHandleA(0)` image does not start with MZ signature (0x5A4D = 23117), or if `e_lfanew` (DWORD at DOS header offset 0x3C) is zero.
