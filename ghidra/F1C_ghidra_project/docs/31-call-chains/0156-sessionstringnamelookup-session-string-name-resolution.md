# Chain: SessionStringNameLookup — Session String/Name Resolution

Seed: FUN_004122c0  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: 4

---

## Overview

Triggered from two callers in the text/UI rendering pipeline (`FUN_00411bf0` and `FUN_00411e90`). Resolves string references for vehicle/player slots based on game mode and indexing parameters. Callees handle linked list indexed access, string copy with realloc, and text attribute lookup.

## Call Tree

```
FUN_004122c0 — SessionStringNameLookup  [trigger: text/UI rendering]
  +-- FUN_00415650 — LinkedListIndexedAccessor  [leaf]
  +-- FUN_00566650 — StringCopyWithBufferRealloc  [leaf]
  +-- FUN_00415550 — LinkedListIndexScannerWithValidation  [1 callee]
  |     +-- FUN_00566810 — Validation/Test Function
  +-- FUN_004134d0 — TextAttributeLookupFormat1  [2 callees]
        +-- FUN_00415680 — Attribute Table Lookup
        +-- FUN_00566650 — StringCopyWithBufferRealloc
```

## Step-by-Step Trace

### Level 0: FUN_004122c0 — SessionStringNameLookup

**Trigger:** Called from FUN_00411bf0 (text/UI rendering) and FUN_00411e90
**Called by:** FUN_00411bf0 — text/UI rendering, FUN_00411e90
**Purpose:** Resolves string reference for vehicle/player slot based on game mode and indexing.

**Key actions:**
1. Resolves target struct via FUN_00415650(param_3)
2. If DAT_007d0398 == 0 and conditions met: computes offset into vehicle array (DAT_008ac394, stride 0x424)
3. Selects one of 8 string pointer offsets based on params
4. Copies string metadata, returns comparison result

**Data passed to callees:** Target struct pointer, string index parameters.

### Level 1: FUN_00415650 — LinkedListIndexedAccessor

**Trigger:** Called from name lookup for struct resolution
**Purpose:** Accesses linked list by index to resolve target struct.

### Level 1: FUN_00566650 — StringCopyWithBufferRealloc

**Trigger:** Called from name lookup (and from FUN_004134d0)
**Purpose:** Copies string with buffer reallocation as needed.

### Level 1: FUN_00415550 — LinkedListIndexScannerWithValidation

**Trigger:** Called from name lookup
**Purpose:** Scans linked list with index validation.

### Level 2: FUN_00566810 — Validation/Test Function

**Trigger:** Called from index scanner
**Purpose:** Validation test for list scanning.

### Level 1: FUN_004134d0 — TextAttributeLookupFormat1

**Trigger:** Called from name lookup
**Purpose:** Looks up text formatting attribute from table indexed by FUN_00415680.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004122c0 | param_3, string index | Struct resolve + offset compute | String reference result |
| FUN_00415650 | List index | Linked list access | Target struct pointer |
| FUN_00566650 | Source string | Copy with realloc | New string buffer |
| FUN_004134d0 | Attribute index | Table lookup | Text attribute value |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d0398 | (mode flag) | FUN_004122c0 (reader) | Mode check for vehicle array |
| DAT_008ac394 | VehicleArray | FUN_004122c0 (reader) | Vehicle array base (stride 0x424) |

## Notes

- FUN_004134d0 shares FUN_00566650 with the seed (string copy utility)
- Chain depth: max 3 (seed → FUN_004134d0 → FUN_00415680)
- FUN_00415680 (Attribute Table Lookup) has no call_graph entry (leaf)
- All callees are data access/fetch utilities — no game logic mutation

---
