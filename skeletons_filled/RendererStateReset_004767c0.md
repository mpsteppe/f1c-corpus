## RendererStateReset_004767c0 — RendererStateResetAndTileGrid

**Summary:** Resets a renderer state counter at offset 0x168 to zero, then calls the UITileGrid rendering function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x168 | RW | 0 | renderer internal counter/state flag, reset to zero |

**Written-by note (persistence):**
- this 0x168: set to 0 every call; external poke overwritten each frame on call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none
