# Chain 40: File I/O Forwarding Wrapper — Simple forward to FUN_0059c127

Seed: FUN_0059bae8  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 10 callees

---

## Overview

Pure forwarding wrapper — calls FUN_0059c127(param_1, param_2[0], param_2[1], 0) which then dispatches through a chain of thunks and SEH handlers. Effectively a file I/O shim layer.

## Call Tree

```
FUN_0059bae8 — File I/O Forwarding Wrapper  [trigger: file I/O call]
  +-- FUN_0059c127 — Thread-Safe Wrapper  [thread-safe dispatch]
  |     +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)  [cleanup]
  |     +-- FUN_00582190 — [254 bytes, undocumented]  [file I/O operation]
  |     +-- FUN_0047aa60 — Empty Stub  [placeholder]
  |     +-- FUN_00583270 — Linked List Destructor with VTable Cleanup  [cleanup]
  |     |     +-- FUN_00587bcf — Free Wrapper  [free]
  |     +-- FUN_00583650 — Single Function Call Wrapper  [dispatch]
  |     |     +-- FUN_00587bcf — Free Wrapper  [free]
  |     +-- FUN_00586170 — Handle Close & Linked List Cleanup  [close handle]
  |     |     +-- FUN_00587bcf — Free Wrapper  [free]
  |     +-- FUN_00585fb0 — Linked List Cleanup with Sub-Object Delete  [cleanup]
  |     |     +-- FUN_00587bcf — Free Wrapper  [free]
  |     +-- FUN_00599796 — Empty Stub  [MSVC EH placeholder]
  |     +-- FUN_0059ac3f — VTable Pointer Setter  [vtable setup]
```

## Step-by-Step Trace

### Level 0: FUN_0059bae8 — File I/O Forwarding Wrapper

**Trigger:** File I/O call from higher-level file operations.
**Called by:** Orphan (no callers recorded).
**Purpose:** Calls FUN_0059c127(param_1, param_2[0], param_2[1], 0).

**Key actions:** Single call to FUN_0059c127 with extracted parameters.

### Level 1: FUN_0059c127 — Thread-Safe Wrapper

Thread-safe wrapper that dispatches through SEH-protected chain of thunks, destructors, and cleanup handlers. Callees include FUN_00587bcf (free wrapper, appears 5+ times in chain), FUN_00583270 (linked list destructor), FUN_00586170 (handle close), FUN_00585fb0 (list cleanup).

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0059bae8 | param_1, param_2 | Forward to FUN_0059c127 | dispatch |
| FUN_0059c127 | forwarded params | SEH-protected dispatch | file operation result |

## Globals Written in This Chain

None.

## Notes

- Trivial forwarding wrapper — key logic is in FUN_0059c127
- FUN_00587bcf appears 5+ times as cleanup/free handler throughout the chain
- `hardcoded` — no configurable fields

---
