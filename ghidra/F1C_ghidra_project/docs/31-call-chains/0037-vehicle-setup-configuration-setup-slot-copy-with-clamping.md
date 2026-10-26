# Chain: Vehicle Setup Configuration — Setup Slot Copy with Clamping

Seed: FUN_004b0ef0  |  System: docs/10-vehicle-physics.md  |  Depth: 3  |  Functions: 4

---

## Overview

Called from vehicle setup initialization paths (callers: FUN_00461900, FUN_004a06e0, FUN_004b0540). Selects one of 6 vehicle setup slots (param_2: 1-6). Copies 12 parameter groups from setup arrays (stride 0x24 = 36 bytes per setup) to runtime struct. All copied values are clamped between stored min/max bounds. Sets mode flags: param_2==1→mode 1, param_2==2→mode 7. Finalizes with FUN_004b1190 (session config loader).

## Call Tree

```
FUN_004b0ef0 — Vehicle Setup Configuration  [setup init: 3 callers]
  +-- FUN_0047f1f0 — Float Clamp [min, max]  [docs/20: clamps *param_1 to [param_2, param_3]]
  +-- FUN_00464720 — Byte Clamp  [docs/20: clamps byte value to [min, max]]
  +-- FUN_004646c0 — Float Clamp  [docs/20: clamps float value]
  +-- FUN_004b1190 — Session Config Loader  [docs/06: finalizes setup]
        +-- FUN_004c5840 — SeasonRaces Section Finder  [docs/08: INI section lookup]
        +-- FUN_005679c0 — String-Keyed Linked List Search  [docs/20: INI key lookup]
        |     +-- FUN_00499e20 — String Pointer Accessor
        |     +-- FUN_00588410 — String Compare
        +-- FUN_00567970 — Data Entry Accessor  [docs/08: INI value getter]
        +-- FUN_00587ece — String-to-Int Conversion  [docs/08]
        +-- FUN_004b1375 — Clamped Float-to-Int Conversion  [docs/20: race time handler]
```

## Step-by-Step Trace

### Level 0: FUN_004b0ef0 — Vehicle Setup Configuration

**Trigger:** Called during vehicle setup initialization (setup slot selection)
**Called by:** FUN_00461900 (docs/??), FUN_004a06e0 (docs/06), FUN_004b0540 (docs/??)
**Purpose:** Selects one of 6 vehicle setups and copies associated parameters.

**Key actions:**
1. param_2 selects setup slot (1-6)
2. Copies 12 parameter groups from setup arrays (stride 0x24 = 36 bytes per setup)
3. Values copied from stored setup to runtime struct
4. Each value clamped via FUN_0047f1f0 (float), FUN_004646c0 (float), FUN_00464720 (byte)
5. Sets mode: param_2==1 → mode 1, param_2==2 → mode 7
6. Calls FUN_004b1190(0xbf800000) to finalize

### Level 1: Clamp Functions

**FUN_0047f1f0 — Float Clamp [range]** [docs/20-math-utilities.md]
- Clamps *param_1 to [param_2, param_3] range in-place
- Used for general float parameter clamping

**FUN_004646c0 — Float Clamp** [docs/20-math-utilities.md]
- Dedicated float clamp utility (simpler signature than FUN_0047f1f0)

**FUN_00464720 — Byte Clamp** [docs/20-math-utilities.md]
- Clamps byte value to [min, max] range

### Level 1: Session Config Loader (FUN_004b1190)

**FUN_004b1190 — Session Config Loader** [docs/06-session-race-logic.md]
- Loads session configuration from INI data
- 5 sub-callees:
  - FUN_004c5840: Season/Races section finder in INI data
  - FUN_005679c0: String-keyed linked list search for INI key lookup
    - FUN_00499e20: String pointer accessor
    - FUN_00588410: String compare
  - FUN_00567970: Data entry accessor (INI value getter)
  - FUN_00587ece: String-to-int conversion
  - FUN_004b1375: Clamped float-to-int conversion (race time value handler)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| param_2 (slot 1-6) | int | Select setup array row | 36-byte setup block |
| Setup values | float/byte | clamp to [min, max] | Validated parameters |
| FUN_004b1190 | 0xbf800000 sentinel | Load session config | Finalized vehicle setup |

## Globals Written in This Chain

None directly — reads from setup arrays in vehicle struct, writes to runtime struct

## Notes

- 3 callers: setup load, session init, and vehicle config paths
- All 4 callees are leaf or near-leaf utility functions
- Clamping is done via 3 separate clamp functions (2 float, 1 byte)
- FUN_004b1190 adds INI file parsing depth to the chain (5 sub-callees)
- Cross-system: docs/10-vehicle → docs/06-session (FUN_004b1190), docs/08-file (FUN_004c5840, FUN_00567970)
