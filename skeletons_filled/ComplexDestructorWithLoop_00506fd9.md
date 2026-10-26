## ComplexDestructorWithLoop_00506fd9 — Destructor with 2D child pointer array cleanup

**Summary:** Sets vtable to off_5ADB90, then iterates over a 2D slab of child pointer entries (rows v1[1063]..v1[1064], columns v1[1060]..v1[1062]), freeing each via FreeWrapper_7bcf. Frees child array and metadata pointers, then delegates to VtableSetFreeChild for final cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_b244 (0050b244)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c534 | loc_59C534 | R | SEH jump target or exception handling label |
| 005adb90 | off_5ADB90 | R | VTable_D3DWrap [DERIVED] — static vtable assigned before cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ccc | VtableSetFreeChild | final cleanup: set vtable to off_5ADB80 and free child pointer |
| 00587bcf | FreeWrapper_7bcf | frees individual child pointers and arrays |
| 0058a5d8 | SEHHandlerInit | initialises structured exception handler |

**Guard conditions:** If v1[1071] (child count) is zero → skips child loop entirely. If v1[1072] (child array) is null → skips child loop. If v1[1063] >= v1[1064] → inner loop is skipped. Otherwise frees all children in slab range.
