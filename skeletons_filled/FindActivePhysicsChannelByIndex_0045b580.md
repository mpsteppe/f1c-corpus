## FindActivePhysicsChannelByIndex_0045b580 — FindNthActivePhysicsChannel

**Summary:** Scans up to 8 physics channels (92-byte stride each) starting at offset 0x90, returns flat index (0-7) of the a2-th channel whose first float field is > 0.0 (active). Returns 0 if fewer than a2+1 active channels exist.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_45B5C0 (0045b5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | R | — | start of physics channel array; first float of each channel: >0.0 = active, <=0.0 = inactive |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If channel's first float at offset 0x90 <= 0.0 → skip (inactive). If offset by index >= 8 → return 0 (not found). Counts only active channels; returns flat index when a2-th active channel match found.
