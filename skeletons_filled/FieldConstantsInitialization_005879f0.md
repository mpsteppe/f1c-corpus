## FieldConstantsInitialization_005879f0 — Reset buffer state fields to defaults

**Summary:** Resets three zero fields (offsets 0x400, 0x404, 0x408) and sets field at 0x40C to constant 500. Acts as buffer state reset/initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BufferedCharIOInit (005876f0), sub_5878A0 (005878a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x400 | RW | 0 | Buffer position/index reset to 0 |
| this | 0x404 | RW | 0 | Buffer field reset to 0 |
| this | 0x408 | RW | 0 | Counter/index reset to 0 |
| this | 0x40C | RW | 500 | Default capacity/limit set to 500 |

**Written-by note (persistence):**
- this 0x400: set to 0 each call; external poke overwrites it
- this 0x404: set to 0 each call; external poke overwrites it
- this 0x408: set to 0 each call; external poke overwrites it
- this 0x40C: set to 500 each call; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional reset of all four fields.
