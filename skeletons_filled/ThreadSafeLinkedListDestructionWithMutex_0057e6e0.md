## ThreadSafeLinkedListDestructionWithMutex_0057e6e0 — MutexProtectedListDestroyAll

**Summary:** Acquires mutex, iterates a linked list destroying every node. For each node with flag byte at offset 8 set, calls vtable destructor (first vtable entry, arg=1). Frees all nodes via FreeWrapper_7bcf. Zeros head/tail/cursor/count. Releases mutex. Network list cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkCleanup_fbe0 (0057fbe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xAC8)+0x0)+0x0) | 0x0 | R | — | vtable pointer of node data (first entry = destructor) |
| *(*(this+0xAC8)+0x0) | 0x0 | R | — | first node entry data pointer |
| *(this+0xAC8) | 0x0 | R | — | linked list head (first node pointer) |
| *(this+0xAC8) | 0x8 | R | — | node byte at offset 8 (flag: whether to call destructor) |
| this | 0xAC8 | RW | 0 | linked list head (cleared to 0 after destruction) |
| this | 0xACC | RW | 0 | linked list tail (cleared to 0 after destruction) |
| this | 0xAD0 | RW | 0 | linked list cursor (cleared to 0 after destruction) |
| this | 0xAD4 | RW | 0 | list node count (cleared to 0 after destruction) |
| this | 0xAD8 | R | — | mutex handle (WaitForSingleObject/ReleaseMutex) |
| this | 0xADC | R | — | mutex wait timeout |

**Written-by note (persistence):**
- this 0xAC8: cleared to 0 after all nodes freed
- this 0xACC: cleared to 0 after all nodes freed
- this 0xAD0: cleared to 0 after all nodes freed
- this 0xAD4: cleared to 0 after all nodes freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | kernel32 import — wait on mutex handle |
| 0059e1a4 | ReleaseMutex | R | kernel32 import — release mutex after destruction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free each linked list node after optional destructor call |

**Guard conditions:** Linked list head at v4 (= this+0xAC8, or 0 if mutex not acquired) must be non-NULL. If list empty, the destruction loop is skipped but head/tail/cursor/count are still zeroed and mutex is released.
