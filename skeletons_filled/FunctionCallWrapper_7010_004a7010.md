## FunctionCallWrapper_7010_004a7010 — ParameterStoreAndCall

**Summary:** Stores two integer parameters as duplicated pairs at offsets 0xC/0x14 and 0x10/0x18, copies an input string via StringCopyWithBufferRealloc, then delegates to ShortComputation_1b70. Part of player options initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerOptionsInitializer (004aa270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | first copy of parameter a3 (option value) |
| this | 0x10 | RW | — | first copy of parameter a4 (related option value) |
| this | 0x14 | RW | — | second copy of parameter a3 (duplicated) |
| this | 0x18 | RW | — | second copy of parameter a4 (duplicated) |

**Written-by note (persistence):**
- this 0xC: once unconditional (a3)
- this 0x10: once unconditional (a4)
- this 0x14: once unconditional (a3, duplicate)
- this 0x18: once unconditional (a4, duplicate)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1b70 | ShortComputation_1b70 | performs further option initialization/computation on the struct |
| 00566650 | StringCopyWithBufferRealloc | copies input string path to allocated buffer |

**Guard conditions:** No guards. Always stores all 4 DWORDS, copies string, and calls ShortComputation_1b70 unconditionally.
