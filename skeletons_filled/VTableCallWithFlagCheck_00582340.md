## VTableCallWithFlagCheck_00582340 — Conditional vtable entry 1 call with flag check

**Summary:** If flag byte at this+0x8 is set, calls vtable entry 1 (offset +4) on object at this+0x0 with refcount arg 1. Returns the flag byte value (callers check for side effect or return value).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x4 | R | — | Vtable entry 1 (offset +4) called on the target object with arg 1 |
| obj | 0x0 | R | — | Object pointer loaded from this+0x0; dereferenced for vtable lookup |
| this | 0x0 | R | — | Pointer to object whose vtable will be called (must be non-null for call) |
| this | 0x8 | R | — | Byte flag controlling whether vtable call is performed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks byte at this+0x8. If zero, skips vtable call entirely (returns flag=0). If non-zero, checks pointer at this+0x0 for null, then invokes vtable[1] destructor.
