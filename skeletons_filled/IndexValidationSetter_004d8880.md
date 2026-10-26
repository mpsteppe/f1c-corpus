## IndexValidationSetter_004d8880 — Validated index setter

**Summary:** Validates and stores an index into `this[2]` (offset 0x8). If index is -1, clears the selection. Otherwise sets it only if the corresponding entry at `this[index+3]` is non-zero and an enable flag is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D8450 (004d8450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 18446744073709551615 | Selected/index value; initialized to -1 (invalid) and set to validated index on success |
| this | this+3 + a2*4 | R | — | Entry validation flag: must be non-zero for index to be accepted |

**Written-by note (persistence):**
- this 0x8: Set to -1 when a2==-1 (clear); set to a2 when validation + enable gate pass. External poke survives (direct assignment).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cf788 | dword_7CF788 | R | Enable flag — must be non-zero to allow validated index set |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `a2 == -1` → unconditionally clears `this[2]` to -1. `a2 != -1` → requires `this[a2+3] != 0` (entry is active/valid); if true and `dword_7CF788 != 0`, stores `this[2] = a2`. BLOCKED if entry is zero or enable flag is zero.
