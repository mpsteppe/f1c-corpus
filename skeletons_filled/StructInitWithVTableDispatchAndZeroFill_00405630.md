## StructInitWithVTableDispatchAndZeroFill_00405630 — StructResetWithVTableDispatch

**Summary:** Resets a struct to default state: sets offset 0x1C to -1, zeroes several fields, runs virtual cleanup on sub-object at 0x30, dispatches vtable method at offset 0x34+4, and zero-fills trailing region from 0x44 to 0x70.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalCleanupWithDualFree (004054a0), BinaryDataDeserialization (004054e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x34) | 0x4 | R | — | vtable dispatch at pointer offset 0x34, method slot +4 |
| this | 0x1C | RW | 18446744073709551615 | dword set to -1 (sentinel/invalid) |
| this | 0x20 | RW | 0 | dword zeroed |
| this | 0x24 | RW | 0 | dword zeroed |
| this | 0x28 | RW | 0 | dword zeroed |
| this | 0x2C | RW | 0 | dword zeroed |
| this | 0x34 | R | — | vtable pointer for cleanup dispatch method |
| this | 0x70 | RW | 0 | byte at end of memset trailing range, set to 0 |

**Written-by note (persistence):**
- this 0x1C: set to -1 once per reset
- this 0x20 through 0x2C: zeroed once per reset
- this 0x70: zeroed once per reset
- all fields retain external poke until next reset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052d990 | VirtualCleanup | virtual-table-backed cleanup on sub-object at offset 0x30 |

**Guard conditions:** none — unconditional reset of all written fields.
