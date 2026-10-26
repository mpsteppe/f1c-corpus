# Chain: Audio Mixer Read Current Value — Mixer Value Read

Seed: FUN_00564271  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 5

---

## Overview

Reads current audio mixer value with fallback. Tries function pointer call first (FUN_005647d0); if result is non-null returns dereferenced mixer value. On null, falls back to string duplicate (FUN_00564690) and retry wrapper (FUN_00564780).

## Call Tree

```
FUN_00564271 — Audio Mixer Read Current Value  [per-mixer-read]
  +-- FUN_005647d0 — Callback + Check [function pointer call]
  |     +-- FUN_00564a20 — callback dispatch
  |     +-- FUN_005648b0 — Linear Interpolation [cleanup]
  |     +-- FUN_005679a5 — error check
  +-- FUN_005648b0 — Linear Interpolation [fallback cleanup]
  +-- FUN_00564690 — String Malloc + Copy (strdup) [fallback]
  +-- FUN_00564780 — Function Pointer Call with Error Handling [retry]
        +-- FUN_00564a20 — callback dispatch
        +-- FUN_005648c0 — retry handler
        +-- FUN_005649d0 — error handler
```

## Step-by-Step Trace

### Level 0: FUN_00564271 — Audio Mixer Read Current Value

**Trigger:** Called to read current mixer value (no callers in graph).
**Called by:** No callers in graph (likely called from audio update loop FUN_00564390).
**Purpose:** Reads audio mixer value with primary/fallback retry pattern.

**Key actions:**
1. Calls FUN_005647d0 — function pointer call with -1 check
2. If result non-null: returns dereferenced value (mixer value)
3. If null: falls back to FUN_00564690 (strdup) + FUN_00564780 (retry), returns fallback value

### Level 1: FUN_005647d0 — Callback + Check

**Trigger:** Primary path to read mixer value.
**Purpose:** Calls function pointer, checks for -1 (error), returns result or falls through.

**Key actions:**
1. Calls FUN_00564a20 — callback dispatch
2. Calls FUN_005648b0 — cleanup / linear interpolation
3. Calls FUN_005679a5 — error check

### Level 1: FUN_00564690 — String Malloc + Copy (strdup)

**Trigger:** Fallback path when primary returns null.
**Purpose:** Allocates memory and copies string (strdup-like) for fallback value construction.

### Level 1: FUN_00564780 — Function Pointer Call with Error Handling

**Trigger:** Retry path after fallback allocation.
**Purpose:** Calls function pointer with error handling wrapper, retries on failure.

**Key actions:**
1. Calls FUN_00564a20 — callback dispatch
2. Calls FUN_005648c0 — retry handler
3. Calls FUN_005649d0 — error handler

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Primary | — | FUN_005647d0 | mixer value or null |
| Check | result | null check | return or fallback |
| Fallback | — | FUN_00564690 | allocated string |
| Retry | string | FUN_00564780 | fallback value |

## Notes

- 4 callees, small chain with retry pattern.
- Shares FUN_005648b0 between primary and fallback paths.
- FUN_00564690 is tagged as "string allocation and copy" — used in both audio and string contexts.
- Standard try/retry pattern for audio driver queries where device may not be ready.
