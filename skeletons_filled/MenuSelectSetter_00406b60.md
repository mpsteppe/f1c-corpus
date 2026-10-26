## MenuSelectSetter_00406b60 — TrackIndexSelectorSetter

**Summary:** Simple setter that writes an integer value to offset 0x54 (track index/selection) and returns it.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | RW | — | track index/selection field (set to input parameter a2) |

**Written-by note (persistence):**
- this 0x54: written unconditionally — external poke survives until next setter call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always writes the value
