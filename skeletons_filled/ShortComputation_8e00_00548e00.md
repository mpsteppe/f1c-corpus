## ShortComputation_8e00_00548e00 — ObjectMultiFieldZeroInit

**Summary:** Zero-initializes the object via GlobalZeroInit_c2a0, then explicitly clears byte at offset 0x0 and DWORDs at offsets 0x10 and 0x14. Returns this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0), sub_545A40 (00545a40), SceneInstanceCollection (00545bb0), StringListAppend (00549020), LinkedListStringInsert (005492f0), StringCopyNodeAlloc (005493b0), F_1024xBatchCallLoop (0054eaa0), F_512xConstructorLoop (005568b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First byte/DWORD of object — explicitly zeroed |
| this | 0x10 | RW | 0 | DWORD field at offset 0x10 — explicitly zeroed |
| this | 0x14 | RW | 0 | DWORD field at offset 0x14 — explicitly zeroed |

**Written-by note (persistence):**
- this 0x0: Written once unconditionally; external poke survives after execution
- this 0x10: Written once unconditionally; external poke survives after execution
- this 0x14: Written once unconditionally; external poke survives after execution

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Bulk zero-initialization of the entire object |

**Guard conditions:** None — always executes unconditionally and returns this pointer.
