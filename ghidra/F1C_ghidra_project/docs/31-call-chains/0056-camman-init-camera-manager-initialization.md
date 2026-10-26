# Chain: CamMan::Init — Camera Manager Initialization

Seed: 0x0040c920  |  System: docs/01-engine-architecture.md  |  Depth: 2  |  Functions: 8

---

## Overview

Initializes the camera manager during game boot. Triggered by Game::Setup() via 0x0042d6b0. Obtains MAINVIEW camera object, zeros camera globals, initializes camera subsystems, configures render culling. Output: initialized camera system with MAINVIEW camera ready.

## Call Tree

```
0x0040c920 — CamMan::Init  [trigger: Game::Setup() calls via 0x0042d6b0]
  +-- 0x004d7a50 — Trace Gate  [logging gate check]
  |     +-- 0x00587c20 — [leaf]
  |     +-- 0x004d7aa0 — Trace Log  [leaf]
  +-- 0x004d7aa0 — Trace Log  [leaf]
  +-- 0x00544f50 — Get Camera Object by Name  [finds "MAINVIEW" camera, leaf]
  +-- 0x0040c240 — Camera Subsystem Init A  [leaf]
  +-- 0x0040c3b0 — Camera Subsystem Init B  [leaf]
  +-- 0x0040c520 — Camera Subsystem Init C  [leaf]
  +-- 0x0040c140 — Camera Subsystem Init D  [returns success flag, leaf]
  +-- 0x0054a200 — Render Culling Enable  [enables culling via D3D, leaf]
```

## Step-by-Step Trace

### Level 0: 0x0040c920 — CamMan::Init

**Trigger:** Game boot — called from Game::Setup() as part of subsystem initialization.
**Called by:** 0x0042d6b0 (Game::Setup post-init).
**Purpose:** Camera manager initialization — sets up camera system with MAINVIEW camera.

**Key actions:**
1. Gets "MAINVIEW" camera object via FUN_00544f50, stores in param_1
2. Zeros camera globals DAT_005ea550/554/558/500/504/508
3. Calls camera subsystem inits: FUN_0040c240, FUN_0040c3b0, FUN_0040c520
4. Sets byte at param_1+0x2d to 0
5. Calls FUN_0040c140; if returns 0, copies param_1[6] into param_1[2]
6. Enables render culling via FUN_0054a200(0x20, 1)

**Data passed to callees:** Camera manager pointer (param_1), camera name string "MAINVIEW".

### Level 1: All callees are leaf functions except trace gate

**0x00544f50** — Gets camera object by name string "MAINVIEW". Returns camera pointer.
**0x0040c240** — Camera subsystem init A (undocumented purpose, leaf).
**0x0040c3b0** — Camera subsystem init B (undocumented purpose, leaf).
**0x0040c520** — Camera subsystem init C (undocumented purpose, leaf).
**0x0040c140** — Camera subsystem init D. Returns 0 on success. Used for conditional copy.
**0x0054a200** — Enables/disables render culling. Called with (0x20, 1).

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0040c920 | camera manager ptr | find MAINVIEW | camera object stored |
| FUN_00544f50 | "MAINVIEW" string | lookup | camera pointer |
| FUN_0040c240 | camera ptr | subsystem init A | state set |
| FUN_0040c3b0 | camera ptr | subsystem init B | state set |
| FUN_0040c520 | camera ptr | subsystem init C | state set |
| FUN_0054a200 | 0x20, 1 | enable culling | render culling on |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005ea550 | camera global A | CamMan::Init | zeroed |
| DAT_005ea554 | camera global B | CamMan::Init | zeroed |
| DAT_005ea558 | camera global C | CamMan::Init | zeroed |
| DAT_005ea500 | camera global D | CamMan::Init | zeroed |
| DAT_005ea504 | camera global E | CamMan::Init | zeroed |
| DAT_005ea508 | camera global F | CamMan::Init | zeroed |

## Notes

Shallow chain (depth 2). All callees are leaf functions (except trace gate which is always-shallow). The conditional copy (if FUN_0040c140 returns 0, copy param_1[6] to param_1[2]) suggests a fallback/default camera position initializer.

---
