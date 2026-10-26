## sub_54FCC0_0054fcc0 — Render state default value initializer

**Summary:** Sets a field at this+0x84 to the constant value 191 (0xBF), regardless of the input parameter a2. The switch statement's intermediate values (0, 63, 127) are immediately overwritten and have no effect. Used during mesh/texture creation to initialize a render state parameter to its default.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXMeshVertexBufferParsingAndLoading (00547b40), D3DTextureResourceCreation (00548190), sub_557CE0 (00557ce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x84 | RW | 191 | Render state default parameter; always set to 191 (0xBF) |

**Written-by note (persistence):**
- this 0x84: unconditionally set to 191 each call; overwrites any prior value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0054fd20 | jpt_54FCCE | R | Switch jump table (dead-code cases; all paths resolve to 191) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — unconditionally sets field to 191 regardless of input.
