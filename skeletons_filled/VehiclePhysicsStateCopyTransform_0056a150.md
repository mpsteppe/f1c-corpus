## VehiclePhysicsStateCopyTransform_0056a150 — CopyStateAndComputeVelocity

**Summary:** Copies physics state (position, rotation, linear/angular momentum) from internal prediction buffer to working offsets, then computes angular velocity = world_inv_inertia * angular_momentum. Part of rigid body integration loop.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BatchIterationWithCounter (0056f060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | RW | — | angular velocity x (result) |
| this | 0x84 | RW | — | angular velocity y (result) |
| this | 0x8C | RW | — | angular velocity z (result) |
| this | 0x94 | R | — | angular momentum x (input) |
| this | 0x9C | R | — | angular momentum y (input) |
| this | 0xA4 | R | — | angular momentum z (input) |
| this | 0xEC | R | — | world-space inverse inertia row 0 col 0 |
| this | 0xF4 | R | — | world-space inverse inertia row 0 col 1 |
| this | 0xFC | R | — | world-space inverse inertia row 0 col 2 |
| this | 0x104 | R | — | world-space inverse inertia row 1 col 0 |
| this | 0x10C | R | — | world-space inverse inertia row 1 col 1 |
| this | 0x114 | R | — | world-space inverse inertia row 1 col 2 |
| this | 0x11C | R | — | world-space inverse inertia row 2 col 0 |
| this | 0x124 | R | — | world-space inverse inertia row 2 col 1 |
| this | 0x12C | R | — | world-space inverse inertia row 2 col 2 |

**Written-by note (persistence):**
- this 0x7C: recalc every frame — external poke does NOT persist
- this 0x84: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005692a0 | F_3x3InertiaTensorTransform | compute world-space inverse inertia tensor from body inertia + rotation |

**Guard conditions:** No guard — always executes fully with no early-return branches.
