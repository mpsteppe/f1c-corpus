## VTableDispatchGetter_005550c0 — VTableMethodCallAndStoreResult

**Summary:** Retrieves a sub-object pointer from `this+0x1100`, calls a vtable method at offset 0x8C on it, stores the returned integer at `*this` (offset 0x0). Used as a generic getter dispatch via interface vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_553070 (00553070), sub_553700 (00553700), sub_557120 (00557120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x8C | R | — | vtable function pointer for method at index 35 (0x8C/4) |
| this | 0x0 | RW | — | result storage field, overwritten each call with vtable method return value |
| this | 0x1100 | R | — | pointer to sub-object with vtable (dispatch target) |

**Written-by note (persistence):**
- this 0x0: overwritten every call with vtable dispatch result; no external persistence

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional vtable dispatch, no branches