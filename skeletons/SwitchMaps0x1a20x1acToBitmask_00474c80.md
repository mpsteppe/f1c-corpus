## SwitchMaps0x1a20x1acToBitmask_00474c80 — MapTrackElementIdToBitmask

**Summary:** Reads an element ID from this+0x31C and maps values 0x1A2-0x1AC to bitmask powers of two (1 through 1024) written to output parameter; returns 1 on match, 0 on unknown ID (sets output to -1).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x31C | R | — | Element/track ID to convert to bitmask |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00474da4 | jpt_474C95 | R | Jump table for the switch dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Only PASSES if this[0x31C] is in range [0x1A2, 0x1AC]; all other values BLOCKED (returns 0, sets output to -1).
