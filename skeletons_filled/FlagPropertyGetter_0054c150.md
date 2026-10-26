## FlagPropertyGetter_0054c150 — Render flag field reader

**Summary:** Reads back render flag values set by the corresponding setter function. Checks flag bits via the second byte of an integer parameter and returns the value stored at +0x234 or +0x238 depending on which flag is active. Peer to RenderFlagSetter_0054c110.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapSplitTimeEvent (004bc390), NetworkMessageReceiveAndDispatch (004c7ca0), TimerFrameRateThrottle (004d3740), TrackTemperatureDisplay (004d37b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | R | — | Render flags word; checked for presence of 0x800 or 0x1000 bits |
| this | 0x234 | R | — | Stored render value for flag 0x800 mode |
| this | 0x238 | R | — | Stored render value for flag 0x1000 mode |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `BYTE1(a3) & 8` (a3 bit 11, value 0x800) is nonzero AND `this[15] & 0x800` is nonzero, PASSES: reads this[141] into *a2. Else if `BYTE1(a3) & 0x10` (a3 bit 12, value 0x1000) is nonzero AND `BYTE1(this[15]) & 0x10` is nonzero, PASSES: reads this[142] into *a2. If neither condition is met, BLOCKED: returns a3 unchanged with no writes to *a2.
