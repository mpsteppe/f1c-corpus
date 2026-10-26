# Chain: Exception Destructor with Flag — C++ Exception Cleanup

Seed: 0x0059befd  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 2

---

## Overview

C++ exception destructor with conditional heap free. Triggered during exception unwinding. If flag parameter has bit 0 set, frees the exception object. Returns the exception pointer.

## Call Tree

```
0x0059befd — Exception Destructor with Flag  [trigger: exception unwinding, ~exception()]
  +-- 0x00587bcf — Free Wrapper (thunk to 0x0058aa6f)  [heap free]
```

## Step-by-Step Trace

### Level 0: 0x0059befd — Exception Destructor with Flag

**Trigger:** C++ exception object destruction during stack unwinding.
**Called by:** No callers documented (called by MSVC exception handling machinery).
**Purpose:** exception::~exception(param_1). If param_2 bit 0: free param_1. Return param_1.

**Key actions:**
1. Checks param_2 bit 0
2. If set: calls FUN_00587bcf(param_1) — frees exception object
3. Returns param_1 (for exception handling chain)

**Data passed to callees:** param_1 — exception object pointer.

### Level 1: Leaf callees

**0x00587bcf** — Free Wrapper. Thunk to FUN_0058aa6f. Frees heap memory.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059befd | exception ptr, flag | check bit 0 | conditional free |
| FUN_00587bcf | exception ptr | heap free | memory freed |

## Globals Written in This Chain

None.

## Notes

Standard C++ exception handling pattern. The conditional free (bit 0 flag) suggests the exception object may be stack-allocated (no free) or heap-allocated (free needed). This is typical MSVC C++ exception handling with custom destructor.

---
