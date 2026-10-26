# Chain: Large Config Function with Physics Constants — Parameter Initialization

Seed: 0x004e45b0  |  System: docs/20-math-utilities.md  |  Depth: 3  |  Functions: 10

---

## Overview

Large configuration initialization function that sets up physics parameters with clamping and conditional cleanup. Triggered during vehicle setup initialization. Computes scaled physics constants from input parameters, writes them to vehicle struct fields, and performs cleanup of up to 7 allocation pointers.

## Call Tree

```
0x004e45b0 — Large Config w/ Physics Constants  [trigger: vehicle setup init]
  +-- 0x005881c0 — Alloc  [leaf]
  +-- 0x004e4790 — Wheel State Reset  [docs/18, 2 sub-calls]
  |     +-- 0x0043e230 — Wheel Controller Init  [docs/18]
  |     +-- 0x00587bcf — Free Wrapper  [heap free]
  +-- 0x0043e050 — TireModelInit  [docs/18, tires, 13 sub-calls]
  |     +-- 0x005881c0 — Alloc  [leaf]
  |     +-- 0x00567740 — Query Mode  [leaf]
  |     +-- 0x00567780 — Alt Init  [leaf]
  |     +-- 0x0042e320 — SessionStructInit  [docs/06, 3 sub-calls]
  |     |     +-- 0x0042e1c0 — Sub-Array Clear  [leaf]
  |     |     +-- 0x0042dc60 — Session Setup  [leaf]
  |     |     +-- 0x0042e400 — Finalize  [leaf]
  |     +-- 0x004f34e0 — Tire Model Data Init  [docs/18, 3 sub-calls, all leaf]
  |     +-- 0x004f4270 — [leaf, called x2]
  |     +-- 0x00438da0 — [leaf]
  |     +-- 0x00439210 — [leaf]
  |     +-- 0x0043c250 — [leaf]
  |     +-- 0x00438cc0 — [docs/18]
  |     +-- 0x00438f00 — [docs/18]
  |     +-- 0x0042ddd0 — [docs/18]
  |     +-- 0x00587bcf — Free Wrapper  [heap free]
  +-- 0x0042e320 — SessionStructInit  [docs/06, 3 sub-calls, see above]
  +-- 0x004f34e0 — Tire Model Data Init  [docs/18, 3 sub-calls, all leaf]
  +-- 0x004f4270 — [leaf, called x2]
  +-- 0x004e5f60 — SuspensionAndWheelPhysics  [docs/18, 21 sub-calls, see complex below]
  +-- 0x004e8010 — Tire Brush Model Force Solver  [docs/18, 2 sub-calls]
  |     +-- 0x005895a2 — Sqrt Lookup  [leaf]
  |     +-- 0x004e8200 — [leaf]
  +-- 0x0042ddd0 — [docs/18]
  +-- 0x00587bcf — Free Wrapper  [called up to 7 times]
```

## Step-by-Step Trace

### Level 0: 0x004e45b0 — Large Config Function with Physics Constants

**Trigger:** Vehicle physics setup initialization.
**Called by:** No callers documented.
**Purpose:** Initializes physics configuration: wheel state, tire model, suspension, and cleans up allocations.

**Key actions:**
1. Calls init sequence (FUN_005881c0, FUN_004e4790)
2. Checks extraout_ECX+0x32bc valid range (0-3, skips if <1 or >3)
3. Sets param_1+0x3498 clamped to [1, 64]
4. Sets float params at +0x349c, +0x34a0, +0x34a4, +0x34a8, +0x34ac:
   - +0x349c = param_squared
   - +0x34a0 = _DAT_0059e43c / (count * 0x28)
   - +0x34a4 = _DAT_0059e43c / ((count*5 + 5) * 8)
5. Frees 7 pointers conditionally

**Data passed to callees:** Vehicle struct pointer (param_1), count parameter.

### Level 1: Key Sub-functions

**0x0043e050 — TireModelInit**
13 sub-calls. Most complex callee. Initializes tire physics model constants: allocates tire data, queries mode, sets up session struct, initializes tire model data, performs wheel controller init, applies tire force settings and cleanup.

**0x004e5f60 — SuspensionAndWheelPhysics**
21 sub-calls. Major suspension/wheel physics init. Chain documented separately as it has its own subtree.

**0x004e8010 — Tire Brush Model Force Solver**
2 sub-calls. Initializes tire brush model solver with sqrt lookup.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004e45b0 | vehicle ptr, count | clamp [1,64] | count set |
| FUN_004e4790 | wheel ptr | init wheel state | wheel reset |
| FUN_0043e050 | tire ptr | init model constants | tire model configured |
| FUN_004e5f60 | suspension ptr | init suspension | suspension params set |
| FUN_00587bcf | alloc ptrs | conditional free | 7 ptrs freed |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_0059e43c | physics constant | read | divisor for computed params |
| DAT_008afea0 | float constant | read | comparison threshold |

## Notes

This function configures physics parameters rather than running simulation. The count clamping [1,64] suggests this controls a per-vehicle resolution or iteration count. Up to 7 heap allocations are conditionally freed, suggesting a cleanup/reinit pattern. The 0x004e5f60 subtree (21 callees) is documented as a separate subsystem in docs/18.

---
