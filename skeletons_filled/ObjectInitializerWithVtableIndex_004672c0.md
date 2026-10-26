## ObjectInitializerWithVtableIndex_004672c0 — GridIndexedWindowManagerConstructor

**Summary:** Constructor for window manager with 2D grid indexing. Calls sub_48C070(this, 0), computes data table pointer from unk_7C5770 + 64*(a3+11*a2), sets vtable to off_59F4F8, stores row/column parameters (a2, a3) and additional param a4 at index 199.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_59F4F8 |
| this | 0x31C | RW | — | field 199 — parameter a4 (size/count) |
| this | 0x320 | RW | — | field 200 — computed table offset (unk_7C5770 + 64*(a3+11*a2)) |
| this | 0x324 | RW | 55 | field 201 — default value 55 |
| this | 0x328 | RW | — | field 202 — row index a3 |
| this | 0x32C | RW | — | field 203 — column index a2 |

**Written-by note (persistence):**
- this 0x0: once (constructor). External poke overwrites.
- this 0x31C: once (constructor). External poke survives.
- this 0x320: once (constructor). External poke survives.
- this 0x324: once (constructor). External poke survives.
- this 0x328: once (constructor). External poke survives.
- this 0x32C: once (constructor). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f4f8 | off_59F4F8 | R | VTable_WindowManager [DERIVED] |
| 007c5770 | unk_7C5770 | R | GlobalGridDataArray [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048c070 | sub_48C070 | base initialization with this pointer and param 0 |

**Guard conditions:** None — unconditional.
