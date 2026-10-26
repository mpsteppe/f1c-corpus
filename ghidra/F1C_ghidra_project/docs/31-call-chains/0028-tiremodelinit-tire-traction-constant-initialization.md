# Chain: TireModelInit — Tire Traction Constant Initialization

Seed: FUN_0043e050  |  System: docs/04-tire-system.md  |  Depth: 3  |  Functions: 14

---

## Overview

Called once per vehicle physics init (caller: FUN_004e45b0). Initializes tire traction model globals based on TireModelMode (DAT_007ce958). Computes tire model step = `400 >> TireModelMode`, derives TireTractionConstant (DAT_005e5240) and its square (DAT_005e5238). Calls a chain of 10 sub-initializers for session struct, tire data, vehicle file parsing, suspension, brake bias, and wheel contact transforms. Cleans up with free wrappers.

## Call Tree

```
FUN_0043e050 — TireModelInit  [once per vehicle: called from FUN_004e45b0]
  +-- FUN_005881c0 — Stack Probe / alloca  [memory setup]
  +-- FUN_00567740 — FPU Control Word Query  [returns 0x200 for normal path]
  +-- FUN_00567780 — Empty Stub  [alt init — called if FPU mode != 0x200]
  +-- FUN_0042e320 — SessionStructInit  [docs/06: session state init]
  |     +-- FUN_0042e1c0 — 28-byte State Block Init
  |     +-- FUN_0042dc60 — Small Data Struct Init
  |     +-- FUN_0042e400 — PenaltyStructInit
  +-- FUN_004f34e0 — Tire Model Data Init  [docs/10: tire struct setup]
  |     +-- FUN_004f3040 — Zero Init (20 dwords)
  |     +-- FUN_004f31f0 — 6x6 Array Zero-Init
  |     +-- FUN_004f2b10 — Zero-Init 16-Element Array
  +-- FUN_004f4270 — .svm/.hdv Vehicle File Parser (x2)  [docs/08: file parser]
  +-- FUN_00438da0 — Suspension Body Array Allocator  [docs/10: allocates +0x162c]
  +-- FUN_00439210 — [undocumented]  [unknown init step]
  +-- FUN_0043c250 — Vehicle Session Init / LifetimeVar Spawn Formula  [docs/03]
  +-- FUN_00438cc0 — BrakeBiasSetup  [docs/18: brake bias init]
  |     +-- FUN_004b15d0 — Bitmask State Test
  +-- FUN_00438f00 — Wheel Contact Point World-Space Transform  [docs/18]
  |     +-- FUN_00435410 — Suspension Tuning Data Accessor  [docs/10]
  |     +-- FUN_00588570 — Float80-to-Double Converter  [docs/20]
  |     +-- FUN_005691d0 — 3x3 Rotation Tensor Matrix Transform  [docs/18]
  +-- FUN_0042ddd0 — ScoreSlotDeallocator  [docs/06: cleanup hook]
  |     +-- FUN_00587bcf — Free Wrapper  [heap free via FUN_0058aa6f]
  +-- FUN_00587bcf — Free Wrapper (x6)  [docs/01: frees non-null params]
        +-- FUN_0058aa6f — Heap Deallocation  [docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_0043e050 — TireModelInit

**Trigger:** Called once per vehicle during physics initialization
**Called by:** FUN_004e45b0 (wheel controller init, docs/18)
**Purpose:** Initializes tire traction model globals and sets up tire subsystem parameters based on TireModelMode.

**Key actions:**
1. Sets context data pointer at param_1+0x1f00
2. Zero-inits wheel states at +0x60 and +0x64
3. Computes `400 >> (TireModelMode & 0x1f)`, stores as double at +0x68 and DAT_005e5240
4. DAT_005e5240 = double(400 >> TireModelMode) * DAT_0059ec70 (tire multiplier)
5. DAT_005e5238 = DAT_005e5240^2 (for force calcs)
6. Calls 10 sub-initializers in sequence
7. If FUN_00567740() returns != 0x200: calls alternative path FUN_00567780
8. Frees 6 non-null parameters via FUN_00587bcf
9. Calls FUN_0042ddd0 cleanup hook

**Globals read:** DAT_007ce958 (TireModelMode), DAT_0059ec70 (TireMultiplierFactor)
**Globals written:** DAT_005e5240, DAT_005e5238

### Level 1: Sub-Initializers

**FUN_0042e320 — SessionStructInit** [docs/06-session-race-logic.md]
- Inits session state block (3 sub-inits)

**FUN_004f34e0 — Tire Model Data Init** [docs/10-vehicle-physics.md]
- Zero-inits tire data arrays (20 dwords, 6x6 matrix, 16-element array)

**FUN_004f4270 — .svm/.hdv Vehicle File Parser (called twice)** [docs/08-file-formats.md]
- Parses vehicle setup file for tire parameters

**FUN_00438da0 — Suspension Body Array Allocator** [docs/10-vehicle-physics.md]
- Allocates suspension body array at +0x162c, stride 0x30, count from +0x15ac

**FUN_0043c250 — LifetimeVar Spawn Formula** [docs/03-engine-wear-damage.md]
- Initializes per-vehicle engine lifetime variables

**FUN_00438cc0 — BrakeBiasSetup** [docs/18-physics-dynamics.md]
- Sets up brake bias parameters for all 4 wheels

**FUN_00438f00 — Wheel Contact Transform** [docs/18-physics-dynamics.md]
- Transforms wheel contact point to world space, reads suspension tuning data

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| TireModelMode (DAT_007ce958) | 0/2/3 | 400 >> mode | tire_model_step |
| tire_model_step | double | * DAT_0059ec70 | DAT_005e5240 |
| DAT_005e5240 | double | square | DAT_005e5238 |
| FUN_004f4270 | .svm file | parse | tire setup params |
| FUN_00438da0 | vehicle ptr | allocate | suspension body array |
| FUN_00438cc0 | vehicle ptr | initialize | brake bias settings |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005e5240 | TireTractionConstant | FUN_0043e050 | Computed from TireModelMode * multiplier |
| DAT_005e5238 | TireTractionConstantSq | FUN_0043e050 | Square of above |

## Notes

- 10 sequential init sub-calls must execute in order per the impl spec (docs/30-impl-specs/08)
- FUN_004f4270 called twice — once for each wheel group (front/rear or left/right)
- FUN_00567780 alternative path triggered only if FPU control word mode != 0x200

---
