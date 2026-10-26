## FailureCategoryNameLookup_004bb730 — Failure category name lookup

**Summary:** Maps integer failure category ID (1-9) to a component name string: Engine, Gearbox, Clutch, Suspension, Brakes, Accident, Electronics, Fuel. Returns default block for unknown IDs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_42BDD0 (0042bdd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004bb778 | jpt_4BB738 | R | Jump table for switch dispatch |
| 005c3164 | aGearbox | R | Str_Gearbox [DERIVED] |
| 005c316c | aEngine | R | ComponentNameEngine [DERIVED] |
| 005c3174 | aBrakes | R | StringBrakes [DERIVED] |
| 005c317c | aSuspension | R | StrSuspension [DERIVED] |
| 005c55cc | aClutch | R | sClutch [DERIVED] |
| 005d2524 | unk_5D2524 | R | SystemMemoryBlock [DERIVED] |
| 005d2528 | aFuel_0 | R | FuelString [DERIVED] |
| 005d2530 | aElectronics | R | ElectronicsString [DERIVED] |
| 005d253c | aAccident | R | Str_Accident [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — default case handles all out-of-range values.
