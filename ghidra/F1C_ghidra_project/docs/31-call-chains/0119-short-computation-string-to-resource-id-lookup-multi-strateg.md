# Chain: Short Computation (String-to-Resource-ID Lookup) — Multi-Strategy ID Resolution

Seed: 0x00405050  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 6

---

## Overview

String-to-Resource-ID Lookup resolves a string name to an integer resource ID through three fallback strategies: internal hash table lookup, file read with format lookup, and direct string format conversion. No callers documented — likely a core utility used across the engine during resource binding. The chain covers tokenization, memory allocation for ID tables, file I/O, and string formatting.

## Call Tree

```
FUN_00405050 — Short Computation (String-to-Resource-ID Lookup)  [trigger: resource name resolution]
  +-- FUN_00404fe0 — One-Time Initialization with Atexit Registration
  +-- FUN_00407f10 — Resource ID Lookup by Name String
  +-- FUN_00566810 — [file read/filter check — docs/06]  [leaf]
  +-- FUN_00587f59 — Single Function Call Wrapper (atoi)  [leaf]
  +-- FUN_00407e40 — Resource Node Lookup by String or ID
  +-- FUN_00595ae2 — String Format with 0x40 Size (File Open Wrapper)
```

## Step-by-Step Trace

### Level 0: FUN_00405050 — String-to-Resource-ID Lookup

**Trigger:** Called during resource binding when a string name needs conversion to numeric ID
**Called by:** No callers documented
**Purpose:** Multi-strategy string-to-integer lookup: tries internal table, then file read, then format lookup.

**Key actions:**
1. Calls FUN_00404fe0 — one-time init / tokenize preprocessing of param_1
2. Calls FUN_00407f10 — tries internal ID lookup table
   - If found (!= -1): stores in *param_2, returns 1 (success)
3. If not found: checks string length > 4
   - Calls FUN_00566810 — file read / filter check
   - If success: calls FUN_00587f59 — wrapper (atoi — string to integer conversion)
   - Calls FUN_00404fe0(0) and FUN_00407e40 — second memory allocation / resource lookup
   - If found: reads ID from *(iVar2 + 0x10), stores in *param_2, returns 1
4. Fallback: calls FUN_00595ae2(param_1, 0x8000, 0x100) — string format conversion
   - If found (!= -1): stores in *param_2, returns 1
5. Returns 0 if all strategies fail

**Data passed to callees:** string param_1, output int pointer param_2

### Level 1: FUN_00407f10 — Resource ID Lookup by Name String

**Trigger:** Called first — fastest lookup path
**Purpose:** Searches internal hash/ID table for matching string, returns numeric ID
**Returns:** ID value or -1 if not found

### Level 1: FUN_00407e40 — Resource Node Lookup by String or ID

**Trigger:** Called second — file-backed lookup path
**Purpose:** Searches resource nodes loaded from file for matching string
**Returns:** Pointer to node (+0x10 contains ID)

### Level 1: FUN_00595ae2 — String Format with 0x40 Size

**Trigger:** Called as final fallback
**Purpose:** Direct string-to-uint conversion (format-based)
**Parameters:** param_1 (string), 0x8000 (flags), 0x100 (buffer size)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Strategy 1 | param_1 string | internal table lookup | ID or -1 |
| Strategy 2 | param_1 string | file read → node lookup | ID from node+0x10 |
| Strategy 3 | param_1 string | string format conversion | ID or -1 |
| All | all results | if found: *param_2 = ID | return 1 or 0 |

## Globals Written in This Chain

None directly — writes result to *param_2 (caller-provided output pointer).

## Notes

- Three-tier fallback: memory → file → format conversion — ensures maximum chance of resolution
- FUN_00587f59 is an atoi wrapper — string-to-integer for numeric resource names
- Strategy 2 requires string length > 4 (minimum for meaningful file lookup)
- FUN_00404fe0 is called twice (once for preprocessing, once with arg 0 for cleanup/reset)

---
