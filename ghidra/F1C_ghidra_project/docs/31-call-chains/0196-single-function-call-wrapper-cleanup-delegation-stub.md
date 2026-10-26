# Chain 195: Single Function Call Wrapper — Cleanup Delegation Stub

Seed: FUN_0059b07a  |  System: docs/01-engine-architecture.md  |  Depth: 2  |  Functions: 12 callees (all cleanup)

---

## Overview

FUN_0059b07a is a trivial cleanup delegation wrapper. It calls FUN_00587b3e(FUN_0047aa60) to register a deferred cleanup callback. All 12 callees in this chain are the standard MSVC cleanup/SEH unwind chain: FUN_00587b3e (Boolean-to-Int Conversion, which registers callbacks), FUN_00587bcf (operator delete), FUN_00581ad0 (CloseHandle + Destroy Linked List), FUN_0047aa60 (Empty Stub), FUN_00583570 (List Destruction with COM Release), FUN_005819c0 (Linked List Destroy), FUN_005861e0 (CloseHandle Wrapper), and FUN_00598aea (conditional cleanup). This is an MSVC atexit-style cleanup chain with no game logic.

## Call Tree

```
FUN_0059b07a — Single Function Call Wrapper  [trigger: cleanup/deinit path]
  +-- FUN_00587b3e — Boolean-to-Int Conversion / Cleanup Dispatcher  [leaf, 155 callers]
  |     +-- FUN_00587bcf — Free Wrapper → FUN_0058aa6f  [leaf, 507 callers total]
  +-- FUN_00587bcf — Free Wrapper (operator delete)  [leaf, called 3x in this chain]
  +-- FUN_00587bcf — Free Wrapper  [duplicate call]
  +-- FUN_00587bcf — Free Wrapper  [duplicate call]
  +-- FUN_00581ad0 — Close Handle + Destroy Linked List + Free Nodes  [leaf]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_0047aa60 — Empty Stub (no-op)  [leaf, 25 callers]
  +-- FUN_00583570 — List Destruction with COM Release  [docs/01]
  |     +-- FUN_005819c0, FUN_005861e0, FUN_0047aa60 — cleanup chain
  +-- FUN_005819c0 — Linked List Destroy with Vtable Destructor Call  [leaf, docs/01]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_005861e0 — CloseHandle Wrapper  [leaf, docs/01]
  +-- FUN_0047aa60 — Empty Stub (duplicate call)  [leaf]
  +-- FUN_00598aea — Conditional Cleanup (vtable reset + destructor)  [docs/01]
  |     +-- FUN_0059a86c — Object Destructor with Ref Count Decrement
  +-- FUN_00587bcf — Free Wrapper (final cleanup)
```

## Step-by-Step Trace

### Level 0: FUN_0059b07a — Single Function Call Wrapper

**Trigger:** Called during module cleanup/deinitialization.
**Called by:** No documented callers (callers.json empty)
**Purpose:** Thunk: FUN_00587b3e(FUN_0047aa60). Registers an empty stub as a deferred cleanup callback.

**Key actions:**
1. Calls FUN_00587b3e(FUN_0047aa60) — registers cleanup callback
2. FUN_0047aa60 is empty stub — no actual cleanup needed
3. Chain includes additional cleanup calls for linked list destruction, handle closing

**Data passed to callees:** None — static registration only.

### Level 1: FUN_00587b3e — Boolean-to-Int Conversion / Cleanup Dispatcher

**Trigger:** Called by seed to register cleanup function.
**Purpose:** atexit-style callback registration. Stores function pointer for deferred cleanup.
**Called by:** 155 callers across the engine — the universal cleanup registration point.

**Key actions:**
1. Stores pointer to FUN_0047aa60 in internal cleanup list
2. Returns immediately

### Level 1: FUN_005819c0 — Linked List Destroy with Vtable Destructor Call

**Trigger:** Part of cleanup chain after FUN_00583570.
**Purpose:** Destroys linked list, calling vtable destructor per node.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059b07a | Cleanup trigger | Call FUN_00587b3e(FUN_0047aa60) | Deferred cleanup registered |
| FUN_00587b3e | FUN_0047aa60 ptr | Store in callback list | Registered |
| FUN_0047aa60 | (none) | Empty stub (no-op) | (none) |
| FUN_00587bcf | Heap pointers | operator delete | Freed memory |

## Notes

- All 12 callees are pure cleanup utilities (docs/01, docs/20)
- No game logic, no globals read/written
- FUN_00587bcf (operator delete wrapper) called 4+ times in this chain alone
- This is archetypal MSVC cleanup stub — common across ~100 similar functions

---
