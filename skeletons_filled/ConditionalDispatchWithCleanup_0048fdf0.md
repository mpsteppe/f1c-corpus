## ConditionalDispatchWithCleanup_0048fdf0 — ConditionalDispatchCleanup

**Summary:** Conditionally dispatches a cleanup/delegation operation on a sub-object. Loads a pointer from this context, calls a delegation function with offset data, accumulates position offset, and invokes a vtable method.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x30) | 0x2C | R | — | Vtable function pointer at entry 11 (offset 44) |
| this | 0x30 | R | — | Pointer to sub-object for delegation |
| this | 0xB4 | R | — | Parameter for delegation function |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | Delegates to sub-object with offset parameter |
| 0049aa30 | OffsetAccumulator | Accumulates/updates positional offset (a2, a3) |

**Guard conditions:** Checks `this[12]` (offset 0x30) for null — BLOCKED (returns early) when null. PASSES when non-null: calls delegation, offset accumulator, then vtable method.
