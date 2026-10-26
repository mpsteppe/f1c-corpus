## ComplexStateValidator_005169ac — ValidateObjectState

**Summary:** Validates an object's state by checking multiple fields against expected values. Returns 1 if all checks pass (byte flags clear, enum-type fields match expected constants, sub-object fields consistent), 0 on any mismatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516A1D (00516a1d), sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC4) | 0x8 | R | — | dword field in sub-object, must equal 2 |
| *(this+0xC4) | 0xC | R | — | dword field in sub-object, must be <= 2 |
| *(this+0xC4) | 0x24 | R | — | dword in sub-object, must equal reference value from this+0x114 |
| *(this+0xC4) | 0x5C | R | — | dword in sub-object, must equal 1 |
| *(this+0xC4) | 0x60 | R | — | dword in sub-object, must equal 1 |
| *(this+0xC4) | 0x78 | R | — | dword in sub-object, must equal reference value from this+0x114 |
| *(this+0xC4) | 0xB0 | R | — | dword in sub-object, must equal 1 |
| *(this+0xC4) | 0xB4 | R | — | dword in sub-object, must equal 1 |
| *(this+0xC4) | 0xCC | R | — | dword in sub-object, must equal reference value from this+0x114 |
| this | 0x20 | R | — | dword, must equal 3 (enum/state check) |
| this | 0x24 | R | — | dword, must equal 3 (enum/state check) |
| this | 0x28 | R | — | dword, must equal 2 (enum/state check) |
| this | 0x48 | R | — | byte flag, must be 0 (cleared) |
| this | 0x64 | R | — | dword, must equal 3 (enum/state check) |
| this | 0xC4 | R | — | pointer to sub-object containing additional validation fields |
| this | 0x108 | R | — | byte flag, must be 0 (cleared) |
| this | 0x114 | R | — | reference value that sub-object fields at +0x24, +0x78, +0xCC must match |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC4) | 0x8 | != | 2 | sub-object type/state field |
| *(this+0xC4) | 0xC | > | 2 | sub-object count/limit field |
| *(this+0xC4) | 0x5C | != | 1 | sub-object mode/flag field |
| *(this+0xC4) | 0x60 | != | 1 | sub-object mode/flag field |
| *(this+0xC4) | 0xB0 | != | 1 | sub-object mode/flag field |
| *(this+0xC4) | 0xB4 | != | 1 | sub-object mode/flag field |
| this | 0x20 | != | 3 | main object state field |
| this | 0x24 | != | 3 | main object state field |
| this | 0x28 | != | 2 | main object state field |
| this | 0x64 | != | 3 | main object state field |

**Guard interpretation:** Each test checks a specific field against expected constant or reference. Any mismatch returns 0 (validation FAIL). Additional checks not in table: byte at this+0x48 must be 0, byte at this+0x108 must be 0, and three sub-object fields (+0x24, +0x78, +0xCC) must all equal reference value at this+0x114. All checks pass → return 1 (PASS).
