## sub_4D7FE0_004d7fe0 — DelegateWithField4

**Summary:** Delegates to sub_4D8A30 passing the value at offset 0x4 of the struct as argument. Called by VTableDispatchChain_7e00 as part of the dispatch chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VTableDispatchChain_7e00 (004d7e00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | argument passed to sub_4D8A30 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d8a30 | sub_4D8A30 | target delegate function receiving field at offset 4 |

**Guard conditions:** none — unconditional call.
