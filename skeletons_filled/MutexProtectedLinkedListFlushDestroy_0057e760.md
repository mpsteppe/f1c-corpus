## MutexProtectedLinkedListFlushDestroy_0057e760 — mutex-protected list destroy (flush all nodes)

**Summary:** Destroys a mutex-protected singly-linked list: waits on mutex, iterates all nodes freeing data pointer (if byte flag at +8 set) and node itself, zeros list head fields, releases mutex.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkCleanup_fbe0 (0057fbe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xB00)+0x4) | 0x4 | R | — | Node next pointer (singly-linked list) |
| *(this+0xB00) | 0x0 | R | — | First node data pointer |
| *(this+0xB00) | 0x8 | R | — | Node byte flag: non-zero means free data pointer |
| this | 0xB00 | RW | 0 | List head pointer (first node address) |
| this | 0xB04 | RW | 0 | List tail pointer |
| this | 0xB08 | RW | 0 | List cursor/iterator |
| this | 0xB0C | RW | 0 | List 4th DWORD field |
| this | 0xB10 | R | — | Mutex handle (WaitForSingleObject / ReleaseMutex) |
| this | 0xB14 | R | — | Mutex wait timeout in ms |

**Written-by note (persistence):**
- this 0xB00: zeroed at end of destroy; no surviving state after flush
- this 0xB04: zeroed at end of destroy; no surviving state after flush
- this 0xB08: zeroed at end of destroy; no surviving state after flush
- this 0xB0C: zeroed at end of destroy; no surviving state after flush

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex before list traversal |
| 0059e1a4 | ReleaseMutex | R | Release mutex after list is cleared |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free node's data pointer (if flag set) and free node itself |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xB00 | == | 0 | List head pointer — NULL means empty list |

**Guard interpretation:** If this+0xB00 (head pointer) is 0, skip node traversal loop entirely. Mutex is still released. If mutex handle (this+0xB10) is 0, WaitForSingleObject is skipped and v4 becomes null (potential null dereference on head field access).
