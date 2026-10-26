# Chain: Season Database Object Factory — Database Sub-Object Construction Dispatch

Seed: FUN_0047f440  |  System: docs/08-file-formats.md  |  Depth: 1  |  Functions: 20 callees (all leaf constructors)

---

## Overview

Triggered during season DB loading. param_2 index (0–0x1fb, 508 entries) selects which sub-object to construct. Each case allocates a different struct type and calls its constructor. The parent DB struct at param_1 has +0x191c (entryArray[508]) and +0x1fe8 (specialPtr). All 20 callees are leaf constructors — they allocate memory, init fields, return. No deeper call chains exist.

## Call Tree

```
FUN_0047f440 — Season Database Object Factory  [trigger: season DB loading, called by Game::Setup path]
  +-- FUN_00470230 — Object constructor (size 0xec, base season entry) [leaf]
  +-- FUN_00487220 — Aero detail constructor (size 0xe4)              [leaf]
  +-- FUN_004685b0 — Team/track list constructor (size 0x17c)         [leaf]
  +-- FUN_0048c9f0 — Driver/entry list constructor (size 0x454)       [leaf]
  +-- FUN_00469880 — Race/track schedule constructor (size 0x188)     [leaf]
  +-- (15 additional leaf constructors omitted)
```

## Step-by-Step Trace

### Level 0: FUN_0047f440 — Season Database Object Factory

**Trigger:** Season DB loading phase. Called with param_1 pointing to DB struct and param_2 as case index.
**Called by:** Unknown (callers.json has no callers for this seed — entry point in loading chain)
**Purpose:** Factory dispatch — allocates and constructs season DB sub-objects by index.

**Key actions:**
1. Switch on param_2 (index 0–0x1fb, 508 cases)
2. Each case: operator_new(size) + constructor call for specific struct type
3. Stores result pointer in parent DB array at +0x191c[param_2]
4. Index 0x1b4 is special — stores in +0x1fe8

**Data passed to callees:** param_1 (parent DB pointer) forwarded to constructors.

### Level 1: Callees (all leaf constructors)

All 20 callees are leaf constructors with 0 further callees. Key types:
- **FUN_00470230**: Base season entry (0xec) — loads `F1_2002.gdb` via FUN_00566650 (path registry)
- **FUN_004685b0**: Team/track list (0x17c)
- **FUN_0048c9f0**: Driver/entry list (0x454, vtable PTR_FUN_005a6f48)
- **FUN_00469880**: Race/track schedule (0x188)
- **FUN_0046a220**: Team entries (0x350)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0047f440 | param_1 (DB), param_2 (index) | case switch | alloc size, constructor call |
| Each callee | param_1 | memory alloc + init | struct at +0x191c[index] |

## Globals Written in This Chain

None — all writes are to the DB struct fields, not globals.

## Notes

All 20 callees are leaf constructors (no entries in call_graph.json). Chain depth = 1. The function dispatches to specific constructor based on index — it's a classic object factory pattern. Most constructors are ~50-200 lines each with no further calls.

---
