## TireNameAccessor_004f1630 — TireNameAccessor

**Summary:** Looks up tire name string from compound index; returns default path if not found. Part of tire/vehicle configuration system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_429960 (00429960), AIPushLap (0042a180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x396C | R | — | Compound index key (first part of lookup) |
| this | 0x3970 | R | — | Compound index key (second part of lookup) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7570 | CompoundIndexLookup | Looks up tire name string from compound index pair |

**Guard conditions:** Checks if CompoundIndexLookup returns null. PASSES (returns lookup result) when non-null. BLOCKED (returns default directory path byte_5EA438) when lookup fails.
