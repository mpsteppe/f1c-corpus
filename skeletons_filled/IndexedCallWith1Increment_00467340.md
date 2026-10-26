## IndexedCallWith1Increment_00467340 — MenuOptionValueAdjust

**Summary:** Adjusts a menu option value by ±1 based on direction (a2=1 increments, else decrements), then dispatches to the appropriate handler based on selection type. Belongs to menu option system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | R | — | pointer to option value data structure |
| this | 0x324 | R | — | current selected value/index of the option |
| this | 0x328 | R | — | secondary parameter for AI gear selection dispatch |
| this | 0x32C | R | — | selection type/category (4 = list clamp, others = AI gear) |
| this | 0x334 | R | — | unknown (not referenced in decompiled code) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] (also: file loader flag (save/restore around file operations, docs/08) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042eaa0 | AIGearSelectionSet | sets AI gear selection for non-type-4 options |
| 0042eb60 | ListSelectionClamp | clamps/validates a list selection value within bounds for type-4 options |
| 004673b0 | MenuOptionValueDisplay | refreshes the formatted display text for the current option |

**Guard conditions:** Checks this[200] (pointer at offset 0x320) for null; if null, function returns immediately (BLOCKED). Only proceeds when pointer is non-null (PASSES).
