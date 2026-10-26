# Chain 192: PitRepairStatusDisplay — Part Wear/Cost Formatting for UI

Seed: FUN_004a58b0  |  System: docs/07-pit-system.md  |  Depth: 2  |  Functions: 3 direct

---

## Overview

Formats and displays per-part repair status (part name, wear, repair cost, repair decision) in the pit stop menu. Reads part wear index and coefficients, computes wear percentage, gets part name, formats repair delta (no change/repaired/increased wear), and displays repair decision (repair/do not repair) with cost.

## Call Tree

```
FUN_004a58b0 — PitRepairStatusDisplay  [called per-part when pit UI is open]
  +-- FUN_004a5820 — Nth Valid Part Lookup  [1 callee — gets part name at index]
  |     +-- FUN_004d7570 — [unnamed — part lookup helper]
  +-- FUN_00423a00 — Binary Search in String Table  [1 callee — string copy to MessageBuffer]
  |     +-- FUN_00588410 — String Compare  [comparison for string table search]
  +-- FUN_0058815f — String Format with Buffer Overflow Check  [2 callees — %s/%d formatting]
        +-- FUN_0058d04d — Core Format Engine  [vsnprintf equivalent]
        +-- FUN_0058cf35 — Buffered Write / Overflow Error Handler  [overflow guard]
```

## Step-by-Step Trace

### Level 0: FUN_004a58b0 — PitRepairStatusDisplay

**Trigger:** Called per-vehicle part when the pit stop menu UI is open and displaying repair options.

**Called by:** Pit UI update loop (callers.json shows 0 callers in graph — called directly from UI rendering code).

**Purpose:** Formats and displays per-part repair status (part name, wear, repair cost, repair decision). Used in pit stop menu.

**Key actions:**
1. Reads part wear index from param_1[0x1b] and wear coefficients from param_1[0x16]/[0x18] (double)
2. If param_1[0x5f] (current lap wear) == 0: clears wear percentage display
3. Otherwise: formats `"%s/%d"` with computed wear percentage
4. If DAT_007d0450 == 1: formats cost with `"%4.1f/%s"` using `(wear_index * coeff_a + coeff_b) * _DAT_0059ea40`
5. Otherwise: formats as integer with default format
6. Gets part name via FUN_004a5820(param_1[0x2b]) and copies to MessageBuffer
7. Computes repair delta: param_1[0x3b] vs param_1[0x3c]
   - Equal: `"%d"` (no change)
   - Target < current: `"%d (-%d)"` (repaired)
   - Target > current: `"%d (+%d)"` (more worn)
8. If param_1[0x4a] == 1 (automatic repair): displays blank
9. Otherwise: checks param_1[0x4b] — 0 → "Do Not Repair", 1 → "Repair"
10. Formats repair decision at param_1 + 0x136
11. If param_1[10] != 1 (manual entry): formats cost `"%s: %d"` with part cost

### Level 1: Callees

**FUN_004a5820 — Nth Valid Part Lookup**
- 1 callee (FUN_004d7570)
- Looks up part name string by index
- Filters to Nth valid (non-null) part in the parts array
- Returns part name string for formatting

**FUN_00423a00 — Binary Search in String Table**
- 1 callee (FUN_00588410 — string compare)
- Copies part name string to MessageBuffer (DAT_005ec4cc)
- Searches string table for part name via binary search

**FUN_0058815f — String Format with Buffer Overflow Check**
- 2 callees: FUN_0058d04d (core format engine) + FUN_0058cf35 (overflow handler)
- Formats wear percentage and cost strings with `%s/%d`, `%4.1f/%s`, `%s: %d` patterns
- Safe string formatting with buffer overflow detection

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Wear data | param_1[0x1b], [0x16], [0x18] | Compute wear % | Wear display string |
| Cost display | DAT_007d0450 | Branch: float vs int format | Cost string |
| Part name | param_1[0x2b] | FUN_004a5820 lookup | Part name string |
| Repair delta | param_1[0x3b] vs [0x3c] | Compare | Delta display string |
| Repair decision | param_1[0x4b] | Check 0/1 | "Repair" / "Do Not Repair" |
| Format | all data | FUN_0058815f safe format | Complete UI string at +0xb6/+0x136 |

## Globals Read

| Global | Name | Used by | Purpose |
|--------|------|---------|---------|
| DAT_007d0450 | CostDisplayMode | FUN_004a58b0 | Float vs integer cost format |
| DAT_005ec4cc | MessageBuffer | FUN_00423a00 | Output buffer for formatted text |

## Notes

- All 3 direct callees are leaf functions with shallow sub-trees (depth 2 max)
- Two distinct format modes: float (CostDisplayMode=1, more detailed) and integer (default)
- The repair delta shows clear visual indication of wear change direction
- "Do Not Repair" vs "Repair" mapping from bit flag at param_1[0x4b]
