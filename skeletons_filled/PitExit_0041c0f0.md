## PitExit_0041c0f0 — PitExitMessageDispatcher

**Summary:** Dispatches position-dependent pit exit audio messages (IDs 397, 516-535) based on car relationship classification (player/rival/constructor rival), relative race position, and championship mode, using vehicle array iteration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarSelectionStateMachine (00434460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041c3bc | jpt_41C243 | R | Jump table referenced within function body |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e838 | dbl_59E838 | R | PositionThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005f0738 | dword_5F0738 | R | VEH[0].0x4060 = position [CONFIRMED] |
| 005f0f74 | dword_5F0F74 | R | VEH[0].0x489C = DriverID [FACT] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initialize driver table entry struct with sentinel/default values |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID, timing info, and driver indices |
| 00418560 | InsertDriverTableEntry | Insert populated entry into shared driver data table |
| 005884ed | RandLCGRandomNumberGenerator | Generate random number for 50% probability flip of constructor rival message IDs |

**Guard conditions:**
1. `dword_7D0308` (RaceActiveFlag) must be non-zero → PASSES: race active. BLOCKED: race inactive.
2. `flt_7CF3C8` (TrackConditionState) must not be 0.0 → PASSES: track condition initialized. BLOCKED: track condition zero.
3. Vehicle count (`dword_5C329C`) must be > 0 → PASSES: vehicles exist. BLOCKED: no vehicles → return.
4. Loop searches vehicle array at `dword_5F0738` stepping by 4656 bytes for first dword matching `a2 + 1` (position). If not found after all vehicles → BLOCKED: return.
5. `dword_7D0410` (ChampionshipMode) == 2 → forces message 397, skips classification logic.
6. State `this[v4]` classification:
   - 1 (player car): position-based messages 516-519.
   - 2 (rival car): gap-to-player comparison → messages 521-525.
   - 3 (constructor rival, mode 4 only): gap comparison + 50% random flip → messages 526-535.
   - Other: default message 397.
