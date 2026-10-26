# Chain: Vehicle Setup File Writer — INI-Style Setup File Save

Seed: 0x0042fd00  |  System: docs/10-vehicle-physics.md  |  Depth: 2  |  Functions: 7

---

## Overview

Called from setup save UI flow (0x00432220, 0x00433b60) or gear field readers (0x0059d822). Writes vehicle setup parameters to INI-format text file with sections [SUSPENSION], [CONTROLS], [ENGINE], [DRIVELINE], per-wheel sections, [BASIC]. On file open failure, logs error via assert+error logger. All callees are file I/O or error utilities — 6 leaf functions + 1 assert with 2 sub-callees.

## Call Tree

```
0x0042fd00 — Vehicle Setup File Writer  [trigger: user saves custom setup in garage]
  +-- 0x005668b0 — file open
  +-- 0x00566940 — file status check
  +-- 0x00566c30 — section/value write  [called 50+ times]
  +-- 0x00566b90 — file close
  +-- 0x005668d0 — cleanup
  +-- 0x004d7a50 — String Split Loop / assert  [error: "Failed to open..."]
  |     +-- 0x00587c20 — [undocumented leaf]
  |     +-- 0x004d7aa0 — error logging
  +-- 0x004d7aa0 — error logging
```

## Step-by-Step Trace

### Level 0: 0x0042fd00 — Vehicle Setup File Writer

**Trigger:** User saves custom setup in garage UI
**Called by:** 0x00432220 (SettingsCopy, docs/10), 0x0059d822 (gear field reader), 0x00433b60 (setup copy)
**Purpose:** Writes setup parameters to INI-format file

**Key actions:**
1. Opens file in write mode via 0x005668b0/0x00566940
2. On failure: calls 0x004d7a50 (assert) + 0x004d7aa0 (error logging), returns -1
3. Writes section headers and values via 0x00566c30 (50+ calls):
   - [Notes]: driver notes string at +0x68
   - [SUSPENSION]: anti-sway, toe-in, caster, track bar, 3rd spring, packer, bump, rebound
   - [CONTROLS]: steer lock, rear brake, brake pressure, handbrake
   - [ENGINE]: rev limit, engine map, engine brake map
   - [DRIVELINE]: gear 1-8 settings, diff pump/power/coast/preload
   - [FRONTLEFT]-[REARRIGHT]: camber, pressure, packer, spring, ride height, bump/rebound, brake disc/pad
   - [BASIC]: downforce, balance, ride, gearing floats, custom bool
4. Closes file via 0x00566b90/0x005668d0

**Struct offsets:** param_1 vehicle setup object — 50+ fields at documented offsets (see docs/10-vehicle-physics.md, docs/13-struct-offsets.md)

**Data passed to callees:** file handle, section name strings, integer/float values

### Level 1: 0x004d7a50 — String Split Loop / assert

**Trigger:** Called on file open failure
**Called by:** 0x0042fd00 (Vehicle Setup File Writer)
**Purpose:** Assert/error display with string splitting

**Key actions:**
1. Calls 0x00587c20 (undocumented)
2. Calls 0x004d7aa0 (error logging)

### Level 1: 0x00566c30 — section/value write

**Trigger:** Called 50+ times per setup save
**Called by:** 0x0042fd00
**Purpose:** Writes formatted section header or key=value line

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x005668b0 | filename path | File open | file handle or -1 |
| 0x0042fd00 | param_1+0x68 (Notes) | Read notes string | "My Setup" |
| 0x00566c30 | section name + values | Write INI line | "[SUSPENSION]\nAntiSway=5\n..." |
| 0x00566b90 | file handle | File close | file written |

## Globals Written in This Chain

None — writes to file, no globals mutated

## Notes

- 5 of 7 callees are pure file I/O leaves
- Error path uses assert (0x004d7a50) + error logging (0x004d7aa0)
- Writes 50+ fields — defines the full set of moddable setup parameters
---
