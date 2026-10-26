## ObjectInitWithVTableSetup_00587030 — Task object init with vtable and parameters

**Summary:** Initializes a TaskBase-derived object: calls sub_587460(0), sets vtable pointer to off_5B8C30 (VTable_TaskBase), and stores three parameters (a4→0x10, a2→0x14, a3→0x18) with byte at 0x19 cleared to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectInitWithVTableFieldSet (0057b780), sub_581070 (00581070), sub_5813E0 (005813e0), sub_5837F0 (005837f0), sub_585870 (00585870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5B8C30 | VTable pointer (TaskBase) |
| this | 0x10 | RW | a4 (4th param) | First config field |
| this | 0x14 | RW | a2 (2nd param) | Second config field |
| this | 0x18 | RW | a3 (3rd param, char) | Third config byte field |
| this | 0x19 | RW | 0 | Cleared to zero on init |

**Written-by note (persistence):**
- this 0x0: set once per call to vtable pointer; external poke overwrites it
- this 0x10: set from a4 each call; external poke overwrites it
- this 0x14: set from a2 each call; external poke overwrites it
- this 0x18: set from a3 each call; external poke overwrites it
- this 0x19: cleared to 0 each call; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8c30 | off_5B8C30 | R | VTable_TaskBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587460 | sub_587460 | Subroutine init called with parameter 0 before field assignment |

**Guard conditions:** None — all operations execute unconditionally.
