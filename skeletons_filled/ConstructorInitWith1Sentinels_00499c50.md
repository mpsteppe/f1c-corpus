## ConstructorInitWith1Sentinels_00499c50 — Constructor with Sentinel-Initialized Slot Array

**Summary:** Constructor that initializes a vtable pointer, stores a context parameter, and initializes an array of 10 slots each as (activeFlag=0, id=-1 sentinel) followed by trailing zero fields. Object lifecycle / initialization system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493060 (00493060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ACAAC) |
| this | 0x4 | RW | — | constructor context parameter (a2) |
| this | 0x8 | RW | 0 | zero-initialized field |
| this | 0xC | RW | 0 | zero-initialized field |
| this | 0x10 | RW | 0 | slot[0] active flag (0 = inactive) |
| this | 0x14 | RW | 18446744073709551615 | slot[0] id (UINT_MAX = -1 sentinel = invalid) |
| this | 0x18 | RW | 0 | slot[1] active flag |
| this | 0x1C | RW | 18446744073709551615 | slot[1] id (sentinel) |
| this | 0x20 | RW | 0 | slot[2] active flag |
| this | 0x24 | RW | 18446744073709551615 | slot[2] id (sentinel) |
| this | 0x28 | RW | 0 | slot[3] active flag |
| this | 0x2C | RW | 18446744073709551615 | slot[3] id (sentinel) |
| this | 0x30 | RW | 0 | slot[4] active flag |
| this | 0x34 | RW | 18446744073709551615 | slot[4] id (sentinel) |
| this | 0x38 | RW | 0 | slot[5] active flag |
| this | 0x3C | RW | 18446744073709551615 | slot[5] id (sentinel) |
| this | 0x40 | RW | 0 | slot[6] active flag |
| this | 0x44 | RW | 18446744073709551615 | slot[6] id (sentinel) |
| this | 0x48 | RW | 0 | slot[7] active flag |
| this | 0x4C | RW | 18446744073709551615 | slot[7] id (sentinel) |
| this | 0x50 | RW | 0 | slot[8] active flag |
| this | 0x54 | RW | 18446744073709551615 | slot[8] id (sentinel) |
| this | 0x58 | RW | 0 | slot[9] active flag |
| this | 0x5C | RW | 18446744073709551615 | slot[9] id (sentinel) |
| this | 0x60 | RW | 0 | trailing field A (zeroed) |
| this | 0x64 | RW | 0 | trailing field B (zeroed) |
| this | 0x68 | RW | 0 | trailing field C (zeroed) |
| this | 0x6C | RW | 0 | counter/state field A (zeroed) |
| this | 0x70 | RW | 0 | counter/state field B (zeroed) |
| this | 0x74 | RW | 0 | counter/state field C (zeroed) |
| this | 0x78 | RW | 0 | counter/state field D (zeroed) |

**Written-by note (persistence):**
- this 0x0: write once at construction — external poke survives until next construction call
- this 0x4: write once at construction — external poke survives until next construction call
- this 0x8: write once at construction — external poke survives until next construction call
- this 0xC: write once at construction — external poke survives until next construction call
- this 0x10: write once at construction — external poke survives until next construction call
- this 0x14: write once at construction — external poke survives until next construction call
- this 0x18: write once at construction — external poke survives until next construction call
- this 0x1C: write once at construction — external poke survives until next construction call
- this 0x20: write once at construction — external poke survives until next construction call
- this 0x24: write once at construction — external poke survives until next construction call
- this 0x28: write once at construction — external poke survives until next construction call
- this 0x2C: write once at construction — external poke survives until next construction call
- this 0x30: write once at construction — external poke survives until next construction call
- this 0x34: write once at construction — external poke survives until next construction call
- this 0x38: write once at construction — external poke survives until next construction call
- this 0x3C: write once at construction — external poke survives until next construction call
- this 0x40: write once at construction — external poke survives until next construction call
- this 0x44: write once at construction — external poke survives until next construction call
- this 0x48: write once at construction — external poke survives until next construction call
- this 0x4C: write once at construction — external poke survives until next construction call
- this 0x50: write once at construction — external poke survives until next construction call
- this 0x54: write once at construction — external poke survives until next construction call
- this 0x58: write once at construction — external poke survives until next construction call
- this 0x5C: write once at construction — external poke survives until next construction call
- this 0x60: write once at construction — external poke survives until next construction call
- this 0x64: write once at construction — external poke survives until next construction call
- this 0x68: write once at construction — external poke survives until next construction call
- this 0x6C: write once at construction — external poke survives until next construction call
- this 0x70: write once at construction — external poke survives until next construction call
- this 0x74: write once at construction — external poke survives until next construction call
- this 0x78: write once at construction — external poke survives until next construction call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acaac | off_5ACAAC | R | VTable_5ACAAC [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — constructor initializes all fields unconditionally on every call.
