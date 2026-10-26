## QuaternionToRotationMatrix_0a7e_00520a7e — QuaternionToRotationMatrixWithLazyNR

**Summary:** Normalizes quaternion (a3) using Newton-Raphson refinement with lazy one-time constant initialization (via byte_8D46B0), then multiplies with matrix (a2) to produce 4-row rotation matrix output (a1). Uses distinct global constants (xmmword_5D8C60-CA0, dword_8D6220/24) from the related function at 0051f98e. Alignment-aware store path. Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 |
| this | 0x10 | RW | — | Output matrix row 1 |
| this | 0x20 | RW | — | Output matrix row 2 |
| this | 0x30 | RW | — | Output matrix row 3 |

**Written-by note (persistence):**
- this 0x0: unconditionally written with result row 0; persists as output
- this 0x10: unconditionally written with result row 1; persists as output
- this 0x20: unconditionally written with result row 2; persists as output
- this 0x30: unconditionally written with result row 3; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8c60 | xmmword_5D8C60 | R | XOR mask for sign negation on normalized quaternion |
| 005d8c70 | xmmword_5D8C70 | R | AND mask for matrix row blending |
| 005d8c80 | xmmword_5D8C80 | R | AND mask for component extraction |
| 005d8c90 | xmmword_5D8C90 | R | AND mask for component extraction |
| 005d8ca0 | xmmword_5D8CA0 | R | AND mask for quaternion component selection |
| 008d4690 | xmmword_8D4690 | RW | Cached Newton-Raphson refinement factor (lazy init) |
| 008d46a0 | xmmword_8D46A0 | RW | Cached inverse sqrt constant (lazy init) |
| 008d46b0 | byte_8D46B0 | RW | Lazy init flags: bit0=cache1, bit1=cache2 |
| 008d6220 | dword_8D6220 | R | Newton-Raphson refinement constant (source for lazy cache) |
| 008d6224 | dword_8D6224 | R | Inverse sqrt scaling constant (source for lazy cache) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks if quaternion squared length is zero (`v7.m128_f32[0] != 0.0`). PASSES (normalizes) when non-zero. BLOCKED (skips normalization, uses raw input) when zero.
