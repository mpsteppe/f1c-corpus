# Chain: SpecialFX::Init — Special Effects Initialization

Seed: FUN_004cf070  |  System: docs/09-track-system.md  |  Depth: 2  |  Functions: 93 (39 direct + 54 transitive)

---

## Overview

SpecialFX::Init is the primary initialization function for the special effects subsystem of F1 Challenge 99-02. Called during Game::Init (triggered from the main game startup sequence in `docs/01-engine-architecture.md`), it reads and processes the track-specific `terrain.ini` configuration file, loads track surface materials, sets up the REACTION (loose) material system, initializes scene bounds via spatial queries, counts LPTREE scene node instances, and registers AI grip values (AIDryGrip, AIWetGrip). The function is 490 lines of Ghidra-decompiled code from `D:\dev\F1_1999_2002\Source\specialfx.cpp`.

End-to-end, the function opens `terrain.ini`, reads it line-by-line parsing three main sections (TRACKVARS, FEEDBACK, LOOSE), then opens `CMAPS.MAS` for per-track REACTION material definitions. It allocates and populates three key arrays: a TRACKVARS feedback array (stride 0x6c), a LOOSE materials array (stride 0x6c), and an LPTREE scene node array (stride 0x3c). After loading, it classifies materials by type (0xc, 0xd, 1, 3, 4) into special slots, runs scene file loading and spatial grid queries to determine scene extents, then reads AI grip values from config. Finally, it iterates scene nodes to count and allocate LPTREE instances. The function touches 8 documentation files across the codebase.

## Call Tree

```
FUN_004cf070 — SpecialFX::Init  [trigger: Game::Init calls during startup; docs/09-track-system.md]
  |
  +-- FUN_004d7a50 — String Split Loop / Debug Gate  [docs/20-math-utilities.md]
  |     +-- FUN_00587c20 — token match/string compare  [docs/06-session-race-logic.md] LEAF
  |     +-- FUN_004d7aa0 — Debug Log Write  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_004d7aa0 — Debug Log Write  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_004ceef0 — [undocumented; buffer clear 256 bytes] LEAF
  |
  +-- FUN_00568a60 — Utility Function (Weighted Running Checksum over File Stream)  [docs/20-math-utilities.md]
  |     +-- FUN_00587db0 — Delegation with Fixed Arg (file open)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_00589fcc — Stream getc with Underflow Handler  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_00587d02 — Close file handle with locking guard  [docs/08-file-formats.md]
  |           +-- FUN_0058c1b1 — Stream Buffer Lock via Critical Section  [docs/20-math-utilities.md] LEAF
  |           +-- FUN_0058c203 — Address-Range Critical Section Leave  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_00587db0 — Delegation with Fixed Arg (file open wrapper)  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_00587ca0 — File Read Until Newline (Char-by-Char)  [docs/08-file-formats.md]
  |     +-- FUN_0058c1b1 — Stream Buffer Lock via Critical Section  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_0058c255 — Buffer refill / file read  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_0058c203 — Address-Range Critical Section Leave  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_005651b0 — [undocumented; line reader tokenizer]  [docs/08-file-formats.md] LEAF
  |
  +-- FUN_00587c20 — [undocumented; token match]  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_00589db0 — [undocumented]  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_0058850f — [undocumented; string→float parse]  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_00565520 — [undocumented; INI field parser]  [docs/08-file-formats.md] LEAF
  |
  +-- FUN_00566810 — [undocumented; string compare]  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_004c58a0 — Validate resource handles, copy string from resource to output buffer  [docs/08-file-formats.md]
  |     +-- FUN_004c5840 — SeasonRaces Section Finder  [docs/08-file-formats.md] LEAF
  |     +-- FUN_005679c0 — String-Keyed Linked List Search  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_00567970 — Data Entry Accessor  [docs/08-file-formats.md] LEAF
  |
  +-- FUN_004c9d10 — Two-Field Setter  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_004ca3e0 — Arithmetic/Comparison (Struct Init -1/0)  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_004ca480 — Material Shader/Reaction Effect Parser  [docs/09-track-system.md]
  |     +-- FUN_00565870 — INI float reader  [undocumented] LEAF
  |     +-- FUN_00565520 — INI string reader  [docs/08-file-formats.md] LEAF
  |     +-- FUN_00557350 — D3D material constructor  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_004cad30 — Color parser (hex string, big-endian)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_004cada0 — Blend mode parser  [undocumented] LEAF
  |
  +-- FUN_004caed0 — 16-Float Lexicographic Comparison with String Fallback  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_004cdd80 — Track Surface Material Loader  [docs/09-track-system.md] LEAF
  |
  +-- FUN_004c9d30 — Recursive Tree Free  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)  [docs/01-engine-architecture.md]
  |     +-- FUN_0058aa6f — Heap deallocation function  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_0053c800 — String Registry (Dedup List)  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_0053cbc0 — [undocumented] LEAF
  |
  +-- FUN_0053ce40 — Physics Object Linked List Removal  [docs/06-session-race-logic.md]
  |     +-- FUN_0055fe30 — Dual Field Cleanup with Null Checks  [docs/01-engine-architecture.md] LEAF
  |     +-- FUN_00557470 — Empty Stub  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_00587bcf — Free Wrapper  [docs/01-engine-architecture.md]
  |           +-- FUN_0058aa6f — Heap deallocation function  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_0053c900 — String Match with Flag Set  [docs/20-math-utilities.md]
  |     +-- FUN_00589901 — [undocumented]  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_0053ca00 — Search Path Prune  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_004cef30 — Unidentified Logic (Light/Display Iteration)  [docs/19-renderer.md]
  |     +-- FUN_00545f40 — Value Getter (get display)  [docs/06-session-race-logic.md] LEAF
  |     +-- FUN_00548850 — Indexed Linked List Search (set active output)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_00547370 — String Copy with Offset (get output name)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_004ce860 — String List Lookup (config lookup)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_004ce8d0 — Config process (param_1 + 0xc + param_2 * 0x6c)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_00547280 — Dual Field Setter by Key (set param)  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_0044c0e0 — Scene/Track File Loader  [docs/19-renderer.md]
  |     +-- FUN_0053ac70 — Guard/early return check  [docs/01-engine-architecture.md] LEAF
  |     +-- FUN_0044c470 — Collision Tree Node Cleanup  [docs/17-physics-collision.md] LEAF
  |     +-- FUN_0044c430 — SinTableInit  [docs/17-physics-collision.md] LEAF
  |
  +-- FUN_004024f0 — [undocumented] LEAF
  |
  +-- FUN_00403cd0 — Keyframe Animation Data Interpolation  [docs/19-renderer.md] LEAF
  |
  +-- FUN_0044c4c0 — SpatialGridQuery  [docs/17-physics-collision.md]
  |     +-- FUN_0044a070 — QuadraticSurfaceCollisionTest (narrow-phase)  [docs/17-physics-collision.md] LEAF
  |     +-- FUN_0044aa30 — BVHTreeTraversal (broad phase insert)  [docs/17-physics-collision.md] LEAF
  |
  +-- FUN_005452f0 — Audio/Network Node Count  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_00545340 — LinkedListNodeFinder  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_0054bda0 — Self-Relative String Copy  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_004c9fb0 — ParticleCollisionSpawn  [docs/17-physics-collision.md]
  |     +-- FUN_0054c230 — Linked List Indexed Accessor  [docs/06-session-race-logic.md] LEAF
  |     +-- FUN_004dd550 — Bounding Box Computation (Min/Max)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_0054b420 — Field copy (3 fields)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_0054e100 — PackedArrayTotalSize  [docs/06-session-race-logic.md] LEAF
  |     +-- FUN_0054e120 — PackedArrayIndexLookup  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_004cb120 — [undocumented] LEAF
  |
  +-- FUN_004ca280 — 15-Field Struct Zero-Init with Free  [docs/20-math-utilities.md]
  |     +-- FUN_00587bcf — Free Wrapper  [docs/01-engine-architecture.md]
  |           +-- FUN_0058aa6f — Heap deallocation function  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_0058815f — String Format with Buffer Overflow Check  [docs/08-file-formats.md]
  |     +-- FUN_0058d04d — Core format engine (vsnprintf equivalent)  [undocumented] LEAF
  |     +-- FUN_0058cf35 — Buffered write / overflow error handler  [docs/06-session-race-logic.md] LEAF
  |
  +-- FUN_00587f64 — String Format Wrapper (synchronized)  [docs/08-file-formats.md]
  |     +-- FUN_0058c1b1 — Critical section enter (lock)  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_00587f90 — File Tell/Seek Position Query  [docs/08-file-formats.md] LEAF
  |     +-- FUN_0058c203 — Critical section leave (unlock)  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_00587d02 — Close file handle with locking guard  [docs/08-file-formats.md]
  |     +-- FUN_0058c1b1 — Stream Buffer Lock via Critical Section  [docs/20-math-utilities.md] LEAF
  |     +-- FUN_0058c203 — Address-Range Critical Section Leave  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_004cdb90 — Constructor: Init Fields  [docs/20-math-utilities.md] LEAF
```

## Data Flow Summary

The primary data flow is file-to-struct: `terrain.ini` is opened, parsed line-by-line, and its contents populate the SpecialFX manager struct (`param_1`). Secondary flow reads `CMAPS.MAS` (a material archive) and config values for AI grip.

**Input files read:**
- `terrain.ini` — track-specific effects config (TRACKVARS, FEEDBACK, LOOSE sections)
- `CMAPS.MAS` — per-track material definitions (REACTION materials)
- Scene files (via FUN_0044c0e0) — spatial grid and scene bounds

**Key struct outputs (SpecialFX manager, param_1 offsets):**
| Offset | Field | Source |
|--------|-------|--------|
| +0x00 | LPTREE count | Counted from scene nodes |
| +0x01 | LPTREE array ptr | Allocated, stride 0x3c |
| +0x02 | Feedback count | Counted from TRACKVARS section |
| +0x03 | Feedback array ptr | Allocated, stride 0x6c |
| +0x04 | Loose material count | Counted from LOOSE/REACTION entries |
| +0x05 | Loose material array ptr | Allocated, stride 0x6c |
| +0x06 | Material type 0xc slot | Classified from loose materials |
| +0x07 | Material type 0xd slot | Classified from loose materials |
| +0x08 | Material type 1 slot | Classified from loose materials |
| +0x09 | Material type 3 slot | Classified from loose materials |
| +0x0a | Material type 4 slot | Classified from loose materials |
| +0x0b | Scene extents ptr | From spatial grid query |
| +0x0c | AIDryGrip | From config lookup |
| +0x0d | AIWetGrip | From config lookup |

**Processing flow:**
1. Debug log entry (FUN_004d7a50/004d7aa0)
2. Build scene path from globals (DAT_008ac48c, DAT_008ac490)
3. Open terrain.ini via checksum helper (FUN_00568a60 → FUN_00587db0)
4. Read sections via line-reading loop (FUN_00587ca0)
5. Parse TRACKVARS: key=value pairs, allocate feedback array
6. Parse FEEDBACK section (skip)
7. Parse LOOSE section: REACTION materials with INCLUDETRACKS/EXCLUDETRACKS filtering
8. Allocate feedback + loose material arrays
9. Open CMAPS.MAS, parse per-track REACTION materials via FUN_004ca480
10. Material dedup via FUN_004caed0 comparison
11. Close files
12. Clean up temp tree (FUN_004c9d30), free (FUN_00587bcf)
13. Classify materials into type slots
14. Run scene/track file loader (FUN_0044c0e0)
15. Compute scene extents via spatial grid query (FUN_0044c4c0)
16. Read AIDryGrip and AIWetGrip from config
17. Count LPTREE scene nodes (iterate scene node list matching "LPTREE" prefix)
18. Allocate LPTREE array, init via FUN_004ca280

## Globals Written in This Chain

| Address | Name | What |
|---------|------|------|
| DAT_008ac48c | Current scene index | Read for scene path |
| DAT_008ac490 | Scene array | Read for scene path |
| DAT_007ce5ec | Settings file path | Used for AI grip lookup |
| DAT_008ad25c | Debug log buffer | Written via debug log calls |
| DAT_005ec428 | String format buffer | Read for path construction |
| DAT_005ec3d8 | String format buffer | Read for path construction |
| DAT_005ea438 | Default path fallback | Read when format buffers null |
| DAT_008b8f24 | Scene load flag | Checked by FUN_0044c0e0 |
| DAT_007ce5d0 | Scene file path | Read by FUN_0044c0e0 |

## Documentation Coverage

| Doc File | Functions involved |
|----------|-------------------|
| docs/01-engine-architecture.md | FUN_00587bcf, FUN_0053ac70, FUN_0055fe30 |
| docs/06-session-race-logic.md | FUN_004d7aa0, FUN_00587c20, FUN_00589db0, FUN_00566810, FUN_0053ce40, FUN_005452f0, FUN_00545340, FUN_00545f40, FUN_0054c230, FUN_0054e100, FUN_0054e120, FUN_0058cf35 |
| docs/08-file-formats.md | FUN_00587ca0, FUN_005651b0, FUN_00565520, FUN_00587d02, FUN_0058815f, FUN_00587f64, FUN_00587f90, FUN_004c58a0, FUN_004c5840, FUN_00567970 |
| docs/09-track-system.md | **FUN_004cf070**, FUN_004ca480, FUN_004cdd80 |
| docs/17-physics-collision.md | FUN_0044c4c0, FUN_0044a070, FUN_0044aa30, FUN_0044c470, FUN_0044c430, FUN_004c9fb0 |
| docs/19-renderer.md | FUN_0044c0e0, FUN_004cef30, FUN_00403cd0 |
| docs/20-math-utilities.md | FUN_004d7a50, FUN_00568a60, FUN_00587db0, FUN_0058850f, FUN_00589fcc, FUN_00557350, FUN_004cad30, FUN_0055fe30, FUN_00557470, FUN_00589901, FUN_0053ca00, FUN_00548850, FUN_00547370, FUN_004ce860, FUN_004ce8d0, FUN_00547280, FUN_004c9d10, FUN_004ca3e0, FUN_004caed0, FUN_004c9d30, FUN_0053c800, FUN_0053c900, FUN_004cdb90, FUN_004ca280, FUN_004dd550, FUN_0054b420, FUN_0058c1b1, FUN_0058c203, FUN_0058c255, FUN_0058aa6f, FUN_005679c0 |

## Notes

- **Depth limit:** Max call depth is 2 (seed → non-leaf → leaf). All 39 Level-1 callees either are leaves themselves or call only leaf functions.
- **Undocumented functions:** 10 of 39 direct callees lack proper documentation in functions.json: FUN_004ceef0, FUN_005651b0 (null summary), FUN_00587c20, FUN_00589db0, FUN_0058850f, FUN_00565520, FUN_00566810, FUN_0053cbc0, FUN_004024f0, FUN_004cb120. These are mostly low-level I/O and string utility functions with triage-only coverage.
- **Thunk pattern:** FUN_00587bcf is a thin free-wrapper thunk to FUN_0058aa6f (heap deallocation). It appears ~200 times across the codebase.
- **CRT wrappers:** Several callees (FUN_0058c1b1, FUN_0058c203, FUN_00589fcc) wrap MSVC CRT stream I/O with critical section guards for thread safety.
- **INI parsing pattern:** The function uses a consistent pattern of FUN_00587ca0 (read line) + FUN_005651b0 (tokenize) + FUN_00565520 (match field) + FUN_00587c20 (section header match) for all INI parsing.
- **Moddability:** AIDryGrip and AIWetGrip values read from `.gdb` config files are configurable per-track. Material properties from `.MTS` files are also configurable. REACTION material definitions in `terrain.ini` are track-specific and editable.
- **Callers:** Only 1 caller — Game::Init (FUN_004ba1f0) at system startup.
- **Relevant doc files:** This chain spans 8 doc files, with heaviest usage of docs/20-math-utilities.md (24 functions) and docs/17-physics-collision.md (5 functions).
