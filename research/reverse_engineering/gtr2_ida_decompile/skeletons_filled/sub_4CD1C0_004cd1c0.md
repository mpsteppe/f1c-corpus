## sub_4CD1C0_004cd1c0 — nested-object gate then case-insensitive string compare

**Summary:** `__thiscall` helper that first clears two state dwords (this[0x980], this[0x984]) and then walks a chain of null-checks into a nested sub-object; only if every gate passes (sub-object present, entry count > 0, table pointer valid, first entry non-null) does it perform a case-insensitive comparison of the two string arguments via `_stricmp` and return its result. Otherwise it returns the null/failed pointer value without comparing.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Pointer to the primary sub-object (this[2]); first null-check gate |
| this | 0x27C | R | — | Pointer loaded from the nested object during the check chain; dereferenced (`*result`) and must be non-zero to allow the comparison |
| this | 0x4F0 | R | — | Pointer field of the nested object; loaded and null-checked before the entry test |
| this | 0x4FC | R | — | Signed entry count of the nested object; must be > 0 to enter the comparison path (guard) |
| this | 0x980 | RW | 0 | State dword cleared to 0 on every entry (reset flag/counter) |
| this | 0x984 | RW | 0 | Second state dword cleared to 0 on every entry (reset flag/counter) |

**Written-by note (persistence):**
- this 0x980: Unconditionally zeroed at function entry before any branch; any prior value (including an external poke) is erased on the next call to this function.
- this 0x984: Same — unconditionally zeroed at entry; not persistent across calls.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cd247 | loc_4CD247 | R | Intra-function code label (return/exit path of one of the early checks) |
| 004cd271 | loc_4CD271 | R | Intra-function code label (return/exit path of another early check) |
| 00631c0d | __stricmp | R | CRT case-insensitive string comparison; called with the two string arguments when all gates pass, its result returned |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4FC | > | 0 | Signed entry count of the nested object; must be positive for the comparison path |

**Guard interpretation:** Comparison runs only if ALL of: this[0x8] non-null → nested object's count at 0x4FC is > 0 (zero or negative blocks) → pointer at 0x4F0 non-null → its first dword non-zero. If all pass, `_stricmp(a2, a3)` is executed and its result returned. Any failed gate returns the null/pointer value and skips the comparison entirely; the two dwords at 0x980/0x984 are zeroed regardless.
