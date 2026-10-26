## sub_59A8FA_0059a8fa — CRT termination table registration

**Summary:** Registers `this` object in the global CRT termination function table (dword_8D4618). Searches for an empty or self-matching slot (index < 8), stores pointer, increments ref count in byte_8D463C at that index.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_598A41 (00598a41), ObjectConstructorWithSEHVtableInit (00598b5d), ObjectInitWithVTableFlagSet (005993eb), ObjectConstructorWithVtableSetup (00599b86), CConstructorWithSEH (00599c58), StreamCreationWithFlagInit (0059a3a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | Index into CRT termination table (slot number, 0-7) |

**Written-by note (persistence):**
- this 0x24: Once — slot index written during registration. External poke would corrupt table indexing.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d4618 | dword_8D4618 | RW | CRTTermFuncTable [DERIVED] |
| 008d463c | byte_8D463C | W | RefCountArray [DERIVED] (also: Reference count array (indexed by extraout_ECX[9]) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059a54d | sub_59A54D | CRT init prologue (SEH/local unwind setup) |
| 0059a5e9 | sub_59A5E9 | CRT cleanup epilogue (SEH unwind teardown) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24 | < | 8 | Slot index must be < 8 to search table |

**Guard interpretation:** PASSES when this[9] < 8 → linear search for empty or self slot. BLOCKED (skip search) when this[9] >= 8 → uses current value directly.
