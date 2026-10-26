# Chain: StateTriggerCheck — Session state condition gate and init cascade

Seed: FUN_004b8ae0  |  System: docs/06-session-race-logic.md  |  Depth: 2  |  Functions: 16

---

## Overview

State gate function called from loading pipeline. Checks a condition threshold (value at +0xf34 - +0xf30), then if positive, calls 13 system setup/init functions sequentially. Returns 1 if DAT_007cc4c8 == 0 AND condition check passes AND comparison value is below threshold. Otherwise returns 0. Acts as a gate for session state initialization cascade.

## Call Tree

```
FUN_004b8ae0 — StateTriggerCheck  [trigger: loading state machine]
  +-- FUN_004b8c40 — LoadingSubInit1  [loading subsystem init]
  +-- FUN_004ba180 — LoadingSubInit2  [loading/asset init]
  +-- FUN_004cfcc0 — ParticleSystemState  [particle system check — docs/19]
  +-- FUN_00404460 — PositionUpdateGate  [physics update gating — docs/10]
  +-- FUN_004d4580 — RenderStateSet  [render state — docs/19]
  +-- FUN_00455e50 — InputStateSet  [input reset — docs/01]
  +-- FUN_0042c690 — MainGameTickUpdate  [main tick — docs/01]
  +-- FUN_0040ca30 — CameraUpdate  [camera update — docs/01]
  +-- FUN_004c8b70 — SoundStateRefresh  [audio refresh — docs/01]
  +-- FUN_004b40a0 — RenderStateRefresh  [render refresh — docs/01]
  +-- FUN_0049f070 — OnScreenPost  [display post — docs/01]
  +-- FUN_004fa7e0 — VidManUpdate  [video manager — docs/01]
  +-- FUN_004a1830 — VariousSystemSetup  [system setup/init — docs/01]
  +-- FUN_0044f460 — ConditionCheck  [condition check — leaf]
  +-- FUN_004b8790 — CompareValue  [comparison — leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004b8ae0 — StateTriggerCheck

**Trigger:** Called from loading phase (FUN_004b87c0 — LoadingPhase1 and FUN_004b8940 — LoadingPhase2)
**Called by:** FUN_004b87c0, FUN_004b8940, FUN_004b86e0
**Purpose:** Checks conditions and triggers sequence of setup calls if conditions met.

**Key actions:**
1. Returns 0 if (fValue +0xf34 - +0xf30) < 0
2. Otherwise calls 13 setup/init functions in sequence
3. Returns 1 if DAT_007cc4c8 == 0 AND FUN_0044f460(1) returns 0 AND FUN_004b8790() result < *(param_1+0xf34)
4. Returns 0 otherwise

**Data passed to callees:** Various system pointers for init/setup

### Level 1: All 13 init functions

All callees are setup/init functions for various subsystems. None have further callees documented in call_graph (all leaf or single-call wrappers).

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004b8ae0 | param_1+0xf30, +0xf34 | Compare delta < 0 | returns 0 |
| FUN_004b8ae0 | DAT_007cc4c8, FUN_0044f460, FUN_004b8790 | If all pass and value < threshold | returns 1 |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007cc4c8 | CheckFlag | FUN_004b8ae0 | Collision check enable flag (read) |

## Notes

- All 13 callee functions are single-call setup wrappers — no further recursion
- Chain depth limited to 2 (seed + leaves)
- Functions FUN_00404460, FUN_0042c690, FUN_0040ca30 are documented in docs/01-engine-architecture.md
- FUN_004cfcc0 is particle system state, cross-system to docs/19-renderer.md

---
