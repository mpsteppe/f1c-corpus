# Chain: Strlen + Alloc + Copy Constructor Pattern — C++ String Copy Construction

Seed: FUN_0059bf56  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 11 callees

---

## Overview

FUN_0059bf56 is a C++ string copy constructor utility. Allocates memory and copies a string, or directly assigns pointer for empty strings (borrowed reference, no copy). Called from source setup and string copy helper contexts (docs/01-engine-architecture.md). Sets string object vtable to PTR_FUN_005b9dc0, reads source string length at param_2+8, stores in param_1[2]. If length==0, directly copies pointer from param_2+4 (no allocation). Else calls _strlen, operator_new(len+1), and FUN_0058fca0 (memcpy/strcpy). Returns param_1. Callees are all memory/cleanup functions: string copy (FUN_0058fca0), cleanup trampoline (FUN_00506ccc), free/delete (FUN_00587bcf, FUN_0057bc70, FUN_00581a20, FUN_00583270, FUN_005833e0), and destructors (FUN_004b0170, FUN_00499ae0, FUN_00599be5).

## Call Tree

```
FUN_0059bf56 — Strlen + Alloc + Copy Constructor  [trigger: string copy construction]
  +-- FUN_0058fca0 — String/Memory Copy  [memcpy/strcpy implementation]
  +-- FUN_00506ccc — Cleanup Trampoline  [cleanup redirect]
  +-- FUN_00587bcf — Free/Delete Wrapper  [memory release]
  +-- FUN_0057bc70 — Cleanup Call  [subsystem cleanup]
  +-- FUN_00581a20 — Cleanup Call  [subsystem cleanup]
  +-- FUN_00583270 — Cleanup Call  [subsystem cleanup]
  +-- FUN_00587bcf — Free/Delete Wrapper  [duplicate entry - thunk]
  +-- FUN_004b0170 — Empty Stub (vtable slot)  [game state update]
  +-- FUN_005833e0 — Linked List Destructor  [list cleanup]
  +-- FUN_00499ae0 — Network/Subsystem Cleanup  [network cleanup]
  +-- FUN_00599be5 — Conditional Destructor  [conditional cleanup]
```

## Step-by-Step Trace

### Level 0: FUN_0059bf56 — Strlen + Alloc + Copy Constructor

**Trigger:** Called during string copy/setup operations from docs/01-engine-architecture.md
**Called by:** Various — string copy helper (FUN_005993af), source setup (FUN_0059ae7d)
**Purpose:** C++ string copy constructor — allocate + copy, or borrow reference for empty strings

**Key actions:**
1. Sets `*param_1 = &PTR_FUN_005b9dc0` (vtable pointer)
2. Reads `param_2 + 8` (string length sentinel)
3. Stores length in `param_1[2]`
4. If length == 0: copies pointer from `param_2 + 4` (borrowed reference, no allocation)
5. Else: calls _strlen(param_2+4), operator_new(len+1), FUN_0058fca0 (copy), stores result in param_1[1]
6. Returns param_1

### Level 1: Key Callees

**FUN_0058fca0 — String/Memory Copy**
- Low-level memcpy/strcpy implementation
- Copies string data from source buffer to newly allocated buffer

**FUN_00587bcf — Free/Delete Wrapper**
- Thunk to FUN_0058aa6f — memory deallocation
- Called for cleanup when string objects are destroyed

**FUN_005833e0 — Linked List Destructor**
- Destructor for linked list nodes
- Part of the memory management subsystem

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059bf56 | param_2 (source string) | Read length at +8 | Check if empty |
| If non-empty | strlen(param_2+4) | operator_new(len+1) | Allocated buffer |
| If non-empty | Source data | FUN_0058fca0 copy | Buffer filled |
| Return | — | — | param_1 with vtable + data ptr + length |

## Globals Written in This Chain

None — pure utility function. Operates on struct pointers only.

## Notes

- Empty string optimization: when length==0, directly copies pointer without allocation (shallow/borrowed reference)
- Vtable PTR_FUN_005b9dc0 enables standard C++ string interface
- Multiple cleanup/destructor callees suggest this string type is used across many subsystems
- Cross-system: called from engine architecture (docs/01) for string setup

---
