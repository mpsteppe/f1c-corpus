# Chain 185: CameraViewportRenderSetup — HUD/Map Position Processing

Seed: FUN_004fbd70  |  System: docs/09-track-system.md  |  Depth: 2  |  Functions: 10

---

## Overview

Processes player and opponent vehicle positions for HUD sprite rendering and track map display. Gets camera position, positions player entity relative to camera, iterates opponent slots, and performs two render passes: head indicators and map/track indicators. Includes lighting/color calculations based on time-of-day.

## Call Tree

```
FUN_004fbd70 — CameraViewportRenderSetup  [per-frame, HUD/map rendering]
  +-- FUN_004fc550 — [unnamed — linked list iteration]  [renderer context init]
  +-- FUN_0040c910 — Short Computation (Indirect Read)  [camera state query]
  +-- FUN_00542460 — Triple Field Getter (Variant)  [camera position getter — returns position data]
  +-- FUN_0054b3b0 — Three-Field Setter with Sub-Call  [sets render transform, 1 sub-callee]
  |     +-- FUN_0054b330 — [unnamed — render transform helper]
  +-- FUN_0054bf60 — [unnamed — animation offset]  [player indicator positioning]
  +-- FUN_0054c230 — Linked List Indexed Accessor  [iterates 3 opponent slots]
  +-- FUN_0054c030 — Flag Field Bit Manipulation  [render state flag management]
  +-- FUN_0054e100 — PackedArrayTotalSize  [buffer size computation]
  +-- FUN_0054e120 — PackedArrayIndexLookup  [sprite index lookup]
  +-- FUN_0054b3f0 — Offset Dispatch  [render dispatch helper]
```

## Step-by-Step Trace

### Level 0: FUN_004fbd70 — CameraViewportRenderSetup

**Trigger:** Called per-frame during HUD/map rendering pass.

**Called by:** Render tick dispatch (callers.json shows 1 caller).

**Purpose:** Processes player+opponent positions for HUD/map rendering.

**Key actions:**
1. Gets camera position via FUN_00542460
2. Positions player entity relative to camera
3. Iterates 3 opponent slots with position updates
4. Two render loops: head indicators and map/track indicators
5. Lighting/color calculations based on time-of-day

**Data passed to callees:** Camera position data, entity position data, render context

### Level 1: Callees

**FUN_004fc550 — [unnamed]**
- No metadata in functions.json
- Likely initializes renderer context or iterates entity linked list

**FUN_0040c910 — Short Computation (Indirect Read)**
- Leaf function (docs/20-math-utilities.md)
- Reads camera state indirectly
- Returns state data used for positioning

**FUN_00542460 — Triple Field Getter (Variant)**
- Leaf function (docs/20-math-utilities.md)
- Gets camera position (returns 3 fields: X, Y, Z)
- Supplies position reference for entity placement

**FUN_0054b3b0 — Three-Field Setter with Sub-Call**
- 1 callee (FUN_0054b330)
- Sets render transform values (position/rotation/scale)
- Writes transform data for HUD/map sprite rendering

**FUN_0054bf60 — [unnamed — animation offset]**
- Leaf function
- Positions player indicator (head indicator sprite)
- Applies offset relative to camera

**FUN_0054c230 — Linked List Indexed Accessor**
- Leaf function
- Accesses opponent slots by index (0, 1, 2)
- Iterates 3 opponent vehicles for position updates

**FUN_0054c030 — Flag Field Bit Manipulation**
- Leaf function
- Manages render state flags (visibility, enabled)
- Gates sprite rendering per entity

**FUN_0054e100 — PackedArrayTotalSize**
- Leaf function
- Computes total size of packed data arrays
- Used for sprite/index buffer sizing

**FUN_0054e120 — PackedArrayIndexLookup**
- Leaf function
- Looks up sprite indices in packed arrays
- Maps vehicle indices to sprite draw indices

**FUN_0054b3f0 — Offset Dispatch**
- Leaf function
- Dispatches render offset calculations
- Applies final position offsets for map rendering

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00542460 | camera context | Get XYZ position | Camera position |
| FUN_004fc550 | render context | Init render pass | Ready for sprites |
| FUN_0054bf60 | player pos + camera | Position head indicator | Player sprite transform |
| FUN_0054c230 | opponent index 0-2 | Iterate slot | Opponent position |
| FUN_0054e120 | vehicle index | Lookup sprite index | Draw index |

## Notes

- 9 of 10 callees are leaf functions — this is a shallow dispatch tree
- Two distinct render passes: head indicators (driver name sprites) and map/track position indicators
- The lighting/color time-of-day calculations use global time constants
- Opponent data comes from VehiclePtrArray (DAT_007c54f0) indexed through opponent slots

---
