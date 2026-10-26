# Chain: SceneElementScan — Scene Element Scan with Condition Check

Seed: FUN_0041ff10  |  System: docs/20-math-utilities.md  |  Depth: 3  |  Functions: 6

---

## Overview

Performs scene element scanning with condition checks. No tracked callers — likely called during scene setup. All callees are scene index/lookup utilities: get index, buffer init, element iteration, element operation, and file/filter check.

## Call Tree

```
FUN_0041ff10 — SceneElementScan  [trigger: scene setup, no tracked callers]
  +-- FUN_004c2990 — ConditionalResultSelector  [2 callees]
  |     +-- FUN_004c2850 — Linked List Dereference
  |     +-- FUN_004c11d0 — Element Selector
  +-- FUN_004c2850 — Linked List Dereference  [leaf — called by 0x004c2990 as well]
  +-- FUN_004c1390 — FixedOffsetReturn  [leaf]
  +-- FUN_004c13a0 — IndexValidationStrideCompute  [leaf]
  +-- FUN_004c0a20 — SceneNameLookupBySeason  [2 callees]
  |     +-- FUN_004c3f80 — Scene Filter
  |     +-- FUN_004c4080 — Scene Select
  +-- FUN_00566810 — FileFilterCheck  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0041ff10 — SceneElementScan

**Trigger:** No tracked callers — called during scene setup/scanning
**Called by:** Unknown
**Purpose:** Scans scene elements with condition checks.

**Key actions:**
1. Gets index via FUN_004c2990
2. Initializes buffer via FUN_004c2850/FUN_004c1390/FUN_004c13a0
3. Iterates elements via FUN_004c0a20
4. Performs element operation via FUN_00566810

**Data passed to callees:** Scene buffer pointer, condition parameters.

### Level 1: FUN_004c2990 — ConditionalResultSelector

**Trigger:** Called from scene element scan for index lookup
**Purpose:** Conditional result selector — calls linked list dereference or element selector.

### Level 2: FUN_004c2850 — Linked List Dereference

**Trigger:** Called from ConditionalResultSelector
**Purpose:** Dereferences linked list to get next scene element.

### Level 2: FUN_004c11d0 — Element Selector

**Trigger:** Called from ConditionalResultSelector
**Purpose:** Selects element from scene data.

### Level 1: FUN_004c1390 — FixedOffsetReturn

**Trigger:** Called from scene element scan
**Purpose:** Returns fixed offset from buffer base.

### Level 1: FUN_004c13a0 — IndexValidationStrideCompute

**Trigger:** Called from scene element scan
**Purpose:** Validates index and computes stride for element access.

### Level 1: FUN_004c0a20 — SceneNameLookupBySeason

**Trigger:** Called from scene element scan for element iteration
**Purpose:** Looks up scene name by season index.

**Key actions:**
1. Calls FUN_004c3f80 for scene filtering
2. Calls FUN_004c4080 for scene selection

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0041ff10 | Scene buffer, conditions | Index + iterate + check | Filtered scene elements |
| FUN_004c2990 | Condition | Selector branch | Element pointer or index |
| FUN_004c0a20 | Season index | Name lookup | Scene name string |
| FUN_00566810 | File/filter check | Condition test | Pass/fail for element |

## Notes

- Two callees (FUN_004c2990, FUN_004c0a20) have call_count=2 each (2 sub-callees)
- All other callees are leaf functions (call_count=0)
- FUN_00566810 has no summary in functions.json (null)
- Chain depth limited to level 2 — no complex sub-trees

---
