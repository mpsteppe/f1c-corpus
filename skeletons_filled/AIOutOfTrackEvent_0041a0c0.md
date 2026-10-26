## AIOutOfTrackEvent_0041a0c0 — AIOutOfTrackEventHandler

**Summary:** Handles AI out-of-track incidents for non-player vehicles. Checks race active and track condition, then inserts driver behavior entry with index 264 (off-track event) for the offending AI driver. Called from game state dispatch chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameStateDispatchChain (0040d240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005f0f74 | dword_5F0F74 | R | VEH[0].0x489C = DriverID [FACT] |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local struct with sentinel values before lookup |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Looks up behavior entry (index 264 = off-track) |
| 00418560 | InsertDriverTableEntry | Inserts off-track behavior entry into driver action table |
| 00418a20 | BooleanOROfTwoChecks | Sets/queries boolean flag check for index 264 on driver table |

**Guard conditions:** dword_7D0308 (RaceActiveFlag) must be non-zero. flt_7CF3C8 (TrackConditionState) != 0.0. Vehicle (a1) must not be the player's vehicle (a1 != current vehicle's team ID). If player vehicle, entry insertion is BLOCKED.
