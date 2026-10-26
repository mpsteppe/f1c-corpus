## AIBehaviorInitialization_004bf0a0 — AI performance initialization per vehicle

**Summary:** Initializes AI opponent timing/performance offsets per vehicle for a race session. Sets per-vehicle speed bias and start delay based on AI difficulty slider, track reference speed, and engine wear mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIOvertake (004beb10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34C | R | — | base AI performance parameter for random variation scaling |
| this | 0x354 | RW | — | accumulated time offset (session time + performance bias) |
| this | 0x358 | RW | — | session/state identifier parameter from caller |
| this | 0x35C | R | — | maximum AI opponents count threshold |
| this | 0x360 | R | — | parameter for vehicle behavior initialization call |

**Written-by note (persistence):**
- this 0x354: written once at function entry (session time) and accumulated with best offset at end; external poke survives until next call
- this 0x358: written once per call from a2 parameter; overwritten each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004bf380 | jpt_4BF119 | R | jump table for EngineWearMode switch |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005acdb0 | dword_5ACDB0 | R | SessionScoringParameter [DERIVED] |
| 005acde0 | flt_5ACDE0 | R | AIDifficultyScaler [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` — waypoint accumulation weight) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007cea5c | dword_7CEA5C | R | EngineWearMode (0/2/3) [DERIVED] |
| 007d01a0 | dword_7D01A0 | R | AIDifficultySlider [CONFIRMED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008acf9c | flt_8ACF9C | R | TotalRaceLaps [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ae90 | StateFlagsLookup | lookup vehicle state flags for comparison against lap count |
| 004ba140 | ArithmeticComparison_a140 | compare ScoringGate to value 1 (gate check) |
| 004be760 | sub_4BE760 | initialize vehicle behavior/AI parameters |
| 004be9e0 | AnimationStateSetter | set animation state based on engine wear mode and wear factor |
| 004bea10 | RandomVariationScaler | generate random performance variation for each AI driver |
| 004bf390 | AIDriverSorting | sort AI drivers by performance after updating timing data |

**Guard conditions:** EngineWearMode switch (case 1): pass only when SessionType==7 (race) to compute wear factor from lap count ratio; case 2 and default skip wear factor computation. Vehicle loop: skips inactive vehicles (v9+13000==-1 or v9+13000==0), vehicles with lap count >= this+0x35C (max opponents), vehicles with AI state == 1 (retired), and vehicles with AI state == 2 or 3 (certain AI modes). After processing: if lap count >= max opponents OR a3 flag is set, resets vehicle's performance slot (this+4*v8 to -1082130432) and forces AI state to 1 (if not already 3).
