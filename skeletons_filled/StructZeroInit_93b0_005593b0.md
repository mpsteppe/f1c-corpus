## StructZeroInit_93b0_005593b0 — SmallStructZeroInit3Fields

**Summary:** Zero-initialize struct via GlobalZeroInit, then explicitly zero first 3 dword fields (offsets 0, 4, 8).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderUISystemGlobalInit (0053c360), MeshVertexIndexBufferLoader (00550ad0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First dword of struct, explicitly zeroed |
| this | 0x4 | RW | 0 | Second dword, explicitly zeroed |
| this | 0x8 | RW | 0 | Third dword, explicitly zeroed |

**Written-by note (persistence):**
- this 0x0: Written unconditionally to 0 once per init call
- this 0x4: Written unconditionally to 0 once per init call
- this 0x8: Written unconditionally to 0 once per init call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-fill entire struct from start |

**Guard conditions:** None (unconditional init).
