# Chain: Camera View System — Camera Setup and Allocation

Seed: FUN_00408e20  |  System: docs/09-track-system.md  |  Depth: 1-2  |  Functions: 13 callees

---

## Overview

Initializes camera views during scene load. Two-pass: first pass reads scene file for up to 32 camera definitions (matching SWINGMAN/COCKPIT/TVCOCKPIT/NOSECAM/LOCALCAM), second pass allocates camera objects. Calls FUN_00408870 to set pit/2SEATER/3SEATER cameras.

## Call Tree

```
FUN_00408e20 — Camera View System  [trigger: scene file loading, camera setup phase]
  +-- FUN_005881c0 — Init routine                                    [leaf]
  +-- FUN_005668b0 — File open                                       [leaf]
  +-- FUN_00456170 — Camera object allocator (200 bytes each)        [leaf]
  +-- FUN_00566b20 — File check                                      [depth 1: HAS 0 callees]
  +-- FUN_00566cc0 — File tokenizer                                  [depth 1: HAS 0 callees]
  +-- FUN_005651b0 — Line read from file                             [leaf]
  +-- FUN_00565520 — Field read from file                            [leaf]
  +-- FUN_00588410 — String compare (byte string)                    [leaf]
  +-- FUN_004562f0 — Camera init from file data                      [leaf]
  +-- FUN_00457000 — Camera data setup                               [depth 1: HAS 0 callees]
  +-- FUN_00408870 — Pit/2seater/3seater camera positions            [depth 1: HAS 0 callees]
  +-- FUN_00456080 — Camera field setter                             [leaf]
  +-- FUN_005668d0 — File close                                      [depth 1: HAS 0 callees]
```

## Step-by-Step Trace

### Level 0: FUN_00408e20 — Camera View System

**Trigger:** Scene load → camera manager initialization. Called during track/scene setup.
**Called by:** Unknown (callers.json has no callers — likely called from scene loading chain)
**Purpose:** Read scene file camera definitions, allocate camera objects, set up fixed cameras.

**Key actions:**
1. First pass: read scene file for up to 32 camera defs via FUN_004562f0
2. String-compare chain matches 5 named types (SWINGMAN, COCKPIT, TVCOCKPIT, NOSECAM, LOCALCAM)
3. Second pass (param_2 != 0): allocate camera objects (200 bytes each):
   - +0x1c: SWINGMAN (TV broadcast cam)
   - +0x14: COCKPIT
   - +0x18: TVCOCKPIT
   - +0x10: NOSECAM
   - +0x20: ExtraCamArray (count × 200 bytes)
4. Calls FUN_00408870 for pit/2seater/3seater camera positions
5. Reads DAT_005ea510 flag for additional camera setup

**Data passed to callees:** camera manager struct pointer, scene file data.

### Level 1: Selected Callees

- **FUN_00408870 (pit/camera pos):** Allocates and positions 4 fixed cameras: 2SEATER, 3SEATER, LEFT_OF_PITS, RIGHT_OF_PITS. Each 200 bytes, initialized with hardcoded position/rotation/scale values. Calls FUN_00456fb0 to finalize.
- **FUN_00566cc0 (file token):** INI tokenizer — reads tokens from scene file buffer.
- **FUN_00457000 (camera data setup):** Sets camera name (+0x40) and count (+0x44) fields.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00408e20 | camManager ptr, scene file | read+parse | camera objects allocated |
| FUN_00566cc0 | file buffer | tokenize | tokens |
| FUN_004562f0 | tokens | match 5 types | camera type IDs |
| FUN_00408870 | camManager ptr | alloc 4 fixed cams | pit/2seater/3seater cams |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005ea510 | ExtraCamFlag | FUN_00408e20 | triggers additional cam setup |

## Notes

All 13 callees are shallow (leaf or depth-1). Main complexity is in the string-matching switch chain and the two-pass allocation pattern.

---
