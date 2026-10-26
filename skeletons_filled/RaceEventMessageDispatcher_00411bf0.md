## RaceEventMessageDispatcher_00411bf0 — EventIdToNamedLookupDispatcher

**Summary:** Dispatches based on event ID (from state block offset +12) to one of several lookup/processing functions. Routes to SessionStringNameLookup (with optional random flag), sub_412490, sub_412E50, TextAttributeLookup, TextAttributeLookup_3710, or MapCollisionShapeToBoneIndex depending on event ID value. Returns handler result or 0 for unrecognized IDs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FontRenderingPrep (00411840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00411d44 | jpt_411C29 | R | jump table for switch on event ID (a2+12) |
| 00411d6c | byte_411D6C | R | case value table for switch dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004122c0 | SessionStringNameLookup | looks up session string by name (most frequent handler, with/without random variant flag) |
| 00412490 | sub_412490 | generic handler for event types 8, 0xF, 0x21 |
| 00412c30 | MapCollisionShapeToBoneIndex | maps collision shape to bone index (event type 0x31) |
| 00412e50 | sub_412E50 | handler for event types 0xB, 0xC, 0x33 |
| 004133b0 | TextAttributeLookup | text attribute lookup for event types 0x12, 0x19-0x1B, 0x1D-0x1E, 0x2E |
| 00413710 | TextAttributeLookup_3710 | alternate text attribute lookup for event types 0x27-0x28 |
| 005884ed | RandLCGRandomNumberGenerator | LCG random generator — provides flag for SessionStringNameLookup variant selection |

**Guard conditions:** switch on event ID — unrecognized/default event IDs return 0 without calling any handler.
