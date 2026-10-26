## VTablePointerInit_0057b7f0 — SetDynamicsObjVTablePointer

**Summary:** Sets vtable pointer to DynamicsObj vtable (off_5B8A64) and tail-calls further initialization routine.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalFreeBasedOnFlagBit (0057b7b0), sub_57E280 (0057e280), sub_580DE0 (00580de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to DynamicsObj vtable) |

**Written-by note (persistence):**
- this 0x0: unconditionally set per call; external poke does not survive reinit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8a64 | off_5B8A64 | R | VTable_DynamicsObj_5B8A64 [DERIVED] — DynamicsObj vtable pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes unconditionally.
