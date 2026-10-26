## PitStallProximityCheck_004b5da0 — Pit Stall Proximity Check

**Summary:** Iterates a circular buffer of pit stall indices, checking vehicle Z-distance to each stall. If within 1.5 units, creates a collision object to register the stall contact.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B4 | R | — | Circular buffer size/modulus |
| this | 0x9B8 | R | — | Current circular buffer index |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: reverse gear throttle multiplier) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b48e0 | CollisionObjectInsertion | Register collision object between stall and vehicle |
| 004b68c0 | CircularBufferCheck | Query circular buffer stall count and buffer state |
| 004b6920 | IndexedPointerLookup | Look up pit stall pointer by circular buffer index |
| 004b6940 | PitstopActionSet | Set pitstop action/speed state |

**Guard conditions:** If CircularBufferCheck() returns 0, PitstopActionSet is called first and CircularBufferCheck(this) is re-evaluated (reinit path). For each index from 0 to v4-1: compute circular index = (this[0x9B8] - i) MOD this[0x9B4]; skip stall if vehicle Z-position (a2+4) is less than stall Z-threshold (v7+108). If Z-distance < 1.5, insert collision object.
