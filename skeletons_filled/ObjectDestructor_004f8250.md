## ObjectDestructor_004f8250 — ObjectDestructor

**Summary:** Calls vtable destruction chain (release at +8, cleanup at +24, delete at +0 with arg 1) on a COM-like object pointer, then nulls it. Used for safe object disposal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DoubleBufferFree (004f83b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | Vtable pointer for object destruction (delete at slot 0) |
| *(obj+0x0) | 0x8 | R | — | Vtable slot 2: release/destroy callback |
| *(obj+0x0) | 0x18 | R | — | Vtable slot 6: cleanup callback |
| obj | 0x0 | R | — | Object pointer to destroy (dereferenced for vtable) |
| this | 0x0 | RW | 0 | Output pointer nulled after destruction |

**Written-by note (persistence):**
- this 0x0: Set to 0 after object destroyed; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `*a1` must be non-null to proceed. If null, returns immediately.
