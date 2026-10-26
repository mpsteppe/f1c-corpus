## RenderStateReset_004986a0 — Render State Fields Reset

**Summary:** Clears three integer state fields to 0 and resets a global string buffer to a default/empty value. Used to reinitialize rendering state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1560 | RW | 0 | First render state integer; cleared to 0 on reset |
| this | 0x1564 | RW | 0 | Second render state integer; cleared to 0 on reset |
| this | 0x1568 | RW | 0 | Third render state integer; cleared to 0 on reset |

**Written-by note (persistence):**
- this 0x1560: Set to 0 unconditionally each call; persists until next setter or reset
- this 0x1564: Same as 0x1560
- this 0x1568: Same as 0x1560

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Global string buffer reset to default/empty value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies default/empty string to the global byte_5EA438 buffer |

**Guard conditions:** (none — always executes full body)
