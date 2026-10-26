## SmallStructInitWithParentCall_00559330 — ListNodeZeroInit

**Summary:** Zero-initialize a small struct: fill entire struct with zeros via GlobalZeroInit, then explicitly zero 4 fields (at offsets 0, 0x14, 0x18, 0x1C).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5594B0 (005594b0), sub_559570 (00559570), LinkedListNodeSearchAllocation (00559630)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First byte/field of struct, explicitly zeroed |
| this | 0x14 | RW | 0 | Explicitly zeroed field (dword slot 5) |
| this | 0x18 | RW | 0 | Explicitly zeroed field (dword slot 6) |
| this | 0x1C | RW | 0 | Explicitly zeroed field (dword slot 7) |

**Written-by note (persistence):**
- this 0x0: Written unconditionally to 0 once per init call
- this 0x14: Written unconditionally to 0 once per init call
- this 0x18: Written unconditionally to 0 once per init call
- this 0x1C: Written unconditionally to 0 once per init call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-fill entire struct from start |

**Guard conditions:** None (unconditional init).
