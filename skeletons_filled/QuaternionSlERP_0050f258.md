## QuaternionSlERP_0050f258 — Quaternion SLERP with derivative/interpolation output

**Summary:** Performs spherical interpolation involving quaternion `a6`, writing interpolated components and/or derivatives to `a1`, `a2`, `a3`. Includes shortest-path negation check, angular offset adjustments from `a7`, and multiple indirect thunk computations for trigonometric weighting.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion/output component 0 (x or scalar-like value) |
| this | 0x4 | RW | — | Quaternion/output component 1 (y) |
| this | 0x8 | RW | — | Quaternion/output component 2 (z) |
| this | 0xC | RW | — | Quaternion/output component 3 (w or scalar-like value) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call (to a1, a2, a3) — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive
- this 0xC: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ade48 | flt_5ADE48 | R | Unknown_Float_5ADE48 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050de26 | j_ShortComputation_de19 | Short float computation helper (called multiple times for SLERP weights) |
| 0050df95 | ThunkViaIndirectJump | Indirect jump thunk (trigonometric or matrix computation) |
| 0050e04f | IndirectJumpThunk | Indirect jump thunk (trigonometric or matrix computation) |
| 0050e0d3 | IndirectJumpThunk_e0d3 | Indirect jump thunk (interpolation/accumulation step) |

**Guard conditions:** The initial quaternion from `a6` may be negated (shortest-path flip) based on comparison flags (v8|v9). If the condition is false (not zero), the quaternion is negated before further processing.
