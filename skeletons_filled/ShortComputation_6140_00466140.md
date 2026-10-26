## ShortComputation_6140_00466140 — UIObjectDestructorWithStateReset

**Summary:** Destructor/cleanup for UI object. Sets vtable to off_59F140, calls StateResetWithZero to reset state field, then calls Destructor_e670.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithConditionalFree_5a70 (00485a70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_59F140 (VTABLE_REASSIGNMENT) |

**Written-by note (persistence):**
- this 0x0: once (destructor reassigns vtable). External poke overwrites.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f140 | off_59F140 | R | VTable_UI_Object_59F140 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004662e0 | StateResetWithZero | reset state field (this+0xF0) to 0 |

**Guard conditions:** None — unconditional cleanup.
