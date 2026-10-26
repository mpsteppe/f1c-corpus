## sub_6CD18B_006cd18b — copy 13-dword state block from source

**Summary:** Copies 13 dwords (offsets 0x00–0x30) from the source block a2 into this object's state block, returning failure code -2147467259 (E_FAIL) if a2 is NULL and 0 on success.

**Called by:** sub_681B61 (00681b61)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Destination dword 0; receives a2[0] |
| this | 0x4 | RW | — | Destination dword 1; receives a2[1] |
| this | 0x8 | RW | — | Destination dword 2; receives a2[2] |
| this | 0xC | RW | — | Destination dword 3; receives a2[3] |
| this | 0x10 | RW | — | Destination dword 4; receives a2[4] |
| this | 0x14 | RW | — | Destination dword 5; receives a2[5] |
| this | 0x18 | RW | — | Destination dword 6; receives a2[6] |
| this | 0x1C | RW | — | Destination dword 7; receives a2[7] |
| this | 0x20 | RW | — | Destination dword 8; receives a2[8] |
| this | 0x24 | RW | — | Destination dword 9; receives a2[9] |
| this | 0x28 | RW | — | Destination dword 10; receives a2[10] |
| this | 0x2C | RW | — | Destination dword 11; receives a2[11] |
| this | 0x30 | RW | — | Destination dword 12; receives a2[12] |

**Written-by note (persistence):**
- this 0x0: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x4: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x8: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0xC: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x10: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x14: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x18: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x1C: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x20: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x24: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x28: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x2C: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call
- this 0x30: Overwritten on every call while a2 is non-null; external poke survives only until the next copy call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 == NULL → immediate return -2147467259 (E_FAIL), nothing copied. Non-null a2 → all 13 dwords are copied and 0 is returned.
