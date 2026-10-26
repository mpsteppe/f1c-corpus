## StructInitWithVtableZero_005507e0 — StructInitZeroVtableAndFields

**Summary:** Zero-initializes the struct via global helper, then explicitly zeros vtable pointer and three dword fields at offsets 0x20, 0x24, 0x28.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MeshVertexIndexBufferLoader (00550ad0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Vtable pointer (set to null/0) |
| this | 0x20 | RW | 0 | Field zeroed explicitly after GlobalZeroInit |
| this | 0x24 | RW | 0 | Field zeroed explicitly after GlobalZeroInit |
| this | 0x28 | RW | 0 | Field zeroed explicitly after GlobalZeroInit |

**Written-by note (persistence):**
- this 0x0: Written unconditionally to 0 on init; external poke overwritten by subsequent init
- this 0x20: Written unconditionally to 0 on init; external poke overwritten
- this 0x24: Written unconditionally to 0 on init; external poke overwritten
- this 0x28: Written unconditionally to 0 on init; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-initialize entire struct memory |

**Guard conditions:** none — always executes all zeroing, no branches.
