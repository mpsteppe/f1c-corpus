## CursorScrollPositionTracker_0044f73c — Update scroll position with viewport clamping

**Summary:** Tracks cursor scroll/drag position within viewport bounds: computes normalized delta from previous center, updates center to current position, clamps within viewport rectangle, and writes both normalized delta and clamped normalized position. No callers identified statically.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Viewport top (Y min) |
| this | 0x4 | R | — | Viewport bottom (Y max) |
| this | 0x8 | R | — | Viewport left (X min) |
| this | 0xC | R | — | Viewport right (X max) |
| this | 0x10 | RW | — | Center X position (updated then clamped) |
| this | 0x14 | RW | — | Center Y position (updated then clamped) |
| this | 0x18 | R | — | Reciprocal half-width for normalization |
| this | 0x1C | R | — | Reciprocal half-height for normalization |
| this | 0x20 | RW | — | Normalized delta X (current - previous center) |
| this | 0x24 | RW | — | Normalized delta Y |
| this | 0x28 | RW | — | Normalized clamped X |
| this | 0x2C | RW | — | Normalized clamped Y |

**Written-by note (persistence):**
- this 0x10: updated unconditionally each call; external poke overwrites
- this 0x14: updated unconditionally each call; external poke overwrites
- this 0x20: computed each call; external poke overwrites
- this 0x24: computed each call; external poke overwrites
- this 0x28: computed each call; external poke overwrites
- this 0x2C: computed each call; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes all position update and clamp logic
