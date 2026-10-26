# Chain: DirectX Mesh/Vertex Buffer Parsing and Loading — Mesh File Level Loading

Seed: 0x00547b40  |  System: docs/19-renderer.md  |  Depth: 3  |  Functions: 23

---

## Overview

Parses binary mesh file data into D3D resources. Triggered when a .scn scene file references a mesh resource — reads structured file format tokens, allocates mesh node structs, iterates sub-mesh groups, creates vertex/index buffers, binds textures, commits mesh to D3D device. Output: fully initialized D3D mesh with vertex buffers, index buffers, attribute tables, and texture bindings.

## Call Tree

```
0x00547b40 — Mesh/Vertex Buffer Loader  [trigger: scene load, mesh file referenced]
  +-- 0x0054a5c0 — Global Buffer Copy w/ Advance  [reads structured file data]
  +-- 0x00546250 — Constructor: Input/Control Init  [allocates mesh struct]
  +-- 0x00546330 — Self-Copy String to Buffer  [copies mesh name string]
  |     +-- 0x00589901 — String normalization  [leaf]
  +-- 0x0054fb90 — Struct Init with Defaults  [initializes sub-mesh group]
  |     +-- 0x0053c2a0 — [leaf]
  +-- 0x0054fc10 — Self-Relative Copy + Normalize  [copies texture name]
  |     +-- 0x00589901 — String normalization  [leaf]
  +-- 0x00552fc0 — Field Setter at +0x48  [sets mesh field]
  +-- 0x00546f30 — Bounded Check + Trigger  [validates bounds]
  |     +-- 0x0054fc40 — [leaf]
  +-- 0x005470a0 — Conditional Render State Set  [sets D3D render state]
  +-- 0x0054fc70 — Single Field Setter  [leaf]
  +-- 0x00546f70 — Conditional Render State Set  [4 render state submode sets]
  |     +-- 0x0054fc40 — render state mask  [leaf]
  |     +-- 0x0054fc80 — render state clear  [leaf]
  |     +-- 0x0054fd30 — scale set  [leaf]
  |     +-- 0x0054fca0 — blend mode set  [leaf]
  +-- 0x005471c0 — Simple Setter (+0xb0)  [leaf]
  +-- 0x00547240 — Gear Ratio Setter w/ Flag  [leaf]
  +-- 0x0054fc80 — Dual Field Setter  [leaf]
  +-- 0x0054fd30 — Short Computation / Double-Setter  [leaf]
  +-- 0x0054fcb0 — Field Setter at +0x80  [leaf]
  +-- 0x0054fcc0 — Render/Format Mode Set  [leaf]
  +-- 0x0054fd50 — Playback Rate/Config Setter  [leaf, audio]
  +-- 0x00548a30 — Random Password/Key Generator  [leaf]
  +-- 0x005477f0 — Binary Search / Trie Lookup  [leaf]
  +-- 0x00546370 — Array Cleanup with Dual Free  [cleans up temporary arrays]
  |     +-- 0x00587bcf — Free Wrapper (thunk to 0x0058aa6f)  [heap free]
  |     +-- 0x00557470 — Empty Stub  [leaf]
  +-- 0x00557470 — Empty Stub  [leaf]
  +-- 0x00587bcf — Free Wrapper  [heap free, called 23 times across function]
  +-- 0x00547670 — Linked List Append w/ Flag Counter  [appends to D3D resource list]
```

## Step-by-Step Trace

### Level 0: 0x00547b40 — DirectX Mesh/Vertex Buffer Parsing and Loading

**Trigger:** Scene load requests a mesh resource (referenced from .scn file).
**Called by:** No callers documented (entry point from scene load path).
**Purpose:** Parses mesh file data and loads vertex/index buffers into D3D resources.

**Key actions:**
1. Calls FUN_0054a5c0 — structured file reading with format tokens, reads mesh header
2. Allocates mesh node struct via FUN_00546250
3. Iterates sub-mesh groups: allocates attribute table, index buffer entries
4. Reads texture names via FUN_0054fc10
5. Creates textures via FUN_00552fc0, binds vertex buffers via FUN_00546f30
6. Optionally loads second texture set and blends
7. Decodes vertex format flags from attribute bits
8. Commits mesh to D3D via FUN_00548a30, FUN_00547670
9. Cleans up temporary arrays via FUN_00546370

**Data passed to callees:** File buffer pointer, mesh struct pointer, texture name strings, D3D device handles.

### Level 1: Key Sub-functions

**0x0054a5c0 — Arithmetic/Comparison / Global Buffer Copy with Advance**
Reads structured data from file buffer, advances read cursor. Returns formatted data.

**0x00546250 — Constructor: Input/Control Init**
Allocates and initializes a new mesh node struct. Returns pointer.

**0x00546f70 — Unidentified Logic (Conditional Render State Set)**
Sets up to 4 D3D render state submodes via leaf setters.

**0x00548a30 — Random Password/Key Generator**
Generates mesh identifier or key value.

**0x00547670 — Linked List Append with Flag-Based Counter**
Appends completed mesh node to D3D resource linked list. Tracks allocation count.

**0x00546370 — Array Cleanup with Dual Free**
Frees temporary arrays allocated during parsing. Calls heap free (0x00587bcf) and no-op stub.

**0x00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)**
Frees heap memory. Called extensively (23 times) during mesh cleanup.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00547b40 | file buffer, mesh name | parse header, allocate struct | mesh_node |
| FUN_0054a5c0 | file buffer | read structured tokens | parsed data blocks |
| FUN_00546250 | mesh struct ptr | allocate sub-resources | initialized structs |
| FUN_0054fc10 | texture name | copy + normalize | normalized texture path |
| FUN_00546f30 | vertex data | create vertex buffer | D3D vertex buffer |
| FUN_00548a30 | — | generate key | mesh identifier |
| FUN_00547670 | mesh node | append to list | committed resource |

## Globals Written in This Chain

None documented — all data passed through struct pointers and file buffers.

## Notes

Most callees (18 of 23) are leaf functions. Chain is wide but shallow — primarily a sequence of initialization calls with little recursion. Many callees are D3D wrapper utilities in docs/20-math-utilities.md. 0x00587bcf (heap free) called repeatedly.

---
