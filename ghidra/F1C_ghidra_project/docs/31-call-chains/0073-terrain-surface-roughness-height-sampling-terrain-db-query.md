# Chain: Terrain Surface Roughness/Height Sampling — Terrain DB Query

Seed: FUN_0045ca20  |  System: docs/17-physics-collision.md  |  Depth: 1  |  Functions: 4 callees

---

## Overview

FUN_0045ca20 samples surface properties from the terrain database. Called by 4 functions: FUN_0045f950 (Session Synchronizer, docs/09 — as ping check), FUN_0045e620 (contact check), FUN_004624e0 (terrain surface height sample), and FUN_00462530. Checks surface type at DAT_005ef9a0[param_2 * 0x1230] — if not type 2 (valid surface), returns early with *param_3=0.0. Calls FUN_0045c780 to get surface index pair, checks cache at param_1+0x1124[iVar3], copies 8 dwords (0x20 bytes) from surface DB at param_1+iVar3×0x20+0x424, calls FUN_005890aa (sorting/filtering), computes weighted average, and for surface type 0x10, caches result and clamps against DAT_007d108c. Modifies param_1+0x12c4+param_2×2 (corrective offset cache).

## Call Tree

```
FUN_0045ca20 — Terrain Surface Roughness/Height Sampling  [trigger: surface query]
  +-- FUN_0045c780 — Bounded Byte Array Accessor  [surface index pair lookup]
  +-- FUN_005890aa — Sort/Filter Utility  [data sorting]
  +-- FUN_0045c7c0 — Short-to-Float Conversion  [surface value read]
  +-- FUN_0045c7a0 — Float-to-Short (__ftol)  [surface value write]
```

## Step-by-Step Trace

### Level 0: FUN_0045ca20 — Terrain Surface Roughness/Height Sampling

**Trigger:** Terrain surface property query from collision or sync system
**Called by:** FUN_0045f950 (ping), FUN_0045e620 (contact check), FUN_004624e0 (height sample), FUN_00462530
**Purpose:** Sample surface roughness/height from terrain database with caching

**Key actions:**
1. Checks surface type at DAT_005ef9a0[param_2 * 0x1230] — if not type 2, return 0
2. Calls FUN_0045c780(param_2) for surface index pair
3. If iVar2 == 0: returns false with *param_3=9.999 (sentinel)
4. Checks cache at param_1+0x1124[iVar3]: if > 0, returns cached value
5. Copies 8 dwords from surface DB at param_1+iVar3×0x20+0x424
6. Calls FUN_005890aa for sorting/filtering
7. Computes weighted average of values in range
8. If param_2 == 0x10: caches result, clamps against DAT_007d108c, writes to +0x12c4+param_2×2

### Level 1: Key Callees

**FUN_0045c780 — Bounded Byte Array Accessor**
- Looks up surface index pair from terrain database
- Returns indices for surface data access

**FUN_005890aa — Sort/Filter Utility**
- Sorts and filters the 8-dword surface data block
- Prepares data for weighted averaging

**FUN_0045c7c0 — Short-to-Float Conversion**
- Reads surface value from terrain DB as short, converts to float
- Converts stored short to float for computation

**FUN_0045c7a0 — Float-to-Short (__ftol)**
- Writes computed surface value back as short
- Uses __ftol for float-to-int conversion

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Type check | param_2 | Read DAT_005ef9a0 at stride 0x1230 | Surface type |
| Index | param_2 | FUN_0045c780 | Surface index pair |
| Cache check | param_1+0x1124 | If > 0 | Return cached value |
| Data read | param_1+0x424 | Copy 8 dwords | Surface data block |
| Sort | 8 dwords | FUN_005890aa | Sorted data |
| Average | Sorted range | Weighted average | Roughness/height |
| Cache | param_2==0x10 | Store at +0x1124 | Cached result |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005ef9a0 | SurfaceTypeDB | (read by) | Surface type array stride 0x1230 |
| DAT_007d108c | SurfaceClampThreshold | (read by) | Clamp threshold for surface type 0x10 |

## Notes

- Cached results stored at param_1+0x1124[] — avoids re-computation for same surface type
- Surface type 0x10 gets special handling: clamping and corrective offset cache at +0x12c4
- DAT_005ef9a0 stride 0x1230 is same pattern as VehicleGridArray — likely the same global
- 4 callers indicates this function is a shared utility across collision and networking systems

---


---
