## CollisionProxyUnregister_0044f0e0 — Unregister collision proxy slot

**Summary:** Unregisters a collision proxy entry: clears one byte in the proxy active-flag array at 0x37C, removes proxy ID from the active list at 0xC88, and resets the proxy's axis float at 0x87C to either 0 or the dead zone threshold.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC88 | R | — | Active proxy ID list (word array, up to 256 entries) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 008afea8 | dbl_8AFEA8 | R | InputAxisDeadZone [DERIVED] (also: ` â€” axis threshold (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes; no conditional early exit
