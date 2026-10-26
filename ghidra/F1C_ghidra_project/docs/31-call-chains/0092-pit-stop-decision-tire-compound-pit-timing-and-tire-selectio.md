# Chain: Pit Stop Decision & Tire Compound — Pit Timing and Tire Selection

Seed: FUN_0042a3d0  |  System: docs/02-ai-system.md  |  Depth: 1-2  |  Functions: 8 callees

---

## Overview

Called during AI pit strategy computation. Reads planned pit stops bitmask (+0x1178), computes remaining laps to next stop, DRS override randomizes pit target to current lap, checks pit-blocking conditions via FUN_0042aee0, selects tire compound based on aggression (hard/medium/soft), scans 7 compound slots, adjusts gear ratios.

## Call Tree

```
FUN_0042a3d0 — Pit Stop Decision & Tire Compound  [trigger: AI pit strategy per-lap]
  +-- FUN_0042aee0 — Pit stop blocking condition check               [leaf — no further callees]
  +-- FUN_004c6d90 — Per-vehicle reset/state access                  [leaf — no further callees]
  +-- FUN_004bc060 — AI strategy/path data access                    [depth 1: HAS 0 callees]
  +-- FUN_004a5bd0 — AI behavior lookup                              [leaf — no further callees]
  +-- FUN_004f1890 — Unknown AI helper                               [leaf — no further callees]
  +-- FUN_0042a6f0 — Post-pit cleanup/exit                           [depth 1: HAS 0 callees]
  +-- FUN_004a5750 — AI state helper                                 [depth 1: HAS 0 callees]
  +-- FUN_004a57a0 — AI state query lookup                           [leaf — no further callees]
```

## Step-by-Step Trace

### Level 0: FUN_0042a3d0 — Pit Stop Decision & Tire Compound

**Trigger:** Per-lap AI pit strategy evaluation. Called from AI tick.
**Called by:** Unknown (callers.json shows 2 callers — from AI strategy chain)
**Purpose:** Decide when to pit and which tire compound to use.

**Key actions:**
1. Read planned stops bitmask at +0x1178 (PitStopFlag)
2. Compute remaining laps until next scheduled stop
3. DRS override: randomize pit target to current lap (force early pit)
4. Check pit-blocking via FUN_0042aee0:
   - Non-race: return bit 3 of +0x1167
   - Race: return 0 only if lap < total AND RacePhase != 8 AND DRS clear
5. Tire compound selection by aggression:
   - < 0.01 → hard (4)
   - 0.01–0.1 → medium (5)
   - >= 0.1 → soft (6)
6. Scan 7 tire slots for matching compound
7. Adjust gear ratios for selected compound

**Data passed to callees:** vehicle struct pointer, pit strategy data.

### Level 1: Selected Callees

- **FUN_0042aee0 (pit blocking):** Returns 0 (allowed) or 1 (blocked) based on lap, RacePhase, DRS flag.
- **FUN_004c6d90 (per-vehicle reset):** Accesses vehicle state array for pit-related data.
- **FUN_004bc060 (strategy data):** Reads AI strategy/path data.
- **FUN_0042a6f0 (post-pit cleanup):** Runs after pit completes: calls FUN_004bd760 for pit exit animation, increments stint counter +0x45e0, clears pit crew timer +0x4534, sets pit-exit timestamp +0x447c.
- **FUN_004a5750 (AI state helper):** Updates AI state flags related to pit.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0042a3d0 | vehicle ptr | pit strategy | pit decision, tire compound |
| FUN_0042aee0 | vehicle ptr | lap/phase/DRS check | blocked flag |
| FUN_0042a6f0 | vehicle ptr | post-pit cleanup | state reset |

## Globals Written in This Chain

None — operates on vehicle struct fields (+0x1178, +0x1167, +0x45e0, +0x4534, +0x447c).

## Notes

Chain depth 1-2. Tire compound selection is moddable (configurable via aggression thresholds). Pit blocking reads RacePhase (DAT_007c56a8) indirectly through FUN_0042aee0.

---
