## TemporaryStateWrapper_00507779 — Save state, process with temporary params, restore

**Summary:** Saves object state fields (width, stride, data pointers, flags), replaces them with temporary values (including a stack-local buffer and constant data pointer), optionally runs DirectXVertexBufferFormatConversion if format != 1, then calls vtable+8 and vtable+4 processing methods. Restores all saved fields and returns saved flag value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | saved this[4] flag to be returned after restore |
| obj | 0x8 | R | — | source surface format (compared to 1 for conversion check) |
| this | 0x0 | R | — | vtable pointer (for calling methods at +4 and +8) |
| this | 0x8 | R | — | this[2] — format selector checked for == 1 |
| this | 0x10 | RW | 0 | this[4] — flag field, overwritten with 0 temporarily |
| this | 0x18 | RW | — | this[6] — data pointer, overwritten with stack-local buffer addr |
| this | 0x2C | RW | — | this[11] — pointer field, overwritten with unk_5D76C8 |
| this | 0x1048 | RW | 1 | this[1042] — source format code, overwritten with 1 for conversion |
| this | 0x104C | RW | — | this[1043] — output buffer pointer, overwritten with this+7 |
| this | 0x1058 | RW | 1 | this[1046] — element/vertex count, overwritten with 1 |
| this | 0x1064 | RW | — | this[1049] — stride field, overwritten with this[1050] |
| this | 0x1068 | R | — | this[1050] — stride value used to overwrite this[1049] |

**Written-by note (persistence):**
- this 0x10: once — set to 0 temporarily, restored to saved value
- this 0x18: once — set to stack buffer, restored
- this 0x2C: once — set to unk_5D76C8, restored
- this 0x1048: once — set to 1, restored
- this 0x104C: once — set to this+7, restored
- this 0x1058: once — set to 1, restored
- this 0x1064: once — set to this[1050], restored

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d76c8 | unk_5D76C8 | R | TextureTempDataPointer [DERIVED] — constant data pointer used as temporary replacement for this[11] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | converts vertex float data if format != 1 during temporary state |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 1 | this[2] — format selector check |

**Guard interpretation:** If this[2] == 1 → skip format conversion, directly call processing methods. If this[2] != 1 → run DirectXVertexBufferFormatConversion before processing methods. ALWAYS restores saved state regardless.
