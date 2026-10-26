## ConstructorWith1Sentinels_0049a930 — ConstructorWithSentinelInit

**Summary:** Constructor that sets the vtable pointer (off_5ACAB0) at offset 0x00, initializes a sub-object at offset 0x24 via ThunkToFUN00491330, zeroes fields 0x04-0x10, sets fields 0x14-0x20 and 0x38 to -1 (sentinel/empty markers), and clears byte at 0x3C and DWORD at 0x34 to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5e30 (00485e30), InitWithVTableParam (00498d20), FunctionCallWrapper_91e0 (004991e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer set to off_5ACAB0 |
| this | 0x4 | RW | 0 | field zeroed on construction |
| this | 0x8 | RW | 0 | field zeroed on construction |
| this | 0xC | RW | 0 | field zeroed on construction |
| this | 0x10 | RW | 0 | field zeroed on construction |
| this | 0x14 | RW | -1 (sentinel) | sentinel marker (-1 = invalid/empty) |
| this | 0x18 | RW | -1 (sentinel) | sentinel marker (-1 = invalid/empty) |
| this | 0x1C | RW | -1 (sentinel) | sentinel marker (-1 = invalid/empty) |
| this | 0x20 | RW | -1 (sentinel) | sentinel marker (-1 = invalid/empty) |
| this | 0x34 | RW | 0 | field zeroed on construction |
| this | 0x38 | RW | -1 (sentinel) | sentinel marker (-1 = invalid/empty) |
| this | 0x3C | RW | 0 | byte field zeroed on construction |

**Written-by note (persistence):**
- this 0x0: vtable pointer set once; external poke survives
- this 0x4: constructor init; external poke survives
- this 0x8: constructor init; external poke survives
- this 0xC: constructor init; external poke survives
- this 0x10: constructor init; external poke survives
- this 0x14: sentinel (-1) set once; external poke survives
- this 0x18: sentinel (-1) set once; external poke survives
- this 0x1C: sentinel (-1) set once; external poke survives
- this 0x20: sentinel (-1) set once; external poke survives
- this 0x34: constructor init; external poke survives
- this 0x38: sentinel (-1) set once; external poke survives
- this 0x3C: constructor init; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acab0 | off_5ACAB0 | R | VTable_5ACAB0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004912f0 | ThunkToFUN00491330 | initialize sub-object at this+9 (offset 0x24) |

**Guard conditions:** None — straight-line constructor, no branches.
