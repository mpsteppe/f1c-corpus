# Chain: Race Monitor Overlay Renderer — In-Race Standings HUD Display

Seed: FUN_0049f870  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 14

---

## Overview

Per-frame HUD rendering of the race standings overlay: driver positions, names, and lap times. Called with no callers recorded (likely dispatcher-based or frame callback). Iterates vehicle grid (DAT_005ef9a0, stride 0x1230), filters monitored vehicles, performs frustum visibility check, sorts visible drivers by position, and renders text via font surface "FTFU30WH". Reads SessionType for points display mode and HUD disable flag DAT_007ce254.

## Call Tree

```
FUN_0049f870 — Race Monitor Overlay Renderer  [trigger: per-frame HUD render]
  +-- FUN_00408490 — Float Multiply with Global Constant  [random seed for offset]
  +-- FUN_0045be00 — Collision Penalty Scaler  [monitor timing: 4]
  |     +-- FUN_0045bb00 — Array Search (threshold)  [collision severity query]
  +-- FUN_0040cd60 — Session Phase Decode  [get current session phase]
  +-- FUN_0040c910 — Short Computation / Lap Counter  [lap count read]
  +-- FUN_004dc960 — 3D Ray-Sphere Intersection  [frustum cull: docs/17]
  |     [leaf: no further callees in call_graph.json]
  +-- FUN_0049feb0 — Merge Sort (Linked List)  [sort visible driver list]
  |     [leaf: merge sort algorithm]
  +-- FUN_0053d1f0 — Wide-String Linked List Search  [font lookup "FTFU30WH"]
  |     [leaf: string search]
  +-- FUN_0049b370 — 2D Text Rendering with Scissor Rectangle  [text render: docs/19]
        +-- FUN_005531f0 — (unknown)
        +-- FUN_00553a20 — Float-to-Int Conversion Chain
        +-- FUN_004dcdd0 — Position Computation with Alignment (9 cases)
        +-- FUN_004dcd80 — Two-Field Setter + Update
        |     +-- FUN_004dca80 — Quad 3D Position Render  [docs/20]
        +-- FUN_004dcf20 — Field Setter + Call
        |     +-- FUN_004dca80 — Quad 3D Position Render
        +-- FUN_004dcd60 — Conditional Call
        |     +-- FUN_00553700 — (unknown)
        +-- FUN_00552fc0 — Field Setter at +0x48
        +-- FUN_00553070 — (unknown)
```

## Step-by-Step Trace

### Level 0: FUN_0049f870 — Race Monitor Overlay Renderer

**Trigger:** Per-frame during race sessions (no caller recorded in call_graph.json).
**Called by:** [undocumented — likely game loop render dispatch]
**Purpose:** Renders standings overlay with driver names, positions, and lap times.

**Key actions:**
1. Checks DAT_007ce254 (DisableHUDFlag) — skip if set
2. Gets random offset via FUN_00408490 for visual variety
3. Gets monitor timing via FUN_0045be00(4)
4. Computes frustum culling parameters
5. Iterates vehicle grid DAT_005ef9a0 (stride 0x1230), filters monitored vehicles
6. Reads driver TeamID (+0x4894), finish position (+0x4060), name (+0x46f8), season points (+0x403c)
7. Calls FUN_004dc960 for frustum visibility check
8. Collects visible vehicles into linked list, sorts via FUN_0049feb0
9. Renders up to 3 visible entries (or more if alternate display mode)
10. Restores render surface offsets, frees linked list

**Globals read:** DAT_007ce254, DAT_005ef9a0, DAT_007c56a4, DAT_005d6d64, DAT_005d6d60, DAT_0059e440, DAT_0059f0c0, DAT_0059e970, DAT_0059f124, DAT_005acb18

**Data passed to callees:** vehicle pointers, screen coordinates, font handle.

### Level 1: FUN_0049b370 — 2D Text Rendering with Scissor Rectangle

**Trigger:** Per visible driver entry.
**Called by:** FUN_0049f870.
**Purpose:** Renders text string at computed screen position with clipping.

**Key actions:**
1. Computes text position with alignment (9 cases via FUN_004dcdd0)
2. Sets up render quad (FUN_004dca80)
3. Renders via conditional font/surface sub-calls

### Level 1: FUN_004dc960 — 3D Ray-Sphere Intersection

**Trigger:** Per vehicle for visibility check.
**Called by:** FUN_0049f870.
**Purpose:** Tests if vehicle is within camera frustum.

**Key actions:**
1. Computes ray/sphere intersection
2. Returns collision point and normal
3. Leaf function — no further calls

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0049f870 | VehicleGrid + stride | iterate + filter | visible driver list |
| FUN_004dc960 | vehicle world pos | frustum cull | visible flag |
| FUN_0049feb0 | visible list | merge sort | sorted by position |
| FUN_0049b370 | driver name + pos | text render | HUD overlay |

## Globals Written in This Chain

None — this is a read-only rendering pass. No globals are written.

## Notes

- No callers recorded in call_graph.json despite being a per-frame function — likely called via function pointer dispatch not captured in static analysis.
- Uses "FTFU30WH" font surface (30px white font).
- Max 3 visible names displayed unless alternate mode flag set.
- Fun_0045be00(4) uses parameter 4 to select monitor timing mode — different from collision penalty scaler (mode 0–3).
- FUN_00408490 called with random seed for position offset jitter.

---
