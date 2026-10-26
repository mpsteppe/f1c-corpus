# Chain: Exception Destructor — C++ Exception Cleanup / Unwind

Seed: FUN_0059aeda  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 7

---

## Overview

MSVC C++ exception handling destructor. Called during stack unwinding when an exception is thrown. Frees allocated memory via FUN_00587bcf (free wrapper thunk) and destroys linked-list based objects. Part of the compiler-generated exception handling infrastructure, not game logic.

## Call Tree

```
FUN_0059aeda — Exception Destructor  [trigger: C++ exception unwind]
  +-- FUN_0058a5d8 — SEH Handler Init  [SEH init: leaf]
  +-- FUN_005993af — Reference Count Decrement with Conditional Free  [ref count]
  +-- FUN_00587bcf — Free Wrapper (thunk to FUN_0058aa6f)  [heap free: docs/01]  [×3]
  |     +-- FUN_0058aa6f — Heap Deallocation Function  [docs/20]
  +-- FUN_00581820 — Linked List Destroy + CloseHandle  [linked list: docs/01]
  +-- FUN_00581b30 — (unknown)  [linked list sub-destroy]
  +-- FUN_005834c0 — List Destruction with Virtual Release  [list dtor: docs/01]
```

## Step-by-Step Trace

### Level 0: FUN_0059aeda — Exception Destructor

**Trigger:** C++ exception throw (unwind).
**Called by:** [no callers recorded — called by MSVC EH runtime]
**Purpose:** Exception-time cleanup — free heap allocations and destroy linked-list objects.

**Key actions:**
1. Calls FUN_0058a5d8 to init SEH handler structures
2. Calls FUN_005993af to decrement ref count with conditional free
3. Calls FUN_00587bcf (3×) to free heap memory via thunk to FUN_0058aa6f
4. Calls FUN_00581820 to destroy linked list and close OS handles

**Data passed to callees:** exception object pointer, cleanup context.

### Level 1: FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)

**Trigger:** Called 3× from exception destructor.
**Called by:** FUN_0059aeda.
**Purpose:** MSVC heap deallocation — operator delete wrapper.

**Key actions:**
1. Thunks to FUN_0058aa6f (heap deallocation)
2. No additional game logic — pure memory management

### Level 1: FUN_00581820 — Linked List Destroy + CloseHandle

**Trigger:** Called once for linked-list type member.
**Called by:** FUN_0059aeda.
**Purpose:** Destroys a linked list structure and closes associated OS handle.

**Key actions:**
1. Iterates linked list nodes, destroys each via FUN_00581b30/FUN_005834c0
2. Calls CloseHandle for any OS handle stored in the structure

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059aeda | exception object | cleanup dispatch | memory freed |
| FUN_00587bcf (×3) | heap ptr | free | deallocated |
| FUN_00581820 | linked list head | iterate + destroy | list freed + handles closed |

## Globals Written in This Chain

None. Pure CRT/MSVC infrastructure.

## Notes

- Not game logic — part of MSVC exception handling (CXXEH).
- Appears in decompiled_full_index_final.md as "Sys/ExceptionDtor".
- FUN_00587bcf is a thunk (unconditional jump) to FUN_0058aa6f (heap deallocation).

---
