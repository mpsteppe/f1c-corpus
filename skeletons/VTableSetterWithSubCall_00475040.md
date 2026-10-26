## VTableSetterWithSubCall_00475040 — UIObjectInitWithVTableCleanup

**Summary:** Sets vtable pointer to off_5A42C0 and calls InitWithVTableCleanup for further initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalFreeWithFlagCheck (00475020)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer for UI object |

**Written-by note (persistence):**
- this 0x0: set once; external vtable swap survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a42c0 | off_5A42C0 | R | Vtable for UI object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — always executes fully.
