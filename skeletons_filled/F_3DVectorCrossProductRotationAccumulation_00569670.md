## F_3DVectorCrossProductRotationAccumulation_00569670 — AccumulateContactImpulse

**Summary:** Accumulates collision contact impulse (a2) into vehicle state: updates linear momentum (offsets 0x64/0x6C/0x74) scaled by factor at 0xB4, updates angular momentum (offsets 0x94/0x9C/0xA4) via cross product of impulse and contact offset (a3), then recomputes torque from world inertia times angular momentum (offsets 0x7C/0x84/0x8C).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionContactImpulse (004599c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | RW | — | accumulated linear velocity/momentum X (updated) |
| this | 0x6C | RW | — | accumulated linear velocity/momentum Y (updated) |
| this | 0x74 | RW | — | accumulated linear velocity/momentum Z (updated) |
| this | 0x7C | RW | — | output torque X (inertia * angular momentum, recomputed) |
| this | 0x84 | RW | — | output torque Y (inertia * angular momentum, recomputed) |
| this | 0x8C | RW | — | output torque Z (inertia * angular momentum, recomputed) |
| this | 0x94 | RW | — | accumulated angular velocity/momentum X (updated) |
| this | 0x9C | RW | — | accumulated angular velocity/momentum Y (updated) |
| this | 0xA4 | RW | — | accumulated angular velocity/momentum Z (updated) |
| this | 0xB4 | R | — | impulse scaling factor (inverse mass or 1/dt) |
| this | 0xEC | R | — | world inertia row 0 col 0 |
| this | 0xF4 | R | — | world inertia row 0 col 1 |
| this | 0xFC | R | — | world inertia row 0 col 2 |
| this | 0x104 | R | — | world inertia row 1 col 0 |
| this | 0x10C | R | — | world inertia row 1 col 1 |
| this | 0x114 | R | — | world inertia row 1 col 2 |
| this | 0x11C | R | — | world inertia row 2 col 0 |
| this | 0x124 | R | — | world inertia row 2 col 1 |
| this | 0x12C | R | — | world inertia row 2 col 2 |

**Written-by note (persistence):**
- this 0x64: recalc every frame — external poke does NOT persist
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0x7C: recalc every frame — external poke does NOT persist
- this 0x84: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist
- this 0x94: recalc every frame — external poke does NOT persist
- this 0x9C: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional accumulation and recomputation, no branches or early returns.
