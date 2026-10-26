## VehicleNameToMessageBuffer_0047f010 — VehicleNameDisplayUpdate

**Summary:** Loads current vehicle name from game module, validates it against the string table, copies valid name to message display buffer, and updates UI text; falls back to default path string if vehicle name is empty.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path, used as fallback display string |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] — string table for vehicle name validation |
| 005ec4cc | byte_5EC4CC | R | MessageDisplayBuffer [DERIVED] — output buffer for vehicle name display |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] — game module manager for vehicle name lookup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | validate vehicle name exists in string table before copying |
| 00462e00 | VehicleNameAccessor | get current vehicle name from game module |
| 00488b40 | UIStringComparison | display vehicle name or fallback text in the UI |

**Guard conditions:** If VehicleNameAccessor returns null or empty string, skips copy and shows fallback default path; if BinarySearchInStringTable fails (name not found in table), skips copy but still displays existing buffer content.
