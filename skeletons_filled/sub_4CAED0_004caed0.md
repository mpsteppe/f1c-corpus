## sub_4CAED0_004caed0 — SpecialFXEqualityMergeCheck

**Summary:** Compares two special FX objects for structural equality across all float fields, IDs, and sub-object material properties (including texture name strings). If equal and incoming object has a larger "priority/version" field at this+0x58, updates the field. Used for deduplication during SpecialFX_Init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x50) | 0x20 | R | — | Sub-object DWORD flag/ID field compared for equality |
| *(this+0x50) | 0x58 | R | — | Sub-object DWORD field compared for equality |
| *(this+0x50) | 0x5C | R | — | Sub-object DWORD field compared for equality |
| *(this+0x50) | 0x60 | R | — | Sub-object DWORD field compared for equality |
| *(this+0x50) | 0x64 | R | — | Sub-object DWORD field compared for equality |
| *(this+0x50) | 0x68 | R | — | Sub-object DWORD field compared for equality |
| *(this+0x50) | 0x6C | R | — | Sub-object DWORD field compared for equality |
| this | 0x4 | R | — | Object ID/DWORD compared for equality |
| this | 0xC | R | — | Float parameter 1 compared for equality |
| this | 0x10 | R | — | Float parameter 2 compared for equality |
| this | 0x14 | R | — | Float parameter 3 compared for equality |
| this | 0x18 | R | — | Float parameter 4 compared for equality |
| this | 0x1C | R | — | Float parameter 5 compared for equality |
| this | 0x20 | R | — | Float parameter 6 compared for equality |
| this | 0x24 | R | — | Float parameter 7 compared for equality |
| this | 0x28 | R | — | Float parameter 8 compared for equality |
| this | 0x2C | R | — | Float parameter 9 compared for equality |
| this | 0x30 | R | — | Float parameter 10 compared for equality |
| this | 0x34 | R | — | Float parameter 11 compared for equality |
| this | 0x38 | R | — | Float parameter 12 compared for equality |
| this | 0x3C | R | — | Float parameter 13 compared for equality |
| this | 0x44 | R | — | Float parameter 14 compared for equality |
| this | 0x48 | R | — | Float parameter 15 compared for equality |
| this | 0x4C | R | — | Float parameter 16 compared for equality |
| this | 0x50 | R | — | Pointer to sub-object (material properties) |
| this | 0x58 | RW | — | Priority/version counter; updated with max of this and a2's value |

**Written-by note (persistence):**
- this 0x58: Written conditionally when a2 has a larger value. External poke survives until next comparison updates it.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Any field mismatch between `this` and `a2` causes immediate return 0 (not equal). All fields including sub-object strings must match for function to reach final update and return 1.
