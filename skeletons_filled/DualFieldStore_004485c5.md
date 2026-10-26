## DualFieldStore_004485c5 — DualFieldStore

**Summary:** Stores the same 32-bit value into two adjacent fields at offsets 0x58 and 0x5C of the target structure. Fastcall convention: a1 in ECX, a2 in EDX (target pointer).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | first copy of input value |
| this | 0x5C | RW | — | second copy of input value |

**Written-by note (persistence):**
- this 0x58: overwritten every call; external poke survives
- this 0x5C: overwritten every call; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard. Unconditional dual-field store.
