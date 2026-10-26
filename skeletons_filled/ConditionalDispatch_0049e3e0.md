## ConditionalDispatch_0049e3e0 — Conditional rendering dispatch

**Summary:** Guarded dispatch to sub_49F1C0 drawing function. Passes render surface and display context after null checks.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D5D0 (0049d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | render surface pointer (this[2]) |
| this | 0x14 | R | — | display context pointer (this[5]) |
| this | 0x68 | R | — | sub-struct pointer (steering input data) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049f1c0 | sub_49F1C0 | rendering function (fixed params 1,1,0 + surface + context) |

**Guard conditions:** Checks `this[2]` (0x8) non-null, `this[5]` (0x14) non-null, and `*(this[5]+84)` non-null — blocks sub_49F1C0 call if any null.
