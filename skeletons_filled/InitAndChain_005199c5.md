## InitAndChain_005199c5 — InitAndChain

**Summary:** Resets animation current index to 0 and chains to SpriteFrameSelector to select the initial frame.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x80 | RW | 0 | current animation index, zeroed to reset position |

**Written-by note (persistence):**
- this 0x80: once, unconditional (set to 0); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none (unconditional zero + chain to SpriteFrameSelector).
