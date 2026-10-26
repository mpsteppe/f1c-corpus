# Chain 196: Single Byte Write via Stream — Low-Level File I/O

Seed: FUN_0059b208  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 11 callees

---

## Overview

FUN_0059b208 writes a single byte to a file stream. Guard: returns 0xFFFFFFFF if param_1 == -1 (invalid handle). Extracts low byte, calls FUN_0059b092 (Thread-safe I/O Wrapper) for the actual write, returns result shifted right by 16 bits. Triggered by FUN_0059a3a9 (buffer size query). The write chain goes through thread-safe I/O wrappers, Free/deallocate, linked list cleanup (FUN_00581a80, FUN_005822b0, FUN_00583570, FUN_005870d0), and finally FUN_00598aea (conditional cleanup).

## Call Tree

```
FUN_0059b208 — Single Byte Write via Stream  [trigger: called by FUN_0059a3a9]
  +-- FUN_0059b092 — Stream Write Function / Thread-Safe I/O Wrapper  [docs/20]
  |     +-- FUN_00587bcf — Free/deallocate
  |     +-- FUN_00587bcf — Free/deallocate
  |     +-- FUN_00587bcf — Free/deallocate
  |     +-- FUN_00581a80 — Linked List Cleanup (Generic)  [docs/20]
  |     +-- FUN_00587bcf — Free/deallocate
  |     +-- FUN_005822b0 — Linked-List Free Standard  [docs/20]
  |     |     +-- (leaf, no further callees)
  |     +-- FUN_00583570 — List Destruction with COM Release  [docs/01]
  |     |     +-- FUN_005870d0 — Set Vtable Pointer and Call Init  [docs/20]
  |     |     +-- FUN_00587bcf — Free/deallocate
  |     |     +-- FUN_00587bcf — Free/deallocate
  |     +-- FUN_005870d0 — Set Vtable Pointer and Call Init  [docs/20]
  |     |     +-- FUN_00587510 — memcpy-like with Realloc  [docs/20]
  |     +-- FUN_0047aa60 — Empty Stub  [docs/20]
  |     +-- FUN_00598aea — Object Destructor exception::~exception  [docs/01]
  |           +-- FUN_0059a86c — Object Destructor with Ref Count Decrement
```

## Step-by-Step Trace

### Level 0: FUN_0059b208 — Single Byte Write via Stream

**Trigger:** Called by FUN_0059a3a9 (buffer size query) for low-level byte write.
**Called by:** FUN_0059a3a9
**Purpose:** Writes a single byte to a file stream handle.

**Key actions:**
1. Guard: if param_1 == -1, return 0xFFFFFFFF
2. Extracts low byte from param_2
3. Calls FUN_0059b092 (thread-safe I/O wrapper)
4. Returns result >> 16, or 0xFFFF on failure

**Data passed to callees:** File handle, byte value to write

### Level 1: FUN_0059b092 — Thread-Safe I/O Wrapper

**Trigger:** Called by seed for actual write.
**Purpose:** Thread-safe file I/O with InterlockedIncrement guard and critical section protection.

**Key actions:**
1. Uses InterlockedIncrement on reentrancy guard (DAT_008d5a58)
2. Critical section protection via FUN_0058c1b1/FUN_0058c203
3. Dispatches to FUN_0059b0f5 for actual write
4. Calls cleanup chain: FUN_00587bcf, FUN_00581a80, FUN_005822b0, etc.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059b208 | File handle + byte | Guard check | 0xFFFFFFFF on invalid |
| FUN_0059b092 | Byte value | Thread-safe write | Result >> 16 |
| FUN_00587bcf | Internal ptrs | operator delete | Freed memory |

## Notes

- 11 callees, all cleanup/file I/O utilities
- FUN_00587bcf called 6+ times in this chain
- FUN_005870d0 — Set Vtable Pointer and Call Init — is from docs/20-math-utilities.md
- Cross-system: FUN_00583570 belongs to docs/01-engine-architecture.md (cleanup)

---
