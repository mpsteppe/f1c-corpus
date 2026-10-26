# Chain 37: Vehicle Physics Joint System Loader — Parses text-format physics scene file, builds constraint network

Seed: FUN_0056d930  |  System: docs/10-vehicle-physics.md  |  Depth: 3  |  Functions: 25 callees

---

## Overview

Triggered during vehicle physics scene loading. The seed reads a text-format file containing BODY, JOINT, HINGE, BAR, and JOINT_HINGE section declarations. Two-pass parser: first counts elements, allocates parallel arrays, then second pass populates body/joint/hinge/bar structs with position, orientation, inertia, and spring/damper parameters. Post-processing computes derived spring/tension values per joint, resolves body reference counts, and assembles the constraint matrix for the iterative solver. Final output is a fully linked constraint network ready for physics integration.

## Call Tree

```
FUN_0056d930 — Vehicle Physics Joint System Loader  [trigger: scene file load for vehicle physics]
  +-- FUN_00534b00 — File Open Wrapper  [opens text file for reading]
  |     +-- FUN_00534b10 — file open impl  [returns: file handle]
  +-- FUN_005351d0 — Tokenizer Next  [advances to next token in file]
  +-- FUN_005651b0 — Line Read  [reads a line from file]
  +-- FUN_00587c20 — Token Match  [compares token string]
  +-- FUN_00565520 — Field Parse  [parses a named field value]
  +-- FUN_00565aa0 — Vector Parse  [parses 3-double vector from text]
  +-- FUN_00588410 — String Compare  [string comparison utility]
  +-- FUN_00568e30 — Body Init Short Computation  [initializes body struct fields]
  |     +-- FUN_00568f20 — struct initialization helper
  +-- FUN_00568e70 — Body Init  [populates body struct from parsed values]
  +-- FUN_005691d0 — 3x3 Rotation Tensor Matrix Transform  [builds rotation matrix]
  |     +-- FUN_0056bd40 — Euler Angles to Rotation Matrix  [docs/18]
  |     +-- FUN_005692a0 — inertia/constraint update  [docs/18]
  +-- FUN_00569280 — Copy 6 Dwords to Struct + Call  [copies inertia data]
  |     +-- FUN_00569410 — post-copy update/notification
  +-- FUN_005697f0 — Triple Buffer Allocation  [allocates 3 output buffers]
  +-- FUN_00569860 — 3D Position Delta to Body-Frame Vector Transform  [joint offset computation]
  +-- FUN_005698e0 — Buffer Entry Append with Matrix Init  [appends joint entry]
  |     +-- FUN_0056c3a0 — 3x4 matrix copy/init  [docs/20-math-utilities]
  +-- FUN_00569990 — 3D Vector Transform with Buffer Write  [writes joint transform]
  +-- FUN_0056d430 — Constraint Count  [counts constraints]
  +-- FUN_0056cf70 — 3x3 Matrix-Vector Multiply (Double)  [constraint math]
  +-- FUN_0056d020 — 3x3 Matrix Inverse & Coordinate Transform  [sub-system solve]
  |     +-- FUN_00435e00 — basis vector initialization
  +-- FUN_0056d2d0 — Sub-System Solve  [solves constraint sub-system]
  +-- FUN_0056d880 — Zero-Fill Arrays and Call Init Routine  [init constraint matrix]
  |     +-- FUN_00568fb0 — init routine
  +-- FUN_00579f89 — Iterative Solver  [solves full constraint system]
  +-- FUN_0056c830 — Matrix Factor  [factors constraint matrix]
  +-- FUN_005355a0 — Close File  [closes scene file]
  +-- FUN_0058986e — File Delete with Error Handling  [cleanup on error]
  |     +-- FUN_0058af5c — error handling callback/propagator
  +-- FUN_0056e970 — Init  [zero-initializes struct header]
```

(20 additional leaf callees with 0-1 sub-callees each omitted.)

## Step-by-Step Trace

### Level 0: FUN_0056d930 — Vehicle Physics Joint System Loader

**Trigger:** Scene file load for vehicle physics subsystem.
**Called by:** Orphan (no callers recorded in call_graph.json — likely called from vehicle setup initialization chain).
**Purpose:** Reads text-format physics scene file, allocates body/joint/hinge/bar arrays, builds constraint network.

**Key actions:**
1. First pass: counts BODY/JOINT/HINGE/BAR/JOINT_HINGE tokens via FUN_00587c20 token match
2. Allocates four parallel arrays: bodies (stride 0x244), joints (stride 0x30), hinges (stride 0x30), bars (stride 0x48)
3. Second pass: parses each section — reads name, position (3 doubles), orientation quaternion (4 doubles), inertia tensor
4. Resolves body references: validates no duplicate names, links reference counts per body
5. Post-process: computes derived spring/damper/tension values per joint/hinge/bar
6. Final allocates and initializes constraint matrix, solves via iterative solver

**Data passed to callees:** File handle, tokenizer state, body/joint/hinge/bar array pointers, constraint matrix pointers.

### Level 1: Key callees

**FUN_00534b00 — File Open Wrapper** — Opens scene file. Calls FUN_00534b10 for actual OS file open.

**FUN_005691d0 — 3x3 Rotation Tensor Matrix Transform** — Builds rotation matrix from parsed orientation data. Calls FUN_0056bd40 (Euler to rotation matrix) and FUN_005692a0 (inertia/constraint update).

**FUN_005698e0 — Buffer Entry Append with Matrix Init** — Appends joint/hinge/bar entry to output array. Calls FUN_0056c3a0 for 3x4 matrix copy.

**FUN_0056d020 — 3x3 Matrix Inverse & Coordinate Transform** — Computes inverse of constraint sub-system matrix. Calls FUN_00435e00 for basis vector initialization.

**FUN_00579f89 — Iterative Solver** — Solves the full constraint system assembled from all joints/hinges/bars. Pure math leaf function.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0056d930 | File path | Open + two-pass parse | Body/Joint/Hinge/Bar arrays |
| FUN_005691d0 | Orientation data | Rotation matrix construction | 3x3 rotation matrix |
| FUN_0056d430 | Joint/Hinge/Bar arrays | Count DOF constraints | Constraint count |
| FUN_0056d880 | Constraint count | Zero-fill + init | Initialized constraint matrix |
| FUN_00579f89 | Constraint matrix | Iterative solve | Solved constraint state |

## Globals Written in This Chain

None — this is a pure data loader with no game state globals.

## Notes

- 25 callees, most are leaf math/utility functions
- The body struct (stride 0x244) contains position (4 doubles), orientation quaternion, inertia tensor (3+3 doubles), 4x4 transform matrix, and per-body reference counts
- Joint/Hinge struct (stride 0x30) and Bar struct (stride 0x48) share header format with additional spring/damper params for bars
- Post-processing computes derived spring/tension values stored at +0x08/+0x10 per joint

---
