# Chain 198: RunCollisionDetectionLoop — Timed Collision Sweep

Seed: FUN_0045f390  |  System: docs/17-physics-collision.md  |  Depth: 3  |  Functions: 9 callees

---

## Overview

FUN_0045f390 runs a timed collision detection loop with a 4.0-second timeout. Guard: only runs if collision shape type at +0x3FC4 == 3. Sets up timer via FUN_00568ba0 (Struct Zero-Init, 17 fields), then loops calling collision query (FUN_0057a5a0 sweep init, FUN_0057a610 collision query) and collision response chain (FUN_004f9fc0, FUN_0042bda0, FUN_0042cf10, FUN_0045c8b0, FUN_004b0170). Accumulates elapsed time via FUN_00568cf0 and FUN_00568d90. Triggered by FUN_00464290 (NetComm server sync).

## Call Tree

```
FUN_0045f390 — RunCollisionDetectionLoop  [trigger: NetComm server sync via 0x00464290]
  +-- FUN_00568ba0 — Struct Zero-Init (17 Fields) / Timer Setup  [leaf, docs/01]
  +-- FUN_0057a5a0 — Animation Timing Update with Param Set / Collision Sweep Init  [docs/19]
  |     +-- FUN_00583680 — Float Addition  [docs/20]
  |     +-- FUN_00584c70 — Thread-Safe Call with Mutex  [docs/01]
  |     +-- FUN_00587b3e — Boolean-to-Int Conversion  [docs/20]
  |     +-- FUN_00586000 — Linked-List Node Append  [docs/01]
  |     +-- FUN_00585380 — VTable Dispatch with Conditional Call  [docs/01]
  +-- FUN_0057a610 — Animation Value Fetch with Timing / Collision Query  [docs/19]
  |     +-- FUN_00584f90 — Mutex-Guarded Timer Read  [docs/01]
  |     +-- FUN_00586a00 — Single Function Call Wrapper  [docs/01]
  +-- FUN_004f9fc0 — Audio Timer Config Set / Collision Response  [docs/20]
  |     +-- FUN_00500170 — Short Computation (Struct Init with Values)  [docs/20]
  |     +-- FUN_00500190 — Vehicle Data Buffer Clear  [docs/06]
  |     +-- FUN_00500170 — Short Computation (dup)
  +-- FUN_0042bda0 — Timer Conversion with sin  [docs/06]
  |     +-- FUN_005895a2 — Math function (sin?)  [docs/20, leaf]
  +-- FUN_0042cf10 — Unknown  [undocumented]
  +-- FUN_0045c8b0 — Array Initialization Loop  [docs/20]
  |     +-- FUN_0045c850 — Per-Element Array Reset  [docs/20, leaf]
  +-- FUN_004b0170 — Empty Stub (vtable slot) / Cleanup  [leaf, 62 callers]
  +-- FUN_00568cf0 — High-Resolution Timer Delta (with Update)  [docs/20]
        +-- FUN_00568d90 — Performance Counter Diff with Scaling  [docs/01]
              +-- FUN_00568cb0 — QPC Timestamp Read Wrapper  [docs/01, leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0045f390 — RunCollisionDetectionLoop

**Trigger:** Called by FUN_00464290 (NetComm server sync) per network sync cycle.
**Called by:** FUN_00464290 (server sync)
**Purpose:** Runs a timed collision detection loop with sweep/response and 4.0s timeout.

**Key actions:**
1. Guard: if *(param_1+0x3fc4) != 3, skip (not collision shape type)
2. Sets up timer via FUN_00568ba0
3. Main loop (4.0s timeout):
   - FUN_0057a5a0 — collision sweep init
   - FUN_0057a610 — collision query
   - On hit: collision response chain (FUN_004f9fc0, FUN_0042bda0, FUN_0042cf10, FUN_0045c8b0, FUN_004b0170)
   - Accumulates elapsed time via FUN_00568cf0
4. On timeout: calls FUN_004b0170, returns 0

**Data passed to callees:** Collision struct pointer (param_1), timer struct pointer

### Level 1: FUN_0057a5a0 — Animation Timing Update / Collision Sweep Init

**Trigger:** Called each iteration of main loop to set up collision sweep.
**Purpose:** Initializes collision sweep query with animation timing parameters.

**Key actions:**
1. Sets up timing parameters for sweep
2. Calls FUN_00584c70 (thread-safe call), FUN_00586000 (list append), FUN_00585380 (vtable dispatch)

### Level 1: FUN_004f9fc0 — Collision Response / Audio Timer Config Set

**Trigger:** Called when collision hit detected.
**Purpose:** Processes collision response — configures audio timer from collision data.

**Key actions:**
1. Parses collision hit data
2. Calls FUN_00500170 — struct init with values
3. Calls FUN_00500190 — vehicle data buffer clear

### Level 1: FUN_00568cf0 → FUN_00568d90 → FUN_00568cb0 — Timer Chain

**Trigger:** Called each loop iteration to get elapsed time.
**Purpose:** High-resolution timer delta with QPC.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0057a5a0 | Collision struct | Sweep init params | Sweep query |
| FUN_0057a610 | Sweep query | Evaluate overlap | Hit/miss + contact data |
| FUN_004f9fc0 | Contact data | Response processing | Audio timer config |
| FUN_00568cf0 | Timer state | Elapsed time query | Delta seconds |

## Notes

- 9 callees spanning docs/19 (renderer/animation), docs/20 (math_util), docs/01, docs/06
- FUN_004f9fc0 is documented as "Audio Timer Config Set" in docs/20 — audio/collision cross-system handoff
- 4.0s timeout constant is hardcoded
- FUN_004b0170 (empty stub) called both on hit (in response chain) and on timeout (cleanup)

---
