## MutexPairInitializer_00585ea0 — InitializeMutexPairWithLists

**Summary:** Initializes a structure with two linked-list head/tail pointer pairs (offsets 0x0/0x4 and 0x10/0x14) and creates two mutexes (offsets 0xC, 0x1C) via CreateMutexA with INFINITE timeouts (offsets 0x10, 0x20). Sets created flags (offsets 0x14, 0x24) to 1 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Linked list 2 head pointer (cleared at end) |
| this | 0x4 | RW | 0 | Linked list 2 auxiliary pointer (cleared at end) |
| this | 0x8 | RW | 0 | Byte flag for list 2 state |
| this | 0xC | RW | 0 | Mutex handle 1 (created via CreateMutexA) |
| this | 0x10 | RW | 18446744073709551615 | Timeout for mutex 1 (initialized to -1 = INFINITE) |
| this | 0x14 | RW | 1 | Mutex 1 created flag (0 before creation, set to 1 if CreateMutexA succeeds) |
| this | 0x18 | RW | 0 | Byte flag for list 1 state |
| this | 0x1C | RW | 0 | Mutex handle 2 (created via CreateMutexA) |
| this | 0x20 | RW | 18446744073709551615 | Timeout for mutex 2 (initialized to -1 = INFINITE) |
| this | 0x24 | RW | 1 | Mutex 2 created flag (0 before creation, set to 1 if CreateMutexA succeeds) |

**Written-by note (persistence):**
- this 0x0: set to 0 unconditionally; external poke survives until next init
- this 0x4: set to 0 unconditionally; external poke survives until next init
- this 0x8: set to 0 unconditionally; external poke survives until next init
- this 0xC: set to CreateMutexA result; overwritten each call
- this 0x10: set to -1 unconditionally
- this 0x14: set to 1 conditionally (if CreateMutexA succeeds); 0 otherwise
- this 0x18: set to 0 unconditionally
- this 0x1C: set to CreateMutexA result; overwritten each call
- this 0x20: set to -1 unconditionally
- this 0x24: set to 1 conditionally (if CreateMutexA succeeds); 0 otherwise

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1ac | CreateMutexA | R | Creates unnamed mutex with SECURITY_ATTRIBUTES (non-inheritable, no descriptor) |
| ff00000000005450 | byte_FF00000000005450 | W | unknown |
| ff00000000005451 | byte_FF00000000005451 | W | unknown |
| ff00000000005452 | byte_FF00000000005452 | W | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — function always initializes all fields. CreateMutexA may fail (return NULL), in which case the created flag at offset 0x14 or 0x24 stays 0.
