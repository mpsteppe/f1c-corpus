## DisplayMessage0x113_0041a6b0 — FixedMessageDisplay_275

**Summary:** Displays fixed race message ID 275 by triggering audio reset, clearing the driver data buffer to defaults, then inserting a single driver table entry with the message ID.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr [DERIVED] (also: ` — engine interface pointer) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID 275, timing info, and driver indices |
| 00418560 | InsertDriverTableEntry | Insert the populated entry into the shared driver data table |
| 004186a0 | BufferInitWith10fDefaults | Reset shared buffer to 10.0f default values |

**Guard conditions:**
`dword_7D0308` (RaceActiveFlag) must be non-zero AND `flt_7CF3C8` (TrackConditionState) must not be 0.0 → PASSES: both conditions true → display message. BLOCKED: either condition false → skip entirely.
