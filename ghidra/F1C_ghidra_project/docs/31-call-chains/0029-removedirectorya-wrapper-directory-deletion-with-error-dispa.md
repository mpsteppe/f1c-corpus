# Chain: RemoveDirectoryA Wrapper — Directory Deletion with Error Dispatch

Seed: FUN_0059b9f3  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 12

---

## Overview

Thin wrapper around Win32 RemoveDirectoryA with structured error handling. Calls RemoveDirectoryA, captures GetLastError() on failure, dispatches to error ID lookup (FUN_0058af5c) for range-checked error handling. Also performs chained memory cleanup via linked-list node removal (walking a list and freeing nodes).

## Call Tree

```
FUN_0059b9f3 — RemoveDirectoryA Wrapper  [called from file system cleanup: 0x00499690]
  +-- RemoveDirectoryA  [Win32 API]
  +-- GetLastError  [Win32 API]
  +-- FUN_0058af5c — Error ID Lookup Table  [docs/01: error code → handler]
  |     +-- FUN_0058afd8 — TLS Offset Getter (+12)
  |     +-- FUN_0058afcf — TLS Offset Getter (+8)
  +-- FUN_00587bcf — Free Wrapper (x3)  [docs/01: heap free via FUN_0058aa6f]
  |     +-- FUN_0058aa6f — Heap Deallocation  [docs/20]
  +-- FUN_00582a10 — System/List Cleanup (248 bytes)  [docs/20: node cleanup]
  +-- FUN_00581a80 — Linked List Cleanup (Generic)  [docs/20: list traversal + free]
  +-- FUN_004b0170 — Empty Stub (vtable slot)  [docs/20: no-op]
  +-- FUN_00585fb0 — Linked List Cleanup with Sub-Object Delete  [docs/20]
  +-- FUN_0047aa60 — Empty Stub  [docs/20: short math utility stub]
```

## Step-by-Step Trace

### Level 0: FUN_0059b9f3 — RemoveDirectoryA Wrapper

**Trigger:** Called from file/directory cleanup path (caller: FUN_00499690)
**Purpose:** Win32 RemoveDirectoryA wrapper with error code capture and dispatch.

**Key actions:**
1. Calls RemoveDirectoryA(param_1) — delete directory
2. If fails: GetLastError() → DVar2 = error code
3. Else: DVar2 = 0
4. If DVar2 != 0: FUN_0058af5c(DVar2) → error ID lookup + handling, returns -1
5. Else: return 0
6. Additional linked-list cleanup: FUN_00582a10, FUN_00581a80, FUN_00585fb0

### Level 1: Error Handling and Cleanup

**FUN_0058af5c — Error ID Lookup Table** [docs/01-engine-architecture.md]
- Looks up error code in TLS-offset-based table
- Calls FUN_0058afd8 (TLS +12) and FUN_0058afcf (TLS +8) for thread-local storage access
- Range checks error code before dispatching handler

**FUN_00587bcf — Free Wrapper (called 3 times)** [docs/01-engine-architecture.md]
- Thunk to FUN_0058aa6f (heap deallocation)

**FUN_00582a10 — System/List Cleanup** [docs/20-math-utilities.md]
- 248-byte cleanup routine for system resource lists

**FUN_00585fb0 — Linked List Cleanup with Sub-Object Delete** [docs/20-math-utilities.md]
- Walks linked list, deletes sub-objects, frees nodes

## Globals Written in This Chain

None. All operations are local/parameter-driven.

## Notes

- 12 callees include 3 duplicate calls to FUN_00587bcf (memory free)
- FUN_00582a10, FUN_00581a80, FUN_00585fb0 are secondary cleanup operations beyond the directory deletion
- The stub functions (FUN_004b0170, FUN_0047aa60) are called but do nothing — likely vtable cleanup hooks

---
