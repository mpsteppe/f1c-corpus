# Chain: Resource Lookup or Create — String-Keyed Resource Pool Management

Seed: FUN_0049a3b0  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 6

---

## Overview

[PARTIAL — not documented in docs/] Looks up a resource by ID/name in a linked list or creates a new entry. Uses string operations (FUN_00589901, FUN_00566650), ID-based list traversal (FUN_0049a520) with character-to-index conversion (FUN_0049a330) and string pointer dereference (FUN_0049a2b0). Initializes new entries with alternating 0/-1 pattern (FUN_0049a250). Forwarding wrapper (FUN_0049a2e0). Probably part of the resource/asset management system.

## Call Tree

```
FUN_0049a3b0 — Resource Lookup or Create  [trigger: resource request by name/ID]
  +-- FUN_00589901 — String Append/Format  [string op: docs/20]
  +-- FUN_0049a520 — ID-Based List Traversal with Comparison  [list search: docs/20]
  |     +-- FUN_00589901 — String Append/Format  (shared)
  |     +-- FUN_0049a330 — Char-to-Index Converter  [A→0..Z→25]
  |     +-- FUN_0049a2b0 — String Pointer Dereference  [docs/19]
  |     +-- FUN_00588410 — String Compare Helper  [docs/06]
  +-- FUN_0049a330 — Char-to-Index Converter  [A-Z→0-25, else -1: docs/20]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [path registry: docs/20]
  +-- FUN_0049a250 — Field Initializer (0/-1 pattern)  [init 7 fields: docs/20]
  +-- FUN_0049a2e0 — Forwarding Call Wrapper  [delegate: docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_0049a3b0 — Resource Lookup or Create

**Trigger:** Resource request by string name or ID.
**Called by:** [no callers recorded — likely dispatcher-based].
**Purpose:** [PARTIAL] Looks up a resource in a pool, creates new entry if not found.

**Key actions:**
1. Calls FUN_00589901 for string append/format operation
2. Calls FUN_0049a520 for ID-based list traversal with comparison
3. Converts first char to index (A-Z → 0-25) via FUN_0049a330
4. Copies string via FUN_00566650 (realloc-capable copy)
5. Initializes 7 fields with alternating 0, -1 pattern via FUN_0049a250
6. Delegates via forwarding wrapper FUN_0049a2e0

**Data passed to callees:** string name/ID pointer, resource pool handle.

### Level 1: FUN_0049a520 — ID-Based List Traversal with Comparison

**Trigger:** Called for pool search.
**Called by:** FUN_0049a3b0.
**Purpose:** Traverses resource list comparing IDs.

**Key actions:**
1. Calls FUN_00589901 for string processing
2. Converts char to index via FUN_0049a330
3. Dereferences string pointer via FUN_0049a2b0
4. Compares strings via FUN_00588410

### Level 1: FUN_0049a250 — Field Initializer (0/-1 pattern)

**Trigger:** Called for new resource entry initialization.
**Called by:** FUN_0049a3b0.
**Purpose:** Initializes 7 fields with alternating 0, -1 pattern.

**Key actions:**
1. Sets fields at offsets 0, 1, 2, 3, 4, 5, 6
2. Pattern: 0, -1, 0, -1, 0, -1, 0

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0049a3b0 | resource name string | lookup or create | resource handle/entry |
| FUN_0049a520 | list head + ID | traversal + compare | match or null |
| FUN_0049a330 | first char | ASCII→index | 0-25 or -1 |
| FUN_0049a250 | new entry ptr | init 7 fields | initialized entry |

## Globals Written in This Chain

None identified.

## Notes

- [PARTIAL] — function lacks a full doc entry in any docs/ file.
- Alternating 0/-1 init pattern suggests a linked list node or small struct with sentinel markers.
- Char-to-index conversion (A-Z → 0-25) suggests name-based resource buckets.
- String copy with realloc (FUN_00566650) indicates dynamic name storage.

---
