## SimpleSetter_71c0_005471c0 — Set this+0xB0 from parameter

**Summary:** Stores a2 into this+0xB0 and returns a2. Direct field setter with no guards.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXMeshVertexBufferParsingAndLoading (00547b40), D3DTextureResourceCreation (00548190)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | RW | — | target field overwritten with a2 on every call |

**Written-by note (persistence):**
- this 0xB0: unconditionally set to a2; persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None unconditional; always writes this+0xB0 = a2.
