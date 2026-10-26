## CollisionDamageDecayProcessor_0045b840 — CollisionDamageDecayProcessor

**Summary:** Processes collision damage decay across physics channels. Iterates through up to 4 active damage channels per frame (rotated start index), applies cooling rate to each damage value, renders damage text at screen position, resets expired channels via PerIndexStructFieldResetter, and sets active damage flag. Calls UI selection rectangle render each frame.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x31C | R | — | scan rotation start index (mod 8, ensures even distribution across frames) |
| this | 0x320 | RW | 1 | active damage flag byte: set to 0 then to 1 if any damage remains after decay |

**Written-by note (persistence):**
- this 0x320: written every frame (cleared to 0, then set to 1 if damage > 0 remains). External poke overwritten each frame.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059f078 | flt_59F078 | R | PenaltyScaleFactor [DERIVED] |
| 005d6d64 | dword_5D6D64 | R | ScreenWidth [DERIVED] — used to compute text line spacing |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] — damage decay amount per frame |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045b430 | PerIndexStructFieldResetter | reset/clear channel at index v6 when damage decays to <= 0 |
| 0045b660 | UICursorSelectionRectangleRenderWithInterpolatio | render cursor selection rectangle UI each frame |
| 0045bb00 | FloatArrayThresholdSearch | threshold/count search for initialization |
| 004dcf30 | TwinFieldGetter_cf30 | retrieve screen dimension (width) for text positioning |
| 004dd030 | TextRenderDispatcher | render damage text at channel position with parameters |
| 00587bdc | CRTFtol | convert screenWidth * 0.035 to int for text line spacing |

**Guard conditions:** Scan up to 8 channels starting at (startIndex + offset) % 8. If no channel has damage value at offset 0x90 > 0.0 → return immediately without text. Process up to 4 active damage entries per frame (loop count < 4). After decay: if damage > 0 → set flag at 0x320 to 1; if <= 0 → reset channel and leave flag 0.
