## F_2FieldInitCall_004de5f0 — TwoFieldZeroAndDualArrayDestruct

**Summary:** Zeroes two DWORD fields at offsets 0xC and 0x14, then calls DualArrayDestructor to clean up internal array structures. Object teardown or reinitialization helper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4DFBB0 (004dfbb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | counter/state field, unconditionally zeroed |
| this | 0x14 | RW | 0 | counter/state field, unconditionally zeroed |

**Written-by note (persistence):**
- this 0xC: unconditionally set to 0 on each call; external poke survives until next call
- this 0x14: unconditionally set to 0 on each call; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ded20 | DualArrayDestructor | destroy/free array structures internal to object |

**Guard conditions:** None — always executes fully.
