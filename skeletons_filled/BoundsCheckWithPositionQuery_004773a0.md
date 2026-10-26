## BoundsCheckWithPositionQuery_004773a0 — PositionBoundsValidator

**Summary:** Reads current position via `DualFieldRead` and validates that `a2` exists and the position falls within the bounding rectangle defined at offsets 0x120-0x124 (X range) and 0x140-0x144 (Y range).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListTraversalVirtualCall (00477160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x120 | R | — | bounding rectangle minimum X |
| this | 0x124 | R | — | bounding rectangle maximum X |
| this | 0x140 | R | — | bounding rectangle minimum Y |
| this | 0x144 | R | — | bounding rectangle maximum Y |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048ea60 | RectangleBoundsCheck | validates final rectangle bounds check |
| 00498880 | DualFieldRead | reads current X/Y position into output variables |

**Guard conditions:** `a2` must be non-null; `v4` (current X) must be > `this[72]` (offset 0x120) AND < `this[73]` (offset 0x124); `v5` (current Y) must be > `this[80]` (offset 0x140) AND < `this[81]` (offset 0x144); `RectangleBoundsCheck` must return non-zero (true)
