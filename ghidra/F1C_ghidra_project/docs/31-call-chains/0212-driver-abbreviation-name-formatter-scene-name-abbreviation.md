# Chain: Driver Abbreviation Name Formatter — Scene name abbreviation

Seed: FUN_004c6a10  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: ~10

---

## Overview

Driver Abbreviation Name Formatter (FUN_004c6a10) formats a driver name as an abbreviation (e.g., "M. Schumacher") for display in scene lists and HUD. It reads the driver name from param_1+0x4620, checks for an `Abbreviation` section override in scene data via FUN_005679c0, and either uses the override string (formatted as `"%-13s"`) or generates an abbreviation as `"%c. %-11s"` (first initial + period + first 11 chars of name). Called from FUN_004c6980 (SetDriverName).

## Call Tree

```
FUN_004c6a10 — Driver Abbreviation Name Formatter  [trigger: SetDriverName]
  +-- FUN_00568210 — Audio Channel Stop  [section check]
  |     +-- FUN_00567db0 — Hash Table Lookup by Name  [section search]
  |           +-- FUN_00567d00 — String Hash  [hash]
  |           +-- FUN_00588410 — String Compare  [compare]
  +-- FUN_005679c0 — String-Keyed Linked List Search  [section lookup]
  |     +-- FUN_00499e20 — String Pointer Accessor  [entry read]
  |     +-- FUN_00588410 — String Compare  [compare]
  +-- FUN_00567970 — Data Entry Accessor  [value get]
  +-- FUN_00587c20 — String Search for '.'  [extension strip]
  +-- FUN_0058815f — String Format with Buffer Overflow Check  [format]
  |     +-- FUN_0058d04d — Core Format Engine (vsnprintf)
  |     +-- FUN_0058cf35 — Buffered Write / Overflow Error Handler
  +-- FUN_00589901 — String Append/Format  [append]
  +-- FUN_00423a00 — Binary Search in String Table  [string copy]
        +-- FUN_00588410 — String Compare
```

## Step-by-Step Trace

### Level 0: FUN_004c6a10 — Driver Abbreviation Name Formatter

**Trigger:** Called from FUN_004c6980 (SetDriverName) when driver name is set/changed
**Called by:** FUN_004c6980 (SetDriverName)
**Purpose:** Format driver name as display abbreviation

**Key actions:**
1. Read driver name from param_1+0x4620
2. Check for `Abbreviation` section via FUN_00568210/FUN_005679c0 section lookup
3. If section found: use abbreviation string directly, format as `"%-13s"` (left-aligned, 13 chars)
4. If section not found: strip file extension via FUN_00587c20 (search for '.'), format as `"%c. %-11s"` (initial + period + first 11 chars)
5. Store result at param_1+0x46f8 (max 15 chars, null-terminated at +0x4707)

**Struct offsets:**
| Offset | Field |
|--------|-------|
| +0x4620 | Full driver name (input) |
| +0x46f8 | Formatted abbreviation (output, max 15 chars) |
| +0x4707 | Null terminator |

**Globals:** DAT_005d3214 ("Abbreviation"), DAT_005d3200 ("%c. %-11s"), DAT_005d320c ("%-13s")

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Read name | param_1+0x4620 | String read | driver name |
| Section check | "Abbreviation" | Hash table lookup | section data or null |
| Format | name | sprintf "%-13s" or "%c. %-11s" | abbreviation string |
| Store | abbreviation | String copy to +0x46f8 | formatted abbreviation |

## Notes

- All callees are utility functions — shallowest chain in this batch (max depth 3)
- String comparison uses FUN_00588410 (MSVC CRT string compare equivalent)
- Format uses FUN_0058815f (vsnprintf-like with buffer overflow protection)
- FUN_00587c20 searches for '.' to strip file extension from scene entry names

---
