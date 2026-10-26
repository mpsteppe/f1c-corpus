# Chain: UIControlWindowInit — UI Control Window/Struct Initialization

Seed: FUN_004a70e0  |  System: docs/19-renderer.md  |  Depth: 2  |  Functions: 13

---

## Overview

Large initialization function setting up a window/control struct with ~10 control types. Zeros header fields (0-4), then sets up repeated triplets of (value=0, sentinel=-1, function pointer) across dozens of control slots. Uses FUN_004a8b10 as slot advancement step between each triplet. Creates 11 control types via specialized constructors (FUN_004b1950 through FUN_004b1a90). All 13 callees are leaf constructors/initializers — this is a pure initialization chain.

## Call Tree

```
FUN_004a70e0 — UIControlWindowInit  [trigger: UI screen/widget creation]
  +-- FUN_004a8b10 — SlotAdvanceStep  [inits 3-dword struct: 0, -1, vtable]  [leaf]
  +-- FUN_004b1950 — CreateControlTypeA  [small struct constructor]  [leaf]
  +-- FUN_004b1970 — CreateControlTypeB  [small struct init with vtable]  [leaf]
  +-- FUN_004b1990 — CreateControlTypeC  [vtable + fields init]  [leaf]
  +-- FUN_004b19b0 — CreateControlTypeD  [vtable + pattern 0,-1,0,-1]  [leaf]
  +-- FUN_004b19d0 — CreateControlTypeE  [field init with defaults]  [leaf]
  +-- FUN_004b1a10 — CreateControlTypeF  [forward/call wrapper]  [leaf]
  +-- FUN_004b1a30 — CreateControlTypeG  [vtable init with defaults, shorter]  [leaf]
  +-- FUN_004b1a50 — CreateControlTypeH  [5-dword struct: 0/-1 + vtable]  [leaf]
  +-- FUN_004b1a70 — CreateControlTypeI  [short constructor]  [leaf]
  +-- FUN_004b1a90 — CreateControlTypeJ  [struct init: vtable + sentinels]  [leaf]
  +-- FUN_004c16b0 — LargeStructZeroInit  [memset-like large array zero]  [leaf]
  +-- FUN_004aa270 — PlayerOptionsInit  [player options init / FailureRate slots]  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004a70e0 — UIControlWindowInit

**Trigger:** UI screen/widget creation — called when a new control window/container is initialized
**Called by:** FUN_004a6fe0 (from callers.json)
**Purpose:** Initializes a window/control struct with function pointer table and multiple control slots.

**Key actions:**
1. Zeros first 4 dwords (header fields at +0x0 through +0x10)
2. Loops through control type tables (PTR_LAB_005acbf0 etc.), creating control instances
3. For each control slot: sets (value=0, sentinel=-1, function pointer), then calls FUN_004a8b10 to advance
4. Uses 7-element loops for each control constructor type
5. Calls FUN_00401000 (memset-like) to initialize large homogeneous arrays
6. Finishes with FUN_004c16b0 (large zero-init) and FUN_004aa270 (player options init)

**Data passed to callees:** struct pointer (param_1), size/type parameters, vtable pointers from PTR_LAB tables

### Level 1: Callees (all leaf, depth 1)

All 13 callees are leaf constructors/initializers. Key groups:
- **FUN_004a8b10:** Slot advancement — writes 0, -1, vtable pointer at current position, advances cursor
- **FUN_004b1950-004b1a10 (Types A-F):** Short struct constructors — write specific patterns of values/sentinels/vtable pointers for different UI control types (buttons, sliders, lists, etc.)
- **FUN_004c16b0:** Large memory zero-init — clears large blocks of the window struct
- **FUN_004aa270:** Initializes player options slot — handles failure rate configuration

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Init header | param_1 | zero 4 dwords | header cleared |
| Control A-J | PTR_LAB tables | create + advance | initialized control slots |
| Large arrays | param_1 + offset | memset | zeroed |
| Finalize | param_1 | player options init | window ready |

## Globals Written in This Chain

None — operates entirely on param_1 struct.

## Notes

- All 13 callees are leaf functions (no further calls). The chain is wide (13 direct) but only 2 levels deep.
- Each control type constructor writes a specific pattern: some are pure vtables, some include sentinel values, some are just forward calls.
- The slot advancement (FUN_004a8b10) creates a linked pattern: each slot has a data field, a sentinel (-1 = unused/invalid), and a vtable pointer for virtual dispatch.
- FUN_004c16b0 and FUN_004aa270 are post-initialization steps — not slot-related.

---
