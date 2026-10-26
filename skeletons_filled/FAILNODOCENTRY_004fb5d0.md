## FAILNODOCENTRY_004fb5d0 — InitLinkedDampingCoefficients

**Summary:** Initializes two float[8] arrays with values derived from a linked-list traversal. If seed >= 500 fills all entries with 500.0; otherwise walks chain accumulating per-node value, filling array entries whose index exceeds per-node thresholds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_4790 (00404790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x110)+0x110) | 0x110 | R | — | next linked-list node pointer |
| *(this+0x110) | 0x3C | R | — | per-node value increment |
| *(this+0x110) | 0x50 | R | — | fill threshold for array1 |
| *(this+0x110) | 0x54 | R | — | fill threshold for array2 |
| this | 0x3C | R | — | seed/base accumulator value |
| this | 0x110 | R | — | linked-list head pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e91c | flt_59E91C | R | ShortConversionMult [DERIVED] (also: conversion multipliers) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** *(this+0x110) == NULL → skip entirely (arrays unchanged). seed (this+0x3C) >= 500.0 → fast-path fill all 8 entries of both arrays with 500.0 (0x43FA0000). In loop: node or next->next == NULL → stop traversal. Next node == self (*(v1+0x110) == v1) → stop. Accumulator crosses 500.0 → jump to fast-path fill. Per-node: (index+1) < *(node+0x50) for array1 or *(node+0x54) for array2 → skip fill for remaining entries (leave prior values).
