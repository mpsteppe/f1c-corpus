## sub_6A6CEE_006a6cee — ValidatePs14Program

**Summary:** ps_1_4 program validation pass: rejects programs with more than 64 objects, flags texture-load instructions whose operand registers resolve to COLOR-dependent register descriptors (error 4500), and runs the dependent-read chain check on every object. Returns 1 if any violation was reported, 0 if the program is clean.

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | this[3]: number of program objects (instructions); must be <= 0x40 |
| this | 0x14 | R | — | this[5]: register descriptor table, indexed by operand register index |
| this | 0x18 | R | — | this[6]: object pointer array iterated by index |
| this | 0x100 | RW | — | this[64]: scratch cursor holding the current object during validation |
| this | 0x104 | R | — | unknown (not visible in provided decompilation) |
| this | 0x108 | R | — | unknown (not visible in provided decompilation) |
| this | 0x13C | R | — | unknown (not visible in provided decompilation) |

**Written-by note (persistence):**
- this 0x100: overwritten at the top of every object iteration (this[64] = object pointer) and read immediately; it is transient loop state, so an external poke is overwritten before its next use and does not persist.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00743ce8 | aCannotPerformT_0 | R | message "cannot perform texture load that is in anyway dependent on COLOR registers" reported with code 4500 |
| 00743d34 | aProgramIsOrder | R | message "program is order of magnitude too large to compile to ps_1_4" reported when object count > 64 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | error reporter: (this, object offset, error code 4500, message string) |
| 006a6c77 | sub_6A6C77 | per-object dependent-read chain validation; returns 0 on violation |

**Guard conditions:** this[3] (object count) > 0x40 → BLOCK: report "program is order of magnitude too large to compile to ps_1_4" and return 1. Otherwise each object is visited: the operand scan runs only when object+36 != 0 and object+4 != 0; for each source operand, if the register descriptor byte at +108 == 1 (COLOR-derived) → report the COLOR-dependency message, set the flag, and keep scanning. Every object (regardless of the +36/+4 test) is then passed to sub_6A6C77(this, object, 0): if it returns 0 → BLOCK: break and return 1. If all objects pass, return the flag (0 = clean, 1 = COLOR violation was recorded). Zero objects → return 0.

**String literals referenced (deterministic):**

- `cannot perform texture load that is in anyway dependent on COLOR registers`
- `program is order of magnitude too large to compile to ps_1_4`
