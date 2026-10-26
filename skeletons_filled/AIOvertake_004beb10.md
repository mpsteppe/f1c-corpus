## AIOvertake_004beb10 — AIOvertakeLogic

**Summary:** Manages AI overtaking/behavioral state: checks accumulated overtake time against threshold, sets session type and total laps to struct fields, detects human-controlled vehicles in qualifying mode, and dispatches AIBehaviorInitialization if activation flag (0x342) is clear. Accumulates time step at offset 0x354.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_46BF10 (0046bf10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x342 | R | — | activation flag: if 0, triggers AIBehaviorInitialization |
| this | 0x350 | R | — | time increment value (added to accumulator 0x354 each call) |
| this | 0x354 | RW | — | accumulated overtake/behavior time counter |
| this | 0x358 | R | — | accumulated time threshold for overtake decision |
| this | 0x35C | RW | — | total race laps counter (overwritten each call) |
| this | 0x360 | RW | — | session type (overwritten each call from dword_7C56A4) |

**Written-by note (persistence):**
- this 0x354: accumulated each call; external poke survives between calls but is overwritten on next accumulate
- this 0x35C: overwritten each call; external poke does not survive
- this 0x360: overwritten each call; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bf0a0 | AIBehaviorInitialization | initializes AI behavior when activation flag is clear |

**Guard conditions:** BLOCKED when accumulated time (0x354) >= threshold (0x358) — overtake timer expired, behavior runs without human-check. PASSES when time < threshold — if session type is 7 (qualifying), scans for human-controlled vehicles (state==1) to enable AI awareness.
