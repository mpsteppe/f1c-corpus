# Chain 169: FUN_0055a910 — Scene Node / Instance Parser

Seed: FUN_0055a910  |  System: docs/09-track-system.md  |  Depth: 3  |  Functions: 18

---

## Overview

Parses an INSTANCE node from a `.scn` scene file during track/scene loading. Called by scene dispatch (FUN_0055b200) when the scene parser encounters an INSTANCE token. The parser allocates an instance node struct, iterates child tokens (MESHFILE, ANIMFILE, SHADOWCASTER, ACTOR, RESPONSE, etc.), setting flags and loading sub-resources. Produces a fully-initialized scene graph node with mesh references, animation sequences, LOD thresholds, shadow/reflection configuration, and collision targets. Writes instance flags at +0x3c and node flags at +0x14 of the allocated struct.

## Call Tree

```
FUN_0055a910 — Scene Node / Instance Parser  [called by scene dispatch FUN_0055b200]
  +-- FUN_00545f50 — Audio Volume/Load Computation  [leaf]
  +-- FUN_0054a600 — Large Object Initializer (instance alloc, 0x23c bytes)
  |     +-- FUN_0053c2a0  [undocumented]
  |     +-- FUN_0053b130 — subsystem prep
  +-- FUN_00559a70 — Line Reader from Buffer (token next)
  |     +-- FUN_00559ad0 — line validation
  +-- FUN_00559f00 — PRNG / 4 Uniform Ints from Seed (float parse)
  |     +-- FUN_00559d80  [undocumented]
  |     +-- FUN_00589278  [undocumented]
  +-- FUN_00559e20 — token match  [leaf]
  +-- FUN_0054a730 — Self-Copy String with Validation (mesh load)
  |     +-- FUN_00589901 — String normalization
  |     +-- FUN_0054a870 — Validation
  +-- FUN_0054d4e0 — Conditional Float Field Setter (LOD set)  [leaf]
  +-- FUN_00545930 — Linked List Node Insert (shadow init)
  |     +-- FUN_00560ba0  [undocumented]
  +-- FUN_0054c110 — Render Flag Setter (Bitmask / special flag)  [leaf]
  +-- FUN_00559820 — [undocumented] (actor register)  [leaf]
  +-- FUN_005598b0 — [undocumented] (response register)  [leaf]
  +-- FUN_0054a770 — Scene Graph / Object Tree Cleanup
  |     +-- FUN_0054c410  [undocumented]
  |     +-- FUN_0054ac30  [undocumented]
  |     +-- FUN_00587bcf — memory free
  |     +-- FUN_00561940 — audio cleanup
  |     +-- FUN_0054fa50 — renderer cleanup
  |     +-- FUN_004b0170 — object release / game state update
  +-- FUN_0054a710 — Two Function Call Chain (cleanup variant)
  |     +-- FUN_0053b160 — FUN_004b0170 trampoline
  |     +-- FUN_004b0170 — object release / game state update
  +-- FUN_0054bb40 — UI List Node Manager (anim sequence init)
  |     +-- FUN_005510f0 — node allocator
  |     +-- FUN_00551440 — list init
  |     +-- FUN_00557350 — post-setup
  |     +-- FUN_00559200 — display buffer init
  |     +-- FUN_004b0170 — render register
  +-- FUN_00551560 — [undocumented] (anim sub)  [leaf]
  +-- FUN_00551790 — Linked List String Key Removal (anim sub)
  |     +-- FUN_00551480 — Audio Flag Set / Animation Start
  |           +-- FUN_00556330 — Timer accumulate
  +-- FUN_00551480 — Audio Flag Set / Animation Start
  |     +-- FUN_00556330 — Timer accumulate
  +-- FUN_0054b4d0 — [PARTIAL] Unknown (orientation apply)  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0055a910 — Scene Node / Instance Parser

**Trigger:** Scene file parser encounters INSTANCE token during track/scene load
**Called by:** FUN_0055b200 (instance dispatch)
**Purpose:** Parses INSTANCE node from `.scn` file — allocates struct, iterates child tokens, sets flags

**Key actions:**
1. Checks VISGROUPS mask against global DAT_008b8ee0 — skip if not visible
2. Calls FUN_0054a600 to allocate 0x23c-byte instance node struct
3. Iterates tokens via FUN_00559a70 (token next) + FUN_00559e20 (token match)
4. For each recognized token: loads sub-resources (mesh, anim, shadow, actor, response, etc.)
5. Sets instance flags at +0x3c and node flags at +0x14 bitmask
6. Recursively calls self for nested INSTANCE children

**Data passed to callees:** Pointer to allocation data (param_1), token strings, float values from file

### Level 1: FUN_0054a600 — Large Object Initializer

**Trigger:** Called to allocate instance node memory
**Purpose:** Allocates 0x23c-byte struct, initializes fields

**Key actions:**
1. Calls FUN_0053c2a0 (subsystem init)
2. Calls FUN_0053b130 (subsystem prep)
3. Returns initialized struct pointer

### Level 1: FUN_0054a770 — Scene Graph / Object Tree Cleanup

**Trigger:** Error or end of instance parsing
**Purpose:** Releases resources associated with a scene node

**Key actions:**
1. Calls FUN_0054c410, FUN_0054ac30 (unknown cleanup)
2. Calls FUN_00587bcf (memory free)
3. Calls FUN_00561940 (audio resource cleanup)
4. Calls FUN_0054fa50 (renderer resource cleanup)
5. Calls FUN_004b0170 (game state update / object release)

### Level 1: FUN_0054bb40 — UI List Node Manager

**Trigger:** ANIMFILE token encountered
**Purpose:** Manages animation sequence linked list

**Key actions:**
1. Calls FUN_005510f0 (node allocator)
2. Calls FUN_00551440 (list initialization)
3. Calls FUN_00557350 (post-setup)
4. Calls FUN_00559200 (display buffer init)
5. Calls FUN_004b0170 (render register)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0054a600 | size 0x23c | alloc + init | instance node ptr |
| FUN_00559a70 | file buffer | read next token | token string |
| FUN_00559e20 | token string | match against known keywords | match index |
| FUN_0054a730 | token data | load mesh file | mesh node list append |
| Various | flag values | bitwise OR at +0x14 / +0x3c | updated flag fields |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008b8ee0 | VISGROUPS mask | READ by FUN_0055a910 | Visibility group filter |

## Notes

- 2 callees (FUN_00559820, FUN_005598b0) not in functions.json — likely orphan/anonymous functions from decompiled_full/
- FUN_004b0170 appears in 3 separate subtrees — shared game state update utility
- FUN_00551480 (Audio Flag Set) appears twice in the tree but is only called once per parse — MSVC artifact or shared utility
- 10 of 18 callees are leaf functions (no further calls)

---
