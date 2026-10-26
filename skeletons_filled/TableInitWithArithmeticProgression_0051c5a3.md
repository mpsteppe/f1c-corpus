## TableInitWithArithmeticProgression_0051c5a3 — Wheel lookup table arithmetic fill

**Summary:** Allocates four 1024-DWORD lookup tables via vtable dispatch and fills each with arithmetic progression values (three linear sequences and one pointer-derived sequence). Used for initializing wheel/suspension suspension-damper data tables.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputBindingConfigSetup (0051cb6d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A0) | 0x8 | RW | — | v2[2]: Table 0 allocation result — filled with arithmetic progression (v9 >> 16) |
| *(this+0x1A0) | 0xC | RW | — | v2[3]: Table 1 allocation result — filled with arithmetic progression (v8 >> 16) |
| *(this+0x1A0) | 0x10 | RW | — | v2[4]: Table 2 allocation result — filled with pointer-derived values from unk_5B6900 |
| *(this+0x1A0) | 0x14 | RW | — | v2[5]: Table 3 allocation result — filled with decreasing arithmetic sequence |
| *(this+0x4) | 0x0 | R | — | Vtable[0]: memory allocator called 4 times with size=1024, type=1 |
| this | 0x4 | R | — | Vtable pointer for allocation dispatch |
| this | 0x1A0 | R | — | Pointer to table sub-struct (v2) that receives the four allocation results |

**Written-by note (persistence):**
- *(this+0x1A0) 0x8: Allocated and filled once per init. Persists unchanged after.
- *(this+0x1A0) 0xC: Same as above.
- *(this+0x1A0) 0x10: Same as above.
- *(this+0x1A0) 0x14: Same as above.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b6900 | unk_5B6900 | R | Base data table — pointer-derived values read with decrementing offset for table 2 fill |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — unconditional table allocation and fill. Always allocates 4x1024 DWORDs and fills with arithmetic progressions.
