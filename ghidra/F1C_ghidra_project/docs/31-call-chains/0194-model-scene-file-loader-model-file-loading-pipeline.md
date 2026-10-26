# Chain 193: Model/Scene File Loader — Model File Loading Pipeline

Seed: FUN_004b6c90  |  System: docs/20-math-utilities.md  |  Depth: 4  |  Functions: 18 callees

---

## Overview

Triggered by FUN_004b7300 during scene/model file loading. FUN_004b6c90 orchestrates loading of 3D model/scene data files: it calls a sequence of file readers, hash bucket managers, linked list builders, and string copy utilities to parse model geometry and scene structure from binary file formats. The chain reads model files via FUN_004b4250 (File Stream Reader), manages asset lookup buckets via FUN_004b5e50 (Hash Bucket List Manager), transfers data buffers via FUN_004b5f60 (LinkedBufferTransfer), and builds linked list structures via FUN_004bb200, FUN_004bafc0, and FUN_004bacf0. File format headers are parsed by FUN_004b43e0 and FUN_004b44a0. Final cleanup uses FUN_00587bcf (Free Wrapper).

## Call Tree

```
FUN_004b6c90 — Model/Scene File Loader  [called by FUN_004b7300 during scene load]
  +-- FUN_004b8090 — Binary Float Comparison (NaN-aware)  [compares float values with NaN guard]
  +-- FUN_00566c00 — File Write with Backend Dispatch  [writes file data, 2 callees]
  |     +-- FUN_00587f90 — File Tell/Seek Position Query
  |     +-- FUN_00587f64 — String Format Wrapper
  +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf, 134 callers — string utility]
  +-- FUN_004b5e50 — Hash Bucket List Manager  [manages asset hash buckets]
  |     +-- FUN_004b5f60 — LinkedBufferTransfer  [data buffer transfer]
  |     +-- FUN_004ba780 — Short Computation / Linked List Peek  [leaf]
  |     +-- FUN_004ba830 — Linked List Node Removal  [leaf]
  +-- FUN_004ba780 — Short Computation / Linked List Peek  [leaf]
  +-- FUN_004ba830 — Linked List Node Removal  [leaf]
  +-- FUN_004bafc0 — Memory Allocation / Linked List Builder  [allocates 0x7f0-byte blocks]
  |     +-- FUN_004bb0c0 — [PARTIAL] Unknown  [leaf]
  +-- FUN_004bb0c0 — [PARTIAL] Unknown  [leaf]
  +-- FUN_004b5040 — Unknown (Buffer/Stream Init with Zero Fill)  [leaf]
  +-- FUN_004bb460 — Destructor with Conditional Free  [leaf, docs/01]
  +-- FUN_004b4250 — File Stream Reader  [reads file stream data]
  |     +-- FUN_004b0220 — Path Truncation Utility
  |     +-- FUN_004b4450 — Wrapper + Pass-Through
  +-- FUN_004b5f60 — LinkedBufferTransfer  [transfers buffers between linked list nodes]
  |     +-- FUN_004ba780 — Linked List Peek  [leaf]
  |     +-- FUN_004bacf0 — Linked List Node Removal  [leaf]
  +-- FUN_004bb6b0 — Linked List Node Removal  [leaf]
  +-- FUN_004bb200 — Complex Multi-Level Allocation with Linked List Insertion  [alloc + insert]
  |     +-- FUN_004bb490 — Linked List Insert (Head)  [leaf]
  +-- FUN_004bacf0 — Linked List Node Removal  [leaf]
  +-- FUN_004b44a0 — File Operation Open + Write  [opens/writes file]
  |     +-- FUN_004b4450 — Wrapper + Pass-Through  [leaf]
  |     +-- FUN_004b4460 — Small Struct Zero-Init  [leaf]
  +-- FUN_004b43e0 — File Format Header Reader  [reads format header]
  |     +-- FUN_004b4f50 — Dual Call Wrapper  [leaf]
  |     +-- FUN_004b4460 — Small Struct Zero-Init  [leaf]
  +-- FUN_00587bcf — Free Wrapper (operator delete)  [leaf, 507 callers total]
```

## Step-by-Step Trace

### Level 0: FUN_004b6c90 — Model/Scene File Loader

**Trigger:** Called by FUN_004b7300 (scene loading dispatch) during model/scene file loading.
**Called by:** FUN_004b7300 (scene load dispatch)
**Purpose:** Orchestrates loading and parsing of 3D model/scene data from binary files.

**Key actions:**
1. Calls FUN_004b8090 — NaN-aware float comparison for geometry bounds
2. Calls FUN_00566c00 — file write backend for writing loaded data
3. Calls FUN_00566650 — string copy for asset name/path handling
4. Calls FUN_004b5e50 — hash bucket management for asset lookup
5. Calls FUN_004b5f60, FUN_004bb200 — linked list building for scene elements
6. Calls FUN_004b4250, FUN_004b44a0 — file I/O for reading model data
7. Calls FUN_004b43e0 — reads format headers
8. Cleans up with FUN_00587bcf

**Data passed to callees:** File path strings, buffer pointers, model struct pointers

### Level 1: FUN_00566c00 — File Write with Backend Dispatch

**Trigger:** Called by seed to write parsed file data.
**Purpose:** Dispatches file write operations to backend.

**Key actions:**
1. Calls FUN_00587f90 — queries file tell/seek position
2. Calls FUN_00587f64 — formats string output for logging/display

### Level 1: FUN_004b5e50 — Hash Bucket List Manager

**Trigger:** Called by seed to manage asset hash buckets during scene loading.
**Purpose:** Manages hash bucket linked lists for asset lookup.

**Key actions:**
1. Calls FUN_004b5f60 — LinkedBufferTransfer for data movement between buckets
2. Calls FUN_004ba780 — linked list peek
3. Calls FUN_004ba830 — linked list node removal

### Level 1: FUN_004bafc0 — Memory Allocation / Linked List Builder

**Trigger:** Called to allocate linked list nodes during loading.
**Purpose:** Allocates 0x7f0-byte data blocks in pool pattern.

**Key actions:**
1. Allocates memory blocks
2. Calls FUN_004bb0c0 — unknown sub-operation

### Level 2 (from FUN_004b5f60): FUN_004bacf0 — Linked List Node Removal

**Trigger:** Called by FUN_004b5f60 during buffer transfer cleanup.
**Purpose:** Removes nodes from linked list.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004b6c90 | File path string | Open + parse file | Scene/model data in linked list |
| FUN_004b4250 | File stream | Stream read | Raw data buffer |
| FUN_004b43e0 | Raw buffer | Parse format header | Struct fields |
| FUN_004b5e50 | Asset data | Hash bucket insert | Organized lookup table |
| FUN_004bb200 | Parsed nodes | Linked list build | Scene node linked list |

## Notes

- Seed has 18 callees, many are leaf utilities (math_util category)
- Hash bucket manager FUN_004b5e50 and LinkedBufferTransfer FUN_004b5f60 appear multiple times in call tree — shared utilities
- FUN_00587bcf (free wrapper) is the most-called function in the entire engine (507 callers)

---
