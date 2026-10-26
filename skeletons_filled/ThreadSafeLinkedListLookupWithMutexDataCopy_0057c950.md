## ThreadSafeLinkedListLookupWithMutexDataCopy_0057c950 — ThreadSafeListLookupAndCopyData

**Summary:** Thread-safe linked list lookup by index with mutex protection. Acquires mutex, walks list to indexed node, transforms internal data via sub_4B3DB0, and copies 16 bytes to output. When index pointer is NULL, copies cached WORD from offset 0x910 instead.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAC8)+0x0) | 0x1C | R | — | field at offset 0x1C in data node (passed to sub_4B3DB0 for transformation) |
| *(this+0xAC8) | 0x0 | R | — | linked list head pointer |
| *(this+0xAC8) | 0x8 | R | — | linked list tail/other pointer |
| this | 0x910 | R | — | cached/default WORD value (fallback when a4 is NULL) |
| this | 0xAC8 | R | — | linked list structure pointer (head at +0, tail at +8, count at +12) |
| this | 0xAD4 | R | — | linked list item count |
| this | 0xAD8 | R | — | mutex handle for thread-safe access |
| this | 0xADC | R | — | mutex wait timeout (passed to WaitForSingleObject) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | acquire mutex with timeout |
| 0059e1a4 | ReleaseMutex | R | release mutex after lookup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3db0 | sub_4B3DB0 | transform data pointer into structure whose first 16 bytes are copied to output |

**Guard conditions:** if a4 (index pointer) is NULL → skip mutex/lookup and copy cached data from this+0x910 (pass through). If a4 non-null, assert index >= 0 and < list count, else skip (return 0). If mutex acquisition fails (WaitForSingleObject returns non-zero and not WAIT_TIMEOUT=128) → skip lookup (v9=0, guarded list access prevented).
