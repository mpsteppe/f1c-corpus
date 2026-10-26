## ShortComputation_fd30_0054fd30 — Paired render state field setter

**Summary:** Stores two integer values into consecutive fields at this+0x78 and this+0x7C. Used by render state setup functions to set paired state parameters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_546F70 (00546f70), sub_546FE0 (00546fe0), ConditionalRenderStateSetup (00547040), GuardedRenderStateSet (005470a0), DirectXMeshVertexBufferParsingAndLoading (00547b40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x78 | RW | — | First render state parameter |
| this | 0x7C | RW | — | Second render state parameter |

**Written-by note (persistence):**
- this 0x78: unconditionally overwritten each call; survives until next call or external modification
- this 0x7C: unconditionally overwritten each call; survives until next call or external modification

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — unconditionally writes both fields.
