## ShortComputation_76b0_004876b0 — VTable reset to ListBoxNode then delegate

**Summary:** Resets object vtable to off_5ABA18 (ListBoxNode), then calls sub_485EB0 for further teardown; returns its result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithSubCallConditionalFree (00487690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5ABA18 | vtable pointer; reset to ListBoxNode vtable before delegated cleanup |

**Written-by note (persistence):**
- this 0x0: written once during destruction; memory freed afterward

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005aba18 | off_5ABA18 | R | VTable_ListBoxNode — vtable set before delegated teardown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional vtable reset + delegate call
