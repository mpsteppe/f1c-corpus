## sub_5FC6D0_005fc6d0 — Struct initializer (base init + default scale/constants)

**Summary:** Constructor/initializer variant that first runs sub_5D9010(this) for base/sub-object initialization, then zeroes the dword block at 0x0/0x4 and 0x24–0x60 and writes two unit-scale triples 1.0f at 0x64/0x68/0x6C and 0x70/0x74/0x78 plus 100.0f at 0x7C. Returns the this pointer.

**Called by:** sub_5FDC80 (005fdc80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Zeroed dword (flags/counter) |
| this | 0x4 | RW | 0 | Zeroed byte (state flag) |
| this | 0x24 | RW | 0 | Zeroed dword (start of the 0x24–0x60 zero block) |
| this | 0x28 | RW | 0 | Zeroed dword |
| this | 0x2C | RW | 0 | Zeroed dword |
| this | 0x30 | RW | 0 | Zeroed dword |
| this | 0x34 | RW | 0 | Zeroed dword |
| this | 0x38 | RW | 0 | Zeroed dword |
| this | 0x3C | RW | 0 | Zeroed dword |
| this | 0x40 | RW | 0 | Zeroed dword |
| this | 0x44 | RW | 0 | Zeroed dword |
| this | 0x48 | RW | 0 | Zeroed dword |
| this | 0x4C | RW | 0 | Zeroed dword |
| this | 0x50 | RW | 0 | Zeroed dword |
| this | 0x54 | RW | 0 | Zeroed dword |
| this | 0x58 | RW | 0 | Zeroed dword |
| this | 0x5C | RW | 0 | Zeroed dword |
| this | 0x60 | RW | 0 | Zeroed dword (end of zero block) |
| this | 0x64 | RW | 1065353216 → 1.0f | First unit-scale vector component |
| this | 0x68 | RW | 1065353216 → 1.0f | First unit-scale vector component |
| this | 0x6C | RW | 1065353216 → 1.0f | First unit-scale vector component |
| this | 0x70 | RW | 1065353216 → 1.0f | Second unit-scale vector component |
| this | 0x74 | RW | 1065353216 → 1.0f | Second unit-scale vector component |
| this | 0x78 | RW | 1065353216 → 1.0f | Second unit-scale vector component |
| this | 0x7C | RW | 1120403456 → 100.0f | Default float constant (magnitude/rate/range) |

**Written-by note (persistence):**
- this 0x0: unconditional straight-line write right after the base init call; persists until the object is reinitialized.
- this 0x4: unconditional byte write; persists until reinitialized.
- this 0x24: unconditional write; persists until reinitialized.
- this 0x28: unconditional write; persists until reinitialized.
- this 0x2C: unconditional write; persists until reinitialized.
- this 0x30: unconditional write; persists until reinitialized.
- this 0x34: unconditional write; persists until reinitialized.
- this 0x38: unconditional write; persists until reinitialized.
- this 0x3C: unconditional write; persists until reinitialized.
- this 0x40: unconditional write; persists until reinitialized.
- this 0x44: unconditional write; persists until reinitialized.
- this 0x48: unconditional write; persists until reinitialized.
- this 0x4C: unconditional write; persists until reinitialized.
- this 0x50: unconditional write; persists until reinitialized.
- this 0x54: unconditional write; persists until reinitialized.
- this 0x58: unconditional write; persists until reinitialized.
- this 0x5C: unconditional write; persists until reinitialized.
- this 0x60: unconditional write; persists until reinitialized.
- this 0x64: unconditional write; persists until reinitialized.
- this 0x68: unconditional write; persists until reinitialized.
- this 0x6C: unconditional write; persists until reinitialized.
- this 0x70: unconditional write; persists until reinitialized.
- this 0x74: unconditional write; persists until reinitialized.
- this 0x78: unconditional write; persists until reinitialized.
- this 0x7C: unconditional write; persists until reinitialized.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d9010 | GlobalZeroInit_c2a0 [exact] | Base/sub-object initialization run first (zero-init of embedded state) before the explicit field defaults are written |

**Guard conditions:** None — fully straight-line: sub_5D9010(this) is called unconditionally, then every field is written unconditionally; the constant return is `this`. Nothing passes or is blocked.
