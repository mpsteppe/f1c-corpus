## VehicleDescriptionAccessor_00463c80 — Vehicle Description String Accessor

**Summary:** Reads vehicle description string pointer at this+0xB4. Returns the pointer if non-null, otherwise returns fallback default directory path as placeholder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadAndProcessMessageBuffer (0047f0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | vehicle description string pointer |
| this | 0x0 | R | — | vtable/primary pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If string pointer at +0xB4 is null, returns fallback default path string instead. PASSES when non-null — returns the actual description pointer.
