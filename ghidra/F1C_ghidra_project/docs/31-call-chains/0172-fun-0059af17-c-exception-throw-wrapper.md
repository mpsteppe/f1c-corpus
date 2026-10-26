# Chain 171: FUN_0059af17 — C++ Exception Throw Wrapper

Seed: FUN_0059af17  |  System: docs/01-engine-architecture.md  |  Depth: 2  |  Functions: 12 (but only 4 unique non-leaf paths)

---

## Overview

MSVC C++ exception throw wrapper. Called when game code needs to throw a C++ exception. Prepares exception object, then calls __CxxThrowException_8 to initiate stack unwinding. The 11 cleanup callees are all part of MSVC exception handling infrastructure — they were registered as unwind/cleanup handlers but are NOT directly called by this function. Instead, they are referenced via the throw info block and invoked by the unwinder during stack unwinding. This function does not return (throw terminates execution flow).

## Call Tree

```
FUN_0059af17 — C++ Exception Throw Wrapper  [called by: game code when throwing exceptions]
  +-- FUN_0059af50 — VTable Constructor (exception prep)  [leaf]
  +-- [MSVC Exception Cleanup Handlers — invoked by unwinder, not direct calls]
  |     +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)  [called 3x in throw info]
  |     |     +-- FUN_0058aa6f — heap deallocation function
  |     +-- FUN_00581880 — Linked List Destruction with VTable Release
  |     |     +-- FUN_00587bcf — Free Wrapper
  |     |     +-- FUN_0058aa6f — heap deallocation
  |     +-- FUN_00581c20 — [undocumented]  [leaf]
  |     +-- FUN_00583050 — Destroy Linked List with SEH, Call Destructors
  |     |     +-- FUN_00587bcf — memory free/dealloc (SEH frame)
  |     +-- FUN_005833e0 — Walk Linked List, Call Destructor, Free Nodes (called 2x)
  |     |     +-- FUN_005867b0 — SEH-guarded cleanup
  |     |     +-- FUN_00587bcf — free/delete
  |     +-- FUN_0047aa60 — Empty Stub  [leaf]
  |     +-- FUN_00599796 — Empty Stub  [leaf]
  |     +-- FUN_00598c70 — Null Check with Virtual Dispatch  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0059af17 — C++ Exception Throw Wrapper

**Trigger:** Game code calls throw on a C++ object
**Called by:** Various game functions (0 callers listed = no callers registered in callers.json, likely because __CxxThrowException_8 is an indirect call)
**Purpose:** Prepares and throws a C++ exception

**Key actions:**
1. Calls FUN_0059af50(param_1) — exception object setup
2. Calls __CxxThrowException_8(local_20, &DAT_005bb890) — MSVC throw with throw info block
3. Does not return (throw terminates execution)

**Data passed:** Exception object pointer, throw info descriptor (DAT_005bb890)

### Level 1: FUN_0059af50 — VTable Constructor

**Purpose:** Prepares exception object vtable and type info

**Key actions:**
- Initializes vtable pointer for exception object
- Sets up type info for catch matching

### Level 1: FUN_00587bcf — Free Wrapper

**Purpose:** Memory deallocation during unwind cleanup
**Called 3 times** in the throw info block

**Key actions:**
- Calls FUN_0058aa6f for heap deallocation

### Level 1: FUN_00581880 — Linked List Destruction with VTable Release

**Purpose:** Destroys linked list, calls vtable release on each node

**Key actions:**
- Calls FUN_00587bcf (free wrapper)
- Calls FUN_0058aa6f (heap deallocation)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| param_1 | exception object ptr | vtable init via FUN_0059af50 | initialized exception |
| local_20, DAT_005bb890 | throw info block | __CxxThrowException_8 | stack unwinding begins |

## Notes

- This is MSVC CRT infrastructure — no game logic
- The 9 non-FUN_0059af50 callees are cleanup handlers registered in the throw info descriptor, not direct calls from this function
- They only execute if an exception propagates through a frame that allocated those resources
- FUN_00587bcf appears 5 times across the tree (3 direct + 2 indirect) — shared free utility
- 4 callees are empty stubs (FUN_0047aa60, FUN_00599796) or simple checks (FUN_00598c70)

---
