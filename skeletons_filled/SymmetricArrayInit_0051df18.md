## SymmetricArrayInit_0051df18 — SymmetricOffsetTableInit

**Summary:** Allocates and initializes a 256-entry symmetric offset table. Creates array with positive values on one side and negative on the other, centered at buffer midpoint, used for symmetric convolution indexing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51DFCB (0051dfcb)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x28 | RW | — | symmetric table pointer (allocated result, written to context) |
| *(this+0x4) | 0x0 | R | — | allocator vtable function (allocate memory) |
| this | 0x4 | R | — | allocator pointer |
| this | 0x1A4 | R | — | context pointer |

**Written-by note (persistence):**
- *(this+0x1A4) 0x28: allocated once, pointer persists until freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early-exit guards; always initializes full 256-entry table unconditionally.
