## SoundEventDispatcher_00411e90 — SoundEventIdDispatch

**Summary:** Dispatches sound-related processing based on event ID (from state block offset +12). Large switch routing to handlers: SessionStringNameLookup, sub_412490, sub_412E50, TextAttributeLookup(_3600/_3710), EnumValueTranslation, SeasonSpecificTeamIDLookup, sub_413820, CollisionShapeSizeClassify, and MapCollisionShapeToBoneIndex. Uses two random generator calls for variant flag selection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FontRenderingPrep (00411840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00412218 | jpt_411ED0 | R | jump table for switch on event ID (a2+12) with ~25 cases |
| 00412280 | byte_412280 | R | case value table for switch dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004122c0 | SessionStringNameLookup | session string lookup (cases 4, 8, 9, 0xC, 0xD, 0x1C, 0x25, 0x2F, 0x33) |
| 00412490 | sub_412490 | generic handler (cases 5, 6, 0xA, 0x10, 0x17, 0x1B, 0x1D, 0x22, 0x23, 0x26, 0x35, 0x36) |
| 00412c30 | MapCollisionShapeToBoneIndex | maps collision shape to bone index (case 0x32) |
| 00412e50 | sub_412E50 | handler (cases 0xE, 0x13, 0x29) |
| 004133b0 | TextAttributeLookup | text attribute lookup (case 0x1E) |
| 00413600 | TextAttributeLookup_3600 | text attr lookup variant (cases 1, 0x18, 0x19) |
| 00413710 | TextAttributeLookup_3710 | text attr lookup variant (cases 2, 0x16, 0x1A) |
| 00413820 | sub_413820 | handler (cases 0x1F, 0x2A) |
| 004139c0 | CollisionShapeSizeClassify | classifies collision shape size (cases 0x20, 0x2B) |
| 00413b60 | SeasonSpecificTeamIDLookup | season-specific team ID lookup (cases 0x14, 0x30) |
| 00414010 | EnumValueTranslation | enum value translation (cases 0x11, 0x34) |
| 005884ed | RandLCGRandomNumberGenerator | LCG random generator — provides flag for SessionStringNameLookup variant selection |

**Guard conditions:** switch on event ID — unrecognized/default case returns 0. Case 0x2C falls through to default (returns -1/0 via v4).
