# Chain: Pit State Slot Activation / Commentary — Pit Entry Slot Management

Seed: FUN_0041ab30  |  System: docs/07-pit-system.md  |  Depth: 3  |  Functions: 3

---

## Overview

Activates a pit entry slot and dispatches per-driver commentary. Called from Vehicle Dynamics Force/Accumulator Integration (FUN_00438130, docs/18). Sets slot param_1+0xa44+param_2*4 = 2. Counts active slots: if <3, per-slot commentary IDs; if >=3, commentary ID 0x68 (generic multi-car pit). Uses the standard commentary pipeline (FUN_004144d0/FUN_004144f0/FUN_00418560).

## Call Tree

```
FUN_0041ab30 — Pit State Slot Activation / Commentary  [trigger: vehicle enters pit]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [commentary init: docs/20]
  +-- FUN_004144f0 — Driver Data Table Lookup  [time conversion: docs/02]
  +-- FUN_00418560 — InsertDriverTableEntry  [commentary output: docs/02]
        +-- FUN_00418b90 — Score/Threshold Gate Check  [docs/06]
        +-- FUN_00418b70 — Short Computation  [docs/20]
        +-- FUN_004145c0 — Struct Copy (32 bytes)  [docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_0041ab30 — Pit State Slot Activation / Commentary

**Trigger:** Called from Vehicle Dynamics Integration (FUN_00438130, docs/18) when a vehicle enters pit lane.
**Called by:** FUN_00438130 (docs/18).
**Purpose:** Activates pit slot and dispatches commentary.

**Key actions:**
1. Sets slot at param_1+0xa44+param_2*4 = 2 (active state)
2. Counts already-active slots
3. If <3 active slots: uses per-slot commentary format IDs
4. If >=3 active slots: uses commentary ID 0x68 (generic "multiple cars in pit")
5. Output via commentary pipeline

**Data passed to callees:** session data pointer, slot index (param_2).

### Level 1: FUN_004144d0 — Struct Init with Sentinel Values

**Trigger:** Called for commentary struct initialization.
**Called by:** FUN_0041ab30.
**Purpose:** Initializes a small struct with sentinel (-1) values.

**Key actions:**
1. Writes -1 sentinel values to struct fields
2. Sets up struct for use by commentary pipeline

### Level 1: FUN_00418560 — InsertDriverTableEntry

**Trigger:** Called for commentary output.
**Called by:** FUN_0041ab30.
**Purpose:** Registers commentary text in driver display table.

**Key actions:**
1. Validates score/threshold (FUN_00418b90)
2. Table lookup with sentinel (FUN_00418b70)
3. Copies 32-byte struct (FUN_004145c0)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0041ab30 | slot index | activate slot | param_1+0xa44+idx*4 = 2 |
| FUN_0041ab30 | active slot count | commentary selection | format ID per slot or 0x68 |
| FUN_00418560 | format ID | table insert | audio/display output |

## Globals Written in This Chain

None. Writes pit slot state (struct field, not global).

## Notes

- Smallest chain (depth 3, 3 callees) — highly focused function.
- Called from physics integration (FUN_00438130, docs/18) — pit entry detection happens during vehicle dynamics update.
- Slot activation value 2 may represent "active/pending" pit state.
- Commentary ID 0x68 = generic multi-car pit message used when 3+ vehicles are in pit simultaneously.
- FUN_004144d0/FUN_004144f0/FUN_00418560 triple is the engine's standard commentary pipeline pattern, seen in 4+ chains in this document.

---

# Worker N Complete

Chains 157–168 (12 chains) traced. All output written.
