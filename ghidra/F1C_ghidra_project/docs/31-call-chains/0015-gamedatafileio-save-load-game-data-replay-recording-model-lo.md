# Chain: GameDataFileIO — save/load game data, replay recording, model loading, and file I/O orchestration

Seed: FUN_004b7300  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: ~55 unique

---

## Overview

FUN_004b7300 (GameDataFileIO) is a top-level game data save/load dispatcher. It
branches on save-vs-load mode, then dispatches to 12 callees spanning replay
recording (FUN_004b7500), filesystem I/O (FUN_00566b20/FUN_00566940), string
path management (FUN_00566650), model/scene loading (FUN_004b6c90), angular math
(FUN_004b86e0), linked-list buffer management (FUN_004b5f60/FUN_004b5e50), node
freeing (FUN_004bb3d0), heap deallocation (FUN_00587bcf), and file existence
checking (FUN_004b8010/FUN_004b9830).

The call graph is wide (12 direct callees) and moderately deep (max depth 3).
Three major subsystems are invoked: replay save/load (FUN_004b7500), model/scene
loading (FUN_004b6c90), and audio stream file I/O (FUN_00566b20). These converge
onto shared leaf utilities: FUN_00566650 (string copy), FUN_00587bcf (memory free,
terminating at FUN_0058aa6f), and FUN_00566b90/FUN_005668d0 (file close/cleanup).

---

## Call Tree

```
FUN_004b7300 ── GameDataFileIO (seed, 12 callees)
│
├── FUN_004b7500  ── Replay Save State Machine (docs/06, 15+ callees) [LEVEL 2+]
│   ├── FUN_004b52a0        ── (leaf, no tracked callees)
│   ├── FUN_004b6190        ── Car State Capture (leaf)
│   ├── FUN_004b7a00        ── Replay Header Init (leaf)
│   ├── FUN_00423a00        ── String Copy (leaf)
│   ├── FUN_004a0e70        ── Message Display (leaf)
│   ├── FUN_00566940        ── File I/O Open/Status (leaf)
│   ├── FUN_00566b90        ── File Close [LEVEL 2]
│   │   ├── FUN_00587d02    ── File close method A (leaf)
│   │   └── FUN_005355a0    ── File close method B (leaf)
│   ├── FUN_005668d0        ── File Handle Cleanup [LEVEL 2]
│   │   ├── FUN_00566b90    ── (see above)
│   │   └── FUN_00587bcf    ── (see below)
│   ├── FUN_004b6a10        ── Lap Data Write (leaf)
│   ├── FUN_00566b20        ── AudioStreamOpen [LEVEL 2] (see below)
│   ├── FUN_00566c00        ── Stream Read/Write (leaf)
│   ├── FUN_00566bd0        ── Stream Protocol (leaf)
│   ├── FUN_004b8010        ── File/Setting Existence Check [LEVEL 2] (see below)
│   ├── FUN_00566650        ── String Copy with Buffer Realloc (leaf)
│   ├── FUN_00566db0        ── Entry Write (leaf)
│   └── FUN_004b5f60        ── LinkedBufferTransfer [LEVEL 2] (see below)
│
├── FUN_00566b20  ── AudioStreamOpen (docs/21, 4 callees) [LEVEL 2]
│   ├── FUN_00566b90        ── File Close (see above)
│   ├── FUN_00568620        ── Buffer Alloc (leaf)
│   ├── FUN_00534b00        ── Stream Open (leaf)
│   └── FUN_00566650        ── String Copy (leaf)
│
├── FUN_00566650  ── String Copy w/ Buffer Realloc (docs/20, LEAF)
│
├── FUN_00566940  ── File I/O Open/Status (docs/06, LEAF)
│
├── FUN_004b6c90  ── Model/Scene File Loader (docs/20, 19 callees) [LEVEL 2]
│   ├── FUN_004b8090        ── (leaf)
│   ├── FUN_00566c00        ── Stream Read (leaf)
│   ├── FUN_00566650        ── String Copy (leaf)
│   ├── FUN_004b5e50        ── Hash Bucket List Manager [LEVEL 2] (see below)
│   ├── FUN_004ba780        ── Begin Object (leaf)
│   ├── FUN_004ba830        ── (leaf)
│   ├── FUN_004bafc0        ── Get Mesh Data (leaf)
│   ├── FUN_004bb0c0        ── Get Mesh Data (leaf)
│   ├── FUN_004b5040        ── (leaf)
│   ├── FUN_004bb460        ── (leaf)
│   ├── FUN_004b4250        ── (leaf)
│   ├── FUN_004b5f60        ── LinkedBufferTransfer [LEVEL 2] (see below)
│   ├── FUN_004bb6b0        ── (leaf)
│   ├── FUN_004bb200        ── (leaf)
│   ├── FUN_004bacf0        ── (leaf)
│   ├── FUN_004b44a0        ── (leaf)
│   ├── FUN_004b43e0        ── (leaf)
│   └── FUN_00587bcf        ── Memory Free (see below)
│
├── FUN_004b86e0  ── AngleClampWrap (docs/06, LEAF)
│
├── FUN_004b5f60  ── LinkedBufferTransfer (docs/06, 2 callees) [LEVEL 2]
│   ├── FUN_00587bcf        ── Memory Free (see below)
│   └── FUN_004b4460        ── Blocking Wait/Poll (leaf)
│
├── FUN_004b5e50  ── Hash Bucket List Manager (docs/06, 3 callees) [LEVEL 2]
│   ├── FUN_004b0170        ── Resource Cleanup (leaf)
│   ├── FUN_004b4f70        ── Sync/Lock (leaf)
│   └── FUN_00587bcf        ── Memory Free (see below)
│
├── FUN_004bb3d0  ── Node Data Free (docs/20, 1 callee) [LEVEL 2]
│   └── FUN_00587bcf        ── Memory Free (see below)
│
├── FUN_00587bcf  ── Memory Free Wrapper (docs/20, 1 callee) [LEVEL 2]
│   └── FUN_0058aa6f        ── Heap Deallocation / operator delete (LEAF)
│
├── FUN_004b8010  ── File/Setting Existence Check (docs/08, 6 callees) [LEVEL 2]
│   ├── FUN_004b9830        ── Path Helper (leaf)
│   ├── FUN_00587db0        ── (leaf)
│   ├── FUN_00587d02        ── File close method A (leaf)
│   ├── FUN_0058ba36        ── (leaf)
│   ├── FUN_0058986e        ── (leaf)
│   └── FUN_00587bcf        ── Memory Free (see below)
│
└── FUN_004b9830  ── Path Helper (LEAF, no tracked callees)
```

---

## Step-by-Step Trace

### Level 0 — Seed
**FUN_004b7300 — GameDataFileIO** (docs/08-file-formats.md):
- Branch on param_3: 0 = save, non-0 = load
- Save path: open file, write game data, write session timestamp
- Load path: cleanup old data, open file, parse data blocks, store TeamID+SessionType
- Updates struct offsets: +0x6c0 (DataListHead), +0x6e4 (SuccessFlag), +0x700 (OpState), +0xf1c (PlayerTeamID), +0xf20 (SessionType)
- Dispatches to 12 callees covering replay, I/O, model loading, math, memory management

### Level 1 — Direct Callees

**1. FUN_004b7500 — Replay Save State Machine**
   - Source: docs/06-session-race-logic.md (Replay.cpp)
   - Guards on param_1+0x6e4 (replay data present) and param_1+0x700 (op state)
   - First-time save (state==1): iterates 0x68 car state captures (FUN_004b6190), writes replay header (FUN_004b7a00), opens file via FUN_00566940, writes lap data (FUN_004b6a10), streams car states (FUN_00566b20/FUN_00566c00/FUN_00566bd0), finalizes (FUN_004b8010)
   - Active replay (state!=1, flag set): closes previous, opens new file, writes path+header via FUN_00566650+FUN_004b6a10, iterates linked list entries via FUN_00566db0+streaming
   - Final: clears state, calls FUN_004b5f60 (cleanup transfer)
   - Depth extends to 3 via FUN_00566b90/FUN_005668d0 (file close chain)

**2. FUN_00566b20 — AudioStreamOpen**
   - Source: docs/21-audio-network-internals.md (Miles Sound System)
   - Opens audio file stream: calls FUN_00566b90 (audio prep/close), FUN_00568620 (buffer alloc), FUN_00534b00 (stream open), FUN_00566650 (header read)
   - Depth extends to 3 via FUN_00566b90 → FUN_00587d02/FUN_005355a0

**3. FUN_00566650 — String Copy with Buffer Realloc**
   - Source: docs/20-math-utilities.md | Confidence: medium
   - String copy utility with optional buffer reallocation
   - Called >200 times across codebase — core path registry utility
   - Leaf — no further callees in call_graph

**4. FUN_00566940 — File I/O Open/Status**
   - Source: docs/06-session-race-logic.md (triaged as UI window class but used as file I/O)
   - Opens file or checks file status in replay/save paths
   - Leaf — no further callees in call_graph

**5. FUN_004b6c90 — Model/Scene File Loader**
   - Source: docs/20-math-utilities.md (modelloader.cpp or sceneloader.cpp)
   - Reads binary model data from file stream, constructs object + component linked lists
   - Reads strings (FUN_00566650), flags, object counts
   - Per-object: calls FUN_004ba780 (begin), FUN_004bafc0/FUN_004bb0c0 (mesh data)
   - Links objects into doubly-linked list at +0x6c0
   - Second pass: shadow/light objects → linked list at +0x6c0
   - Component objects → linked list at +0x714
   - 19 callees, all leaves except FUN_004b5e50, FUN_004b5f60, FUN_00587bcf

**6. FUN_004b86e0 — AngleClampWrap**
   - Source: docs/06-session-race-logic.md
   - Clamps or wraps angular/steering value between min/max bounds
   - Two modes: clamp (if +0xf81 != 0) or wrap (infinite loop reflecting value)
   - Stores previous value at +0xf3c, current at +0xf38
   - Leaf — no further callees

**7. FUN_004b5f60 — LinkedBufferTransfer**
   - Source: docs/06-session-race-logic.md
   - Transfers nodes between two linked lists (FIFO queue)
   - Walks list at +0x714, removes matching node, frees via FUN_00587bcf
   - Creates new 0xc-byte node, appends to output queue at +0x30
   - 2 callees: FUN_00587bcf + FUN_004b4460 (blocking wait)

**8. FUN_004b5e50 — Hash Bucket List Manager**
   - Source: docs/06-session-race-logic.md (F1Manager.cpp)
   - Processes 64 hash buckets (stride 0x10 = 4 pointers each)
   - Removes matching entries from collision chain, frees memory
   - Re-adds to separate linked list at +0x10/+0x14/+0x18/+0x1c
   - 3 callees: FUN_004b0170 (resource cleanup), FUN_004b4f70 (sync/lock), FUN_00587bcf (free)

**9. FUN_004bb3d0 — Node Data Free**
   - Source: docs/20-math-utilities.md | Confidence: high
   - Frees a linked-list node data payload
   - 1 callee: FUN_00587bcf (free wrapper)

**10. FUN_00587bcf — Memory Free / operator delete wrapper**
    - Source: docs/20-math-utilities.md (also docs/01/06/08)
    - Trampoline thunk — unconditional jmp to FUN_0058aa6f
    - Called ~200+ times across codebase as universal memory deallocator
    - 1 callee: FUN_0058aa6f (heap deallocation)

**11. FUN_004b8010 — File/Setting Existence Check**
    - Source: docs/08-file-formats.md (file_check.cpp)
    - Checks if a file or setting exists by building path (FUN_004b9830) and validating
    - 6 callees: FUN_004b9830, FUN_00587db0, FUN_00587d02, FUN_0058ba36, FUN_0058986e, FUN_00587bcf

**12. FUN_004b9830 — Path Helper**
    - Not in functions.json (undocumented leaf)
    - Assists in path construction for existence checks
    - Leaf — no tracked callees

### Level 2 — Second-depth callees (major branches)

**From FUN_004b7500 (Replay Save) — file close chain:**
- FUN_00566b90 — File Close (docs/20, source: audio/filesystem):
  - Calls FUN_00587d02 (file close method A) and FUN_005355a0 (file close method B)
  - Both leaves (depth 3)
- FUN_005668d0 — File Handle Cleanup (docs/20):
  - Calls FUN_00566b90 (file close) and FUN_00587bcf (free)
  - Converges onto same file close chain

**From FUN_004b6c90 (Model Loader) — major sub-callees:**
- FUN_004b5e50 — Hash Bucket Manager (3 callees, see Level 1 above)
- FUN_004b5f60 — LinkedBufferTransfer (2 callees, see Level 1 above)
- All other 15 callees are leaves

### Level 3 — Termination leaves
- FUN_0058aa6f — Heap Deallocation / operator delete (called from FUN_00587bcf)
- FUN_00587d02 — File close method A (called from FUN_00566b90)
- FUN_005355a0 — File close method B (called from FUN_00566b90)
- All other Level 2+ callees terminate at Level 2

---

## Data Flow Summary

```
FUN_004b7300(param_1=GameData*, param_2=path, param_3=mode)
   │
   ├── [mode==0 SAVE]
   │   ├──→ open file, write data, write session time
   │   ├──→ FUN_004b7500 (replay save path)
   │   │       ├──→ FUN_00566940 open file
   │   │       ├──→ FUN_004b6a10 write lap data
   │   │       ├──→ FUN_00566b20/FUN_00566c00/FUN_00566bd0 stream car state data
   │   │       └──→ FUN_00566b90/FUN_005668d0 close file
   │   └──→ FUN_004b8010 check/save setting
   │
   └── [mode!=0 LOAD]
       ├──→ FUN_004b6c90 load model/scene data
       │       ├──→ FUN_00566c00 read stream
       │       ├──→ FUN_00566650 read name strings
       │       ├──→ FUN_004ba780/FUN_004bafc0/FUN_004bb0c0 construct objects
       │       └──→ FUN_004b5e50/FUN_004b5f60 manage hash buckets + linked lists
       ├──→ FUN_004b86e0 clamp/wrap angular value
       ├──→ FUN_004b5e50 cleanup hash buckets
       ├──→ FUN_004b5f60 transfer linked buffer nodes
       ├──→ FUN_004bb3d0 free node data
       └──→ FUN_00587bcf → FUN_0058aa6f free heap memory
```

**Data flowing:**
- param_1: GameData struct (offsets: +0x6c0 DataListHead, +0x6e4 SuccessFlag, +0x700 OpState, +0xf1c PlayerTeamID, +0xf20 SessionType)
- param_2: file path string
- param_3: mode flag (0=save, non-0=load)
- Replay data flows through FUN_004b7500 → linked list at +0x714 → streaming functions
- Model data flows through FUN_004b6c90 → linked lists at +0x6c0 and +0x714
- Heap: FUN_00587bcf → FUN_0058aa6f releases memory from deallocated nodes

---

## Globals Written

No game-state globals directly written by this chain. Functions operate on:
- GameData struct pointed by param_1 (offsets documented above)
- Linked lists within the struct (DataListHead at +0x6c0, replay list at +0x714)
- Heap via FUN_00587bcf/FUN_0058aa6f (internal heap state, not game-modellable)
- File system (file writes, close operations)

---

## Notes

- Wide tree: 12 direct callees, ~55 total unique functions in chain
- Max depth = 3: most paths terminate at Level 2 or 3
- Convergence points:
  - FUN_00566650 (String Copy) — called from seed, FUN_004b7500, FUN_00566b20, FUN_004b6c90
  - FUN_00587bcf (Memory Free) — called from seed, FUN_004b6c90, FUN_004b5f60, FUN_004b5e50, FUN_004bb3d0, FUN_004b8010, FUN_005668d0 (7 sites)
  - FUN_00566b90 (File Close) — called from FUN_004b7500, FUN_005668d0, FUN_00566b20
- File I/O subsystem: FUN_00566940 (open), FUN_00566c00 (read/write), FUN_00566b90/FUN_005668d0 (close/cleanup), FUN_00587d02/FUN_005355a0 (close methods A/B) — forms a complete open/read/close pipeline
- Replay subsystem (FUN_004b7500): handles both first-time save and ongoing replay recording with file rotation, car state capture loop, and linked-list-based replay buffer
- Model loader (FUN_004b6c90): complex object construction from binary file, builds doubly-linked lists, reads mesh data per object, second pass for shadow/light objects
- FUN_00566940 discrepancy: Triaged as UI window class in docs/06 but used as file I/O open function throughout save/replay paths — likely the same function handles both file streams and UI descriptor loading
- FUN_004b9830: not in functions.json — undocumented leaf function for path construction
