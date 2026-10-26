# Chain 170: FUN_004a0250 — Post Race Monitor

Seed: FUN_004a0250  |  System: docs/06-session-race-logic.md  |  Depth: 2  |  Functions: 14

---

## Overview

Post-race results/standings display page ("POST RACE MONITOR"). Triggered when race session ends and results page needs to be shown. Checks session type (race vs non-race), game mode, and player vehicle state to determine which sub-screens to display (standings, timing, status). Manages cursor visibility, input handling, and navigation (escape → return to menu). Called from race end flow in FUN_00404f30.

## Call Tree

```
FUN_004a0250 — Post Race Monitor  [called by FUN_00404f30]
  +-- FUN_004d21d0 — [undocumented]  [condition check]
  +-- FUN_004a0da0 — [undocumented]
  +-- FUN_0042d210 — [undocumented, param (1)]
  +-- FUN_004c8d60 — [undocumented]
  +-- FUN_004bc060 — [undocumented]
  +-- FUN_0046ba20 — [undocumented]
  +-- FUN_0046c030 — [undocumented]
  +-- FUN_00497940 — page display
  +-- FUN_004d5840 — [undocumented]  [cleanup]
  +-- FUN_004a0d30 — [undocumented]  [cleanup]
  +-- FUN_0042bc10 — [undocumented]  [cleanup]
  +-- FUN_004efac0 — [undocumented]  [escape: menu nav]
  +-- FUN_004c6d90 — [undocumented]  [escape: cleanup]
  +-- FUN_004f7010 — [undocumented]  [per-driver flag check at +0xc4]
```

## Step-by-Step Trace

### Level 0: FUN_004a0250 — Post Race Monitor

**Trigger:** Race session ends, results page requested
**Called by:** FUN_00404f30
**Purpose:** Shows post-race standings, handles cursor/input/navigation

**Key actions:**
1. Shows cursor via ShowCursor(1) loop
2. If SessionType == 7 (race) and mode != 6:
   a. Calls FUN_004d21d0 (condition check)
   b. If false and not mode 5 and DAT_007cec90 == 0: calls FUN_004a0da0, FUN_0042d210(1), FUN_004c8d60
   c. If true: checks player vehicle state at +13000, handles input, optionally calls FUN_0046ba20/FUN_0046c030
   d. Calls FUN_00497940 (page display)
3. Cleanup: FUN_004d5840, FUN_004a0d30, FUN_0042bc10
4. If escape pressed: FUN_004efac0 (menu nav), FUN_004c6d90 (cleanup)
5. Iterates drivers: if driver+0xc4 flag set, calls FUN_004f7010
6. Finalizes with camera/viewport setup

**Globals read:** DAT_007c56a4 (SessionType), DAT_007d0410 (RaceMode), DAT_007c54e8 (PlayerVehiclePtr), DAT_007cec90

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| SessionType | DAT_007c56a4 | check == 7 | branch selection |
| RaceMode | DAT_007d0410 | check != 6 | branch selection |
| PlayerVehiclePtr | DAT_007c54e8 | state check at +13000 | input enable/disable |

## Notes

- 12 of 14 callees are undocumented (no functions.json summary or doc entry)
- Only FUN_00497940 (page display) has a name — all others are anonymous
- Chain is shallow: all callees are leaves (no further recursion depth)
- FUN_004f7010 iterates per-driver with flag check at offset +0xc4

---
