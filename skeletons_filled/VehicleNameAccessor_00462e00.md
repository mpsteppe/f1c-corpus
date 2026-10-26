## VehicleNameAccessor_00462e00 — Vehicle Name String Accessor

**Summary:** Reads vehicle name/description string pointer at this+0xBC. Returns the pointer if non-null, otherwise returns fallback default directory path string as placeholder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleNameToMessageBuffer (0047f010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xBC | R | — | vehicle name/description string pointer |
| this | 0x0 | R | — | vtable/primary pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If string pointer at +0xBC is null, returns fallback default path string instead. PASSES when non-null — returns the actual vehicle name pointer.
