## SSEQuaternionCompositionFromAxisAngleComponents_00520e0e — Construct quaternion from axis-angle components via SSE

**Summary:** Packs three axis-angle float components (a2=angle, a3/a4=axis direction) with a constant vector, multiplies by another constant, calls sub_528CC0 (quaternion composition helper), then finalizes with additional SSE shuffles/multiply/add/xor to produce a normalized quaternion in a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output __m128 quaternion (w, x, y, z) |

**Written-by note (persistence):**
- this 0x0: Written once by the final `*a1 = v10` store; external caller provides pointer — no persistence, purely output.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d62a0 | xmmword_8D62A0 | R | SIMDAddConstant [DERIVED] |
| 008d62b0 | xmmword_8D62B0 | R | Xmmword_QuaternionMultiply [DERIVED] |
| 008d62c0 | dword_8D62C0 | R | SSE_ColorUnpack [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00528cc0 | sub_528CC0 | Quaternion composition helper: processes intermediate packed vector into per-component values |

**Guard conditions:** None — no conditional branches; always executes full computation path.
