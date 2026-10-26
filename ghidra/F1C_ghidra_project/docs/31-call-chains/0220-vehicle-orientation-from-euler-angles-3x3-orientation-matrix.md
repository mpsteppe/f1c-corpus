# Chain: Vehicle Orientation from Euler Angles — 3x3 Orientation Matrix Construction

Seed: 0x004b2dd0  |  System: docs/18-physics-dynamics.md  |  Depth: 1  |  Functions: 10

---

## Overview

Called from physics body transform (0x004b2b50) and renderer transform (0x005001f0). Converts packed short Euler angles to an orthonormal 3x3 rotation matrix. Uses sin/cos for angle decomposition, constructs basis vectors via cross products, normalizes, and writes final orientation. All 10 callees are leaf matrix/math operations.

## Call Tree

```
0x004b2dd0 — Vehicle Orientation from Euler Angles  [trigger: physics/render transform update]
  +-- 0x004b2480 — angle validation
  +-- 0x004b25d0 — trig setup
  +-- 0x004b2750 — trig setup
  +-- 0x0044c550 — angle→matrix conversion
  +-- 0x00588570 — math/random utility
  +-- 0x004b31a0 — [undocumented matrix op]
  +-- 0x004b2bf0 — [undocumented matrix op]
  +-- 0x004b29b0 — [undocumented matrix op]
  +-- 0x004b2c50 — [undocumented matrix op]
  +-- 0x004b2930 — [undocumented matrix op]
```

## Step-by-Step Trace

### Level 0: 0x004b2dd0 — Vehicle Orientation from Euler Angles

**Trigger:** Called during physics or render transform update
**Called by:** 0x004b2b50 (physics body transform, docs/18), 0x005001f0 (renderer transform, docs/19)
**Purpose:** Converts packed short Euler angles to 3x3 orthonormal orientation matrix

**Key actions:**
1. Reads 3 short angles from param_1[9]/[0xb]/[0xd], converts to radians via _DAT_0059e778
2. Validates angles via 0x004b2480
3. Sets up trig via 0x004b25d0/0x004b2750 (sin/cos computation)
4. Normalizes to unit length, scales by _DAT_0059e670
5. Constructs 3x3 basis via cross products between local axes
6. Converts packed position data via _DAT_0059e780
7. Calls 0x0044c550 for angle→matrix, then orthonormalizes
8. Uses 0x00588570 (random) and fpatan for yaw/pitch extraction
9. Writes final orientation to param_2+0x8/0xc/0x10

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x004b2dd0 | param_1[9]/[b]/[d] (short angles) | Radians conversion | float angles |
| 0x004b2480 | float angles | Validation | clamped angles |
| 0x004b25d0/0x004b2750 | angles | sin/cos computation | trig values |
| 0x0044c550 | trig values | Matrix construction | 3x3 rotation |
| 0x004b2dd0 | 3x3 matrix | Orthonormalize | final orientation |

## Globals Written in This Chain

None — writes to param_2 output buffer only

## Notes

- All 10 callees are leaf functions — no further recursion
- 0x00588570 (math/random) is shared across physics/renderer systems
- 6 undocumented callees (0x004b31a0, 0x004b2bf0, 0x004b29b0, 0x004b2c50, 0x004b2930) are likely matrix operation helpers
---
