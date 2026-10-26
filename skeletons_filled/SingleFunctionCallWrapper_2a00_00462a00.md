## SingleFunctionCallWrapper_2a00_00462a00 — Byte Accessor via Deep Pointer Chain

**Summary:** Reads a single byte at offset 0x5D from a sub-object reached through a multi-level pointer chain (this → vtable → intermediate pointer at +0x3FB8 → deref → +0x5D). Returns the byte value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneTextureApply (0045cf50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x3FB8)+0x0) | 0x5D | R | — | target byte read and returned |
| *(obj+0x3FB8) | 0x0 | R | — | intermediate pointer dereference |
| obj | 0x3FB8 | R | — | sub-object pointer in this |
| this | 0x0 | R | — | vtable pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always reads and returns the byte unconditionally.
