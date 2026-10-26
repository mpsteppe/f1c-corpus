## EulerAnglesToQuaternion_0050dd40 — Euler angles to quaternion conversion

**Summary:** Converts three Euler angles (`a2`, `a3`, `a4`) into a quaternion (x,y,z,w). Computes half-angle sines/cosines and combines them via trigonometric products for the final quaternion components.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion x (combined from half-angle trig products) |
| this | 0x4 | RW | — | Quaternion y (combined from half-angle trig products) |
| this | 0x8 | RW | — | Quaternion z (combined from half-angle trig products) |
| this | 0xC | RW | — | Quaternion w (combined from half-angle trig products) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive
- this 0xC: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — all four quaternion components are unconditionally written.
