# Chain 183: ObjectInitWithVTable — C++ Constructor + Initialization Chain

Seed: FUN_0059b038  |  System: docs/01-engine-architecture.md  |  Depth: 3  |  Functions: 9 unique

---

## Overview

C++ object constructor. Calls base class initializer (FUN_0059ae7d) which triggers an SEH initialization chain (FUN_0058a5d8 → FUN_0059bf56 → FUN_005993af → FUN_0059a9ca), then sets the vtable pointer to PTR_LAB_005b9d8c. Additional memory cleanup/linked list functions are part of global initializer sequencing, not the constructor itself.

## Call Tree

```
FUN_0059b038 — ObjectInitWithVTable  [called during global object construction]
  +-- FUN_0059ae7d — C++ Object Constructor with Vtable  [base class init]
  |     +-- FUN_0058a5d8 — SEH init  [SEH frame setup]
  |           +-- FUN_0059bf56 — Source setup  [initialization source config]
  |                 +-- FUN_005993af — Init  [core init logic]
  |                       +-- FUN_0059a9ca — Field init  [field-level initialization]
  +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)  [memory free]
  +-- FUN_00581a80 — Linked List Cleanup (Generic)  [global list cleanup]
  +-- FUN_005822b0 — Linked-List Free Standard  [list deallocation]
  +-- FUN_005834c0 — List Destruction with Virtual Release  [vtable-based list dtor]
  +-- FUN_00586170 — Handle Close & Linked List Cleanup  [handle management]
  +-- FUN_0047aa60 — Empty Stub  [placeholder]
  +-- FUN_00598aea — Vtable Setter  [sets PTR_FUN_005b9bb4, calls FUN_0059a86c]
  +-- FUN_0059a9c2 — Single Function Call Wrapper  [indirect call helper]
```

## Step-by-Step Trace

### Level 0: FUN_0059b038 — ObjectInitWithVTable

**Trigger:** Called during global object construction at startup or during a specific class instantiation.

**Called by:** Various init functions (referenced from docs/01-engine-architecture.md triage line 7047, called from exception/SEH init sequence).

**Purpose:** C++ constructor initializer: calls a base class setup function then sets vtable pointer.

**Key actions:**
1. Calls FUN_0059ae7d(param_2) — base/child class constructor
2. Sets `*param_1 = &PTR_LAB_005b9d8c` — assigns vtable pointer for this class
3. Additional callees (FUN_00587bcf, FUN_00581a80, etc.) are linked via the constructor's initialization list

**Data passed to callees:** param_1 (object pointer), param_2 (constructor argument)

### Level 1: FUN_0059ae7d — C++ Object Constructor with Vtable

**Trigger:** Called from FUN_0059b038 as base class initializer.

**Purpose:** Initializes base class components, sets up SEH frame, calls derived initialization chain.

**Key actions:**
1. Calls FUN_0058a5d8 — SEH frame init (exception handling setup)
2. Calls FUN_0059bf56 — source configuration
3. Calls FUN_005993af — core initialization logic
4. Calls FUN_0059a9ca — field-level init (final step)

### Level 2: Init Chain

**FUN_0058a5d8 — SEH Init**
- Sets up structured exception handling frame for the constructor
- Ensures cleanup on exception during construction

**FUN_0059bf56 — Source Setup**
- Configures initialization source data
- Intermediate step in the four-stage init sequence

**FUN_005993af — Init**
- Core initialization logic
- Allocates/initializes class member fields

**FUN_0059a9ca — Field Init**
- Final field-level initialization
- Sets default values for class members

### Level 0 Additional Callees (Global Initializer Context)

**FUN_00587bcf — Free Wrapper**
- Thunk to FUN_0058aa6f (memory free)
- Used for cleanup/release of previously allocated memory

**FUN_00581a80 — Linked List Cleanup (Generic)**
- Generic cleanup for linked list structures
- Walks list nodes, calls deallocation per node

**FUN_005822b0 — Linked-List Free Standard**
- Standard linked list deallocation
- Frees all nodes in a linked list

**FUN_005834c0 — List Destruction with Virtual Release**
- Vtable-based list destruction
- Calls virtual release method per node before freeing

**FUN_00586170 — Handle Close & Linked List Cleanup**
- Handle resource cleanup
- Closes system handles and cleans up linked lists

**FUN_0047aa60 — Empty Stub**
- No functional logic
- Placeholder for future extension

**FUN_00598aea — Vtable Setter**
- Sets vtable to PTR_FUN_005b9bb4
- Calls FUN_0059a86c (further init)
- Part of sibling class constructor

**FUN_0059a9c2 — Single Function Call Wrapper**
- Calls another function indirectly
- Utility wrapper for function dispatch

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059b038 | param_1, param_2 | Call base ctor | Object partially initialized |
| FUN_0059ae7d | param_2 | SEH init → source → init → field | Base class ready |
| *param_1 = vtable | vtable ptr | Assign | Object fully constructed |

## Notes

- The chain demonstrates the 4-stage init pattern: SEH → source → init → field
- FUN_00587bcf appears 3 times in the raw call graph (duplicate entries from Ghidra decompilation artifacts)
- The vtable pointer assignment at PTR_LAB_005b9d8c identifies the specific class being constructed
- Several callees (FUN_00587bcf, FUN_00581a80, etc.) are likely called during exception cleanup or global init sequencing, not direct constructor body calls

---
