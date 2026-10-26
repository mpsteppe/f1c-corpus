## InverseScale_0054fe00 — Reciprocal scale factor setter

**Summary:** Computes the inverse (1.0 / a2) of an input float and stores it at this+0x58. Used during mesh vertex buffer loading to pre-compute a reciprocal scale factor for vertex data processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXMeshVertexBufferParsingAndLoading (00547b40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | Reciprocal scale factor; set to 1.0/a2 |

**Written-by note (persistence):**
- this 0x58: unconditionally overwritten each call; survives until next call or external modification

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | 1.0 constant used for reciprocal computation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — unconditionally computes and stores the reciprocal.
