# Chain: Exception Destructor with Conditional Free — C++ exception object cleanup

Seed: FUN_0059bacc  |  System: docs/01-engine-architecture.md  |  Depth: 2  |  Functions: 18

---

## Overview

This function implements a standard MSVC++ "scalar deleting destructor" pattern. Called indirectly via C++ exception handling unwind tables (no direct callers in the codebase), it calls a pre-destructor cleanup function (FUN_0059baa3), then conditionally frees the object memory based on a flag in param_2. The pattern matches compiler-generated destructor thunks used in C++ exception handling for stack-allocated or heap-allocated objects.

## Call Tree

```
FUN_0059bacc — Exception Destructor with Conditional Free  [trigger: C++ exception unwind / scope exit]
  |
  +-- FUN_0059baa3 — Pre-Destructor Cleanup  [member cleanup] LEAF
  |
  +-- FUN_00587bcf — Free/Delete Operator  [called 5x, conditional on param_2 & 1]
  |     +-- FUN_0058aa6f — Heap Deallocation (operator delete)  LEAF
  |
  +-- FUN_00581c20 — Cleanup/Destructor  [additional cleanup] LEAF
  |
  +-- FUN_0047aa60 — Array Destructor / Small Destructor  [docs/20 - empty stub] LEAF
```

## Step-by-Step Trace

### Level 0: FUN_0059bacc — Exception Destructor

**Trigger:** C++ exception unwinding via SEH table; no explicit callers in codebase
**Called by:** MSVC compiler-generated exception handling code (0 callers in call_graph.json)
**Purpose:** cleanup + conditional free of exception or heap object

**Key actions:**
1. Calls FUN_0059baa3(param_1) — pre-destructor cleanup
2. If (param_2 & 1) != 0: calls FUN_00587bcf(param_1) — free memory
3. Returns param_1

**Data passed to callees:** param_1 (object pointer) forwarded to all callees

### Level 1: Callees

**FUN_0059baa3 — Pre-Destructor Cleanup:** Performs actual member cleanup before memory is freed. Leaf function.

**FUN_00587bcf — Free/Delete Operator:** Memory deallocation wrapper that calls FUN_0058aa6f (operator delete). Called 5 times from the seed function (appears as 5 separate entries in call_graph, matching 5 member pointer frees).

**FUN_00581c20 — Cleanup/Destructor:** Additional cleanup for specific members. Leaf function.

**FUN_0047aa60 — Array Destructor / Small Destructor:** Empty stub in docs/20-math-utilities.md. No-op.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059baa3 | param_1 (object ptr) | member cleanup | cleaned members |
| FUN_00587bcf | param_1 (object ptr) | free memory | deallocated |
| FUN_0058aa6f | freed ptr | operator delete | heap freed |

## Globals Written

None. Operates entirely on heap-allocated object pointed to by param_1.

## Notes

- **Orphan function:** 0 callers in call_graph.json — called indirectly via MSVC SEH unwind tables
- **Scalar deleting destructor pattern:** matches MSVC++ convention: param_2 bit 0 controls whether to free
- **FUN_00587bcf dominance:** called 5x from seed (once per member pointer), plus FUN_00581c20 called 1x
- **All Level 2 functions are leaves:** max depth 2
- **FUN_0047aa60 is an empty stub** — likely dead code or unused array cleanup path
- **Doc span:** docs/01 (seed), docs/20 (stubs), docs/06 (FUN_00581c20)

---
