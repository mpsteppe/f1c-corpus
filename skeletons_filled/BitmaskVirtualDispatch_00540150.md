## BitmaskVirtualDispatch_00540150 — Bitmask-based virtual dispatch to surface accessors

**Summary:** Dispatches to one of three surface getters based on lower 3 bits of selector (a3 or this+0x18). Bit 1 → direct pointer at this+0x8; bit 2 → vtable[10] call via this+0xC; bit 4 → vtable[17] call via this+0x16. Returns result or fallthrough.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ArgumentReorderWrapper_3230 (00543230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x10)+0x0) | 0x44 | R | — | vtable[17] (offset 68) — dispatch with a2 arg |
| *(*(this+0xC)+0x0) | 0x28 | R | — | vtable[10] (offset 40) — dispatch with no extra args |
| *(this+0x10) | 0x0 | R | — | vtable pointer of third sub-object |
| *(this+0xC) | 0x0 | R | — | vtable pointer of second sub-object |
| this | 0x8 | R | — | direct pointer returned when bit 1 set |
| this | 0xC | R | — | sub-object 2 pointer — vtable dispatch when bit 2 set (and bit 1 clear) |
| this | 0x10 | R | — | sub-object 3 pointer — vtable dispatch when bit 4 set |
| this | 0x18 | R | — | default fallback selector — used when a3 is 0 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a3 == 0 → use this+0x18 as selector. Bit 1 (0x1) set → return this+0x8 (with vtable[10] call if non-null). Bit 2 (0x2) set → return this+0xC vtable[10] result. Bit 4 (0x4) set → dispatch via this+0x10 vtable[17]. Bits 1/2 fall through to bit 4 check if the pointer is null.
