## ShortComputation_c9d0_0048c9d0 — VTableSetterC9D0

**Summary:** Sets vtable at this+0x0 to UIElementVTable (off_5AC044). Minimal vtable initializer stub.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_c9b0 (0048c9b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | &off_5AC044 | VTable pointer set to UIElementVTable |

**Written-by note (persistence):**
- this 0x0: written once per call. Survives until overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac044 | off_5AC044 | R | UIElementVTable — assigned as object vtable |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — always executes unconditionally.
