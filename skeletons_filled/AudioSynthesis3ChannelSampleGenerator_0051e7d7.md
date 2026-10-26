## AudioSynthesis3ChannelSampleGenerator_0051e7d7 — ThreeChannelTableSampleGenerator

**Summary:** Generates 3-channel output samples by summing component values from phase-selected lookup tables. For each pixel, reads 3 source bytes, adds table-based offsets from three phase-indexed tables, writes accumulated output byte, advances rolling 4-bit phase counter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x18 | R | — | component table 0 base pointer |
| *(this+0x1A4) | 0x1C | R | — | component table 1 base pointer |
| *(this+0x1A4) | 0x20 | R | — | component table 2 base pointer |
| *(this+0x1A4) | 0x30 | RW | — | phase counter (rolling 4-bit, incremented per pixel) |
| *(this+0x1A4) | 0x34 | R | — | phase offset table for component 0 |
| *(this+0x1A4) | 0x38 | R | — | phase offset table for component 1 |
| *(this+0x1A4) | 0x3C | R | — | phase offset table for component 2 |
| this | 0x5C | R | — | pixel width (stride) |
| this | 0x1A4 | R | — | context pointer |

**Written-by note (persistence):**
- *(this+0x1A4) 0x30: phase counter incremented per pixel; survives across calls as persistent state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if a4 (pixel count) <= 0, skip outer loop. if v18 (width) > 0, process inner sample loop (line 47). PASSES when count > 0; BLOCKED when zero.
