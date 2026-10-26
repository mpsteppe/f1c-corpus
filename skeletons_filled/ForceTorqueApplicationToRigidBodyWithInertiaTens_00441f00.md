## ForceTorqueApplicationToRigidBodyWithInertiaTens_00441f00 — Rigid body force-torque with inertia tensor transform

**Summary:** Applies force/torque inputs to a rigid body by transforming velocity through a 3x4 inertia tensor matrix, adding translational offsets and suspension damping, and writing computed force-torque to 4 per-wheel output slots (24 bytes each). Sets an active flag at 0x1724.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x4 | R | — | inertia tensor matrix row 0, col 1 (translation offset X) |
| *(this+0x15F0) | 0xC | R | — | inertia tensor matrix row 0, col 2 (translation offset Y) |
| *(this+0x15F0) | 0x14 | R | — | inertia tensor matrix row 0, col 3 (translation offset Z) |
| *(this+0x15F0) | 0x1C | R | — | inertia tensor matrix row 0, col 0 (rotation 0,0) |
| *(this+0x15F0) | 0x24 | R | — | inertia tensor matrix row 0, col 1 (rotation 0,1) |
| *(this+0x15F0) | 0x2C | R | — | inertia tensor matrix row 0, col 2 (rotation 0,2) |
| *(this+0x15F0) | 0x34 | R | — | inertia tensor matrix row 1, col 0 (rotation 1,0) |
| *(this+0x15F0) | 0x3C | R | — | inertia tensor matrix row 1, col 1 (rotation 1,1) |
| *(this+0x15F0) | 0x44 | R | — | inertia tensor matrix row 1, col 2 (rotation 1,2) |
| *(this+0x15F0) | 0x4C | R | — | inertia tensor matrix row 2, col 0 (rotation 2,0) |
| *(this+0x15F0) | 0x54 | R | — | inertia tensor matrix row 2, col 1 (rotation 2,1) |
| *(this+0x15F0) | 0x5C | R | — | inertia tensor matrix row 2, col 2 (rotation 2,2) |
| this | 0x15F0 | R | — | pointer to 3x4 double inertia tensor matrix |
| this | 0x15F4 | R | — | suspension damping multiplier (~1.5328e-5) |
| this | 0x1724 | RW | 1 | active flag: 1 = force/torque being applied, 0 = all inputs zero |

**Written-by note (persistence):**
- this 0x1724: conditional — set to 0 if all inputs zero, else set to 1. External poke could be overwritten by either path.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059ed58 | dbl_59ED58 | R | SuspensionSpringRate [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** All 4 torque/force input parameters (a2, a3, a4, a5) == 0.0 → sets 0x1724 flag to 0 and skips entire force-torque computation (4-iteration loop). Any non-zero input → sets 0x1724 flag to 1 and executes all 4 wheel iterations.
