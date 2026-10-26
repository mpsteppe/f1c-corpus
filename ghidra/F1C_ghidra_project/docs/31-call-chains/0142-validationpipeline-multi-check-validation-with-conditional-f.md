# Chain: ValidationPipeline — Multi-check validation with conditional frees

Seed: FUN_0045c400  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 7

---

## Overview

Large validation pipeline with 7 sequential checks and up to 7 conditional frees. Calls init/check functions (FUN_005881c0, FUN_0042e320, FUN_004f34e0, FUN_004f4270), then runs 7 iterations of FUN_00568a60 (weighted running checksum) accumulating results. After validation, frees up to 7 conditional pointers via FUN_00587bcf. Returns AND of all 7 validation flags. Used as a generic parser/validator — called for texture/image parsing (docs/19) and data file parsing (docs/06).

## Call Tree

```
FUN_0045c400 — ValidationPipeline  [trigger: data validation during load/parse]
  +-- FUN_005881c0 — StackProbeAlloca  [stack probe / alloca]  [leaf]
  +-- FUN_0042e320 — SessionStructInit  [session struct init, 3 callees]
  |     +-- FUN_0042e1c0 — [undocumented]
  |     +-- FUN_0042e240 — [undocumented]
  |     +-- FUN_0042e290 — [undocumented]
  +-- FUN_004f34e0 — TireModelDataInit  [tire model data init, 3 callees]
  |     +-- [subtree: 3 callees — docs/10]
  +-- FUN_004f4270 — SVMHDVVehicleFileParser  [.svm/.hdv parser]  [leaf]
  +-- FUN_00568a60 — WeightedRunningChecksumOverFileStream  [7× validation check, 3 callees]
  |     +-- [subtree: 3 callees — docs/20]
  +-- FUN_00587bcf — FreeWrapper  [up to 7× conditional free]  [leaf]
  +-- FUN_0042ddd0 — ScoreSlotDeallocator  [score slot cleanup, 1 callee]
        +-- FUN_0042de20 — [undocumented]
```

## Step-by-Step Trace

### Level 0: FUN_0045c400 — ValidationPipeline

**Trigger:** Data validation during file parsing or texture/scene loading
**Called by:** FUN_0045c0c0 (parser type 1), FUN_004607a0 — 2 callers
**Purpose:** Multi-stage validation pipeline — runs 7 checks against input data, returns pass/fail AND.

**Key actions:**
1. Stack probe via FUN_005881c0 (alloca guard)
2. Calls FUN_0042e320 — session struct initialization (prepares validation context)
3. Calls FUN_004f34e0 — tire model data init (loads reference data for comparison)
4. Calls FUN_004f4270 — .svm/.hdv file parser (reads vehicle setup data for validation)
5. Runs 7× FUN_00568a60() — weighted running checksum over file stream, accumulates into accumulator
6. Frees up to 7 conditional pointers via FUN_00587bcf
7. Calls FUN_0042ddd0 — score slot deallocation (post-validation cleanup)
8. Returns AND of all 7 validation flags

**Data passed to callees:** validation buffer, file stream pointer, accumulator variables

### Level 1: Callees

**FUN_00568a60 — WeightedRunningChecksumOverFileStream (3 callees)**
Runs a weighted checksum computation over data stream — used 7 times sequentially, each call checks a different aspect of the data. Each call returns a pass/fail flag.

**FUN_004f4270 — SVMHDVVehicleFileParser [leaf]**
Parses vehicle .svm/.hdv files — reads setup data used as reference for validation.

**FUN_0042e320 — SessionStructInit (3 callees)**
Initializes a session-related struct used as validation context/work area.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Stack probe | frame size | alloca guard | stack safe |
| Context init | session struct | init 3 callees | context ready |
| Tire ref | tire model | init | reference data |
| File parser | .svm/.hdv | parse | vehicle data |
| 7× checksum | data stream | weighted checksums | 7 flags |
| 7× free | conditional ptrs | free | dealloc |
| Return | 7 flags | AND | pass/fail |

## Notes

- The 7× FUN_00568a60 pattern suggests 7 separate validation criteria checked against the data
- Called in two contexts: texture/image parsing (docs/19-renderer.md) and data file directory parsing (docs/06-session-race-logic.md)
- The weighted running checksum is likely a CRC or hash-based integrity check
- FUN_004f4270 (.svm/.hdv parser) inclusion suggests validation compares against expected vehicle setup values

---
