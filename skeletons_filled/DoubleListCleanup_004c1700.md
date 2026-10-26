## DoubleListCleanup_004c1700 — DualLinkedListDestructor

**Summary:** Destructor for a structure containing two singly-linked lists. Walks each list, frees nodes and optionally their data payloads when the ownership flag (node+8) is set. Performs three passes: first list cleanup with PitStopMemoryCleanup, second list cleanup with ShortComputation_4370, then a final verification pass on the first list. Zeros all pointers afterward.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StaticInitBulk (004a8b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | R | — | node next pointer, used during list traversal |
| *(this+0x14) | 0x4 | R | — | node next pointer in second list |
| obj | 0x0 | R | — | node data pointer, freed if ownership flag set |
| obj | 0x8 | R | — | ownership flag byte: non-zero means node owns its data |
| this | 0x0 | RW | 0 | first list head pointer, zeroed after cleanup |
| this | 0x4 | RW | 0 | second list head pointer, zeroed after cleanup |
| this | 0x8 | RW | 0 | first list tail/aux pointer, zeroed |
| this | 0xC | RW | 0 | first list auxiliary pointer, zeroed |
| this | 0x10 | RW | 0 | second list tail/aux pointer, zeroed |
| this | 0x14 | RW | 0 | second list auxiliary pointer, zeroed |
| this | 0x18 | RW | 0 | second list pointer, zeroed |
| this | 0x1C | RW | 0 | second list pointer, zeroed |

**Written-by note (persistence):**
- this 0x0 through 0x1C: all set to 0 unconditionally — external poke survives (no data left to manage)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414370 | ShortComputation_4370 | cleanup/release resources associated with a data object |
| 004c0b10 | PitStopMemoryCleanup | cleanup pit stop memory for a node's data |
| 004c1e20 | sub_4C1E20 | verify/cleanup single entry in first list |
| 004c1e40 | UtilityFunction_1e40 | general cleanup helper |
| 00587bcf | FreeWrapper_7bcf | deallocate memory block |

**Guard conditions:** Node ownership flag at node+8 guards data cleanup — if zero, only the node itself is freed, not its data. Additionally, data pointer at node+0 must be non-null before dereferencing for cleanup.
