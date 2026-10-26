## sub_4DAE00_004dae00 — RaceEndProgressionGate

**Summary:** Gate function controlling race-end flow progression. Returns 1 when timers have expired and player position relative to finished vehicles allows proceeding. Part of race management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4DA840 (004da840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Short expiration timer: when <= 0.0, immediately allow progression |
| this | 0x1C | R | — | Medium hold timer: when > 0.0, block progression |
| this | 0x20 | R | — | Count of finished/advanced vehicles (compared to total VehicleCount) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005f073c | dword_5F073C | R | VEH[0].0x4064 = FinishState [FACT] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d1b50 | sub_4D1B50 | Resolves current vehicle index from ForceFeedbackBase |

**Guard conditions:**
- Line 7: `*(this+0x14) <= 0.0` (short timer expired). PASS: return 1 (immediate proceed). BLOCK: continue to next check.
- Line 9: `*(this+0x1C) > 0.0` (hold timer still running). PASS: return 0 (block). BLOCK: continue to finish state check.
- Line 11-12: Current vehicle FinishState == 1 AND `*(this+0x20) >= player_position_index`. PASS: set v2 to player DSQ/retired flag status. BLOCK: v2 stays 0.
- Line 17: `*(this+0x20) != VehicleCount`. PASS: return v2 (may block if player not DSQ/retired). BLOCK (count == total): return 1 (all accounted for, proceed).
