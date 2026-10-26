# Chain: WheelDynamicsInit — 4-Wheel Vehicle Dynamics Substructure Initialization

Seed: FUN_0043e230  |  System: docs/18-physics-dynamics.md  |  Depth: 3  |  Functions: 8

---

## Overview

Called from vehicle dynamics post-update (callers: FUN_0042c9f0 DynMan::Post, FUN_004e4790 wheel controller init, FUN_00438ca0). Initializes the 4-wheel vehicle dynamics substructure. Loops over 4 wheels (stride 0x464), sets contact constraints, slip ratios, slip angles, and force/moment components. Calls subsystem inits (buffer clear, resource destroy, physics step). Zeroes 0x1f38 bytes of state and initializes wheel IDs with default double values (~384.494).

## Call Tree

```
FUN_0043e230 — WheelDynamicsInit  [called from 3 callers: DynMan::Post, wheel ctrl init, vehicle setup]
  +-- FUN_00431a50 — Simple Setter with Flag  [docs/18: wheel RPM/velocity from param_1[0x753]]
  +-- FUN_00431930 — SetContactConstraint  [docs/18: per-wheel slip ratio init]  [×4]
  +-- FUN_004319c0 — Parameter Array Setter with Dirty Flag  [docs/18: per-wheel slip angle init]  [×4]
  +-- FUN_00431a70 — PhysicsGridValueSet  [docs/18: per-component force/moment]  [×12]
  +-- FUN_004d5840 — Resource Destroy  [docs/20: subsystem cleanup]
  |     +-- FUN_00587bcf — Free Wrapper  [heap free]
  |           +-- FUN_0058aa6f — Heap Deallocation
  +-- FUN_004358f0 — PhysicsBufferClear  [docs/18: buffer reset]
  +-- FUN_0056e970 — [undocumented: docs/18]  [physics step init]
  +-- FUN_00587bcf — Free Wrapper (×2)  [docs/01: frees buffers at param_1[0x73f] and param_1[0x58b]]
        +-- FUN_0058aa6f — Heap Deallocation  [docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_0043e230 — WheelDynamicsInit

**Trigger:** Called from three callers: DynMan::Post() (per-frame), wheel controller init, vehicle setup
**Called by:** FUN_0042c9f0 (DynMan::Post, docs/01), FUN_004e4790 (wheel controller init, docs/18), FUN_00438ca0 (docs/18)
**Purpose:** Initializes 4-wheel vehicle dynamics substructure.

**Key actions:**
1. Calls FUN_00431a50 with wheel RPM/velocity (param_1[0x753])
2. Loops 4 times (4 wheels), stride 0x464 per wheel:
   - FUN_00431930(wheel_ptr, slip_ratio) — set contact constraint
   - FUN_004319c0(wheel_ptr, slip_angle) — set parameter with dirty flag
   - FUN_00431a70(wheel_ptr, component) — ×3 per wheel (3 force/moment components)
3. Calls FUN_004d5840 (subsystem cleanup) and FUN_004358f0 (buffer clear)
4. Sets param_1[0x7c0] = 0
5. Calls FUN_0056e970 (physics step init)
6. Frees buffers at param_1[0x73f] and param_1[0x58b] if non-null
7. Zeroes 0x7ce × 4 = 0x1f38 bytes starting at param_1
8. Loop 4 times (stride 0x119×4=0x464): sets wheel ID, initializes default double values

### Level 1: Wheel Per-Component Setters

**FUN_00431a50 — Simple Setter with Flag** [docs/18-physics-dynamics.md]
- Sets wheel RPM/velocity value from param_1[0x753] with dirty flag
- Called once per init

**FUN_00431930 — SetContactConstraint** [docs/18-physics-dynamics.md]
- Sets wheel slip ratio contact constraint at wheel offset
- Called 4 times (once per wheel)

**FUN_004319c0 — Parameter Array Setter with Dirty Flag** [docs/18-physics-dynamics.md]
- Sets slip angle parameter array element, marks dirty
- Called 4 times (once per wheel)

**FUN_00431a70 — PhysicsGridValueSet** [docs/18-physics-dynamics.md]
- Sets force/moment component in physics grid
- Called 12 times (3 components × 4 wheels)

### Level 1: Subsystem Inits

**FUN_004d5840 — Resource Destroy** [docs/20-math-utilities.md]
- Cleans up old resources, calls FUN_00587bcf for heap free

**FUN_004358f0 — PhysicsBufferClear** [docs/18-physics-dynamics.md]
- Clears/resets physics buffer to zero state

**FUN_0056e970 — [undocumented]** [docs/18-physics-dynamics.md]
- Physics step initialization (no further call graph info)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| param_1[0x753] | wheel RPM/velocity | FUN_00431a50 setter | Wheel state init |
| slip_ratio (per wheel) | float | FUN_00431930 | Contact constraint |
| slip_angle (per wheel) | float | FUN_004319c0 | Parameter array entry |
| force/moment (×3/wheel) | float | FUN_00431a70 | Grid value set |
| param_1[0x73f],[0x58b] | buffer pointers | FUN_00587bcf free | Memory freed |

## Notes

- 4-wheel loop with stride 0x464 is consistent across all three callers
- 3 callers: DynMan::Post (per-frame), wheel controller init (once), vehicle setup (once)
- FUN_0056e970 is undocumented — appears in docs/18 but no further call graph info
- Total: 4 setters × 4 wheels = 16 setter calls + 2 subsystem inits + 2 frees + zero-init

---
