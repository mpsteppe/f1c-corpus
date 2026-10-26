## StatusCheckWithErrorDispatch_00598aa0 — StatusCheckWithErrorDispatch

**Summary:** Examines an object's status via its vtable-dispatch function; if the status indicates failure (function returns -1) or the error flags are clear, calls sub_59A5FE to dispatch an error notification. Used for cleanup/teardown validation in the locale/exception infrastructure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RefCountDecrementWithCleanup (00598994), RefCountDecrementWithCheck (00599ad9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | vtable-relative offset to the sub-object (vtable[1]) |
| this | 0x0 | R | — | pointer to the virtual function table |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059a5fe | sub_59A5FE | dispatch error notification with status flags |

**Guard conditions:** Checks (v3[4] & 6) == 0 AND vtable function at slot 11 returns -1 → sets error flag v2=4. If v2 is non-zero → calls sub_59A5FE with combined error flags. If sub-object's vtable[10] is NULL, ORs additional bit 2 (4) into flags.
