## SSE3DCrossProductWith33Matrix_0051f0be — SSE3DCrossProductWith33Matrix

**Summary:** Computes 3D cross product of three input vectors (a2, a3, a4) using SSE intrinsics. Loads pairs of floats from each input, applies shuffle/ multiply/ subtract/ add operations with sign-flip via XOR mask at xmmword_5D8A20, and stores result in output __m128 at a1. Part of SSE-accelerated 3D math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output __m128 result of 3D cross product |

**Written-by note (persistence):**
- this 0x0: unconditionally written with cross product result; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8a20 | xmmword_5D8A20 | R | XOR mask for cross product sign flip (right-hand rule) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always computes and stores cross product result.
