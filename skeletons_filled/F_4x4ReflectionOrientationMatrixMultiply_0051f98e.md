## F_4x4ReflectionOrientationMatrixMultiply_0051f98e — SSEReflectionOrientationMatrixMultiply

**Summary:** Multiplies a 4x4 reflection/orientation matrix (a2) with a rotation-like matrix derived from normalized input vector/quaternion (a3), storing 4-row result at output (a1). Normalizes a3 using Newton-Raphson refinement with lazy one-time constant initialization via byte_8D46B0 flags. Alignment-aware store path (unaligned stores if output address not 16-byte aligned). Part of SSE 3D math library.

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
| 005d8b00 | xmmword_5D8B00 | R | XOR mask for sign flip on normalized input |
| 005d8b10 | xmmword_5D8B10 | R | SSE constant for matrix row blending |
| 005d8b20 | xmmword_5D8B20 | R | AND mask for component extraction |
| 005d8b30 | xmmword_5D8B30 | R | AND mask for component extraction |
| 005d8b40 | xmmword_5D8B40 | R | AND mask for quaternion component selection |
| 008d4690 | xmmword_8D4690 | RW | Cached Newton-Raphson refinement factor (lazy init) |
| 008d46a0 | xmmword_8D46A0 | RW | Cached inverse sqrt constant (lazy init) |
| 008d46b0 | byte_8D46B0 | RW | Lazy init flags: bit0=cache1, bit1=cache2 |
| 008d60c0 | dword_8D60C0 | R | Newton-Raphson refinement constant (source for lazy cache) |
| 008d60c4 | dword_8D60C4 | R | Inverse sqrt scaling constant (source for lazy cache) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks if vector squared length is zero (`v7.m128_f32[0] != 0.0`). PASSES (normalizes) when non-zero. BLOCKED (skips normalization, uses raw input) when zero.
