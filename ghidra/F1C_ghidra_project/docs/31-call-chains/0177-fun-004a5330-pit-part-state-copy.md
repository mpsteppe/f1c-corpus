# Chain 176: FUN_004a5330 — Pit Part State Copy

Seed: FUN_004a5330  |  System: docs/07-pit-system.md  |  Depth: 2  |  Functions: 7

---

## Overview

Copies part setup from source to destination struct during pit stop preparation. Copies data blocks, part name, status, gets part handle, resolves part ID, initializes repair display, cost offsets, and clears decision flags. Called from vehicle setup flow to duplicate part configuration.

## Call Tree

```
FUN_004a5330 — Pit Part State Copy  [called by: vehicle setup / pit preparation]
  +-- FUN_004d7880 — [undocumented]  [leaf]
  +-- FUN_004d7570 — [undocumented]  [leaf]
  +-- FUN_004a57f0 — [undocumented] test function
  |     +-- FUN_004a5820 — Nth Valid Part Lookup
  |           +-- FUN_004d7570 — [undocumented]
  +-- FUN_004a5820 — Nth Valid Part Lookup
  |     +-- FUN_004d7570 — [undocumented]
  +-- FUN_004a5660 — [undocumented]
  |     +-- FUN_004a55e0 — [undocumented]
  +-- FUN_004a56b0 — [undocumented]  [leaf]
  +-- FUN_004a3440 — [undocumented]  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004a5330 — Pit Part State Copy

**Trigger:** Pit stop preparation — needs to copy part setup
**Called by:** FUN_004e5f60
**Purpose:** Copies part data from source to destination, initializes repair state

**Key actions:**
1. Copies data blocks, part name, status via FUN_004d7880
2. Gets part handle via FUN_004d7570
3. Resolves part ID via FUN_004a57f0 → FUN_004a5820 chain
4. Initializes repair display, cost offsets
5. Clears decision flags

**Data passed:** Source struct pointer, destination struct pointer

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| source data | part name/status | FUN_004d7880 | copied to destination |
| part handle | destination | FUN_004d7570 | resolved handle |
| part lookup | source part ID | FUN_004a57f0 → 5820 | Nth valid part |
| decision flags | flags | clear | zeroed flags |

## Notes

- 5 of 7 callees are not in functions.json — all from decompiled_full anonymous corpus
- FUN_004a5820 (Nth Valid Part Lookup) is the only named callee — iterates parts, skips worn
- All callees are shallow (depth ≤ 2)

---
