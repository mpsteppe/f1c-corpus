# Chain: Render/UI System Global Init — Rendering Subsystem Bootstrap

Seed: FUN_0053c360  |  System: docs/19-renderer.md  |  Depth: 2  |  Functions: 11

---

## Overview

Called during renderer/UI system startup — one-shot initialization. Zeroes a large global array (DAT_008b5a3c..DAT_008b8f2c, stride 0x84), sets global flags and sentinels, handles param_5 mode flags (bit 4 → mode 2, float 0.5; bit 3 → mode 3, float 0.333), and allocates two subsystem objects stored in DAT_008b8f04 and DAT_008b8f2c.

## Call Tree

```
FUN_0053c360 — Render/UI System Global Init  [trigger: renderer startup — callers: 0 (root)]
  +-- FUN_0053d930 — Buffer Init  [zeroes/initializes render buffer arrays]
  +-- FUN_0053d750 — [undocumented render init helper]
  +-- FUN_0055be80 — [undocumented subsystem init]
  +-- FUN_0053b0d0 — [undocumented render init helper]
  +-- FUN_005566d0 — [undocumented timing/timer init]
  +-- FUN_0055f080 — Object Allocator 1  [allocates 0xa0 byte object]
  +-- FUN_0055f0d0 — [undocumented render util]
  +-- FUN_0055f060 — [undocumented render util]
  +-- FUN_005593b0 — Object Allocator 2  [allocates 0xc byte object]
```

## Step-by-Step Trace

### Level 0: FUN_0053c360 — Render/UI System Global Init

**Trigger:** Called once at renderer/UI subsystem startup (root init function).
**Called by:** None (callers: 0 — called by CRT init or WinMain directly).
**Purpose:** One-time initialization of all rendering/UI global state.

**Key actions:**
1. Zeroes large global array (DAT_008b5a3c..0x8b6abc, stride 0x84)
2. Sets multiple global flags and sentinels
3. Handles param_5 flags: bit 4 → mode 2, float 0.5; bit 3 → mode 3, float 0.333
4. Calls FUN_0053d930 (buffer init), FUN_0053d750, FUN_0055be80, FUN_0053b0d0, FUN_005566d0
5. Allocates two objects: FUN_0055f080() (0xa0 bytes), FUN_005593b0() (0xc bytes)
6. Stores allocated pointers in DAT_008b8f04 and DAT_008b8f2c

**Globals:** DAT_008b5a3c..DAT_008b8f2c (renderer state array and subsystem pointers)

**Data passed to callees:** param_5 mode flags, allocation size parameters

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0053c360 | none | Zero DAT_008b5a3c range | 0-initialized render state |
| FUN_0053c360 | param_5 bits 3/4 | Mode dispatch | Mode 2 or 3 with float param |
| FUN_0053d930 | buffer size | Init buffer | Initialized buffer |
| FUN_0055f080 | 0xa0 bytes | Allocate | Object pointer → DAT_008b8f04 |
| FUN_005593b0 | 0xc bytes | Allocate | Object pointer → DAT_008b8f2c |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008b5a3c..008b6abc | RenderStateArray | FUN_0053c360 | Zeroed renderer state |
| DAT_008b8f04 | SubsystemPtr1 | FUN_0053c360 | 0xa0-byte alloc |
| DAT_008b8f2c | SubsystemPtr2 | FUN_0053c360 | 0xc-byte alloc |

## Notes

- Root init function — no callers. Part of renderer DLL or static init.
- Mode dispatch (param_5 bits 3/4) controls render quality/feature level
- The 0xc-byte object (FUN_005593b0) is likely a reference counter or small state struct

---

---
