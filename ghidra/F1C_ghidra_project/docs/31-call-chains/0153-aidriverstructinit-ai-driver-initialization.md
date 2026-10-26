# Chain: AIDriverStructInit — AI Driver Initialization

Seed: FUN_00424790  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: 7

---

## Overview

No tracked callers in call_graph. Initializes AI driver struct with defaults, name matching, and difficulty scaling. Most complex sub-branch is the AI Command/Message Queue Dispatcher (`FUN_00424cd0`, 5 callees), which initializes the AI command queue. Secondary branches handle audio pitch scaling and guarded call checks.

## Call Tree

```
FUN_00424790 — AIDriverStructInit  [trigger: no tracked callers — AI system init]
  +-- FUN_00424cd0 — AICommandQueueDispatch  [5 callees]
  |     +-- FUN_004a46f0 — Queue Processor
  |     +-- FUN_0042adb0 — Queue State Init
  |     +-- FUN_004c6d90 — Per-Vehicle Reset
  |     +-- FUN_004a5c80 — StateChangeNotify
  |     +-- FUN_00429ee0 — Queue Flush
  +-- FUN_004f1510 — ScaleAudioPitch  [3 callees]
  |     +-- FUN_005881f0 — RNG
  |     +-- FUN_0059d9b5 — Buffer Jitter Apply
  |     +-- FUN_004e8010 — Finalize
  +-- FUN_004a5c10 — GuardedCallWithCheck  [2 callees]
  |     +-- FUN_004a5820 — Check/Query
  |     +-- FUN_004a4830 — Action
  +-- FUN_0042ae00 — AIClearStateFlags  [leaf]
  +-- FUN_00424ac0 — AIDifficultyInterpolation  [leaf — reads DAT_007d01a0]
  +-- FUN_00424080 *  — Process AI Ability  [undocumented]
  +-- FUN_00429960 *  — [undocumented]
```

*Marked functions exist as callees but have no entry in functions.json (undocumented).

## Step-by-Step Trace

### Level 0: FUN_00424790 — AIDriverStructInit

**Trigger:** No tracked callers in call_graph — called during AI system initialization
**Called by:** Unknown
**Purpose:** Initializes AI driver struct with defaults, name matching, difficulty scaling.

**Key actions:**
1. Zeroes/resets fields, sets FLOAT_MAX, loops init arrays
2. If param_2 != 0: full init with vehicle name matching, grid position, difficulty
3. Finds matching vehicle by name comparison
4. Initializes 7 callout slots from FUN_004a5c10
5. Calls FUN_00424ac0 for difficulty scaling

**Data passed to callees:** AI driver struct pointer, initialization flags.

### Level 1: FUN_00424cd0 — AICommandQueueDispatch

**Trigger:** Called during struct init for queue setup
**Purpose:** Dispatches commands to AI driver command queue and maintains queue state.

**Key actions:**
1. Calls FUN_004a46f0 to process queue
2. Calls FUN_0042adb0 to init queue state
3. Calls FUN_004c6d90 for per-vehicle reset
4. Calls FUN_004a5c80 for state change notification
5. Calls FUN_00429ee0 to flush queue

### Level 1: FUN_004f1510 — ScaleAudioPitch

**Trigger:** Called during struct init for audio setup
**Purpose:** Scales AI vehicle audio pitch based on driver parameters.

**Key actions:**
1. Generates random value via FUN_005881f0
2. Applies buffer jitter via FUN_0059d9b5
3. Finalizes via FUN_004e8010

### Level 1: FUN_004a5c10 — GuardedCallWithCheck

**Trigger:** Called during struct init for callout slots
**Purpose:** Guarded call with precondition check.

**Key actions:**
1. Checks precondition via FUN_004a5820
2. Executes action via FUN_004a4830

### Level 1: FUN_0042ae00 — AIClearStateFlags

**Trigger:** Called during struct init
**Purpose:** Clears AI state flags to defaults.

### Level 1: FUN_00424ac0 — AIDifficultyInterpolation

**Trigger:** Called during struct init
**Purpose:** Piecewise linear interpolation of AI performance based on AIDifficultySlider.

**Key actions:**
1. If AIDifficultySlider < 0x65: lerps low→mid
2. If >= 0x65: lerps mid→high

**Globals:** DAT_007d01a0 (AIDifficultySlider), _DAT_005ea3dc, _DAT_005ea3e0, _DAT_005ea3e4

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00424790 | Vehicle name, grid pos, difficulty | Zero + match + scale | Initialized AI struct |
| FUN_00424cd0 | Queue state | Init + dispatch | Ready command queue |
| FUN_00424ac0 | AIDifficultySlider (0-120) | Piecewise lerp | Scaled ability values |
| FUN_004f1510 | Driver params | RNG + jitter + finalize | Scaled audio pitch |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d01a0 | AIDifficultySlider | FUN_00424ac0 (reader) | AI difficulty 0-120 |

## Notes

- Two callees (FUN_00424080, FUN_00429960) are undocumented — no functions.json entry exists
- Most complex callee: FUN_00424cd0 (5 callees) initializes the AI command/message queue
- FUN_00424ac0 (AI Difficulty Interpolation) is documented as `configurable` moddability
- FUN_004f1510 (ScaleAudioPitch) with 3 callees provides audio variation per AI driver
- 2 additional leaf callees (if needed) could be documented from the 7 total

---
