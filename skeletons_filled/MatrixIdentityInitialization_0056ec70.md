## MatrixIdentityInitialization_0056ec70 — MatrixColumnRowIdentityInit

**Summary:** Initializes one column and one row of a matrix to identity values (sets diagonal element to 1.0, all others to 0), or delegates to a virtual method if the vtable pointer is present.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_56ECF0 (0056ecf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x30) | 0x18 | R | — | Virtual function table entry (offset 24 in vtable) |
| this | 0x20 | R | — | Matrix dimension (this[8]) |
| this | 0x28 | R | — | Column pointer array (this[10]) |
| this | 0x2C | R | — | Row pointer array (this[11]) |
| this | 0x30 | R | — | Vtable pointer (this[12]) — non-null means virtual dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks if this[12] (vtable pointer) is non-zero. PASSES when non-null — delegates to virtual method at vtable+24 for initialization. BLOCKED for virtual path when null — proceeds with manual identity initialization: zeroes column a2 and row a2, then sets diagonal *(v8 + 8*a2+4) to 1072693248 (1.0 as IEEE 754 double).
