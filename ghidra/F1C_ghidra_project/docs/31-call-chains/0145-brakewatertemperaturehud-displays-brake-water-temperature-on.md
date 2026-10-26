# Chain: BrakeWaterTemperatureHUD — Displays brake/water temperature on in-car HUD

Seed: FUN_0049db80  |  System: docs/03-engine-wear-damage.md  |  Depth: 2  |  Functions: 3

---

## Overview

Reads brake temperatures (4 corners: FL, FR, RL, RR) and water temperature from global arrays, formats them on the in-car HUD. Called per-frame during active session (param_1+8 != 0). Reads water temp from DAT_007c91b4 minus offset DAT_005acafc. Reads 4 brake corner temps from DAT_007c7ab8/7c7f1c/7c8380/7c87e4 minus DAT_0059eac8 (celsius offset). Uses FUN_0049f6a0 for HUD string rendering and FUN_0049db00 for temperature display format.

## Call Tree

```
FUN_0049db80 — BrakeWaterTemperatureHUD  [trigger: per-frame HUD render during active session]
  +-- FUN_00423a00 — BinarySearchStringTable  [string table lookup for "WATER:"/"BRAKES:"]  [leaf]
  +-- FUN_0049f6a0 — StringFormatAndRender  [HUD text render, 3 callees]
  |     +-- [subtree: 3 callees — docs/20]
  +-- FUN_0049db00 — TempDisplayFormat  [temperature format conversion]  [undocumented]
```

## Step-by-Step Trace

### Level 0: FUN_0049db80 — BrakeWaterTemperatureHUD

**Trigger:** Per-frame during active race session — HUD rendering phase
**Called by:** FUN_0049d5d0 (from callers.json — HUD main dispatcher)
**Purpose:** Display brake (per-corner) and water temperature on in-car HUD.

**Key actions:**
1. If param_1+8 != 0 (session active):
2. **WATER:** Copies "WATER:" label via FUN_00423a00, reads water temp from (DAT_007c91b4 - DAT_005acafc), displays via FUN_0049f6a0
3. **BRAKES:** Copies "BRAKES:" label, reads 4 corner temps:
   - FL: DAT_007c7ab8 - DAT_0059eac8
   - FR: DAT_007c7f1c - DAT_0059eac8
   - RL: DAT_007c8380 - DAT_0059eac8
   - RR: DAT_007c87e4 - DAT_0059eac8
4. Uses DAT_005ccbb8 (base Y), DAT_005ccbc0 (base X), DAT_005ccbbc (line height increment) for HUD positioning

**Data passed to callees:** temperature values (float), label strings, HUD position coordinates

### Level 1: Callees

**FUN_00423a00 — BinarySearchStringTable [leaf]**
Looks up "WATER:" and "BRAKES:" string constants from the game string table.

**FUN_0049f6a0 — StringFormatAndRender (3 callees)**
Formats temperature value as text and renders it on the HUD at the specified position.

**FUN_0049db00 — TempDisplayFormat [undocumented]**
Temperature-specific display formatter — likely converts raw float (Celsius) to integer display string.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Session check | param_1+8 | != 0 | active/inactive |
| Water label | "WATER:" | string copy | label text |
| Water temp | DAT_007c91b4 - DAT_005acafc | subtract offset | Celsius value |
| Brake label | "BRAKES:" | string copy | label text |
| Brake FL | DAT_007c7ab8 - DAT_0059eac8 | subtract offset | FL temp |
| Brake FR | DAT_007c7f1c - DAT_0059eac8 | subtract offset | FR temp |
| Brake RL | DAT_007c8380 - DAT_0059eac8 | subtract offset | RL temp |
| Brake RR | DAT_007c87e4 - DAT_0059eac8 | subtract offset | RR temp |
| Render | temp + pos | format + draw | HUD text |

## Globals Read

| Global | Name | Purpose |
|--------|------|---------|
| DAT_007c7ab8 | BrakeTempFL | Front left brake temperature |
| DAT_007c7f1c | BrakeTempFR | Front right brake temperature |
| DAT_007c8380 | BrakeTempRL | Rear left brake temperature |
| DAT_007c87e4 | BrakeTempRR | Rear right brake temperature |
| DAT_007c91b4 | WaterTemp | Engine water temperature |
| DAT_005acafc | TemperatureOffset | Celsius conversion offset |
| DAT_0059eac8 | BrakeTempCelsiusOffset | Brake temp Celsius offset |
| DAT_005ccbb8 | HUDPosBaseY | HUD Y position base |
| DAT_005ccbc0 | HUDPosBaseX | HUD X position base |
| DAT_005ccbbc | HUDLineHeight | Line height increment |

## Notes

- All 4 brake corner temps use the same Celsius offset (DAT_0059eac8) — suggests temperature is stored in raw sensor units, converted to Celsius for display
- Water temperature uses a different offset (DAT_005acafc) — different sensor scale
- Confirms brake temperature tracking per-corner in vehicle struct (global arrays indexed by corner)
- FUN_0049db00 is NOT FOUND in functions.json — likely an undocumented temperature format function
- This is a pure read-only HUD function — no state is modified
