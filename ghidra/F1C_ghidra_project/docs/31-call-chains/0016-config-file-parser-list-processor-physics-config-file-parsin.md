# Chain: Config File Parser / List Processor — physics config file parsing with linked-list node processing

Seed: FUN_004330d0  |  System: docs/18-physics-dynamics.md  |  Depth: 6  |  Functions: 17 unique (8 direct + 9 transitive)

---

## Overview

FUN_004330d0 is a config file parsing utility that reads a physics data file, parses its content, and iterates a linked list of nodes calling a per-node processor for each. It is called by FUN_00433b60 (Add Vehicle Config Entry to Linked List in docs/02-ai-system.md, source: config_manager.cpp). The chain is an I/O pipeline: build path → open → alloc buffer → read → parse → iterate nodes → close/cleanup. Deepest paths go through error handling (TLS getters) and file close dispatch (lock/unlock via CRT critical sections).

Max depth = 6 along the leftmost path: seed → FUN_00432cf0 → FUN_004b0b10 (leaf, level 2). The longest deep path: seed → FUN_0058ba36 → FUN_0058af5c → FUN_0058afd8 → FUN_0058e0c7 → FUN_0058ab58/FUN_0058e0b4 (leaves, level 6).

---

## Call Tree

```
FUN_004330d0 — Config File Parser / List Processor  [docs/18-physics-dynamics.md, 8 callees]
  called by: FUN_00433b60 — Add Vehicle Config Entry to Linked List  [docs/02-ai-system.md]
  │
  ├── FUN_00432cf0 — PhysicsFilePathBuild  [docs/18-physics-dynamics.md, 1 callee]  [L1]
  │   └── FUN_004b0b10 — Short Computation (Add 0x14)  [docs/20-math-utilities.md] LEAF  [L2]
  │
  ├── FUN_005668b0 — Zero-Init Small Struct  [docs/20-math-utilities.md] LEAF  [L1]
  │
  ├── FUN_00568620 — alloc  [no tracked callees] LEAF  [L1]
  │
  ├── FUN_0058ba36 — Toggle File Read-Only Attribute via Win32 API  [docs/08-file-formats.md, 1 callee]  [L1]
  │   └── FUN_0058af5c — Error ID Lookup Table  [docs/01-engine-architecture.md, 2 callees]  [L2]
  │       ├── FUN_0058afd8 — TLS Offset Getter (+12)  [docs/01-engine-architecture.md, 1 callee]  [L3]
  │       │   └── FUN_0058e0c7 — TLS Value Retrieval with Init  [docs/20-math-utilities.md, 2 callees]  [L4]
  │       │       ├── FUN_0058ab58 — heap alloc  [docs/20-math-utilities.md] LEAF  [L5]
  │       │       └── FUN_0058e0b4 — Two-Field Initializer  [docs/20-math-utilities.md] LEAF  [L5]
  │       └── FUN_0058afcf — TLS Offset Getter (+8)  [docs/20-math-utilities.md, 1 callee]  [L3]
  │           └── FUN_0058e0c7 — TLS Value Retrieval with Init  [docs/20-math-utilities.md]  [L4]
  │               ├── FUN_0058ab58 — heap alloc LEAF  [L5]
  │               └── FUN_0058e0b4 — Two-Field Initializer LEAF  [L5]
  │
  ├── FUN_00566940 — parse (file status check / parser)  [docs/06-session-race-logic.md] LEAF  [L1]
  │
  ├── FUN_00432bf0 — AutoLoadEntry Writer  [docs/08-file-formats.md] LEAF  [L1]
  │
  ├── FUN_005668d0 — Sub-Call with Conditional Field Free  [docs/01-engine-architecture.md, 2 callees]  [L1]
  │   ├── FUN_00566b90 — Conditional File Handle Close with Flag Dispatch  [docs/08-file-formats.md, 2 callees]  [L2]
  │   │   ├── FUN_00587d02 — Close file handle with locking guard  [docs/08-file-formats.md, 2 callees]  [L3]
  │   │   │   ├── FUN_0058c1b1 — Stream Buffer Lock via Critical Section  [docs/20-math-utilities.md] LEAF  [L4]
  │   │   │   └── FUN_0058c203 — Address-Range Critical Section Leave  [docs/20-math-utilities.md] LEAF  [L4]
  │   │   └── FUN_005355a0 — Stream/File Type Check with Dispatch  [docs/20-math-utilities.md] LEAF  [L3]
  │   └── FUN_00587bcf — Free wrapper (thunk to FUN_0058aa6f)  [docs/01-engine-architecture.md, 1 callee]  [L2]
  │       └── FUN_0058aa6f — Heap deallocation function  [docs/20-math-utilities.md] LEAF  [L3]
  │
  └── FUN_00566b90 — Conditional File Handle Close with Flag Dispatch  [docs/08-file-formats.md, 2 callees]  [L1]
      ├── FUN_00587d02 — Close file handle with locking guard  [docs/08-file-formats.md, 2 callees]  [L2]
      │   ├── FUN_0058c1b1 — Stream Buffer Lock via Critical Section  [docs/20-math-utilities.md] LEAF  [L3]
      │   └── FUN_0058c203 — Address-Range Critical Section Leave  [docs/20-math-utilities.md] LEAF  [L3]
      └── FUN_005355a0 — Stream/File Type Check with Dispatch  [docs/20-math-utilities.md] LEAF  [L2]
```

---

## Step-by-Step Trace

### Level 0 — Seed
**FUN_004330d0 — Config File Parser / List Processor** (docs/18-physics-dynamics.md, source: dynamics/config):
- Reads config filename from param_2 into buffer via FUN_00432cf0 (max 256 bytes)
- On success: opens file (FUN_005668b0), allocates read buffer (FUN_00568620), reads file content (FUN_0058ba36)
- Calls FUN_00566940 to parse buffer content
- If parse succeeds: iterates linked list at param_1+0x1c, calling FUN_00432bf0 (AutoLoadEntry Writer) on each node
- Cleanup: calls FUN_005668d0 then FUN_00566b90 (file close/cleanup)
- Only 1 caller: FUN_00433b60 (Add Vehicle Config Entry to Linked List, docs/02-ai-system.md)

### Level 1 — Direct Callees

**1. FUN_00432cf0 — PhysicsFilePathBuild** (docs/18-physics-dynamics.md):
   - Gets executable base directory via FUN_004b0b10()
   - Copies to local buffer (255 chars), strips file extension (finds last '.' and replaces with '\0')
   - Concatenates physics filename from PTR_DAT_005c3f84
   - Copies result to param_2 with size limit param_3 - 1
   - Returns 0 on success, 1 on failure
   - **1 callee:** FUN_004b0b10 (leaf, level 2)

**2. FUN_005668b0 — Zero-Init Small Struct** (docs/20-math-utilities.md):
   - Confidence: high. Zero-initializes a small struct.
   - **Leaf** — no further callees

**3. FUN_00568620 — alloc** (no doc entry in functions.json, no tracked callees):
   - Allocates read buffer for file content.
   - **Leaf** — no further callees

**4. FUN_0058ba36 — Toggle File Read-Only Attribute via Win32 API** (docs/08-file-formats.md):
   - Confidence: high. Toggles file read-only attribute via Win32 API.
   - **1 callee:** FUN_0058af5c (error handler on failure)
   - Max depth to leaf: 5 more levels through error/TLS chain

**5. FUN_00566940 — parse** (docs/06-session-race-logic.md, triage category: game_util):
   - File status check / parser function. Called as file I/O open/status utility.
   - **Leaf** — no further callees

**6. FUN_00432bf0 — AutoLoadEntry Writer** (docs/08-file-formats.md, heading_level: 3):
   - Writes AutoLoadEntry section: Track, Classes, Session, (unnamed) fields
   - Uses FUN_00566c30 (write field to file). Returns 0 on success, 1 if param_2 null/empty.
   - **Leaf** — no tracked callees in call_graph.json (FUN_00566c30 not a separate call_graph entry)

**7. FUN_005668d0 — Sub-Call with Conditional Field Free** (docs/01-engine-architecture.md):
   - Calls FUN_00566b90 (conditional file handle close)
   - If param_1+4 non-null: calls FUN_00587bcf to free pointer
   - **2 callees:** FUN_00566b90 (file close dispatch), FUN_00587bcf (memory free)

**8. FUN_00566b90 — Conditional File Handle Close with Flag Dispatch** (docs/08-file-formats.md):
   - Gets handle from *param_1
   - If param_1[4]==0: calls FUN_00587d02 (close method A), sets *param_1=0
   - Else: calls FUN_005355a0 (close method B), sets *param_1=0
   - **2 callees:** FUN_00587d02, FUN_005355a0

### Level 2 — Second-depth callees

**FUN_004b0b10 — Short Computation (Add 0x14)** (docs/20-math-utilities.md):
   - Called by FUN_00432cf0 (PhysicsFilePathBuild). Gets base executable directory.
   - Confidence: high, category: math_util
   - Leaf — no further callees

**FUN_0058af5c — Error ID Lookup Table** (docs/01-engine-architecture.md):
   - Called by FUN_0058ba36 on read failure
   - Maps error IDs via lookup table at 0x005e65c0 (stride 8, ~90 entries)
   - Calls FUN_0058afd8 (TLS getter) to store param_1
   - Walks table, matched via FUN_0058afcf (TLS access), stores mapped code
   - Range mapping: 0x12-0x24 → code 0xd; 0xbb-0xca → code 8; default → code 0x16
   - 2 callees: FUN_0058afd8, FUN_0058afcf

**FUN_00566b90 — Conditional File Handle Close with Flag Dispatch** (docs/08-file-formats.md):
   - Same function as callee #8 above — called from FUN_005668d0
   - Full description in Level 1 above
   - 2 callees: FUN_00587d02, FUN_005355a0

**FUN_00587bcf — Free wrapper** (docs/01-engine-architecture.md):
   - Universal memory free thunk → jumps to FUN_0058aa6f
   - Called ~200+ times across codebase
   - 1 callee: FUN_0058aa6f (heap deallocation)

### Level 3 — Third-depth callees

**FUN_0058afd8 — TLS Offset Getter (+12)** (docs/01-engine-architecture.md):
   - Confidence: high. Retrieves TLS value at offset +12 from TLS base.
   - Used by error ID lookup to store/retrieve error state per-thread.
   - 1 callee: FUN_0058e0c7 (TLS Value Retrieval with Init)

**FUN_0058afcf — TLS Offset Getter (+8)** (docs/20-math-utilities.md):
   - Confidence: high. Retrieves TLS value at offset +8 from TLS base.
   - Used by error ID lookup table traversal.
   - 1 callee: FUN_0058e0c7 (same TLS init function)

**FUN_00587d02 — Close file handle with locking guard** (docs/08-file-formats.md):
   - Confidence: high. MSVC __fclose_lk wrapper for thread-safe file close.
   - Used for file close method A (flag == 0 path).
   - 2 callees: FUN_0058c1b1 (stream lock via critsec), FUN_0058c203 (critsec leave)

**FUN_005355a0 — Stream/File Type Check with Dispatch** (docs/20-math-utilities.md):
   - File close method B (flag != 0 path). Different close method.
   - Used by conditional file close dispatch.
   - Leaf — no further callees

**FUN_0058aa6f — Heap deallocation function** (docs/20-math-utilities.md):
   - operator delete / heap free. Called from FUN_00587bcf thunk.
   - Leaf — no further callees

### Level 4 — Fourth-depth callees

**FUN_0058e0c7 — TLS Value Retrieval with Init** (docs/20-math-utilities.md):
   - Confidence: high. MSVC CRT per-thread data management.
   - Retrieves TLS value; initializes if null via heap alloc + buffer init.
   - Category: crt_util
   - 2 callees: FUN_0058ab58 (heap alloc), FUN_0058e0b4 (buffer init)

**FUN_0058c1b1 — Stream Buffer Lock via Critical Section** (docs/20-math-utilities.md):
   - Confidence: high. Locks CRT stream buffer via critical section for thread-safe I/O.
   - Source file: CRT stream I/O
   - 1 callee: FUN_0058dfea (critsect lazy init + enter) — technically level 5 but closes immediately
   - Effectively leaf in this chain context

**FUN_0058c203 — Address-Range Critical Section Leave** (docs/20-math-utilities.md):
   - Confidence: high. Unlocks CRT stream buffer critical section.
   - Leaf — no further callees

### Level 5 — Fifth-depth callees (deepest leaf)

**FUN_0058ab58 — heap alloc** (docs/20-math-utilities.md):
   - Minimal doc (triage only). Leaf.
   
**FUN_0058e0b4 — Two-Field Initializer** (docs/20-math-utilities.md):
   - Initializes two fields in a struct. Leaf.

**FUN_0058dfea — Critical Section Lazy Init + Enter** (docs/01-engine-architecture.md):
   - Called by FUN_0058c1b1. Lazy-initializes and enters a critical section.
   - 1 callee: FUN_0058e04b (critsect leave) — returns immediately
   - Effectively leaf at this level

---

## Data Flow Summary

```
FUN_004330d0(param_1=list_head, param_2=config_filename)
  │
  ├──→ FUN_00432cf0 → build physics file path from exe dir + filename
  │     └──→ FUN_004b0b10 → get executable base path  [leaf]
  │
  ├──→ FUN_005668b0 → open file (zero-init struct)  [leaf]
  ├──→ FUN_00568620 → allocate read buffer  [leaf]
  ├──→ FUN_0058ba36 → read file content
  │     └──→ [on error] FUN_0058af5c → error ID lookup
  │           ├──→ FUN_0058afd8 → TLS getter (+12)
  │           │     └──→ FUN_0058e0c7 → TLS init (heap alloc + init)
  │           └──→ FUN_0058afcf → TLS getter (+8)
  │                 └──→ FUN_0058e0c7 → TLS init (heap alloc + init)
  │
  ├──→ FUN_00566940 → parse buffer content  [leaf]
  │
  ├──→ [for each node in linked list at param_1+0x1c]
  │     └──→ FUN_00432bf0 → write AutoLoadEntry fields to node  [leaf]
  │
  ├──→ FUN_005668d0 → file close + cleanup
  │     ├──→ FUN_00566b90 → conditional close dispatch
  │     │     ├──→ FUN_00587d02 → close method A (locking guard)
  │     │     │     ├──→ FUN_0058c1b1 → stream lock (critsec)
  │     │     │     └──→ FUN_0058c203 → stream unlock
  │     │     └──→ FUN_005355a0 → close method B  [leaf]
  │     └──→ FUN_00587bcf → free pointer field
  │           └──→ FUN_0058aa6f → heap deallocation  [leaf]
  │
  └──→ FUN_00566b90 → conditional close dispatch (cleanup)
        ├──→ FUN_00587d02 → close method A (locking guard)
        │     ├──→ FUN_0058c1b1 → stream lock (critsec)
        │     └──→ FUN_0058c203 → stream unlock
        └──→ FUN_005355a0 → close method B  [leaf]
```

**Data flowing:**
- param_1: linked list head pointer (config entry nodes at +0x1c)
- param_2: config filename string
- Intermediate: exe directory path (local buffer), read buffer (heap-allocated via FUN_00568620)
- Parse output: linked list at param_1+0x1c populated by FUN_00432bf0 per node
- Error state: stored via TLS (FUN_0058afd8/FUN_0058afcf → FUN_0058e0c7)
- File handle: managed by FUN_00566b90 dispatch (method A or B)

---

## Globals Written

| Address | Name | What |
|---------|------|------|
| PTR_DAT_005c3f84 | Physics filename pointer | Read by FUN_00432cf0 to build file path |
| TLS offsets +8/+12 | Per-thread error state | Written by FUN_0058af5c error ID lookup via FUN_0058afd8/FUN_0058afcf |
| DAT_005e65c0 | Error lookup table base | Read by FUN_0058af5c for error code mapping |

No moddable game-state globals directly written. The chain operates on file handles, heap buffers, TLS error state, and linked-list entries. All moddability is hardcoded.

---

## Notes

- **Depth limit:** Max depth = 6 (seed → FUN_0058ba36 → FUN_0058af5c → FUN_0058afd8 → FUN_0058e0c7 → FUN_0058ab58/FUN_0058e0b4). The rightmost file-close path reaches only depth 4.
- **Convergence points:**
  - FUN_00587d02 (close method A) — called from FUN_00566b90 in both close paths (FUN_005668d0 and FUN_00566b90)
  - FUN_0058e0c7 (TLS init) — called from both FUN_0058afd8 and FUN_0058afcf
- **File open/read/close pipeline:** FUN_005668b0 (open) → FUN_00568620 (alloc) → FUN_0058ba36 (read) → FUN_00566b90/FUN_005668d0 (close) — complete I/O lifecycle
- **Error handling path:** FUN_0058ba36 → FUN_0058af5c (error lookup) → TLS getters → TLS init with heap alloc — error info stored per-thread via MSVC CRT TLS mechanism
- **File close dispatch:** FUN_00566b90 branches on flag at param_1+0x10: 0 → FUN_00587d02 (locking guard, CRT _fclose_lk), non-0 → FUN_005355a0 (stream type check + close)
- **CRT wrappers:** FUN_0058c1b1/FUN_0058c203 wrap MSVC CRT stream locking via critical sections; FUN_0058dfea/FUN_0058e04b are the lower-level critsec enter/leave primitives
- **Known quality issues:**
  - FUN_00568620 (alloc) lacks a proper functions.json entry with summary — confidence cannot be assessed
  - FUN_00432bf0 (AutoLoadEntry Writer) has heading_level 3 in docs/08-file-formats.md with no call_count in functions.json
  - FUN_00566940 (parse) has triage-only coverage with null summary
- **Caller context:** FUN_004330d0 is called by FUN_00433b60 (Add Vehicle Config Entry to Linked List, docs/02-ai-system.md, source: config_manager.cpp) during vehicle config loading
- **Moddability:** Entire chain is hardcoded — no tunable parameters read from config globals. The chain reads physics files but the file content parsing is hardcoded structure.
